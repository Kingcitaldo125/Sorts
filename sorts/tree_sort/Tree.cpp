#include <iostream>

#include "Tree.hpp"

Tree::Tree()
{
}

Tree::Tree(const int n)
{
  root = std::make_shared<Node<int>>(n);
}
  
Tree::Tree(Node<int>* n)
{
  root = std::make_shared<Node<int>>(n->payload);
}

Tree::Tree(const std::vector<int>& ns)
{
  for(const auto& n : ns)
  {
    add(n, root.get());
  }
}
  
Tree::~Tree()
{
}

void Tree::add(const int n, Node<int>* _root)
{
  if (_root == nullptr)
  {
    root = std::make_shared<Node<int>>(n);
    return;
  }

  if (n <= _root->payload)
  {
    if (_root->left == nullptr)
    {
      _root->left = std::make_shared<Node<int>>(Node<int>(n));
      return;
    }

    add(n, _root->left.get());
  }
  else
  {
    if (_root->right == nullptr)
    {
      _root->right = std::make_shared<Node<int>>(Node<int>(n));
      return;
    }

    add(n, _root->right.get());
  }
}

void Tree::do_traverse(Node<int>* n)
{
  if(n == nullptr)
    return;

  if(n->left != nullptr)
    do_traverse(n->left.get());

  auto pld = n->payload;
//  std::cout << "Visited: " << pld << "\n";
  contents.push_back(pld);

  if(root->right != nullptr)
    do_traverse(n->right.get());
}

// In-order
void Tree::traverse(Node<int>* _root)
{
  contents.clear();

  do_traverse(_root);
}

Node<int>* Tree::get_root() const
{
  return root == nullptr ? nullptr : root.get();
}

std::vector<int> Tree::get_contents() const
{
  return contents;
}

