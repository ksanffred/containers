#ifndef __S21_LIST_H__
#define __S21_LIST_H__

#include <cstddef>
#include <limits>
#include <utility>

#include "../deque/s21_deque.h"

namespace s21 {
template <class T>
class list : public deque<T> {
 public:
  class ListIterator;
  class ListConstIterator;

  // List Member type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;
  using iterator = ListIterator;
  using const_iterator = ListConstIterator;
  using deque<T>::deque;

  // List Functions
  list();
  list(size_type);
  list(std::initializer_list<value_type> const &);
  list(const list &);
  list(list &&);
  using deque<T>::operator=;

  // List Element access
  using deque<T>::front;
  using deque<T>::back;

  // List Iterators
  iterator begin();
  iterator end();

  // List Capacity
  using deque<T>::empty;
  using deque<T>::size;
  size_type max_size() const;

  // List Modifiers
  using deque<T>::clear;
  iterator insert(iterator, const_reference);
  void erase(iterator);
  using deque<T>::push_back;
  using deque<T>::pop_back;
  using deque<T>::push_front;
  using deque<T>::pop_front;
  using deque<T>::swap;
  void merge(list &);
  void splice(const_iterator, list &);
  void reverse();
  void unique();
  void sort();
  template <class... Args>
  iterator insert_many(const_iterator, Args &&...);
  template <class... Args>
  void insert_many_back(Args &&...);
  template <class... Args>
  void insert_many_front(Args &&...);
};
}  // namespace s21

#include "s21_list.tpp"
#include "s21_list_iterator.h"
#endif
