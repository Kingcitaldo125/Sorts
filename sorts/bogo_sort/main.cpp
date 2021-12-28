#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

using std::cout;
using std::endl;

void print_vector(const std::vector<int> &mints) {
  for (const auto &v : mints) {
    cout << v << " ";
  }
  cout << '\n';
}

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

  print_vector(mints);

  cout << "is_sorted: " << std::boolalpha
       << std::is_sorted(mints.begin(), mints.end()) << endl;

  return 0;
}
