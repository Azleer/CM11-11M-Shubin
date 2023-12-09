cmake_minimum_required(VERSION 3.5)
project(HomeWork1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SOURCE_EXE main.cpp)

include_directories(Parser)
add_executable(HomeWork1 ${SOURCE_EXE})

add_subdirectory(Parser)

target_link_libraries(HomeWork1 Parser)