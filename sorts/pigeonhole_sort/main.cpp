#include <algorithm>
#include <iostream>
#include <vector>

#include "SortUtils.hpp"

void pigeonhole_sort(std::vector<int>::iterator begin,
                     std::vector<int>::iterator end) {
  auto minmax = std::minmax_element(begin, end);

  std::vector<std::vector<int>> slots((*minmax.second) - (*minmax.first) + 1, std::vector<int>());

  for (auto itm = begin; itm != end; ++itm) {
    slots[*itm - *minmax.first].push_back(*itm);
  }

  auto &idx = begin;
  for (const auto &vec : slots) {
    for (const auto &v : vec) {
      *idx = v;
      ++idx;
    }
  }
}

int main() {
  std::vector<int> mints{57, 63, 86, 68, 50, 53, 28, 68, 41, 16, 74, 5,
                         12, 87, 97, 13, 67, 62, 79, 86, 6,  92, 4,  29,
                         73, 96, 90, 31, 42, 24, 60, 23, 79, 43, 79};

  pigeonhole_sort(mints.begin(), mints.end());

  SortUtils::print_vector(mints);
  SortUtils::print_sorted<int>(mints.begin(), mints.end(), "mints");

  return 0;
}
