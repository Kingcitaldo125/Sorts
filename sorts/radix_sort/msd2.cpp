#include <algorithm>
#include <iostream>
#include <vector>

inline void print_row(const std::vector<int>& row)
{
    if (row.size() == 0) return;

    for(const auto& r : row)
    {
        std::cout << r << " ";
    }

    std::cout << "\n";
}

void print_buckets(const std::vector<std::vector<int>>& buckets)
{
    for(const auto& row : buckets)
    {
        print_row(row);
    }
}

inline int calc_digit(const int digit, const int digit_idx, const int longest_digits)
{
    const int sint = static_cast<int>(std::to_string(digit).size());
    return (digit_idx + sint) - longest_digits;
}

std::vector<int> msd_rec(std::vector<int> mints, const int digit_idx, const int longest_digits)
{
    if (mints.size() <= 1 || digit_idx >= longest_digits)
    {
        return mints;
    }

    std::vector<std::vector<int>> buckets(10, std::vector<int>());
    for(const auto& m : mints)
    {
        const auto m_str = std::to_string(m);
        const auto calc_digit_idx = calc_digit(m, digit_idx, longest_digits);

        if (calc_digit_idx < 0)
        {
            buckets.at(0).push_back(m);
            continue;
        }

        buckets.at(std::stoi(std::string(1, m_str.at(calc_digit_idx)))).push_back(m);
    }

    mints.clear();

    int row_ctr = 0;
    std::vector<std::vector<int>> xbuckets(10, std::vector<int>());
    for(const auto& row : buckets)
    {
        auto xres = msd_rec(row, digit_idx + 1, longest_digits);

        for (const auto& x : xres)
        {
            xbuckets.at(row_ctr).push_back(x);
        }

        ++row_ctr;
    }

    for(const auto& xrow : xbuckets)
    {
        for (const auto& x : xrow)
        {
            mints.push_back(x);
        }
    }

    return mints;
}

std::vector<int> msd_radix(std::vector<int> mints)
{
    if (mints.size() <= 1) return mints;

    const auto longest_digits = std::to_string(*std::max_element(mints.begin(), mints.end())).size();

    return msd_rec(mints, 0, static_cast<int>(longest_digits));
}

int main()
{
    const auto res = msd_radix({65, 98, 21, 12, 104, 92, 106, 41});

    print_row(res);

    return 0;
}
