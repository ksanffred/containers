#ifndef __MY_SET_H__
#define __MY_SET_H__

#include <initializer_list>

#include "../rbtree/my_rbtree.h"

namespace my {

template <class Key>
class set {
 public:
  typedef Key key_type;
  typedef key_type value_type;
  typedef value_type& reference;
  typedef const value_type& const_reference;
  typedef typename Tree<key_type, value_type>::Iterator iterator;
  typedef typename Tree<key_type, value_type>::ConstIterator const_iterator;
  typedef size_t size_type;

 public:
  Tree<key_type, value_type> base_;

 public:
  set();
  set(std::initializer_list<value_type> const& items);
  set(const set& s);
  set(set&& s);
  ~set() {};

 public:
  set& operator=(const set& s);
  set& operator=(set&& s);

 public:
  iterator begin() const;
  iterator end() const;

 public:
  bool empty();
  size_type size();
  size_type max_size();
  void printSet();

 public:
  void clear();
  std::pair<iterator, bool> insert(const value_type& value);
  void erase(iterator pos);
  void swap(set& other);
  void merge(set& other);

 public:
  iterator find(const key_type& key);
  bool contains(const key_type& key);

 public:
  template <class... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args&&... args);
};
}  // namespace my
#include "my_set.tpp"
#endif
