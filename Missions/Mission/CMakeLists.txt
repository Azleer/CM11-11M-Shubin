cmake_minimum_required(VERSION 3.5)
project(Mission)
project(Mission LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)




set(SOURCE_LIB mission.cpp program.cpp dive.cpp lift.cpp return.cpp move.cpp)
add_library(Mission STATIC ${SOURCE_LIB})


