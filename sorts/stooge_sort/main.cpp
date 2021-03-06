#include <algorithm>
#include <iostream>
#include <vector>

#include "SortUtils.hpp"

void stooge_sort_base(std::vector<int> &vec, const unsigned int j,
                      const unsigned int i = 0) {
  if (vec.at(i) > vec.at(j))
    std::swap(vec.at(i), vec.at(j));

  const auto partition_val = (j - i + 1);
  if (partition_val > 2) {
    const auto t = partition_val / 3;
    stooge_sort_base(vec, j - t, i);
    stooge_sort_base(vec, j, i + t);
    stooge_sort_base(vec, j - t, i);
  }
}

inline void stooge_sort(std::vector<int> &vec) {
  stooge_sort_base(vec, static_cast<unsigned int>(vec.size() - 1));
}

int main() {
  std::vector<int> mints{98, 75, 68, 18, 40, 73, 28, 61, 98, 52, 7,  92, 5,
                         8,  60, 97, 66, 38, 53, 28, 97, 53, 91, 18, 85};

  stooge_sort(mints);

  SortUtils::print_vector(mints);
  SortUtils::print_sorted<int>(mints.begin(), mints.end(), "mints");

  return 0;
}
