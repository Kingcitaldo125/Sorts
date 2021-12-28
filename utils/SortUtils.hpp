#pragma once

#include <string>
#include <vector>

class SortUtils {
public:
  SortUtils() {}
  virtual ~SortUtils() {}

  template <typename T> static void print_vector(const std::vector<T> &mints);

  template <typename T>
  static bool print_sorted(typename std::vector<T>::iterator begin,
                           typename std::vector<T>::iterator end,
                           const std::string &name = "");
};
