#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

using siter = std::vector<int>::iterator;

void print_vector(const std::vector<int> &mints) {
  for (auto &v : mints) {
    cout << v << " ";
  }
  cout << '\n';
}

void cocktail_shaker_sort(siter begin, siter end) {
  auto head = begin;
  auto tail = end;
  unsigned int passes = 0;
  bool swap = true;
  while (swap) {
    swap = false;
    for (auto i = head; i != tail - (passes + 1); ++i) {
      auto second = i + 1;
      if (*i > *second) {
        std::iter_swap(i, second);
        swap = true;
      }
    }

    for (auto i = tail - (passes + 2); i != head; --i) {
      auto second = i - 1;
      if (*i < *second) {
        std::iter_swap(i, second);
        swap = true;
      }
    }

    ++head;
    ++passes;
  }
}

int main() {
  std::vector<int> mints{72, 50, 65, 97, 48, 2,  5,  41, 62,
                         63, 44, 47, 28, 13, 27, 35, 42};

  cocktail_shaker_sort(mints.begin(), mints.end());

  print_vector(mints);

  cout << "is_sorted: " << std::boolalpha
       << std::is_sorted(mints.begin(), mints.end()) << endl;

  return 0;
}
