macro(process_options)
  include(${PROJECT_SOURCE_DIR}/cmake/ProcessSortNames.cmake)

  process_sort_names()

  foreach(x ${sort_names})
    set(BuildStr "build_")
    string(APPEND BuildStr ${x})
    string(TOUPPER ${BuildStr} BuildStr)
    message(VERBOSE "processing option for ${x} - Option Name: ${BuildStr}")
    option(${BuildStr} "Build the ${x} subproject" OFF)
  endforeach()
endmacro()

