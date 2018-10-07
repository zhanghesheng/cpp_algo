cmake_minimum_required(VERSION 3.7)
project(Excemple)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp vtable.hpp thpool.c thpool.h mlist.hpp)
add_executable(Excemple ${SOURCE_FILES})