#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

void print_vec(const std::vector<int> &mints) {
  for (auto &i : mints) {
    cout << i << " ";
  }
  cout << "\n";
}

void pigeonhole_sort(std::vector<int>::iterator begin,
                     std::vector<int>::iterator end) {
  auto min = std::min_element(begin, end);
  auto max = std::max_element(begin, end);

  std::vector<std::vector<int>> slots((*max) - (*min) + 1, std::vector<int>());

  for (auto itm = begin; itm != end; ++itm) {
    slots[*itm - *min].push_back(*itm);
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

  print_vec(mints);

  cout << "is_sorted: " << std::boolalpha
       << std::is_sorted(mints.begin(), mints.end()) << endl;

  return 0;
}
