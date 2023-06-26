#include <iostream>
#include <fstream>
#include <string>
#include "visitor.hpp"

#include <fmt/core.h>
#include <fmt/color.h>

#include <stack>

namespace {
    static uintmax_t last_disp = 0;
    static std::unordered_map<std::string, uintmax_t> vars_disp;
    static std::ofstream output_file;

    inline uintmax_t compute_type_size(const std::string& _tinfo) {
        if (_tinfo == "void")       // 0 byte
            return 0;
        else if (_tinfo == "char")  // 1 byte
            return 1;
        else if (_tinfo == "int")   // 4 bytes
            return 4;
        else                        // long: 8 bytes
            return 8;
    }

    inline const std::string& get_op_size_prefix(const std::string& type) {
        static const std::string sizes[4] = {
            "8","16","32","64"
        };

        if (type == "char") return sizes[0];
        else if (type == "int") return sizes[2];
        else if (type == "long") return sizes[3];

        throw std::runtime_error(
            fmt::format(
                "{} (compilation): cannot find size of type '{}'",
                fmt::styled("error", fg(fmt::color::red)),
                type
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
            output_file << "//\t Parameter (" << p._type << "): " << p._name << " => located at [" << last_disp << "]\n";
            vars_disp.emplace(p._name, last_disp);
            last_disp += compute_type_size(p._type);
        }
        for (const auto& _vdef : f.second.getVarTable()) {
            output_file << "//\t Local var (" << _vdef.second << "): " << _vdef.first << " => located at [" << last_disp << "]\n";
            vars_disp.emplace(_vdef.first, last_disp);
            last_disp += compute_type_size(_vdef.second);
        }
        output_file << "// Load parameters\n";
        params_def_list::reverse_iterator rit = params.rbegin();
        for (; rit != params.rend(); ++rit) {
            output_file << "[[BITS" << get_op_size_prefix(rit->_type) << "]] " <<  "store " << vars_disp.at(rit->_name) << "\n";
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
void Visitor::visit(ConversionNode* node) {
    static const std::unordered_map<std::string, std::string> conv_ops_map = {
        { "char", "secb" },
        { "int", "secd"},
        { "long", "secq" }
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

    output_file << "[[BITS" << prefix_size << "]] " << conv_ops_map.at(node->getRetType()) << "\n";
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
