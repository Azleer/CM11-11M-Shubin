cmake_minimum_required(VERSION 3.5)
project(List LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SOURCE_EXE main.cpp)

include_directories(MyList)
add_executable(List ${SOURCE_EXE})

add_subdirectory(MyList)

target_link_libraries(List MyList)
