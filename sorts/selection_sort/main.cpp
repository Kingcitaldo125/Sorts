#include <algorithm>
#include <iostream>
#include <vector>

#include "SortUtils.hpp"

using std::cout;
using std::endl;

void print_vector(const std::vector<int> &mints) {
  for (const auto &v : mints) {
    cout << v << " ";
  }
  cout << '\n';
}

inline void selection_sort(std::vector<int>::iterator begin,
                           std::vector<int>::iterator end) {
  for (auto i = begin; i != end; ++i) {
    std::iter_swap(i, std::min_element(i, end));
  }
}

int main() {
  std::vector<int> mints{23, 4,  20, 91, 2,  50, 63,  55, 52, 80, 34,
                         81, 56, 70, 42, 95, 49, 100, 85, 31, 17, 82,
                         41, 58, 54, 16, 11, 22, 10,  9,  7,  97, 75,
                         59, 92, 69, 46, 8,  76, 29,  68, 67, 27, 25,
                         45, 28, 98, 35, 36, 78, 21,  57, 37, 51, 74};

  selection_sort(mints.begin(), mints.end());

  SortUtils::print_vector(mints);
  SortUtils::print_sorted<int>(mints.begin(), mints.end(), "mints");

  return 0;
}
