#include "tests_entry.h"
#define DEFAULT_STACK {1, 2, 3}
using namespace s21;

TEST(stack, DefaultConstructor) {
  stack<int> stack_;

  ASSERT_EQ(stack_.empty(), true);
  stack_.~stack();
}
TEST(stack, InitializerListConstructor) {
  stack<int> stack_ = DEFAULT_STACK;

  ASSERT_EQ(stack_.size(), (stack<int>::size_type)3);
  stack_.~stack();
}
TEST(stack, CopyConstructor) {
  stack<int> stack_ = DEFAULT_STACK;
  stack<int> stack_copy(stack_);

  ASSERT_EQ(stack_.top(), stack_copy.top());
  stack_.~stack();
  stack_copy.~stack();
}
TEST(stack, MoveConstructor) {
  stack<int> stack_ = DEFAULT_STACK;
  stack<int> stack_copy(std::move(stack_));

  ASSERT_EQ(stack_copy.top(), 1);
  ASSERT_EQ(stack_.empty(), true);
  stack_.~stack();
  stack_copy.~stack();
}
TEST(stack, Destructor) {
  stack<int> stack_;

  stack_.~stack();
  ASSERT_EQ(stack_.empty(), true);
}
TEST(stack, Assigment) {
  stack<int> stack_ = DEFAULT_STACK;
  stack<int> stack_copy = stack_;

  ASSERT_EQ(stack_.size(), stack_copy.size());
  ASSERT_EQ(stack_.top(), stack_copy.top());
  stack_.~stack();
  stack_copy.~stack();
}
TEST(stack, Top) {
  stack<int> stack_ = DEFAULT_STACK;

  ASSERT_EQ(stack_.top(), 1);
  stack_.~stack();
}
TEST(stack, Empty) {
  stack<int> stack_;

  ASSERT_EQ(stack_.empty(), true);
  stack_.~stack();
}
TEST(stack, Size) {
  stack<int> stack_ = DEFAULT_STACK;

  ASSERT_EQ(stack_.size(), (stack<int>::size_type)3);
  stack_.~stack();
}
TEST(stack, Push) {
  stack<int> stack_ = DEFAULT_STACK;

  stack_.push(0);
  ASSERT_EQ(stack_.top(), 0);
  ASSERT_EQ(stack_.size(), (stack<int>::size_type)4);
  stack_.~stack();
}
TEST(stack, Pop) {
  stack<int> stack_ = DEFAULT_STACK;

  stack_.pop();
  ASSERT_EQ(stack_.top(), 2);
  ASSERT_EQ(stack_.size(), (stack<int>::size_type)2);
  stack_.~stack();
}
TEST(stack, Swap) {
  stack<int> stack_first = DEFAULT_STACK;
  stack<int> stack_second = {4, 5, 6};

  stack_first.swap(stack_second);
  ASSERT_EQ(stack_first.size(), (stack<int>::size_type)3);
  ASSERT_EQ(stack_second.size(), (stack<int>::size_type)3);
  ASSERT_EQ(stack_first.top(), 4);
  ASSERT_EQ(stack_second.top(), 1);
  stack_first.~stack();
  stack_second.~stack();
}
TEST(stack, InsertManyBack) {
  stack<int> stack_;

  stack_.insert_many_back(1, 2, 3);
  ASSERT_EQ(stack_.top(), 1);
  stack_.~stack();
}