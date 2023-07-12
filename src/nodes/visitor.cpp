#include <iostream>
#include <fstream>
#include <string>
#include "visitor.hpp"
#include "../internal_types.hpp"

#include <fmt/core.h>
#include <fmt/color.h>

#include <stack>

namespace {
    static uintmax_t last_disp = 0;
    static std::unordered_map<std::string, uintmax_t> vars_disp;
    static std::ofstream output_file;

    static uintmax_t data_var = 0;

    inline uintmax_t compute_type_size(const _typeinfo_t& _tinfo) {
        if (_tinfo._isptr) {
            return sizeof(void*);
        }

        const std::string& _type = _tinfo._type;
        if (_type == "void")       // 0 byte
            return 0;
        else if (_type == "char")  // 1 byte
            return 1;
        else if (_type == "int")   // 4 bytes
            return 4;
        else                        // long: 8 bytes
            return 8;
    }

    inline const std::string& get_op_size_prefix(const _typeinfo_t& type) {
        static const std::string sizes[4] = {
            "8","16","32","64"
        };
        static const std::string ptr_size = std::to_string(8ULL * sizeof(void*));
        
        if (type._isptr) return ptr_size;
        else if (type._type == "char") return sizes[0];
        else if (type._type == "int") return sizes[2];
        else if (type._type == "long") return sizes[3];

        throw std::runtime_error(
            fmt::format(
                "{} (compilation): cannot find size of type '{}'",
                fmt::styled("error", fg(fmt::color::red)),
                type._type
            )
        );
    }
}

