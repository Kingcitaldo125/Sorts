#include <algorithm>
#include <iostream>
#include <vector>

#include "SortUtils.hpp"

using std::cout;
using std::endl;

void print_vec(const std::vector<int> &mints) {
  for (const auto &i : mints) {
    cout << i << " ";
  }
  cout << "\n";
}

// Uses the Hoare partition scheme
// https://en.wikipedia.org/wiki/Quicksort#Hoare_partition_scheme
// Received the range condition checks from
// https://www.youtube.com/watch?v=SLauY6PpjW4&ab_channel=HackerRank
unsigned int partition(std::vector<int> &mvec, const int low, const int high) {
  auto nleft_idx = low;
  auto nright_idx = high;

  const auto pivot = mvec.at((high + low) / 2);

  while (nleft_idx <= nright_idx) {
    while (mvec.at(nleft_idx) < pivot) {
      ++nleft_idx;
    }
    while (mvec.at(nright_idx) > pivot) {
      --nright_idx;
    }

    auto &nleft = mvec.at(nleft_idx);
    auto &nright = mvec.at(nright_idx);

    if (nleft_idx <= nright_idx) {
      std::swap(nleft, nright);
      ++nleft_idx;
      --nright_idx;
    }
  }

  return nleft_idx;
}

// std::vector<T>::iterator does not work for two reasons:
// 1. Passing in *begin() and *end() gets the whole range of elements, but
// dereffing *end is UB. Only way to avoid this flavor of UB is:
// 2. Trying to fix 1. by passing in *begin() and *end()-1; this accounts for
// all items except the last one, which throws off the algorithm's efficacy
// Indexing the vector (retrieving elements @ two indices) is really the only
// way to go
void quick_sort_driver(std::vector<int> &mints, const int low, const int high) {
  if (low >= high)
    return;

  const unsigned int idx = partition(mints, low, high);

  quick_sort_driver(mints, low, idx - 1);
  quick_sort_driver(mints, idx, high);
}

// Use wrapper function to truncate to just indices that map to an actual item
// Avoids walking off the end and dereferencing an area of memory that's not
// ours
void quick_sort(std::vector<int> &mints) {
  quick_sort_driver(mints, 0, mints.size() - 1);
}

int main() {
  std::vector<int> mints{63, 80, 25, 32, 41, 23, 80, 99, 94, 40, 62, 70,
                         36, 26, 4,  86, 60, 52, 69, 61, 25, 57, 96, 4,
                         25, 77, 57, 72, 17, 25, 64, 93, 95, 94, 81};

  quick_sort(mints);

  SortUtils::print_vector(mints);
  SortUtils::print_sorted<int>(mints.begin(), mints.end(), "mints");

  return 0;
}
