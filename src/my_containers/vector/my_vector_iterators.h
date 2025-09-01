#ifndef __MY_VECTOR_ITERATORS_H__
#define __MY_VECTOR_ITERATORS_H__

namespace my {
template <class T>
class vector<T>::VectorIterator {
 public:
  value_type *ptr_;

  VectorIterator() = default;
  VectorIterator(value_type *);
  VectorIterator(VectorConstIterator &);
  ~VectorIterator() = default;

  reference operator*();
  VectorIterator operator++(int);
  VectorIterator operator--(int);
  VectorIterator &operator++();
  VectorIterator &operator--();
  bool operator==(const VectorIterator &) const;
  bool operator!=(const VectorIterator &) const;
  VectorIterator operator+(int) const;
  VectorIterator operator-(int) const;
  ptrdiff_t operator-(const VectorIterator &) const;
};
template <class T>
class vector<T>::VectorConstIterator : public VectorIterator {
 public:
  const value_type *ptr_;

  VectorConstIterator() = default;
  VectorConstIterator(const value_type *);
  VectorConstIterator(const VectorIterator &);
  ~VectorConstIterator() = default;

  const_reference operator*() const;
  VectorConstIterator operator++(int);
  VectorConstIterator operator--(int);
  VectorConstIterator &operator++();
  VectorConstIterator &operator--();
  bool operator==(const VectorConstIterator &) const;
  bool operator!=(const VectorConstIterator &) const;
  VectorConstIterator operator+(int) const;
  VectorConstIterator operator-(int) const;
  ptrdiff_t operator-(const VectorConstIterator &) const;
};
}  // namespace my

#include "my_vector_iterators.tpp"
#endif