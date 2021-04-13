cmake_minimum_required(VERSION 3.17)
project(project)

set(CMAKE_CXX_STANDARD 11)

add_executable(part_a lex.yy.c part_a.cpp)
add_executable(part_b lex.yy.c part_b.cpp)
