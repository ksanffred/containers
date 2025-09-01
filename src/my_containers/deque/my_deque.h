#ifndef __MY_DEQUE_H__
#define __MY_DEQUE_H__

#include <cstddef>

#include "../utility/my_node.h"

namespace my {
template <class T>
class deque {
 public:
  // Deque Member type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  // Deque Functions
  deque();
  deque(std::initializer_list<value_type> const &);
  deque(const deque &);
  deque(deque &&);
  ~deque();
  deque &operator=(deque &&);

  // Deque Element access
  const_reference front() const;
  const_reference back() const;

  // Deque Capacity
  bool empty() const;
  size_type size() const;

  // Deque Modifiers
  void clear();
  void push_back(const_reference);
  void pop_back();
  void push_front(const_reference);
  void pop_front();
  void swap(deque &);

  // protected:
  size_type size_ = 0;
  Node<T> *head_ = nullptr;
  Node<T> *tail_ = nullptr;
};
}  // namespace my

#include "my_deque.tpp"
#endif
