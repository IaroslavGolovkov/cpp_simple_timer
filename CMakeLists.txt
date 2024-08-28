cmake_minimum_required(VERSION 3.5)

project(simple_timer_example
    VERSION 0.0.1
    DESCRIPTION "Simple timer written in C++"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(simple_timer_example
    example.cpp
    timer.h
)
