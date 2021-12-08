cmake_minimum_required(VERSION 3.16)

project(Sorts VERSION 0.0.0 LANGUAGES CXX)

option(BUILD_ALL "Build all of the sortation subprojects" ON)

option(BUILD_BOGO_SORT "Build the BOGO_Sort subprojects" OFF)
option(BUILD_BUBBLE_SORT "Build the Bubble_Sort subprojects" OFF)
option(BUILD_COUNTING_SORT "Build the Counting_Sort subprojects" OFF)
option(BUILD_INSERTION_SORT "Build the Insertion_Sort subprojects" OFF)
option(BUILD_RADIX_SORT "Build the Radix_Sort subprojects" OFF)
option(BUILD_SELECTION_SORT "Build the Selection_Sort subprojects" OFF)

include(${PROJECT_SOURCE_DIR}/cmake/ProcessSubdirs.cmake)

