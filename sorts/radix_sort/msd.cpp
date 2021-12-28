#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;

void print_vec(const std::vector<unsigned int> &mints) {
  for (const auto &i : mints) {
    cout << i << " ";
  }
  cout << "\n";
}

std::vector<unsigned int> radix_sort_msd(const std::vector<unsigned int> &mints,
                                         const int idx = 0) {
  std::array<std::vector<unsigned int>, 10> holder;
  std::vector<unsigned int> singles;

  if (mints.size() <= 1)
    return mints;

  if (std::all_of(mints.begin(), mints.end(),
                  [&](const auto &i) { return i == mints.at(0); }))
    return mints;

  std::size_t largest_size =
      std::to_string(*std::max_element(mints.begin(), mints.end())).size();

  for (const auto &m : mints) {
    auto mstr = std::to_string(m);
    auto mstr_size = mstr.size();

    if (mstr_size < largest_size) {
      singles.push_back(m);
      continue;
    }

    holder.at(std::stoi(std::string(1, mstr.at(idx)))).push_back(m);
  }

  singles = radix_sort_msd(singles, idx);

  for (auto &vector : holder) {
    if (vector.empty())
      continue;

    for (const auto &i : radix_sort_msd(vector, idx + 1))
      singles.push_back(i);
  }

  return singles;
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

  print_vec(mints);

  cout << "is_sorted: " << std::boolalpha
       << std::is_sorted(mints.begin(), mints.end()) << endl;

  return 0;
}
