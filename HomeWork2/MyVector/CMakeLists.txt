cmake_minimum_required(VERSION 3.5)
project(MyVector)
project(MyVector LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_LIB myvector.cpp)
add_library(MyVector STATIC ${SOURCE_LIB})


