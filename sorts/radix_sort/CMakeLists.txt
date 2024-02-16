set(TARGET_NAME_LSD lsd)
set(TARGET_NAME_MSD msd)
set(TARGET_NAME_MSD2 msd2)

add_executable(${TARGET_NAME_LSD} lsd.cpp)
add_executable(${TARGET_NAME_MSD} msd.cpp)
add_executable(${TARGET_NAME_MSD2} msd2.cpp)

target_link_libraries(${TARGET_NAME_LSD} PRIVATE sort_utils)
target_link_libraries(${TARGET_NAME_MSD} PRIVATE sort_utils)
target_link_libraries(${TARGET_NAME_MSD2} PRIVATE sort_utils)

target_include_directories(${TARGET_NAME_LSD} PRIVATE ${CMAKE_SOURCE_DIR}/utils)
target_include_directories(${TARGET_NAME_MSD} PRIVATE ${CMAKE_SOURCE_DIR}/utils)
target_include_directories(${TARGET_NAME_MSD2} PRIVATE ${CMAKE_SOURCE_DIR}/utils)
