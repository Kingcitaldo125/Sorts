set(SORT_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(SORT_BIN_DIR "${CMAKE_BINARY_DIR}/sorts")

message(DEBUG "SORT_SRC_DIR ${SORT_SRC_DIR}")
message(DEBUG "SORT_BIN_DIR ${SORT_BIN_DIR}")

# Other options are in the form "BUILD_<sort_name_uppercase>"
# where the "<sort_name_uppercase>" is the name of the sort's parent folder/directory, uppercase.
# e.g. Selection Sort will be "BUILD_SELECTION_SORT" where it's folder is named "selection_sort"
include(${CMAKE_SOURCE_DIR}/cmake/Process.cmake)
process()

