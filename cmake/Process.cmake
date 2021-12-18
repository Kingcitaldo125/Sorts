macro(process)
  include(${PROJECT_SOURCE_DIR}/cmake/ProcessOptions.cmake)
  include(${PROJECT_SOURCE_DIR}/cmake/ProcessSubdirs.cmake)

  process_options()
  process_subdirs()
endmacro()
