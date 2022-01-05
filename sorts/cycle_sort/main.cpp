#include <algorithm>
#include <iostream>
#include <vector>

#include "SortUtils.hpp"

void cycle_sort(std::vector<int> &mints) {
  auto i = mints.begin();

  while (1) {
    auto scount = std::count_if(mints.begin(), mints.end(),
                                [&](const auto &itm) { return *i > itm; });

    if (std::distance(i, mints.begin() + scount) == 0) {
      if (i >= mints.end()) {
        break;
      } else {
        ++i;
        continue;
      }
    }

    auto displacement = mints.begin() + scount;
    std::iter_swap(i, displacement);
  }
}

int main() {
  std::vector<int> mints{11, 72, 89, 37, 59, 69, 12, 57, 27, 32};

  cycle_sort(mints);

  SortUtils::print_vector(mints);
  SortUtils::print_sorted<int>(mints.begin(), mints.end(), "mints");

  return 0;
}
