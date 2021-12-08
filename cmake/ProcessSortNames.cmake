macro(process_sort_names)
  file(GLOB file_listing LIST_DIRECTORIES true RELATIVE ${PROJECT_SOURCE_DIR} *sort/)

  set(sort_names "")

  foreach(x ${file_listing})
    list(APPEND sort_names ${x})
  endforeach()
endmacro()

