#include "SortUtils.hpp"
#include "Tree.hpp"

int main() {
  std::vector<int> mints{
      63, 2,  8,  55, 11, 40, 97, 98, 16, 75, 93, 33, 66, 75, 93, 13, 26,
      30, 65, 15, 31, 54, 58, 52, 72, 66, 30, 19, 72, 91, 72, 2,  36, 2,
      33, 77, 58, 17, 47, 28, 74, 73, 49, 29, 61, 91, 49, 96, 18, 95, 14,
      89, 13, 30, 87, 12, 75, 46, 5,  4,  63, 21, 78, 64, 7,  19, 47, 49,
      68, 57, 30, 88, 26, 76, 57, 75, 89, 85, 59, 27, 19, 11, 99, 2,  91,
      57, 21, 39, 73, 13, 47, 1,  48, 75, 38, 93, 57, 32, 16, 87};

  Tree tree(mints);

  // Traversing tells the tree to collect its contents into an auxillary vector
  tree.traverse(tree.get_root());

  // Retrieve the contents from the auxillary vector
  mints = tree.get_contents();

  SortUtils::print_vector(mints);
  SortUtils::print_sorted<int>(mints.begin(), mints.end(), "mints");

  return 0;
}

