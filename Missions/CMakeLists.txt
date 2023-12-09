cmake_minimum_required(VERSION 3.5)
project(HomeWork3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SOURCE_EXE main.cpp)

include_directories(Mission)
add_executable(HomeWork3 ${SOURCE_EXE})

add_subdirectory(Mission)

target_link_libraries(HomeWork3 Mission)
