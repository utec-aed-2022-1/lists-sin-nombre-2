cmake_minimum_required(VERSION 3.21)
project(lists_sin_nombre_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lists_sin_nombre_2
        circular.h
        double.h
        forward.h
        list.h
        main.cpp
        node.h
        tester.h)
