cmake_minimum_required(VERSION 3.28)
project(dumake)

set(CMAKE_CXX_STANDARD 20)

include_directories(src include)

add_executable(dumake
        main.cpp
        include/parser.h
        src/parser.cpp
        include/target.h
        src/target.cpp
        include/executor.h
        src/executor.cpp
)
