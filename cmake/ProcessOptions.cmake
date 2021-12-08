macro(process_sort_names)
  file(GLOB file_listing LIST_DIRECTORIES true RELATIVE ${PROJECT_SOURCE_DIR} *sort/)

  set(sort_names "")

  foreach(x ${file_listing})
    list(APPEND sort_names ${x})
    message(DEBUG "Processing directory ${x}")
  endforeach()
endmacro()

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

