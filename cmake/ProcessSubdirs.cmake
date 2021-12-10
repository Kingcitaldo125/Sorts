macro(process_subdirs)
  list(LENGTH option_names len_options_names)
  list(LENGTH option_values len_options_values)

  math(EXPR range_length "${len_options_names} - 1")

  message(DEBUG "range_length: ${range_length}")

  foreach(x RANGE ${range_length})
    list(GET option_names ${x} build_option_name)
    list(GET option_values ${x} sort_name)

    math(EXPR y "${x} + 1")
    if(${y} EQUAL 1)
      message(DEBUG "${y}st sort:")
    elseif(${y} EQUAL 2)
      message(DEBUG "${y}nd sort:")
    elseif(${y} EQUAL 3)
      message(DEBUG "${y}rd sort:")
    else()
      message(DEBUG "${y}th sort:")
    endif()

    message(DEBUG "build_option_name: ${build_option_name}")
    message(DEBUG "sort_name: ${sort_name}")
    message(DEBUG "")
    if(BUILD_ALL)
      add_subdirectory(${sort_name})
    elseif(${build_option_name})
      add_subdirectory(${sort_name})
    endif()
  endforeach()

endmacro()