void Visitor::visit(ProgramNode* node) {
    output_file = std::ofstream(node->getTUName());

    output_file << "// Program\n";
    for (auto& f : node->getFunctions()) {
        last_disp = 0;
        vars_disp.clear();

        output_file << "\n// Function:\nlabel " << f.first << "\n";
        output_file << "\n// Local data\n";

        auto params = f.second.getParamsList();

        for (size_t i = 0; i < params.size(); ++i) {
            auto& p = params[i];
            output_file << "//\t Parameter (" << p._tinfo._type << "): " << p._name << " => located at [" << last_disp << "]\n";
            vars_disp.emplace(p._name, last_disp);
            last_disp += compute_type_size(p._tinfo);
        }
        for (const auto& _vdef : f.second.getVarTable()) {
            output_file << "//\t Local var (" << _vdef.second._type << "): " << _vdef.first << " => located at [" << last_disp << "]\n";
            vars_disp.emplace(_vdef.first, last_disp);
            last_disp += compute_type_size(_vdef.second);
        }
        output_file << "// Load parameters\n";
        params_def_list::reverse_iterator rit = params.rbegin();
        for (; rit != params.rend(); ++rit) {
            output_file << "[[BITS" << get_op_size_prefix(rit->_tinfo) << "]] " <<  "store " << vars_disp.at(rit->_name) << "\n";
        }
        for (auto& statement : f.second.getStatements()) {
            statement.accept(*this);
        }
    }

    output_file.close();
}
void Visitor::visit(StatementNode* node) {
    output_file << "\n// Statement\n";
    ExpNode* exp = node->getExp();
    if (exp->getExpType().starts_with("imm_") || exp->getExpType() == "var") {
        if (node->getOutVar() == "") {
            std::cerr << "Warning: orphan immediate found at line " << node->getline() << std::endl;
            return;
        }

        const std::string& bin_size = get_op_size_prefix(exp->getRetType());

        output_file << "[[BITS" << bin_size << "]] " << "load_c ";
        exp->accept(*this);
        output_file << "[[BITS" << bin_size << "]] " << "store " << vars_disp.at(node->getOutVar()) << "\n";
    }
    else {
        exp->accept(*this);
        if (node->getOutVar() != "") {
            output_file << "[[BITS" << get_op_size_prefix(exp->getRetType()) << "]] " << "store " << vars_disp.at(node->getOutVar()) << "\n";
        }
    }
}
void Visitor::visit(IdentifierNode* node) {
    if (vars_disp.count(node->getName())) {
        output_file << vars_disp.at(node->getName()) << "\n";
    }
    else {
        output_file << node->getName() << "\n";
    }
}
void Visitor::visit(DereferenceNode* node) {
    // not yet implemented
}
void Visitor::visit(AddressofNode* node) {
    // not yet implemented
}
void Visitor::visit(IntegerNode* node) {
    output_file << node->getValue() << "\n";
}
void Visitor::visit(LongNode* node) {
    output_file << node->getValue() << "\n";
}
void Visitor::visit(FloatNode* node) {
    output_file << node->getValue() << "\n";
}
void Visitor::visit(CharNode* node) {
    output_file << (uint16_t)node->getValue() << "\n";
}
void Visitor::visit(StringNode* node) {
    const std::string& str = node->getValue();
    output_file << ".string " << str << "\n";
    output_file << "ldptr " << data_var << "\n";
    ++data_var;
}
void Visitor::visit(ConversionNode* node) {
    static const std::unordered_map<std::string, std::string> conv_ops_map = {
        { "char", "secb" },
        { "int",  "secd" },
        { "long", "secq" }
    };
    static const std::unordered_map<size_t, std::string> size_conv_ops_map = {
        {  8, "secb" },
        { 16, "secw" },
        { 32, "secd" },
        { 64, "secq" }
    };

    ExpNode* exp = node->getExp();
    const auto& prefix_size = get_op_size_prefix(exp->getRetType());

    if (exp->getExpType() != "op") {
        const char* bin_op = exp->isConst() ? "load_c " : "load_v" ;
        output_file << "[[BITS" << prefix_size << "]] " << bin_op; exp->accept(*this);
    }
    else {
        exp->accept(*this);
    }

    const _typeinfo_t& ret_type = node->getRetType();
    std::string conv_op = "";

    if (ret_type._isptr) {
        conv_op = size_conv_ops_map.at(8 * sizeof(void*));
    }
    else {
        conv_op = conv_ops_map.at(ret_type._type);
    }

    output_file << "[[BITS" << prefix_size << "]] " << conv_op << "\n";
}
void Visitor::visit(MathNode* node) {
    if (node->getLeft()->getExpType() != "op" && node->getRight()->getExpType() != "op") {
        const char* l_str = node->getLeft()->isConst() ? "load_c " : "load_v ";
        const char* r_str = node->getRight()->isConst() ? "load_c " : "load_v ";

        output_file << "[[BITS" << get_op_size_prefix(node->getLeft()->getRetType()) << "]] " << l_str; node->getLeft()->accept(*this);
        output_file << "[[BITS" << get_op_size_prefix(node->getRight()->getRetType()) << "]] " << r_str; node->getRight()->accept(*this);        
    }
    else if (node->getLeft()->getExpType() == "op" && node->getRight()->getExpType() == "op") {
        node->getLeft()->accept(*this);
        node->getRight()->accept(*this);
    }
    else {
        if (node->getLeft()->getExpType() == "op") {
            node->getLeft()->accept(*this);
            const char* r_str = node->getRight()->isConst() ? "load_c " : "load_v ";

            output_file << "[[BITS" << get_op_size_prefix(node->getLeft()->getRetType()) << "]] " << r_str; node->getRight()->accept(*this);
        }
        else {
            const char* l_str = node->getRight()->isConst() ? "load_c " : "load_v ";

            output_file << "[[BITS" << get_op_size_prefix(node->getRight()->getRetType()) << "]] " << l_str; node->getLeft()->accept(*this);
            node->getRight()->accept(*this);
        }
    }

    output_file << "[[BITS" << get_op_size_prefix(node->getLeft()->getRetType()) << "]] ";
    char op = node->getOp();
    if (op == '+') {
        output_file << "add\n";
    }
    else if (op == '-') {
        output_file << "sub\n";
    }
    else if (op == '*') {
        output_file << "mul\n";
    }
    else if (op == '/') {
        output_file << "div\n";
    }
}
void Visitor::visit(FunctionCall* node) {
    const auto& args = node->getParameters();
    for (size_t i = 0; i < args.size(); ++i) {
        if (args[i]->isConst()) {
            output_file << "[[BITS" << get_op_size_prefix(args[i]->getRetType()) << "]] load_c "; args[i]->accept(*this);
        }
        else if (args[i]->getExpType() == "var") {
            output_file << "[[BITS" << get_op_size_prefix(args[i]->getRetType()) << "]] load_v "; args[i]->accept(*this);
        }
        else {
            args[i]->accept(*this);
        }
    }

    output_file << "call " << node->getName() << "\n";
}
void Visitor::visit(NativeFunctionCall* node) {
    const auto& args = node->getParameters();
    for (size_t i = 0; i < args.size(); ++i) {
        if (args[i]->isConst()) {
            output_file << "[[BITS" << get_op_size_prefix(args[i]->getRetType()) << "]] load_c "; args[i]->accept(*this);
        }
        else if (args[i]->getExpType() == "var") {
            output_file << "[[BITS" << get_op_size_prefix(args[i]->getRetType()) << "]] load_v "; args[i]->accept(*this);
        }
        else {
            args[i]->accept(*this);
        }
    }

    output_file << "natcall " << node->getLib() << "," << node->getName() << "\n";
}
