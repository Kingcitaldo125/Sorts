#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

#include "SortUtils.hpp"

using std::cout;
using std::endl;

unsigned long bogo_sort(std::vector<int>::iterator begin,
                        std::vector<int>::iterator end) {
  unsigned long i = 0;
  std::mt19937 twister(
      std::chrono::high_resolution_clock::now().time_since_epoch().count());

  while (1) {
    if (std::is_sorted(begin, end))
      break;
    std::random_shuffle(begin, end, [&](const int j) { return twister() % j; });
    ++i;
  }

  return i;
}

int main() {
  std::vector<int> mints{72, 5, 65, 97, 48};

  cout << "Took '" << bogo_sort(mints.begin(), mints.end()) << "' iterations\n";

  SortUtils::print_vector(mints);
  SortUtils::print_sorted<int>(mints.begin(), mints.end(), "mints");

  return 0;
}
