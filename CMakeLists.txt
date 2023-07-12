cmake_minimum_required(VERSION 3.22)

project(relc)

find_package(fmt)

# only set SKIP_ANTLR to TRUE if you are sure that the grammar file won't change in the near future
# if it changes, just rebuild cmake without any arguments (e.g. "cmake .." instead of "cmake -DSKIP_ANTLR:BOOL=1 ..")

if ((NOT DEFINED SKIP_ANTLR) OR (SKIP_ANTLR EQUAL 0))
    message("Antlr-4 generation enabled")

    add_custom_target(AntlrRelcGrammar
        COMMAND bash -ic [[antlr4 -Dlanguage=Cpp src/antlr_grammar/relcgrammar.g4 -no-listener -visitor -Xexact-output-dir -o src/grammar]]
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
else()
    message("Antlr-4 generation disabled")
endif()

aux_source_directory("src/grammar" AntlrRelcGrammarSources)
aux_source_directory("src/grammar_visitor" RelcGrammarSources)
add_library(RelcGrammar STATIC ${AntlrRelcGrammarSources} ${RelcGrammarSources})

aux_source_directory("src/nodes" NodesLibSources)
add_library(NodesLib STATIC ${NodesLibSources})

aux_source_directory("src/bytecode_gen" BytecodeGeneratorSources)
add_library(BytecodeGenerator STATIC ${BytecodeGeneratorSources})

add_library(vlibc STATIC
    "src/vlibc/stdio.cpp"
    "src/vlibc/stdlib.cpp"
    "src/vlibc/vlibc.cpp"
)

add_executable(relc
    "src/symbols.cpp"
    "src/preprocessor.cpp"
    "src/main.cpp"
)

add_executable(relcvm
    "src/relcvm/engine/context.cpp"
    "src/relcvm/engine/engine.cpp"
    "src/relcvm/instructions/arithmetic.cpp"
    "src/relcvm/instructions/binary.cpp"
    "src/relcvm/instructions/conditional.cpp"
    "src/relcvm/instructions/control_flow.cpp"
    "src/relcvm/instructions/conversions.cpp"
    "src/relcvm/instructions/memory.cpp"
    "src/relcvm/main.cpp"
)

if ((NOT DEFINED SKIP_ANTLR) OR (SKIP_ANTLR EQUAL 0))
    add_dependencies(RelcGrammar AntlrRelcGrammar)
endif()

target_include_directories(RelcGrammar PUBLIC
    "/usr/local/include/antlr4-runtime"
)
target_include_directories(relc PRIVATE
    "src"
)
target_include_directories(relcvm PRIVATE
    "src"
    "src/relcvm"
)
target_include_directories(vlibc PRIVATE
    "src"
    "src/relcvm"
)

set(VLIBC_HEADERS
    "resources/stdlib.h"
    "resources/stdio.h"
)

target_compile_features(RelcGrammar PUBLIC cxx_std_23)
target_compile_features(NodesLib PUBLIC cxx_std_23)
target_compile_features(BytecodeGenerator PUBLIC cxx_std_23)
target_compile_features(vlibc PUBLIC cxx_std_23)
target_compile_features(relc PUBLIC cxx_std_23)
target_compile_features(relcvm PUBLIC cxx_std_23)

target_link_libraries(RelcGrammar PUBLIC antlr4-runtime)
target_link_libraries(relc RelcGrammar NodesLib BytecodeGenerator fmt::fmt)
target_link_libraries(relcvm BytecodeGenerator vlibc fmt::fmt)

include(GNUInstallDirs)

set(VLIBC_HEADERS_INSTALL_DIR ${CMAKE_INSTALL_FULL_DATADIR}/relc/vlibc_headers)
configure_file(src/cmake_env.hpp.in ${CMAKE_BINARY_DIR}/custom_gen/include/cmake_env.hpp)
include_directories(${CMAKE_BINARY_DIR}/custom_gen/include)

install(TARGETS
    relc relcvm RelcGrammar NodesLib BytecodeGenerator vlibc
)
install(FILES ${VLIBC_HEADERS}
    DESTINATION ${VLIBC_HEADERS_INSTALL_DIR}
)

# just to make sure Antlr generation is enabled if "cmake .." is run after "cmake -DSKIP_ANTLR:BOOL=1 .."
unset(SKIP_ANTLR CACHE)