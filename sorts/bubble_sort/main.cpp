#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

void print_vector(const std::vector<int>& mints) {
    for (const auto& v : mints) {
        cout << v << " ";
    }
    cout << '\n';
}

void bubble_sort(std::vector<int>::iterator begin,
    std::vector<int>::iterator end) {
    bool swap = true;
    unsigned long int passes = 0;

    while (swap) {
        swap = false;
        for (auto i = begin; i != end - (passes + 1); ++i) {
            const auto second = i + 1;
            if (*i > *second) {
                std::iter_swap(i, second);
                swap = true;
            }
        }
        ++passes;
    }
}

int main() {
    std::vector<int> mints{ 72, 5,  65, 97, 48, 2,  50, 41, 62,
                           63, 44, 47, 28, 13, 27, 35, 42 };

    bubble_sort(mints.begin(), mints.end());

    print_vector(mints);

    cout << "is_sorted: " << std::boolalpha
        << std::is_sorted(mints.begin(), mints.end()) << endl;

    return 0;
}
