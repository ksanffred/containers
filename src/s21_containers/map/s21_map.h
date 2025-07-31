#ifndef __S21_MAP_H__
#define __S21_MAP_H__

#include <initializer_list>

#include "../rbtree/s21_rbtree.h"

namespace s21 {
template <class Key, class T>
class map {
 public:
  typedef Key key_type;
  typedef T mapped_type;
  typedef std::pair<key_type, mapped_type> value_type;
  typedef value_type& reference;
  typedef const value_type& const_reference;
  typedef typename Tree<key_type, value_type>::Iterator iterator;
  typedef typename Tree<key_type, value_type>::ConstIterator const_iterator;
  typedef size_t size_type;

 public:
  Tree<key_type, value_type> base_;

 public:
  map();
  map(std::initializer_list<value_type> const& items);
  map(const map& m);
  map(map&& m);
  ~map() {};

 public:
  map& operator=(map&& map);

 public:
  iterator begin() const;
  iterator end() const;

 public:
  T& at(const Key& key);
  T& operator[](const Key& key);

 public:
  bool empty();
  size_type size();
  size_type max_size();

 public:
  void clear();
  std::pair<iterator, bool> insert(const value_type& value);
  std::pair<iterator, bool> insert(const Key& key, const T& obj);
  std::pair<iterator, bool> insert_or_assign(const Key& key, const T& obj);
  void erase(iterator pos);
  void swap(map& other);
  void merge(map& other);

 public:
  iterator find(const Key& key);
  bool contains(const Key& key);

 public:
  template <class... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args&&... args);
};
}  // namespace s21
#include "s21_map.tpp"
#endif