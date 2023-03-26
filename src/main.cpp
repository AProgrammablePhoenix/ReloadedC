#include <iostream>
#include <string>

#include <filesystem>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>

#include <dlfcn.h>

#include "preprocessor.hpp"
#include "nodes/program_node.hpp"
#include "nodes/visitor.hpp"
#include "nodes/NodesLib.hpp"

#include <fmt/core.h>
#include <fmt/format.h>
#include <fmt/color.h>

#include "antlr4-runtime.h"
#include "grammar/relcgrammarLexer.h"
#include "grammar/relcgrammarParser.h"

#include "grammar_visitor/gvisitor.hpp"

#include "bytecode_gen/bytecode_gen.hpp"

std::vector<std::string> split_lines(const std::string& s) {
    std::vector<std::string> ret;
    
    std::stringstream ss(s);
    for (std::string line; std::getline(ss, line);) {
        ret.emplace_back(line);
    }

    return ret;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Not enough arguments were provided\n";
        std::cerr << "usage: relc <filename>\n";
        return 1;
    }

    void* libc = dlopen("libc.so.6", RTLD_LAZY);
    if (!libc) {
        fmt::print(fg(fmt::color::dark_red) | fmt::emphasis::bold, "{}\n",dlerror());
    }

    std::string content;

    std::ifstream hfile(argv[1]);
    if (hfile) {
        size_t content_len = std::filesystem::file_size(argv[1]);
        content.resize(content_len);
        hfile.read(content.data(), content_len);
    } else {
        fmt::print("{}: couldn't not open file: '{}'\n",
            fmt::styled("error", fg(fmt::color::red)),
            argv[1]
        );
    }
    auto lines = split_lines(content);
    lines = preprocess_file(lines);

    const std::string preproc_name = std::string(argv[1]) + ".i";

    std::ofstream preprocessed(std::string(argv[1]) + ".i");
    if (preprocessed) {
        for (const auto& l : lines) {
            preprocessed << l << std::endl;
        }
    }

    std::string antlr_input;
    std::ifstream preprocessed_input(std::string(argv[1]) + ".i");
    if (preprocessed_input) {
        size_t content_len = std::filesystem::file_size(std::string(argv[1]) + ".i");
        antlr_input.resize(content_len);
        preprocessed_input.read(antlr_input.data(), content_len);
    }

    antlr4::ANTLRInputStream input(antlr_input);
    relcgrammarLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    relcgrammarParser parser(&tokens);

    relcgrammarParser::ProgramContext* tree = parser.program();

    gvisitor visitor;
    std::shared_ptr<ProgramNode> program = visitor.visitProgram(tree, std::string(argv[1]) + ".tu");

    Visitor v;
    program->accept(v);

    bytecode_gen generator(std::string(argv[1]) + ".tu");
    const auto& bytecode = generator.generate();

    std::ofstream output_bytecode(std::string(argv[1]) + ".relexe", std::ios::out | std::ios::binary);
    if (output_bytecode) {
        output_bytecode.write((char*)bytecode.data(), bytecode.size());
    }

    if (libc) {
        dlclose(libc);
    }

    return 0;
}