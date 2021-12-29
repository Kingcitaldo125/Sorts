#include <algorithm>
#include <iostream>
#include <vector>

#include "SortUtils.hpp"

inline void flip(std::vector<int>::iterator begin, std::vector<int>::iterator iter) {
  std::reverse(begin, iter + 1);
}

inline void pancake_sort(std::vector<int>::iterator begin,
                  std::vector<int>::iterator end) {
  for (auto i = end; i != begin; --i) {
    flip(begin, std::max_element(begin, i));
    flip(begin, i - 1);
  }
}

int main() {
  std::vector<int> mints{41, 8,  17, 33, 5,  23, 37, 10, 23, 12, 9,  9,  26,
                         14, 49, 17, 48, 24, 42, 38, 6,  10, 30, 33, 44, 31,
                         36, 15, 23, 12, 6,  31, 36, 28, 42, 40, 4,  1,  40,
                         28, 40, 3,  40, 4,  37, 40, 10, 36, 17, 11};

  pancake_sort(mints.begin(), mints.end());

  SortUtils::print_vector(mints);
  SortUtils::print_sorted<int>(mints.begin(), mints.end(), "mints");

  return 0;
}
