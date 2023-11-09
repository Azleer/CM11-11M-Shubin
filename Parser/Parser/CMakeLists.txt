cmake_minimum_required(VERSION 3.5)
project(Parser)
project(Parser LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_LIB parser.cpp)
add_library(Parser STATIC ${SOURCE_LIB})


