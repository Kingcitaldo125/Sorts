#include <algorithm>
#include <iostream>
#include <vector>

#include "SortUtils.hpp"

void bead_sort(std::vector<int>::iterator begin,
               std::vector<int>::iterator end) {
  auto m_size = *std::max_element(begin, end);
  std::vector<int> mints(m_size, 0);

  for (auto j = begin; j != end; ++j) {
    auto num = *j;
    for (auto k = 0; k < num; ++k)
      ++mints.at(k);
  }

  std::vector<unsigned int> holder;
  for (auto j = begin; j != end; ++j) {
    unsigned int i = 0;
    std::for_each(mints.begin(), mints.end(), [&](auto &m) {
      if (m > 0)
        ++i;
      --m;
    });
    holder.push_back(i);
  }

  auto _ptr = begin;
  for (auto crevit = holder.crbegin(); crevit != holder.crend(); ++crevit) {
    *_ptr = *crevit;
    ++_ptr;
  }
}

int main() {
    std::vector<int> mints{ 72, 5,  65, 97, 48, 2,  50, 41, 62,
                           63, 44, 47, 28, 13, 27, 35, 42 };

    bead_sort(mints.begin(), mints.end());

    SortUtils::print_vector(mints);
    SortUtils::print_sorted<int>(mints.begin(), mints.end(), "mints");

    return 0;
}

