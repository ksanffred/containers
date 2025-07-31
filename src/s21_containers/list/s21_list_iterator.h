#ifndef __S21_LIST_ITERATOR_H__
#define __S21_LIST_ITERATOR_H__

#include "../utility/s21_node.h"
#include "s21_list.h"

namespace s21 {
template <class T>
class list<T>::ListIterator {
 public:
  Node<value_type> *node_;

  ListIterator() = default;
  ListIterator(Node<value_type> *);
  ListIterator(ListConstIterator &);
  ~ListIterator() = default;

  reference operator*();
  value_type *operator->();
  ListIterator &operator++();
  ListIterator operator++(int);
  ListIterator &operator--();
  ListIterator operator--(int);
  bool operator==(const ListIterator &) const;
  bool operator!=(const ListIterator &) const;
};
template <class T>
class list<T>::ListConstIterator : public ListIterator {
 public:
  const Node<value_type> *node_;

  ListConstIterator() = default;
  ListConstIterator(const Node<value_type> *);
  ListConstIterator(const ListIterator &);
  ~ListConstIterator() = default;

  const_reference operator*() const;
  const value_type *operator->() const;
  ListConstIterator &operator++();
  ListConstIterator operator++(int);
  ListConstIterator &operator--();
  ListConstIterator operator--(int);
  bool operator==(const ListConstIterator &) const;
  bool operator!=(const ListConstIterator &) const;
};
}  // namespace s21

#include "s21_list_iterator.tpp"
#endif