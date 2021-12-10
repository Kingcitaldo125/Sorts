#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

using veciter = std::vector<int>::iterator;

void merge(veciter begin, veciter mid, veciter end)
{
	bool swap = true;
	while (swap)
	{
		swap = false;

		for (auto i = begin; i != mid - 1; ++i)
		{
			auto j = i + 1;
			for (auto k = mid; k != end - 1; ++k)
			{
				auto l = k + 1;

				if (*i > *j)
				{
					std::iter_swap(i,j);
					swap = true;
				}
				if (*k > *l)
				{
					std::iter_swap(k, l);
					swap = true;
				}
				if (*j > *k)
				{
					std::iter_swap(j, k);
					swap = true;
				}
			}
		}
	}
}

void merge_sort(veciter begin, veciter end)
{
	if (std::distance(begin, end) <= 1)
		return;

	auto mid_point = begin + (std::distance(begin, end) / 2);

	merge_sort(begin, mid_point - 1);
	merge_sort(mid_point, end);
	merge(begin, mid_point, end);
}

int main()
{
	std::vector<int> mints{ 63, 2, 8, 55, 11, 40, 97, 98, 16, 75, 93, 33, 66, 75, 93, 13, 26, 30, 65, 15, 31, 54, 58, 52, 72, 66, 30, 19, 72, 91, 72, 2, 36, 2, 33, 77, 58, 17, 47, 28, 74, 73, 49, 29, 61, 91, 49, 96, 18, 95, 14, 89, 13, 30, 87, 12, 75, 46, 5, 4, 63, 21, 78, 64, 7, 19, 47, 49, 68, 57, 30, 88, 26, 76, 57, 75, 89, 85, 59, 27, 19, 11, 99, 2, 91, 57, 21, 39, 73, 13, 47, 1, 48, 75, 38, 93, 57, 32, 16, 87 };

	merge_sort(mints.begin(), mints.end());

	for (auto& i : mints)
	{
		cout << i << " ";
	}
	cout << "\n";

	cout << (std::is_sorted(mints.begin(), mints.end()) ? "Sorted" : "UnSorted") << endl;

	return 0;
}
