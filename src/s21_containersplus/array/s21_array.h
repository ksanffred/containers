#ifndef __S21_ARRAY_H__
#define __S21_ARRAY_H__

namespace s21 {
template <typename T, std::size_t N>
class array {
 public:
  // Array Member type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  // Array Member functions
  array();
  array(std::initializer_list<value_type> const &);
  array(const array &);
  array(array &&);
  ~array() = default;
  array &operator=(array &&);

  // Array Element access
  reference at(size_type);
  reference operator[](size_type);
  reference front();
  reference back();
  iterator data();

  // Array Iterators
  iterator begin();
  iterator end();

  // Array Capacity
  bool empty();
  size_type size();
  size_type max_size();

  // Array Modifiers
  void swap(array &);
  void fill(const_reference);

 private:
  value_type values_[N] = {};
  size_type size_ = N;
};
}  // namespace s21

#include "s21_array.tpp"
#endif