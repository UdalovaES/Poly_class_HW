cmake_minimum_required(VERSION 3.23)
project(HW6_polygone)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(HW6_polygone
        main.cpp
        polynominal.cpp
        polynominal.h)
