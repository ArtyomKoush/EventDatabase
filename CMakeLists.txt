cmake_minimum_required(VERSION 3.10)
project(CourseProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(CourseProject main.cpp tests/test_runner.h token.h token.cpp condition_parser.h condition_parser.cpp tests/condition_parser_test.cpp database.h database.cpp node.cpp node.h date.cpp date.h tests/database_test.cpp tests/node_test.cpp tests/date_test.cpp)