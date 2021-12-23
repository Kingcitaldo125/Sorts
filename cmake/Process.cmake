macro(process)
  include(${CMAKE_SOURCE_DIR}/cmake/ProcessOptions.cmake)
  include(${CMAKE_SOURCE_DIR}/cmake/ProcessSubdirs.cmake)

  process_options()
  process_subdirs()
endmacro()

