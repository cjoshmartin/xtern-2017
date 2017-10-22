cmake_minimum_required(VERSION 3.8)
project(netxtern)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Array.cpp
        Array.h
        BaseArray.cpp
        BaseArray.h
        main.cpp
        Makefile
        Queue.cpp
        Queue.h
        Stack.cpp
        Stack.h)

add_executable(netxtern ${SOURCE_FILES})