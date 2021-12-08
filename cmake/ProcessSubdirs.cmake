macro(process_subdirs)
  if(BUILD_ALL)
    add_subdirectory(bogo_sort)
    add_subdirectory(bubble_sort)
    add_subdirectory(counting_sort)
    add_subdirectory(insertion_sort)
    add_subdirectory(radix_sort)
    add_subdirectory(selection_sort)
  elseif(BUILD_BOGO_SORT)
    add_subdirectory(bogo_sort)
  elseif(BUILD_BUBBLE_SORT)
    add_subdirectory(bubble_sort)
  elseif(BUILD_COUNTING_SORT)
    add_subdirectory(counting_sort)
  elseif(BUILD_INSERTION_SORT)
    add_subdirectory(insertion_sort)
  elseif(BUILD_RADIX_SORT)
    add_subdirectory(radix_sort)
  elseif(BUILD_SELECTION_SORT)
    add_subdirectory(selection_sort)
  endif()
endmacro()
