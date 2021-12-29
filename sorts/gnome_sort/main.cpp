#include <algorithm>
#include <iostream>
#include <vector>

#include "SortUtils.hpp"

void gnome_sort(std::vector<int>::iterator begin,
                std::vector<int>::iterator end) {
  auto i = begin + 1;
  while (1) {
    if (std::distance(i, end) < 1)
      break;

    if (*(i - 1) <= *i) {
      ++i;
      continue;
    } else {
      std::iter_swap(i - 1, i);
      --i;
      if (std::distance(begin, i) == 0)
        i = begin + 1;
    }
  }
}

int main() {
  std::vector<int> mints{65, 28, 60, 73, 44, 84, 91, 5,  63, 8,  82, 46, 9,
                         97, 42, 7,  51, 18, 68, 84, 70, 64, 53, 52, 50};

  gnome_sort(mints.begin(), mints.end());

  SortUtils::print_vector(mints);
  SortUtils::print_sorted<int>(mints.begin(), mints.end(), "mints");

  return 0;
}
