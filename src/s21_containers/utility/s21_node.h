#ifndef __S21_NODE_H__
#define __S21_NODE_H__

namespace s21 {
template <class T>
struct Node {
  using value_type = T;

  value_type value;
  Node<value_type> *next = nullptr;
  Node<value_type> *prev = nullptr;
  Node(value_type = value_type(), Node<value_type> * = nullptr,
       Node<value_type> * = nullptr);
};
template <class T>
Node<T> *getMiddle(Node<T> *);
template <class T>
Node<T> *mergeNodes(Node<T> *, Node<T> *);
template <class T>
Node<T> *mergeSort(Node<T> *);
}  // namespace s21

#include "s21_node.tpp"
#endif