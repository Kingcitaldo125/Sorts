#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>

#include "SortUtils.hpp"

// Selection sort
inline void next_sort(std::vector<int> &vec) {
  const auto end = vec.end();
  for (auto i = vec.begin(); i != end; ++i) {
    std::iter_swap(i, std::min_element(i, end));
  }
}

template <size_t N_BUCKETS> void bucket_sort(std::vector<int> &arr) {
  std::array<std::vector<int>, N_BUCKETS> buckets;

  int MAX_KEY = 1;

  for (const auto &i : arr) {
    MAX_KEY = std::max(i, MAX_KEY);
  }
  ++MAX_KEY;

  for (unsigned i = 0; i < arr.size(); ++i) {
    const auto buck_idx = N_BUCKETS * arr.at(i) / MAX_KEY;
    buckets.at(buck_idx).emplace_back(arr.at(i));
  }

  arr.clear();
  for (auto &bucket : buckets) {
    next_sort(bucket);

    for (const auto &b : bucket)
      arr.push_back(b);
  }
}

int main() {
  std::vector<int> mints{32,  867, 661, 347, 91,  238, 739, 820, 20,  838,
                         796, 550, 803, 240, 327, 81,  896, 810, 151, 281,
                         886, 106, 660, 45,  787, 674, 20,  120, 437, 25,
                         930, 751, 3,   145, 674, 362, 809, 517, 418, 469,
                         689, 738, 623, 842, 643, 211, 308, 13,  792, 790};

  bucket_sort<5>(mints); // 5 buckets

  SortUtils::print_vector(mints);
  SortUtils::print_sorted<int>(mints.begin(), mints.end(), "mints");

  return 0;
}
