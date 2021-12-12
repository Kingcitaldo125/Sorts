#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;

void print_vec(const std::vector<int>& mints)
{
	for (auto& i : mints)
	{
		cout << i << " ";
	}
	cout << "\n";
}

int partition(std::vector<int>& mvec, const int low, const int high)
{
	auto nleft_idx = low;
	auto nright_idx = high;

	auto pivot = mvec.at((high + low) / 2);

	while (nleft_idx <= nright_idx)
	{
		while (auto nleft = mvec.at(nleft_idx) < pivot)
		{
			++nleft_idx;
		}
		while (auto nright = mvec.at(nright_idx) > pivot)
		{
			--nright_idx;
		}

		auto& nleft = mvec.at(nleft_idx);
		auto& nright = mvec.at(nright_idx);

		if (nleft_idx <= nright_idx)
		{
			std::swap(nleft, nright);
			++nleft_idx;
			--nright_idx;
		}
	}

	return nleft_idx;
}

void quick_sort_driver(std::vector<int>& mints, const int low, const int high)
{
	if (low >= high)
	{
		return;
	}

	const int idx = partition(mints, low, high);
	
	quick_sort_driver(mints, low, idx - 1);
	quick_sort_driver(mints, idx, high);
}

void quick_sort(std::vector<int>& mints)
{
	quick_sort_driver(mints, 0, mints.size() - 1);
}

int main()
{
	std::vector<int> mints{ 63, 80, 25, 32, 41, 23, 80, 99, 94, 40, 62, 70, 36, 26, 4, 86, 60, 52, 69, 61, 25, 57, 96, 4, 25, 77, 57, 72, 17, 25, 64, 93, 95, 94, 81 };

	quick_sort(mints);

	print_vec(mints);

	cout << "is_sorted: " << std::boolalpha << std::is_sorted(mints.begin(), mints.end()) << "\n";

	return 0;
}
