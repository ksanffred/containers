#include "tests_entry.h"
#define DEFAULT_VECTOR {1, 2, 3}
#define DEFAULT_SIZE 3
using namespace s21;

TEST(VectorIterator, DefaultConstructor) {
  vector<int>::VectorIterator it;

  it.~VectorIterator();
}
TEST(VectorIterator, ParametrizedConstructor) {
  vector<int>::VectorIterator it(nullptr);

  ASSERT_EQ(it.ptr_, nullptr);
  it.~VectorIterator();
}
TEST(VectorIteratorOperators, Star) {
  vector<int> vector_(DEFAULT_VECTOR);
  vector<int>::VectorIterator it = vector_.begin();

  ASSERT_EQ(*it, 1);
  it.~VectorIterator();
  vector_.~vector();
}
TEST(VectorIteratorOperators, Preincrement) {
  vector<int> vector_(DEFAULT_VECTOR);
  vector<int>::VectorIterator it = vector_.begin();

  for (vector<int>::size_type i = 0; i < vector_.size(); i++) ++it;
  ASSERT_EQ(it, vector_.end());
  it.~VectorIterator();
  vector_.~vector();
}
TEST(VectorIteratorOperators, Predecrement) {
  vector<int> vector_(DEFAULT_VECTOR);
  vector<int>::VectorIterator it = vector_.end();

  for (vector<int>::size_type i = 0; i < vector_.size(); i++) --it;
  ASSERT_EQ(it, vector_.begin());
  it.~VectorIterator();
  vector_.~vector();
}
TEST(VectorIteratorOperators, Postincrement) {
  vector<int> vector_(DEFAULT_VECTOR);
  vector<int>::VectorIterator it = vector_.begin();

  for (vector<int>::size_type i = 0; i < vector_.size(); i++) it++;
  ASSERT_EQ(it, vector_.end());
  it.~VectorIterator();
  vector_.~vector();
}
TEST(VectorIteratorOperators, Postdecrement) {
  vector<int> vector_(DEFAULT_VECTOR);
  vector<int>::VectorIterator it = vector_.end();

  for (vector<int>::size_type i = 0; i < vector_.size(); i++) it--;
  ASSERT_EQ(it, vector_.begin());
  it.~VectorIterator();
  vector_.~vector();
}
TEST(VectorIteratorOperators, Equality) {
  vector<int> vector_(DEFAULT_VECTOR);
  vector<int>::VectorIterator it_first = vector_.begin();
  vector<int>::VectorIterator it_second = vector_.begin();

  ASSERT_EQ(it_first == it_second, true);
  it_first.~VectorIterator();
  it_second.~VectorIterator();
  vector_.~vector();
}
TEST(VectorIteratorOperators, NonEquality) {
  vector<int> vector_(DEFAULT_VECTOR);
  vector<int>::VectorIterator it_first = vector_.begin();
  vector<int>::VectorIterator it_second = vector_.end();

  ASSERT_EQ(it_first != it_second, true);
  it_first.~VectorIterator();
  it_second.~VectorIterator();
  vector_.~vector();
}
TEST(VectorIteratorOperators, PlusNumber) {
  vector<int> vector_(DEFAULT_VECTOR);
  vector<int>::VectorIterator it = vector_.begin();

  it = it + DEFAULT_SIZE;
  ASSERT_EQ(it, vector_.end());
  it.~VectorIterator();
  vector_.~vector();
}
TEST(VectorIteratorOperators, MinusNumber) {
  vector<int> vector_(DEFAULT_VECTOR);
  vector<int>::VectorIterator it = vector_.end();

  it = it - DEFAULT_SIZE;
  ASSERT_EQ(it, vector_.begin());
  it.~VectorIterator();
  vector_.~vector();
}
TEST(VectorIteratorOperators, Minus) {
  vector<int> vector_(DEFAULT_VECTOR);
  vector<int>::VectorIterator it_first = vector_.end();
  vector<int>::VectorIterator it_second = vector_.begin();

  ASSERT_EQ(it_first - it_second, DEFAULT_SIZE);
  vector_.~vector();
  it_first.~VectorIterator();
  it_second.~VectorIterator();
}
TEST(VectorConstIterator, DefaultConstructor) {
  vector<int>::VectorConstIterator it;

  it.~VectorConstIterator();
}
TEST(VectorConstIterator, ParametrizedConstructor) {
  vector<int>::VectorConstIterator it(nullptr);

  ASSERT_EQ(it.ptr_, nullptr);
  it.~VectorConstIterator();
}
TEST(VectorConstIterator, Star) {
  vector<int> vector_(DEFAULT_VECTOR);
  vector<int>::VectorConstIterator it = vector_.begin();

  ASSERT_EQ(*it, 1);
  it.~VectorConstIterator();
  vector_.~vector();
}
TEST(VectorConstIterator, Preincrement) {
  vector<int> vector_(DEFAULT_VECTOR);
  vector<int>::VectorConstIterator it = vector_.begin();

  for (vector<int>::size_type i = 0; i < vector_.size(); i++) ++it;
  ASSERT_EQ(it, vector_.end());
  it.~VectorConstIterator();
  vector_.~vector();
}
TEST(VectorConstIterator, Predecrement) {
  vector<int> vector_(DEFAULT_VECTOR);
  vector<int>::VectorConstIterator it = vector_.end();

  for (vector<int>::size_type i = 0; i < vector_.size(); i++) --it;
  ASSERT_EQ(it, vector_.begin());
  it.~VectorConstIterator();
  vector_.~vector();
}
TEST(VectorConstIterator, Postincrement) {
  vector<int> vector_(DEFAULT_VECTOR);
  vector<int>::VectorConstIterator it = vector_.begin();

  for (vector<int>::size_type i = 0; i < vector_.size(); i++) it++;
  ASSERT_EQ(it, vector_.end());
  it.~VectorConstIterator();
  vector_.~vector();
}
TEST(VectorConstIterator, Postdecrement) {
  vector<int> vector_(DEFAULT_VECTOR);
  vector<int>::VectorConstIterator it = vector_.end();

  for (vector<int>::size_type i = 0; i < vector_.size(); i++) it--;
  ASSERT_EQ(it, vector_.begin());
  it.~VectorConstIterator();
  vector_.~vector();
}
TEST(VectorConstIterator, Equality) {
  vector<int> vector_(DEFAULT_VECTOR);
  vector<int>::VectorConstIterator it_first = vector_.begin();
  vector<int>::VectorConstIterator it_second = vector_.begin();

  ASSERT_EQ(it_first == it_second, true);
  it_first.~VectorConstIterator();
  it_second.~VectorConstIterator();
  vector_.~vector();
}
TEST(VectorConstIterator, NonEquality) {
  vector<int> vector_(DEFAULT_VECTOR);
  vector<int>::VectorConstIterator it_first = vector_.begin();
  vector<int>::VectorConstIterator it_second = vector_.end();

  ASSERT_EQ(it_first != it_second, true);
  it_first.~VectorConstIterator();
  it_second.~VectorConstIterator();
  vector_.~vector();
}
TEST(VectorConstIterator, PlusNumber) {
  vector<int> vector_(DEFAULT_VECTOR);
  vector<int>::VectorConstIterator it = vector_.begin();

  it = it + DEFAULT_SIZE;
  ASSERT_EQ(it, vector_.end());
  it.~VectorConstIterator();
  vector_.~vector();
}
TEST(VectorConstIterator, MinusNumber) {
  vector<int> vector_(DEFAULT_VECTOR);
  vector<int>::VectorConstIterator it = vector_.end();

  it = it - DEFAULT_SIZE;
  ASSERT_EQ(it, vector_.begin());
  it.~VectorConstIterator();
  vector_.~vector();
}
TEST(VectorConstIterator, Minus) {
  vector<int> vector_(DEFAULT_VECTOR);
  vector<int>::VectorConstIterator it_first = vector_.end();
  vector<int>::VectorConstIterator it_second = vector_.begin();

  ASSERT_EQ(it_first - it_second, DEFAULT_SIZE);
  vector_.~vector();
  it_first.~VectorConstIterator();
  it_second.~VectorConstIterator();
}
TEST(vector, DefaultConstructor) {
  vector<int> vector_;

  ASSERT_EQ(vector_.empty(), true);
  vector_.~vector();
}
TEST(vector, ParametrizedConstructor) {
  vector<int> vector_(DEFAULT_SIZE);

  ASSERT_EQ(vector_.size(), (vector<int>::size_type)DEFAULT_SIZE);
  vector_.~vector();
}
TEST(vector, InitializerListConstructor) {
  vector<int> vector_(DEFAULT_VECTOR);

  ASSERT_EQ(vector_.front(), 1);
  ASSERT_EQ(vector_.back(), 3);
  vector_.~vector();
}
TEST(vector, CopyConstructor) {
  vector<int> vector_(DEFAULT_VECTOR);
  vector<int> vector_copy(vector_);

  ASSERT_EQ(vector_.front(), vector_copy.front());
  ASSERT_EQ(vector_.back(), vector_copy.back());
  vector_.~vector();
  vector_copy.~vector();
}
TEST(vector, MoveConstructor) {
  vector<int> vector_(DEFAULT_VECTOR);
  vector<int> vector_copy(std::move(vector_));

  ASSERT_EQ(vector_copy.front(), 1);
  ASSERT_EQ(vector_.empty(), true);
  vector_.~vector();
  vector_copy.~vector();
}
TEST(vector, Destructor) {
  vector<int> vector_;

  vector_.~vector();
  ASSERT_EQ(vector_.empty(), true);
}
TEST(vector, Assignment) {
  vector<int> vector_(DEFAULT_VECTOR);
  vector<int> vector_copy = vector_;

  ASSERT_EQ(vector_.size(), vector_copy.size());
  ASSERT_EQ(vector_.front(), vector_copy.front());
  ASSERT_EQ(vector_.back(), vector_copy.back());
  vector_.~vector();
  vector_copy.~vector();
}
TEST(vector, At) {
  vector<int> vector_(DEFAULT_VECTOR);

  ASSERT_EQ(vector_.at(0), 1);
  vector_.~vector();
}
TEST(vector, SquareBrackets) {
  vector<int> vector_(DEFAULT_VECTOR);

  ASSERT_EQ(vector_[DEFAULT_SIZE - 1], 3);
  vector_.~vector();
}
TEST(vector, Front) {
  vector<int> vector_(DEFAULT_VECTOR);

  ASSERT_EQ(vector_.front(), 1);
  vector_.~vector();
}
TEST(vector, Back) {
  vector<int> vector_(DEFAULT_VECTOR);

  ASSERT_EQ(vector_.back(), 3);
  vector_.~vector();
}
TEST(vector, Data) {
  vector<int> vector_;

  ASSERT_EQ(vector_.data(), nullptr);
  vector_.~vector();
}
TEST(vector, Begin) {
  vector<int> vector_(DEFAULT_VECTOR);
  vector<int>::iterator it = vector_.begin();

  ASSERT_EQ(*it, 1);
  it.~VectorIterator();
  vector_.~vector();
}
TEST(vector, End) {
  vector<int> vector_(DEFAULT_VECTOR);
  vector<int>::iterator it = vector_.end() - 1;

  ASSERT_EQ(*it, 3);
  it.~VectorIterator();
  vector_.~vector();
}
TEST(vector, Empty) {
  vector<int> vector_;

  ASSERT_EQ(vector_.empty(), true);
  vector_.~vector();
}
TEST(vector, Size) {
  vector<int> vector_(DEFAULT_SIZE);

  ASSERT_EQ(vector_.size(), (vector<int>::size_type)DEFAULT_SIZE);
  vector_.~vector();
}
TEST(vector, MaxSize) {
  vector<int> vector_(DEFAULT_SIZE);

  ASSERT_EQ(vector_.max_size(),
            std::numeric_limits<vector<int>::size_type>::max() / sizeof(int));
  vector_.~vector();
}
TEST(vector, Reserve) {
  vector<int> vector_;

  vector_.reserve(DEFAULT_SIZE);
  ASSERT_NE(vector_.data(), nullptr);
  ASSERT_EQ(vector_.capacity(), (vector<int>::size_type)DEFAULT_SIZE);
  vector_.~vector();
}
TEST(vector, Capacity) {
  vector<int> vector_(DEFAULT_VECTOR);

  ASSERT_EQ(vector_.capacity(), (vector<int>::size_type)DEFAULT_SIZE);
  vector_.~vector();
}
TEST(vector, ShrinkToFit) {
  vector<int> vector_(DEFAULT_SIZE);

  ASSERT_EQ(vector_.size(), (vector<int>::size_type)DEFAULT_SIZE);
  ASSERT_EQ(vector_.capacity(), (vector<int>::size_type)DEFAULT_SIZE);
  vector_.clear();
  vector_.shrink_to_fit();
  ASSERT_EQ(vector_.size(), (vector<int>::size_type)0);
  ASSERT_EQ(vector_.capacity(), (vector<int>::size_type)0);
  vector_.~vector();
}
TEST(vector, Clear) {
  vector<int> vector_(DEFAULT_SIZE);

  vector_.clear();
  ASSERT_EQ(vector_.size(), (vector<int>::size_type)0);
  vector_.~vector();
}
TEST(vector, Insert) {
  vector<int> vector_(DEFAULT_VECTOR);

  vector_.insert(vector_.begin(), 4);
  vector_.insert(vector_.end(), 5);
  ASSERT_EQ(vector_.size(), (vector<int>::size_type)(DEFAULT_SIZE + 2));
  ASSERT_EQ(vector_.front(), 4);
  ASSERT_EQ(vector_.back(), 5);
  vector_.~vector();
}
TEST(vector, Erase) {
  vector<int> vector_(DEFAULT_VECTOR);

  vector_.erase(vector_.begin());
  ASSERT_EQ(vector_.size(), (vector<int>::size_type)(DEFAULT_SIZE - 1));
  ASSERT_EQ(vector_.front(), 2);
  ASSERT_EQ(vector_.back(), 3);
  vector_.~vector();
}
TEST(vector, PushBack) {
  vector<int> vector_(DEFAULT_VECTOR);

  vector_.push_back(-1);
  ASSERT_EQ(vector_.back(), -1);
  ASSERT_EQ(vector_.size(), (vector<int>::size_type)(DEFAULT_SIZE + 1));
  vector_.~vector();
}
TEST(vector, PopBack) {
  vector<int> vector_(DEFAULT_VECTOR);

  vector_.pop_back();
  ASSERT_EQ(vector_.back(), 2);
  ASSERT_EQ(vector_.size(), (vector<int>::size_type)(DEFAULT_SIZE - 1));
  vector_.~vector();
}
TEST(vector, Swap) {
  vector<int> vector_first(DEFAULT_VECTOR);
  vector<int> vector_second({4, 5, 6});

  vector_first.swap(vector_second);
  ASSERT_EQ(vector_first.size(), vector_second.size());
  ASSERT_EQ(vector_first.front(), 4);
  ASSERT_EQ(vector_first.back(), 6);
  ASSERT_EQ(vector_second.front(), 1);
  ASSERT_EQ(vector_second.back(), 3);
  vector_first.~vector();
  vector_second.~vector();
}
TEST(vector, InsertMany) {
  vector<int> vector_ = DEFAULT_VECTOR;
  vector<int>::iterator it;

  vector_.insert_many(vector_.end(), 4, 5, 6);
  it = vector_.begin();
  ASSERT_EQ(vector_.size(), (vector<int>::size_type)(DEFAULT_SIZE * 2));
  ASSERT_EQ(*it++, 1);
  ASSERT_EQ(*it++, 2);
  ASSERT_EQ(*it++, 3);
  ASSERT_EQ(*it++, 4);
  ASSERT_EQ(*it++, 5);
  ASSERT_EQ(*it, 6);
  vector_.~vector();
  it.~VectorIterator();
}
TEST(vector, InsertManyBack) {
  vector<int> vector_ = DEFAULT_VECTOR;
  vector<int>::iterator it;

  vector_.insert_many_back(4, 5, 6);
  it = vector_.begin();
  ASSERT_EQ(vector_.size(), (vector<int>::size_type)(DEFAULT_SIZE * 2));
  ASSERT_EQ(*it++, 1);
  ASSERT_EQ(*it++, 2);
  ASSERT_EQ(*it++, 3);
  ASSERT_EQ(*it++, 4);
  ASSERT_EQ(*it++, 5);
  ASSERT_EQ(*it, 6);
  vector_.~vector();
  it.~VectorIterator();
}