#ifndef __MY_MULTISET_H__
#define __MY_MULTISET_H__

#include <initializer_list>

#include "../../my_containers/rbtree/my_rbtree.h"

namespace my {
template <class Key>
class multiset {
 public:
  typedef Key key_type;
  typedef key_type value_type;
  typedef value_type& reference;
  typedef const value_type& const_reference;
  typedef typename Tree<key_type, value_type, std::less_equal<Key>>::Iterator
      iterator;
  typedef
      typename Tree<key_type, value_type, std::less_equal<Key>>::ConstIterator
          const_iterator;
  typedef size_t size_type;

 public:
  Tree<key_type, value_type, std::less_equal<Key>> base_;

 public:
  multiset();
  multiset(std::initializer_list<value_type> const&);
  multiset(const multiset&);
  multiset(multiset&&);
  ~multiset() {};

 public:
  multiset& operator=(multiset&&);

 public:
  iterator begin() const;
  iterator end() const;

 public:
  bool empty();
  size_type size();
  size_type max_size();

 public:
  void clear();
  std::pair<iterator, bool> insert(const value_type&);
  void erase(iterator);
  void swap(multiset&);
  void merge(multiset&);

 public:
  size_type count(const Key&);
  iterator find(const Key&);
  bool contains(const Key&);
  std::pair<iterator, iterator> equal_range(const Key&);
  iterator lower_bound(const Key&);
  iterator upper_bound(const Key&);

 public:
  template <class... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args&&...);
};
}  // namespace my
#include "my_multiset.tpp"
#endif
