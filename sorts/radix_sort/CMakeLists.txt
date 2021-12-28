set(TARGET_NAME_LSD lsd)
set(TARGET_NAME_MSD msd)

add_executable(${TARGET_NAME_LSD} lsd.cpp)
add_executable(${TARGET_NAME_MSD} msd.cpp)

target_link_libraries(${TARGET_NAME_LSD} PRIVATE sort_utils)
target_link_libraries(${TARGET_NAME_MSD} PRIVATE sort_utils)

target_include_directories(${TARGET_NAME_LSD} PRIVATE ${CMAKE_SOURCE_DIR}/utils)
target_include_directories(${TARGET_NAME_MSD} PRIVATE ${CMAKE_SOURCE_DIR}/utils)
