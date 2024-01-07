cmake_minimum_required(VERSION 3.27)
project(LinAlgCPP)

set(CMAKE_CXX_STANDARD 17)

include_directories(classes)
include_directories(files)

add_executable(LinAlgCPP
        classes/ComplexNumber.cpp
        classes/Matrix.cpp
        classes/Matrix.h
        classes/Vector.cpp
        classes/Vector.h
        classes/VectorEquation.h
        classes/VectorEquation.cpp
        files/input.txt
        main.cpp
        classes/ComplexNumber.h)
