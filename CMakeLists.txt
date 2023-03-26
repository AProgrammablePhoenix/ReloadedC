cmake_minimum_required(VERSION 3.22)

project(relc)

find_package(fmt)

add_custom_target(AntlrRelcGrammar
    COMMAND bash -ic [[antlr4 -Dlanguage=Cpp src/antlr_grammar/relcgrammar.g4 -no-listener -visitor -Xexact-output-dir -o src/grammar]]
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

aux_source_directory("src/grammar" AntlrRelcGrammarSources)
aux_source_directory("src/grammar_visitor" RelcGrammarSources)
add_library(RelcGrammar STATIC ${AntlrRelcGrammarSources} ${RelcGrammarSources})

aux_source_directory("src/nodes" NodesLibSources)
add_library(NodesLib STATIC ${NodesLibSources})

aux_source_directory("src/bytecode_gen" BytecodeGeneratorSources)
add_library(BytecodeGenerator STATIC ${BytecodeGeneratorSources})

add_executable(relc
    "src/symbols.cpp"
    "src/preprocessor.cpp"
    "src/main.cpp"
)

add_dependencies(RelcGrammar AntlrRelcGrammar)
target_include_directories(RelcGrammar
    PUBLIC "/usr/local/include/antlr4-runtime"
)
target_include_directories(relc
    PRIVATE "src"
)

target_compile_features(NodesLib PUBLIC cxx_std_23)
target_compile_features(BytecodeGenerator PUBLIC cxx_std_23)
target_compile_features(relc PUBLIC cxx_std_23)
target_link_libraries(RelcGrammar PUBLIC antlr4-runtime)
target_link_libraries(relc RelcGrammar NodesLib BytecodeGenerator fmt::fmt)