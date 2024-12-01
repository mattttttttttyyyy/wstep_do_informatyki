cmake_minimum_required(VERSION 3.29)
project(2)

set(CMAKE_CXX_STANDARD 14)

include_directories(kolejka_jedno_kierunkowa)

add_executable(2
    kolejka_jedno_kierunkowa/main.cpp
    kolejka_jedno_kierunkowa/main.h)
