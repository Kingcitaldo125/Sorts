#include <algorithm>
#include <iostream>
#include <vector>

#include "SortUtils.hpp"

void d_sort(std::vector<int>::iterator begin, std::vector<int>::iterator end,
            const unsigned int gap) {
  // need at least 2 elements in vector to perform swaps
  if (std::distance(begin, end) == 1)
    return;

  for (auto i = begin; i != end - gap; ++i) {
    auto nxt = i + gap;

    while (*i > *nxt && i >= begin) {
      std::iter_swap(i, nxt);
      --i;
      --nxt;
    }
  }
}

void shell_sort(std::vector<int>::iterator begin,
                std::vector<int>::iterator end) {
  auto gap = std::distance(begin, end) / 2;

  while (gap > 0) {
    d_sort(begin, end, gap);
    gap = gap / 2;
  }

  d_sort(begin, end, 0);
}

int main() {
  std::vector<int> mints{98, 46, 7,  52, 99, 86, 67, 40, 49, 92,
                         8,  36, 82, 50, 95, 37, 82, 61, 52, 41};

  shell_sort(mints.begin(), mints.end());

  SortUtils::print_vector(mints);
  SortUtils::print_sorted<int>(mints.begin(), mints.end(), "mints");

  return 0;
}
