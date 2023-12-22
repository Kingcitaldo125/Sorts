#include <chrono>
#include <iostream>
#include <list>
#include <mutex>
#include <thread>
#include <vector>

static std::mutex mtx;

void corot(std::vector<int> &mints, const int N) {
  std::this_thread::sleep_for(std::chrono::milliseconds(N));
  {
    std::lock_guard<std::mutex> mlock(mtx);
    mints.push_back(N);
  }
}

std::vector<int> sleep_sort(const std::vector<int> &mvec) {
  std::vector<int> mints;
  std::list<std::thread> threads;

  for (const auto &i : mvec) {
    threads.push_back(std::thread(corot, std::ref(mints), i));
  }

  for (auto &th : threads) {
    th.join();
  }

  return mints;
}

int main() {
  std::vector<int> values{32,  867, 661, 347, 91,  238, 739, 820, 20,  838,
                          796, 550, 803, 240, 327, 81,  896, 810, 151, 281,
                          886, 106, 660, 45,  787, 674, 20,  120, 437, 25,
                          930, 751, 3,   145, 674, 362, 809, 517, 418, 469,
                          689, 738, 623, 842, 643, 211, 308, 13,  792, 790};

  const auto mints = sleep_sort(std::move(values));

  SortUtils::print_vector(mints);
  SortUtils::print_sorted<int>(mints.begin(), mints.end(), "mints");

  return 0;
}
