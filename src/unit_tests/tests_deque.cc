#include "tests_entry.h"
#define DEFAULT_DEQUE {1, 2, 3}
using namespace my;

TEST(deque, DefaultConstructor) {
  deque<int> deque_;

  ASSERT_EQ(deque_.empty(), true);
  deque_.~deque();
}
TEST(deque, InitializerListConstructor) {
  deque<int> deque_ = DEFAULT_DEQUE;

  ASSERT_EQ(deque_.front(), 1);
  ASSERT_EQ(deque_.back(), 3);
  deque_.~deque();
}
TEST(deque, CopyConstructor) {
  deque<int> deque_ = DEFAULT_DEQUE;
  deque<int> deque_copy(deque_);

  ASSERT_EQ(deque_.front(), deque_copy.front());
  ASSERT_EQ(deque_.back(), deque_copy.back());
  deque_.~deque();
  deque_copy.~deque();
}
TEST(deque, MoveConstructor) {
  deque<int> deque_ = DEFAULT_DEQUE;
  deque<int> deque_copy(std::move(deque_));

  ASSERT_EQ(deque_copy.front(), 1);
  ASSERT_EQ(deque_.empty(), true);
  deque_.~deque();
  deque_copy.~deque();
}
TEST(deque, Destructor) {
  deque<int> deque_;

  deque_.~deque();
  ASSERT_EQ(deque_.empty(), true);
}
TEST(deque, Assigment) {
  deque<int> deque_ = DEFAULT_DEQUE;
  deque<int> deque_copy = deque_;

  ASSERT_EQ(deque_.size(), deque_copy.size());
  ASSERT_EQ(deque_.front(), deque_copy.front());
  ASSERT_EQ(deque_.back(), deque_copy.back());
  deque_.~deque();
  deque_copy.~deque();
}
TEST(deque, Front) {
  deque<int> deque_ = DEFAULT_DEQUE;

  ASSERT_EQ(deque_.front(), 1);
  deque_.~deque();
}
TEST(deque, Back) {
  deque<int> deque_ = DEFAULT_DEQUE;

  ASSERT_EQ(deque_.back(), 3);
  deque_.~deque();
}
TEST(deque, Empty) {
  deque<int> deque_;

  ASSERT_EQ(deque_.empty(), true);
  deque_.~deque();
}
TEST(deque, Size) {
  deque<int> deque_ = DEFAULT_DEQUE;

  ASSERT_EQ(deque_.size(), (deque<int>::size_type)3);
  deque_.~deque();
}
TEST(deque, Clear) {
  deque<int> deque_ = DEFAULT_DEQUE;

  deque_.clear();
  ASSERT_EQ(deque_.empty(), true);
  deque_.~deque();
}
TEST(deque, PushBack) {
  deque<int> deque_ = DEFAULT_DEQUE;

  deque_.push_back(1);
  ASSERT_EQ(deque_.back(), 1);
  ASSERT_EQ(deque_.size(), (deque<int>::size_type)4);
  deque_.~deque();
}
TEST(deque, PopBack) {
  deque<int> deque_ = DEFAULT_DEQUE;

  deque_.pop_back();
  ASSERT_EQ(deque_.back(), 2);
  ASSERT_EQ(deque_.size(), (deque<int>::size_type)2);
  deque_.~deque();
}
TEST(deque, PushFront) {
  deque<int> deque_ = DEFAULT_DEQUE;

  deque_.push_front(1);
  ASSERT_EQ(deque_.front(), 1);
  ASSERT_EQ(deque_.size(), (deque<int>::size_type)4);
  deque_.~deque();
}
TEST(deque, PopFront) {
  deque<int> deque_ = DEFAULT_DEQUE;

  deque_.pop_front();
  ASSERT_EQ(deque_.front(), 2);
  ASSERT_EQ(deque_.size(), (deque<int>::size_type)2);
  deque_.~deque();
}
TEST(deque, Swap) {
  deque<int> deque_first = DEFAULT_DEQUE;
  deque<int> deque_second = {4, 5, 6};

  deque_first.swap(deque_second);
  ASSERT_EQ(deque_first.size(), (deque<int>::size_type)3);
  ASSERT_EQ(deque_second.size(), (deque<int>::size_type)3);
  ASSERT_EQ(deque_first.front(), 4);
  ASSERT_EQ(deque_first.back(), 6);
  ASSERT_EQ(deque_second.front(), 1);
  ASSERT_EQ(deque_second.back(), 3);
  deque_first.~deque();
  deque_second.~deque();
}