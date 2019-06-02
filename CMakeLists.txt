cmake_minimum_required(VERSION 2.8.9)

project(directory_test)

#Bring the headers, such as Student.h, into the project
include_directories(include)

enable_testing()

add_library(test_main OBJECT tests/test_main.cpp)

add_executable(test_Basic tests/test_Basic.cpp $<TARGET_OBJECTS:test_main>)
add_test(NAME test_Basic COMMAND test_Basic)

#The file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")

add_executable(tictactoe ${SOURCES})