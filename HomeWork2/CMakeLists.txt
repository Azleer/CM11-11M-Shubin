cmake_minimum_required(VERSION 3.5)
project(HomeWork2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SOURCE_EXE main.cpp)

include_directories(MyVector)
add_executable(HomeWork2 ${SOURCE_EXE})

add_subdirectory(MyVector)

target_link_libraries(HomeWork2 MyVector)
