#ifndef __MY_VECTOR_H__
#define __MY_VECTOR_H__

#include <algorithm>
#include <cstddef>

namespace my {
template <typename T>
class vector {
 public:
  class VectorIterator;
  class VectorConstIterator;

  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = vector<T>::VectorIterator;
  using const_iterator = vector<T>::VectorConstIterator;
  using size_type = std::size_t;

  // Vector Member functions
  vector();
  vector(size_type);
  vector(std::initializer_list<value_type> const &);
  vector(const vector &);
  vector(vector &&);
  ~vector();
  vector &operator=(vector &&);

  // Vector Element access
  reference at(size_type);
  reference operator[](size_type);
  const_reference front() const;
  const_reference back() const;
  value_type *data();

  // Vector Iterators
  iterator begin();
  iterator end();

  // Vector Capacity
  bool empty() const;
  size_type size() const;
  size_type max_size() const;
  void reserve(size_type);
  size_type capacity() const;
  void shrink_to_fit();

  // Vector Modifiers
  void clear();
  iterator insert(iterator, const_reference);
  void erase(iterator);
  void push_back(const_reference);
  void pop_back();
  void swap(vector &);
  template <typename... Args>
  iterator insert_many(const_iterator, Args &&...);
  template <typename... Args>
  void insert_many_back(Args &&...);

 private:
  value_type *data_;
  size_type size_;
  size_type capacity_;
};
}  // namespace my

#include "my_vector.tpp"
#include "my_vector_iterators.h"
#endif
