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

void insertion_sort(std::vector<int>::iterator begin,
	std::vector<int>::iterator end) {
	// need at least 2 elements in vector to perform swaps
	if (std::distance(begin, end) <= 1)
		return;

	for (auto i = begin + 1; i != end; ++i) {
		auto first = i - 1;
		auto i_cpy = i;

		while (*i_cpy < *first) {
			std::iter_swap(i_cpy, first);

			if (first <= begin)
				break;

			--i_cpy;
			--first;
		}
	}
}

int main() {
  std::vector<int> mints{96,  65,  131, 67, 70, 72,  8,  13, 46, 144,
                         145, 114, 18,  20, 55, 119, 58, 91, 124};

  insertion_sort(mints.begin(), mints.end());

  SortUtils::print_vector(mints);
  SortUtils::print_sorted<int>(mints.begin(), mints.end(), "mints");

  return 0;
}
