cmake_minimum_required(VERSION 3.16)

project(Sorts VERSION 0.14.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

option(BUILD_ALL "Build all of the sortation subprojects" ON)

add_subdirectory(sorts)
add_subdirectory(utils)
