cmake_minimum_required(VERSION 3.10)

project(bro)

enable_testing()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(src/compiler src/stats)

add_executable(parser src/compiler/parser.c src/compiler/hello.c src/compiler/compiler.c src/compiler/grammar.c)
add_executable(eval src/compiler/eval.c src/compiler/compiler.c src/compiler/hello.c src/compiler/grammar.c)


add_executable(debug src/debug/cmd.c src/debug/debug.c src/compiler/compiler.c src/compiler/hello.c src/compiler/grammar.c)
