#include <algorithm>
#include <iostream>
#include <vector>

#include "SortUtils.hpp"

void comb_sort(std::vector<int>::iterator begin,
               std::vector<int>::iterator end) {
  const auto shrink_factor = 1.3;
  const auto size = std::distance(begin, end);
  auto gap = size - 1;

  while (1) {
    for (auto i = begin + gap; i < begin + size; ++i) {
      const auto second = i - gap;
      if (*second > *i) {
        std::iter_swap(i, second);
      }
    }

    gap = gap / shrink_factor;

    if (gap < 1)
      break;
  }
}

int main() {
  std::vector<int> mints{72, 5,  65, 97, 48, 2,  50, 41, 62,
                         63, 44, 47, 28, 13, 27, 35, 42};

  comb_sort(mints.begin(), mints.end());

  SortUtils::print_vector(mints);
  SortUtils::print_sorted<int>(mints.begin(), mints.end(), "mints");

  return 0;
}
