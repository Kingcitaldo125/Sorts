#pragma once

#include <memory>
#include <vector>

class Tree;

// Struct template for the Tree class
template<typename T>
struct Node
{
  Node() : payload(-1), left(nullptr), right(nullptr) { }
  explicit Node(T p) : payload(p), left(nullptr), right(nullptr) { }

  std::shared_ptr<Node<T>> left;
  std::shared_ptr<Node<T>> right;
  T payload;
};

// BST data structure
class Tree
{
public:
  Tree();

  explicit Tree(const int n);
  explicit Tree(Node<int>* n);
  explicit Tree(const std::vector<int>& ns);

  // Bonus: Implement copy constructor for the tree class
  Tree(const Tree& t) = delete;
  virtual ~Tree();
  
  void add(const int n, Node<int>* root);
  // In-order
  void traverse(Node<int>* root);

  Node<int>* get_root() const;
  std::vector<int> get_contents() const;

protected:
  void do_traverse(Node<int>* n);
private:
  std::shared_ptr<Node<int>> root;
  std::vector<int> contents;
};

