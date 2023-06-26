#include <iostream>
#include <string>

#include <filesystem>
#include <fstream>
#include <memory>
#include <vector>

#include <dlfcn.h>

#include "preprocessor.hpp"
#include "nodes/program.hpp"
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


int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Not enough arguments were provided\n";
        std::cerr << "usage: relc <filename>\n";
        return 1;
    }

    std::string content = read_file(argv[1]);
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

    return 0;
}