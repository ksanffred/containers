#include "tests_entry.h"
#define DEFAULT_SIZE 5
#define DEFAULT_LIST {1, 2, 3, 4, 5}
using namespace my;

TEST(ListIterator, DefaultConstructor) {
  list<int>::ListIterator it;

  it.~ListIterator();
}
TEST(ListIterator, ParametrizedConstructor) {
  Node<int> node(1);
  list<int>::ListIterator it(&node);

  ASSERT_EQ(it.node_->value, 1);
  it.~ListIterator();
  node.~Node();
}
TEST(ListIteratorOperators, Star) {
  Node<int> node(1);
  list<int>::ListIterator it(&node);

  ASSERT_EQ(*it, 1);
  it.~ListIterator();
  node.~Node();
}
TEST(ListIteratorOperators, Arrow) {
  struct Room {
    double length = 3.2;
    double width = 2.8;
  };
  Node<struct Room> node;
  list<struct Room>::ListIterator it(&node);

  ASSERT_EQ(it->length, 3.2);
  ASSERT_EQ(it->width, 2.8);
  it.~ListIterator();
  node.~Node();
}
TEST(ListIteratorOperators, Preincrement) {
  list<int> list_(DEFAULT_SIZE);
  list<int>::ListIterator it = list_.begin();

  for (int i = 0; i < DEFAULT_SIZE; i++) ++it;
  ASSERT_EQ(it, list_.end());
  it.~ListIterator();
  list_.~list();
}
TEST(ListIteratorOperators, Postincrement) {
  list<int> list_(DEFAULT_SIZE);
  list<int>::ListIterator it = list_.begin();

  for (int i = 0; i < DEFAULT_SIZE; i++) it++;
  ASSERT_EQ(it, list_.end());
  it.~ListIterator();
  list_.~list();
}
TEST(ListIteratorOperators, Predecrement) {
  list<int> list_(DEFAULT_SIZE);
  list<int>::ListIterator it = list_.end();

  for (int i = 0; i < DEFAULT_SIZE; i++) --it;
  ASSERT_EQ(it, list_.end());
  it.~ListIterator();
  list_.~list();
}
TEST(ListIteratorOperators, Postdecrement) {
  list<int> list_(DEFAULT_SIZE);
  list<int>::ListIterator it = list_.end();

  for (int i = 0; i < DEFAULT_SIZE; i++) it--;
  ASSERT_EQ(it, list_.end());
  it.~ListIterator();
  list_.~list();
}
TEST(ListIteratorOperators, Equality) {
  Node<int> node(1);
  list<int>::ListIterator it_first(&node);
  list<int>::ListIterator it_second(&node);

  ASSERT_EQ(it_first == it_second, true);
  it_first.~ListIterator();
  it_second.~ListIterator();
  node.~Node();
}
TEST(ListIteratorOperators, NonEquality) {
  Node<int> node_first(1);
  Node<int> node_second(2);
  list<int>::ListIterator it_first(&node_first);
  list<int>::ListIterator it_second(&node_second);

  ASSERT_EQ(it_first != it_second, true);
  it_first.~ListIterator();
  it_second.~ListIterator();
  node_first.~Node();
  node_second.~Node();
}
TEST(ListConstIterator, DefaultConstructor) {
  list<int>::ListConstIterator it;

  it.~ListConstIterator();
}
TEST(ListConstIterator, ParametrizedConstructor) {
  const Node<int> node(1);
  list<int>::ListConstIterator it(&node);

  ASSERT_EQ(it.node_->value, 1);
  it.~ListConstIterator();
  node.~Node();
}
TEST(ListConstIteratorOperators, Star) {
  const Node<int> node(1);
  list<int>::ListConstIterator it(&node);

  ASSERT_EQ(*it, 1);
  it.~ListConstIterator();
  node.~Node();
}
TEST(ListConstIteratorOperators, Arrow) {
  struct Room {
    double length = 3.2;
    double width = 2.8;
  };
  Node<struct Room> node;
  list<struct Room>::ListConstIterator it(&node);

  ASSERT_EQ(it->length, 3.2);
  ASSERT_EQ(it->width, 2.8);
  it.~ListConstIterator();
  node.~Node();
}
TEST(ListConstIteratorOperators, Preincrement) {
  list<int> list_(DEFAULT_SIZE);
  list<int>::ListConstIterator it = list_.begin();

  for (int i = 0; i < DEFAULT_SIZE; i++) it++;
  ASSERT_EQ(it, list_.end());
  it.~ListConstIterator();
  list_.~list();
}
TEST(ListConstIteratorOperators, Postincrement) {
  list<int> list_(DEFAULT_SIZE);
  list<int>::ListConstIterator it = list_.begin();

  for (int i = 0; i < DEFAULT_SIZE; i++) it++;
  ASSERT_EQ(it, list_.end());
  it.~ListConstIterator();
  list_.~list();
}
TEST(ListConstIteratorOperators, Predecrement) {
  list<int> list_(DEFAULT_SIZE);
  list<int>::ListConstIterator it = list_.end();

  for (int i = 0; i < DEFAULT_SIZE; i++) it--;
  ASSERT_EQ(it, list_.end());
  it.~ListConstIterator();
  list_.~list();
}
TEST(ListConstIteratorOperators, Postdecrement) {
  list<int> list_(DEFAULT_SIZE);
  list<int>::ListConstIterator it = list_.end();

  for (int i = 0; i < DEFAULT_SIZE; i++) it--;
  ASSERT_EQ(it, list_.end());
  it.~ListConstIterator();
  list_.~list();
}
TEST(ListConstIteratorOperators, Equality) {
  Node<int> node(1);
  list<int>::ListConstIterator it_first(&node);
  list<int>::ListConstIterator it_second(&node);

  ASSERT_EQ(it_first == it_second, true);
  it_first.~ListConstIterator();
  it_second.~ListConstIterator();
  node.~Node();
}
TEST(ListConstIteratorOperators, NonEquality) {
  Node<int> node_first(1);
  Node<int> node_second(2);
  list<int>::ListConstIterator it_first(&node_first);
  list<int>::ListConstIterator it_second(&node_second);

  ASSERT_EQ(it_first != it_second, true);
  it_first.~ListConstIterator();
  it_second.~ListConstIterator();
  node_first.~Node();
  node_second.~Node();
}
TEST(list, DefaultConstructor) {
  list<int> list_;

  ASSERT_EQ(list_.empty(), true);
  list_.~list();
}
TEST(list, ParametrizedConstructor) {
  list<int> list_(DEFAULT_SIZE);

  ASSERT_EQ(list_.size(), (list<int>::size_type)DEFAULT_SIZE);
  list_.~list();
}
TEST(list, InitializerListConstructor) {
  list<int> list_ = DEFAULT_LIST;

  ASSERT_EQ(list_.front(), 1);
  ASSERT_EQ(list_.back(), 5);
  list_.~list();
}
TEST(list, CopyConstructor) {
  list<int> list_(DEFAULT_SIZE);
  list<int> list_copy(list_);

  ASSERT_EQ(list_.front(), list_copy.front());
  ASSERT_EQ(list_.back(), list_copy.back());
  list_.~list();
  list_copy.~list();
}
TEST(list, MoveConstructor) {
  list<int> list_(DEFAULT_SIZE);
  list<int> list_copy(std::move(list_));

  ASSERT_EQ(list_copy.front(), 0);
  ASSERT_EQ(list_.empty(), true);
  list_.~list();
  list_copy.~list();
}
TEST(list, Destructor) {
  list<int> list_;

  list_.~list();
  ASSERT_EQ(list_.empty(), true);
}
TEST(list, Assignment) {
  list<int> list_(DEFAULT_SIZE);
  list<int> list_copy = list_;

  ASSERT_EQ(list_.size(), list_copy.size());
  ASSERT_EQ(list_.front(), list_copy.front());
  ASSERT_EQ(list_.back(), list_copy.back());
  list_.~list();
  list_copy.~list();
}
TEST(list, Front) {
  list<int> list_(DEFAULT_SIZE);

  ASSERT_EQ(list_.front(), 0);
  list_.~list();
}
TEST(list, Back) {
  list<int> list_(DEFAULT_SIZE);

  ASSERT_EQ(list_.back(), 0);
  list_.~list();
}
TEST(list, Begin) {
  list<int> list_(DEFAULT_SIZE);
  list<int>::iterator it = list_.begin();

  ASSERT_EQ(*it, 0);
  it.~ListIterator();
  list_.~list();
}
TEST(list, End) {
  list<int> list_(DEFAULT_SIZE);
  list<int>::iterator it = list_.end();

  it.~ListIterator();
  list_.~list();
}
TEST(list, Empty) {
  list<int> list_;

  ASSERT_EQ(list_.empty(), true);
  list_.~list();
}
TEST(list, Size) {
  list<int> list_(DEFAULT_SIZE);

  ASSERT_EQ(list_.size(), (list<int>::size_type)DEFAULT_SIZE);
  list_.~list();
}
TEST(list, MaxSize) {
  list<int> list_(DEFAULT_SIZE);

  ASSERT_EQ(list_.max_size(), std::numeric_limits<list<int>::size_type>::max() /
                                  sizeof(struct Node<int>));
  list_.~list();
}
TEST(list, Clear) {
  list<int> list_(DEFAULT_SIZE);

  list_.clear();
  ASSERT_EQ(list_.empty(), true);
  list_.~list();
}
TEST(list, Insert) {
  list<int> list_(DEFAULT_SIZE);

  list_.insert(list_.begin(), DEFAULT_SIZE);
  for (auto it = list_.begin(); it != list_.end(); it++)
    ASSERT_EQ(*it, (it == list_.begin()) ? DEFAULT_SIZE : 0);
  list_.~list();
}
TEST(list, Erase) {
  list<int> list_(DEFAULT_SIZE);

  list_.erase(list_.begin());
  ASSERT_EQ(list_.size(), (list<int>::size_type)(DEFAULT_SIZE - 1));
  list_.~list();
}
TEST(list, PushBack) {
  list<int> list_(DEFAULT_SIZE);

  list_.push_back(1);
  ASSERT_EQ(list_.back(), 1);
  ASSERT_EQ(list_.size(), (list<int>::size_type)(DEFAULT_SIZE + 1));
  list_.~list();
}
TEST(list, PopBack) {
  list<int> list_(DEFAULT_SIZE);

  list_.pop_back();
  ASSERT_EQ(list_.size(), (list<int>::size_type)(DEFAULT_SIZE - 1));
  list_.~list();
}
TEST(list, PushFront) {
  list<int> list_(DEFAULT_SIZE);

  list_.push_front(1);
  ASSERT_EQ(list_.front(), 1);
  ASSERT_EQ(list_.size(), (list<int>::size_type)(DEFAULT_SIZE + 1));
  list_.~list();
}
TEST(list, PopFront) {
  list<int> list_(DEFAULT_SIZE);

  list_.pop_front();
  ASSERT_EQ(list_.size(), (list<int>::size_type)(DEFAULT_SIZE - 1));
  list_.~list();
}
TEST(list, Swap) {
  list<int> list_first(DEFAULT_SIZE);
  list<int> list_second(DEFAULT_SIZE + 1);

  list_first.swap(list_second);
  ASSERT_EQ(list_first.size(), (list<int>::size_type)(DEFAULT_SIZE + 1));
  ASSERT_EQ(list_second.size(), (list<int>::size_type)(DEFAULT_SIZE));
  list_first.~list();
  list_second.~list();
}
TEST(list, Splice) {
  list<int> list_(DEFAULT_SIZE);
  list<int> list_copy(list_);
  list<int>::const_iterator it = list_.begin();

  list_.splice(it, list_copy);
  ASSERT_EQ(list_.size(), (list<int>::size_type)(2 * DEFAULT_SIZE));
  it.~ListIterator();
  list_.~list();
  list_copy.~list();
}
TEST(list, Reverse) {
  list<int> list_ = {1, 2, 3, 4};
  list<int> reversed_list = {4, 3, 2, 1};

  list_.reverse();
  ASSERT_EQ(list_.front(), reversed_list.front());
  ASSERT_EQ(list_.back(), reversed_list.back());
  list_.~list();
  reversed_list.~list();
}
TEST(list, Sort) {
  list<int> list_ = {2, 4, 1, 3, 5};
  list<int> sorted_list = DEFAULT_LIST;

  list_.sort();
  ASSERT_EQ(list_.front(), sorted_list.front());
  ASSERT_EQ(list_.back(), sorted_list.back());
  ASSERT_EQ(list_.size(), sorted_list.size());
  list_.~list();
  sorted_list.~list();
}
TEST(list, InsertMany) {
  list<int> list_ = DEFAULT_LIST;
  list<int>::iterator it = list_.begin();

  list_.insert_many(++it, 7, 8, 9);
  it = list_.begin();
  ASSERT_EQ(*it++, 1);
  ASSERT_EQ(*it++, 7);
  ASSERT_EQ(*it++, 8);
  ASSERT_EQ(*it++, 9);
  ASSERT_EQ(*it, 2);
  list_.~list();
  it.~ListIterator();
}
TEST(list, InsertManyBack) {
  list<int> list_ = DEFAULT_LIST;
  list<int>::iterator it;

  list_.insert_many_back(7, 8, 9);
  it = list_.end();
  ASSERT_EQ(list_.back(), 9);
  ASSERT_EQ(list_.size(), (list<int>::size_type)(DEFAULT_SIZE + 3));
  list_.~list();
  it.~ListIterator();
}
TEST(list, InsertManyFront) {
  list<int> list_ = DEFAULT_LIST;
  list<int>::iterator it;

  list_.insert_many_front(7, 8, 9);
  it = list_.begin();
  ASSERT_EQ(*it++, 9);
  ASSERT_EQ(*it++, 8);
  ASSERT_EQ(*it++, 7);
  ASSERT_EQ(*it++, 1);
  ASSERT_EQ(*it++, 2);
  list_.~list();
  it.~ListIterator();
}