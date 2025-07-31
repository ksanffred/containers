#include "tests_entry.h"
#define DEFAULT_QUEUE {1, 2, 3}
using namespace s21;

TEST(queue, DefaultConstructor) {
  queue<int> queue_;

  ASSERT_EQ(queue_.empty(), true);
  queue_.~queue();
}
TEST(queue, InitializerListConstructor) {
  queue<int> queue_ = DEFAULT_QUEUE;

  ASSERT_EQ(queue_.size(), (queue<int>::size_type)3);
  queue_.~queue();
}
TEST(queue, CopyConstructor) {
  queue<int> queue_ = DEFAULT_QUEUE;
  queue<int> queue_copy(queue_);

  ASSERT_EQ(queue_.front(), queue_copy.front());
  ASSERT_EQ(queue_.back(), queue_copy.back());
  queue_.~queue();
  queue_copy.~queue();
}
TEST(queue, MoveConstructor) {
  queue<int> queue_ = DEFAULT_QUEUE;
  queue<int> queue_copy(std::move(queue_));

  ASSERT_EQ(queue_copy.front(), 1);
  ASSERT_EQ(queue_.empty(), true);
  queue_.~queue();
  queue_copy.~queue();
}
TEST(queue, Destructor) {
  queue<int> queue_;

  queue_.~queue();
  ASSERT_EQ(queue_.empty(), true);
}
TEST(queue, Assigment) {
  queue<int> queue_ = DEFAULT_QUEUE;
  queue<int> queue_copy = queue_;

  ASSERT_EQ(queue_.size(), queue_copy.size());
  ASSERT_EQ(queue_.front(), queue_copy.front());
  ASSERT_EQ(queue_.back(), queue_copy.back());
  queue_.~queue();
  queue_copy.~queue();
}
TEST(queue, Front) {
  queue<int> queue_ = DEFAULT_QUEUE;

  ASSERT_EQ(queue_.front(), 1);
  queue_.~queue();
}
TEST(queue, Back) {
  queue<int> queue_ = DEFAULT_QUEUE;

  ASSERT_EQ(queue_.back(), 3);
  queue_.~queue();
}
TEST(queue, Empty) {
  queue<int> queue_;

  ASSERT_EQ(queue_.empty(), true);
  queue_.~queue();
}
TEST(queue, Size) {
  queue<int> queue_ = DEFAULT_QUEUE;

  ASSERT_EQ(queue_.size(), (queue<int>::size_type)3);
  queue_.~queue();
}
TEST(queue, Push) {
  queue<int> queue_ = DEFAULT_QUEUE;

  queue_.push(1);
  ASSERT_EQ(queue_.back(), 1);
  ASSERT_EQ(queue_.size(), (queue<int>::size_type)4);
  queue_.~queue();
}
TEST(queue, Pop) {
  queue<int> queue_ = DEFAULT_QUEUE;

  queue_.pop();
  ASSERT_EQ(queue_.front(), 2);
  ASSERT_EQ(queue_.size(), (queue<int>::size_type)2);
  queue_.~queue();
}
TEST(queue, Swap) {
  queue<int> queue_first = DEFAULT_QUEUE;
  queue<int> queue_second = {4, 5, 6};

  queue_first.swap(queue_second);
  ASSERT_EQ(queue_first.size(), (queue<int>::size_type)3);
  ASSERT_EQ(queue_second.size(), (queue<int>::size_type)3);
  ASSERT_EQ(queue_first.front(), 4);
  ASSERT_EQ(queue_first.back(), 6);
  ASSERT_EQ(queue_second.front(), 1);
  ASSERT_EQ(queue_second.back(), 3);
  queue_first.~queue();
  queue_second.~queue();
}
TEST(queue, InsertManyBack) {
  queue<int> queue_;

  queue_.insert_many_back(1, 2, 3);
  ASSERT_EQ(queue_.front(), 1);
  ASSERT_EQ(queue_.back(), 3);
  queue_.~queue();
}