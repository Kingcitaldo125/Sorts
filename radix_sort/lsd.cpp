#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;

std::vector<int> radix_sort_lsd(const std::vector<int>& vecc)
{
	std::array<std::vector<int>, 10> marray;
	std::vector<int> mints(vecc.begin(), vecc.end());

	marray.fill(std::vector<int>());

	int i = 0;
	bool processed = true;
	while (processed)
	{
		processed = false;
		for (auto& j : mints)
		{
			auto j_str = std::to_string(j);
			int size = static_cast<int>(j_str.size());
			auto idx = size - (i + 1);

			if (idx < 0)
			{
				marray.at(0).push_back(j);
				continue;
			}

			processed = true;
			auto char_int = std::stoi(std::string(1, j_str.at(idx)));
			marray.at(char_int).push_back(j);
		}

		if (!processed)
			break;

		mints.clear();

		for (auto& vec : marray)
		{
			for (auto& v : vec)
				mints.push_back(v);
		}

		for (auto& vec : marray)
		{
			vec.clear();
		}

		++i;
	}

	return mints;
}

int main()
{
	std::vector<int> mints{ 684, 126, 635, 1051, 491, 712, 676, 733, 833, 418, 133, 113, 1324, 571, 604, 958, 1455, 455, 109, 1141, 624, 797, 1204, 1401, 470, 534, 1172, 87, 919, 758, 1082, 1361, 197, 1353, 1498, 1206, 450, 711, 1121, 251, 1194, 515, 1449, 892, 597, 441, 303, 1038, 739, 241, 135, 1358, 255, 302, 332, 174, 1409, 651, 57, 38, 464, 402, 728, 1129, 1476, 475, 452, 161, 1188, 750, 1389, 899, 360, 792, 332, 1198, 923, 217, 1075, 500, 1424, 1034, 1103, 1207, 447, 1281, 408, 500, 549, 879, 1014, 1203, 951, 687, 311, 183, 551, 614, 3, 500 };

	mints = radix_sort_lsd(mints);

	for (auto& v : mints)
	{
		cout << v << " ";
	}
	cout << '\n';

	cout << mints.size() << " items\n";
	cout << "is_sorted: " << std::boolalpha << std::is_sorted(mints.begin(), mints.end()) << endl;

	return 0;
}
