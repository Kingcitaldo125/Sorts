set(TARGET_NAME insertion)

add_executable(${TARGET_NAME} main.cpp)

target_link_libraries(${TARGET_NAME} PRIVATE sort_utils)

target_include_directories(${TARGET_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/utils)
