#include <algorithm>
#include <iostream>
#include <vector>

void stalin_sort(std::vector<int>& mints)
{
    while(!std::is_sorted(mints.begin(), mints.end()))
    {
        std::vector<int> holder;
        for(auto it = mints.begin(); it < mints.end() - 1; ++it)
        {
            auto second = it + 1;
            if (*it > *second)
                continue;
            holder.push_back(*it);
        }
        mints = std::move(holder);
    }
}

int main() {
  std::vector<int> mints{63, 80, 25, 32, 41, 23, 80, 99, 94, 40, 62, 70,
                         36, 26, 4,  86, 60, 52, 69, 61, 25, 57, 96, 4,
                         25, 77, 57, 72, 17, 25, 64, 93, 95, 94, 81};

  stalin_sort(mints);

  SortUtils::print_vector(mints);
  SortUtils::print_sorted<int>(mints.begin(), mints.end(), "mints");

  return 0;
}