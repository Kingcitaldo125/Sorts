#pragma once

#include <memory>
#include <vector>

template<typename T>
struct Node
{
  Node() : payload(-1), left(nullptr), right(nullptr) { }
  explicit Node(T p) : payload(p), left(nullptr), right(nullptr) { }

  std::shared_ptr<Node<T>> left;
  std::shared_ptr<Node<T>> right;
  T payload;
};

class Tree
{
public:
  Tree();

  explicit Tree(const int n);
  explicit Tree(Node<int>* n);
  explicit Tree(const std::vector<int>& ns);

  Tree(const Tree& t) = delete;
  virtual ~Tree();
  
  void add(const int n, Node<int>* root);
  void traverse(Node<int>* root);

  Node<int>* get_root() const;
  std::vector<int> get_contents() const;

protected:
  void do_traverse(Node<int>* n);
private:
  std::shared_ptr<Node<int>> root;
  std::vector<int> contents;
};

