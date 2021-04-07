cmake_minimum_required(VERSION 3.10)

project(bro)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


add_executable(hellobro src/compiler/hello.c src/compiler/grammar.c)
add_executable(broeval src/compiler/eval.c)
add_executable(bro src/compiler/bro.c)
