cmake_minimum_required(VERSION 3.5)
project(MyList LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SOURCE_EXE main.cpp mylist.h)


add_executable(List ${SOURCE_EXE})

