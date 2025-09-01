#include "tests_entry.h"
#define DEFAULT_ARRAY {1, 2, 3}
#define DEFAULT_SIZE 3
using namespace my;

TEST(array, DefaultConstructor) {
  array<int, 0> array_;

  ASSERT_EQ(array_.empty(), true);
  array_.~array();
}
TEST(array, InitializerListConstructor) {
  array<int, DEFAULT_SIZE> array_(DEFAULT_ARRAY);

  ASSERT_EQ(array_.front(), 1);
  ASSERT_EQ(array_.back(), 3);
  array_.~array();
}
TEST(array, CopyConstructor) {
  array<int, DEFAULT_SIZE> array_(DEFAULT_ARRAY);
  array<int, DEFAULT_SIZE> array_copy(array_);

  ASSERT_EQ(array_.front(), array_copy.front());
  ASSERT_EQ(array_.back(), array_copy.back());
  array_.~array();
  array_copy.~array();
}
TEST(array, MoveConstructor) {
  array<int, DEFAULT_SIZE> array_(DEFAULT_ARRAY);
  array<int, DEFAULT_SIZE> array_copy(std::move(array_));

  ASSERT_EQ(array_copy.front(), 1);
  array_.~array();
  array_copy.~array();
}
TEST(array, Destructor) {
  array<int, DEFAULT_SIZE> array_;

  array_.~array();
}
TEST(array, Assigment) {
  array<int, DEFAULT_SIZE> array_(DEFAULT_ARRAY);
  array<int, DEFAULT_SIZE> array_copy = array_;

  ASSERT_EQ(array_.size(), array_copy.size());
  ASSERT_EQ(array_.front(), array_copy.front());
  ASSERT_EQ(array_.back(), array_copy.back());
  array_.~array();
  array_copy.~array();
}
TEST(array, At) {
  array<int, DEFAULT_SIZE> array_(DEFAULT_ARRAY);

  ASSERT_EQ(array_.at(0), 1);
  array_.~array();
}
TEST(array, SquareBrackets) {
  array<int, DEFAULT_SIZE> array_(DEFAULT_ARRAY);

  ASSERT_EQ(array_[DEFAULT_SIZE - 1], 3);
  array_.~array();
}
TEST(array, Front) {
  array<int, DEFAULT_SIZE> array_(DEFAULT_ARRAY);

  ASSERT_EQ(array_.front(), 1);
  array_.~array();
}
TEST(array, Back) {
  array<int, DEFAULT_SIZE> array_(DEFAULT_ARRAY);

  ASSERT_EQ(array_.back(), 3);
  array_.~array();
}
TEST(array, Data) {
  array<int, DEFAULT_SIZE> array_;

  ASSERT_NE(array_.data(), nullptr);
  array_.~array();
}
TEST(array, Begin) {
  array<int, DEFAULT_SIZE> array_(DEFAULT_ARRAY);
  array<int, DEFAULT_SIZE>::iterator it = array_.begin();

  ASSERT_EQ(*it, 1);
  array_.~array();
}
TEST(array, End) {
  array<int, DEFAULT_SIZE> array_(DEFAULT_ARRAY);
  array<int, DEFAULT_SIZE>::iterator it = array_.end() - 1;

  ASSERT_EQ(*it, 3);
  array_.~array();
}
TEST(array, Empty) {
  array<int, 0> array_;

  ASSERT_EQ(array_.empty(), true);
  array_.~array();
}
TEST(array, Size) {
  array<int, DEFAULT_SIZE> array_(DEFAULT_ARRAY);

  ASSERT_EQ(array_.size(), (array<int, DEFAULT_SIZE>::size_type)DEFAULT_SIZE);
  array_.~array();
}
TEST(array, MaxSize) {
  array<int, DEFAULT_SIZE> array_(DEFAULT_ARRAY);

  ASSERT_EQ(array_.max_size(),
            std::numeric_limits<std::size_t>::max() / sizeof(int));
  array_.~array();
}
TEST(array, Swap) {
  array<int, DEFAULT_SIZE> array_first(DEFAULT_ARRAY);
  array<int, DEFAULT_SIZE> array_second({4, 5, 6});

  array_first.swap(array_second);
  ASSERT_EQ(array_first.size(), array_second.size());
  ASSERT_EQ(array_first.front(), 4);
  ASSERT_EQ(array_first.back(), 6);
  ASSERT_EQ(array_second.front(), 1);
  ASSERT_EQ(array_second.back(), 3);
  array_first.~array();
  array_second.~array();
}
TEST(array, Fill) {
  array<int, DEFAULT_SIZE> array_;

  array_.fill(0);
  ASSERT_EQ(array_[0], 0);
  ASSERT_EQ(array_[1], 0);
  ASSERT_EQ(array_[2], 0);
  array_.~array();
}