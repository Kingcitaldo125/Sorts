cmake_minimum_required(VERSION 3.16)

project(Sorts VERSION 0.0.0 LANGUAGES CXX)

option(BUILD_ALL "Build all of the sortation subprojects" ON)

# Other options are in the form "BUILD_<sort_name_uppercase>"
# where the "<sort_name_uppercase>" is the name of the sort's parent folder/directory, uppercase.
# e.g. Selection Sort will be "BUILD_SELECTION_SORT" where it's folder is named "selection_sort"

include(${PROJECT_SOURCE_DIR}/cmake/ProcessOptions.cmake)
include(${PROJECT_SOURCE_DIR}/cmake/ProcessSubdirs.cmake)

process_options()
process_subdirs()
