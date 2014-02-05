cmake_minimum_required(VERSION 2.8)

SET(CXX clang++)

project(lllld CXX)

INCLUDE_DIRECTORIES(include/)

add_executable(main main.cpp)
