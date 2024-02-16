#include <algorithm>
#include <iostream>
#include <vector>

#include "SortUtils.hpp"

inline void print_row(const std::vector<int> &row) {
  if (row.size() == 0)
    return;

  for (const auto &r : row) {
    std::cout << r << " ";
  }

  std::cout << "\n";
}

void print_buckets(const std::vector<std::vector<int>> &buckets) {
  for (const auto &row : buckets) {
    print_row(row);
  }
}

inline int calc_digit(const int digit, const int digit_idx,
                      const int longest_digits) {
  const int sint = static_cast<int>(std::to_string(digit).size());
  return (digit_idx + sint) - longest_digits;
}

std::vector<int> msd_rec(std::vector<int> mints, const int digit_idx,
                         const int longest_digits) {
  if (mints.size() <= 1 || digit_idx >= longest_digits) {
    return mints;
  }

  std::vector<std::vector<int>> buckets(10, std::vector<int>());
  for (const auto &m : mints) {
    const auto m_str = std::to_string(m);
    const auto calc_digit_idx = calc_digit(m, digit_idx, longest_digits);

    if (calc_digit_idx < 0) {
      buckets.at(0).push_back(m);
      continue;
    }

    buckets.at(std::stoi(std::string(1, m_str.at(calc_digit_idx))))
        .push_back(m);
  }

  mints.clear();

  int row_ctr = 0;
  std::vector<std::vector<int>> xbuckets(10, std::vector<int>());
  for (const auto &row : buckets) {
    auto xres = msd_rec(row, digit_idx + 1, longest_digits);

    for (const auto &x : xres) {
      xbuckets.at(row_ctr).push_back(x);
    }

    ++row_ctr;
  }

  for (const auto &xrow : xbuckets) {
    for (const auto &x : xrow) {
      mints.push_back(x);
    }
  }

  return mints;
}

std::vector<int> radix_sort_msd(std::vector<int> mints) {
  if (mints.size() <= 1)
    return mints;

  const auto longest_digits =
      std::to_string(*std::max_element(mints.begin(), mints.end())).size();

  return msd_rec(mints, 0, static_cast<int>(longest_digits));
}

int main() {
  std::vector<unsigned int> mints{
      684,  126,  635,  1051, 491,  712, 676,  733,  833,  418,  133,  113,
      1324, 571,  604,  958,  1455, 455, 109,  1141, 624,  797,  1204, 1401,
      470,  534,  1172, 87,   919,  758, 1082, 1361, 197,  1353, 1498, 1206,
      450,  711,  1121, 251,  1194, 515, 1449, 892,  597,  441,  303,  1038,
      739,  241,  135,  1358, 255,  302, 332,  174,  1409, 651,  57,   38,
      464,  402,  728,  1129, 1476, 475, 452,  161,  1188, 750,  1389, 899,
      360,  792,  332,  1198, 923,  217, 1075, 500,  1424, 1034, 1103, 1207,
      447,  1281, 408,  500,  549,  879, 1014, 1203, 951,  687,  311,  183,
      551,  614,  3,    500};

  mints = radix_sort_msd(mints);

  SortUtils::print_vector(mints);
  SortUtils::print_sorted<unsigned int>(mints.begin(), mints.end(), "mints");

  return 0;
}
