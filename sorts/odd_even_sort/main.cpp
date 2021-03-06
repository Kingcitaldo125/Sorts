#include <algorithm>
#include <iostream>
#include <vector>

#include "SortUtils.hpp"

void odd_even_sort(std::vector<int>::iterator begin,
                   std::vector<int>::iterator end) {
  bool swap = true;
  while (swap) {
    swap = false;
    for (auto i = begin; i < end - 1; i += 2) {
      const auto second = i + 1;
      if (*i > *second) {
        std::iter_swap(i, second);
        swap = true;
      }
    }

    for (auto i = begin + 1; i < end - 1; i += 2) {
      const auto second = i + 1;
      if (*i > *second) {
        std::iter_swap(i, second);
        swap = true;
      }
    }
  }
}

int main() {
  std::vector<int> mints{10, 67, 44, 48, 23, 5,  18, 24, 53, 48, 17, 47, 67,
                         37, 83, 77, 57, 2,  49, 92, 27, 28, 67, 98, 90, 26,
                         99, 32, 3,  57, 40, 98, 97, 38, 81, 11, 3,  85, 61,
                         10, 17, 11, 70, 1,  58, 10, 36, 76, 66, 35};

  odd_even_sort(mints.begin(), mints.end());

  SortUtils::print_vector(mints);
  SortUtils::print_sorted<int>(mints.begin(), mints.end(), "mints");

  return 0;
}
