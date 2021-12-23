#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;

void heapify(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
  auto min = std::min_element(begin, end);

  if (*begin != *min)
    std::iter_swap(begin, min);

  auto max = std::max_element(begin, end);

  if (*max != *(end - 1))
    std::iter_swap(max, end - 1);
}

void build_max_heap(std::vector<int>::iterator begin,
                    std::vector<int>::iterator end) {
  if (std::distance(begin, end) == 1)
    return;

  auto itm = std::max_element(begin, end);
  if (*begin != *itm)
    std::iter_swap(begin, itm);

  build_max_heap(begin + 1, end);

  std::iter_swap(begin, end - 1);
}

void heap_sort(std::vector<int>::iterator begin,
               std::vector<int>::iterator end) {
  if (std::distance(begin, end) == 1)
    return;

  build_max_heap(begin, end);
  heapify(begin, end);
  heap_sort(begin, end - 1);
}

int main() {
  std::vector<int> mints{812, 144, 272, 835, 911, 934, 482, 948, 384, 648,
                         349, 67,  301, 211, 146, 989, 871, 34,  556, 765,
                         458, 397, 473, 140, 367, 198, 149, 584, 123, 256};

  heap_sort(mints.begin(), mints.end());

  for (auto &i : mints) {
    cout << i << " ";
  }
  cout << "\n";

  cout << "is_sorted: "
       << (std::is_sorted(mints.begin(), mints.end()) ? "Sorted" : "UnSorted")
       << std::endl;

  return 0;
}
