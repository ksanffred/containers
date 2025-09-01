#ifndef __MY_STACK_H__
#define __MY_STACK_H__

#include <cstddef>

#include "../deque/my_deque.h"

namespace my {
template <class T, class Container = deque<T>>
class stack {
 public:
  // Stack Member type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  // Stack Member functions
  stack();
  stack(std::initializer_list<value_type> const &);
  stack(const stack &);
  stack(stack &&);
  ~stack();
  stack &operator=(stack &&);

  // Stack Element access
  const_reference top() const;

  // Stack Capacity
  bool empty() const;
  size_type size() const;

  // Stack Modifiers
  void push(const_reference);
  void pop();
  void swap(stack &);
  template <class... Args>
  void insert_many_back(Args &&...);

 private:
  Container deque_;
};
}  // namespace my

#include "my_stack.tpp"
#endif
