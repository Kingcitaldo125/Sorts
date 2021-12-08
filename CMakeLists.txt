cmake_minimum_required(VERSION 3.16)

project(Sorts VERSION 0.0.0 LANGUAGES CXX)

option(BUILD_ALL "Build all of the sortation subprojects" ON)

include(${PROJECT_SOURCE_DIR}/cmake/ProcessOptions.cmake)
include(${PROJECT_SOURCE_DIR}/cmake/ProcessSubdirs.cmake)

process_subdirs()
process_options()
