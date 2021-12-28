#include <algorithm>
#include <iostream>

#include "SortUtils.hpp"

template <typename T>
inline void SortUtils::print_vector(const std::vector<T> &mints) {
  for (const auto &v : mints) {
    std::cout << v << " ";
  }

  if (mints.size() > 0)
    std::cout << '\n';
}

template <typename T>
inline bool SortUtils::print_sorted(typename std::vector<T>::iterator begin,
                             typename std::vector<T>::iterator end,
                             const std::string &name) {
  auto res = std::is_sorted(begin, end);

  if (name.size() > 0)
    std::cout << name << " sorted: " << std::boolalpha << res << "\n";
  else
    std::cout << std::boolalpha << res << "\n";

  return res;
}

template void SortUtils::print_vector<int>(const std::vector<int> &mints);

template bool SortUtils::print_sorted<int>(typename std::vector<int>::iterator begin,
                             typename std::vector<int>::iterator end,
                             const std::string &name);

template void SortUtils::print_vector<unsigned int>(const std::vector<unsigned int> &mints);

template bool SortUtils::print_sorted<unsigned int>(typename std::vector<unsigned int>::iterator begin,
                             typename std::vector<unsigned int>::iterator end,
                             const std::string &name);
