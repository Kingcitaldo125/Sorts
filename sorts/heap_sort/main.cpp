#include <algorithm>
#include <iostream>
#include <vector>

#include "SortUtils.hpp"

void heapify(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
  const auto minmax = std::minmax_element(begin, end);

  if (*begin != *minmax.first)
    std::iter_swap(begin, minmax.first);

  if (*minmax.second != *(end - 1))
    std::iter_swap(minmax.second, end - 1);
}

// OPTIMIZE:
// Replace selection sort functionality with functionality
// that checks each parent node against its children
// (check parent value to ensure it's larger than its children's values)
void build_max_heap(std::vector<int>::iterator begin,
                    std::vector<int>::iterator end) {
  if (std::distance(begin, end) == 1)
    return;

  const auto itm = std::max_element(begin, end);
  if (*begin != *itm)
    std::iter_swap(begin, itm);

  build_max_heap(begin + 1, end);

  std::iter_swap(begin, end - 1);
}

void heap_sort(std::vector<int>::iterator begin,
               std::vector<int>::iterator end) {
  if (std::distance(begin, end) == 1)
    return;

  build_max_heap(begin, end);
  heapify(begin, end);
  heap_sort(begin, end - 1);
}

int main() {
  std::vector<int> mints{812, 144, 272, 835, 911, 934, 482, 948, 384, 648,
                         349, 67,  301, 211, 146, 989, 871, 34,  556, 765,
                         458, 397, 473, 140, 367, 198, 149, 584, 123, 256};

  heap_sort(mints.begin(), mints.end());

  SortUtils::print_vector(mints);
  SortUtils::print_sorted<int>(mints.begin(), mints.end(), "mints");

  return 0;
}
