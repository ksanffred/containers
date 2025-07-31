#ifndef __S21_QUEUE_H__
#define __S21_QUEUE_H__

#include <cstddef>

#include "../deque/s21_deque.h"

namespace s21 {
template <class T, class Container = deque<T>>
class queue {
 public:
  // Queue Member type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  // Queue Member functions
  queue();
  queue(std::initializer_list<value_type> const &);
  queue(const queue &);
  queue(queue &&);
  ~queue();
  queue &operator=(queue &&);

  // Queue Element access
  const_reference front() const;
  const_reference back() const;

  // Queue Capacity
  bool empty() const;
  size_type size() const;

  // Queue Modifiers
  void push(const_reference);
  void pop();
  void swap(queue &);
  template <class... Args>
  void insert_many_back(Args &&...);

 private:
  Container deque_;
};
}  // namespace s21

#include "s21_queue.tpp"
#endif
