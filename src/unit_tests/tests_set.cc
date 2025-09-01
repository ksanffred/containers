#include <set>

#include "tests_entry.h"

TEST(Set, Constructors_default) {
  my::set<int> first;
  EXPECT_TRUE(first.begin() == first.end());
  EXPECT_EQ(first.size(), (my::set<int>::size_type)0);
}
TEST(Set, Constructors_initializer_list_int) {
  my::set<int> first{2, 5, 21, 14, 5, 0};
  std::set<int> result{2, 5, 21, 14, 5, 0};
  auto iter_f = first.begin(), eiter_f = first.end();
  auto iter_r = result.begin(), eiter_r = result.end();
  for (; iter_f != eiter_f && iter_r != eiter_r; ++iter_f, ++iter_r) {
    EXPECT_EQ(*iter_f, *iter_r);
  }
}
TEST(Set, Constructors_initializer_list_string) {
  my::set<std::string> first{"hello", "apple", "hell", "apple", ""};
  std::set<std::string> result{"hello", "apple", "hell", "apple", ""};
  auto iter_f = first.begin(), eiter_f = first.end();
  auto iter_r = result.begin(), eiter_r = result.end();
  for (; iter_f != eiter_f && iter_r != eiter_r; ++iter_f, ++iter_r) {
    EXPECT_EQ(*iter_f, *iter_r);
  }
}
TEST(Set, Constructors_copy) {
  my::set<int> first{2, 5, 21, 14, 5, 0};
  my::set<int> second{first};
  std::set<int> result{2, 5, 21, 14, 5, 0};
  auto iter_f = first.begin(), eiter_f = first.end();
  auto iter_s = second.begin(), eiter_s = second.end();
  auto iter_r = result.begin(), eiter_r = result.end();
  for (; iter_f != eiter_f && iter_s != eiter_s && iter_r != eiter_r;
       ++iter_f, ++iter_s, ++iter_r) {
    EXPECT_EQ(*iter_f, *iter_s);
    EXPECT_EQ(*iter_s, *iter_r);
  }
  EXPECT_EQ(first.size(), second.size());
  EXPECT_EQ(result.size(), second.size());
}
TEST(Set, Constructors_move) {
  my::set<int> first{2, 5, 21, 14, 5, 0};
  my::set<int> second{std::move(first)};
  std::set<int> result{2, 5, 21, 14, 5, 0};
  auto iter_s = second.begin(), eiter_s = second.end();
  auto iter_r = result.begin(), eiter_r = result.end();
  for (; iter_s != eiter_s && iter_r != eiter_r; ++iter_s, ++iter_r) {
    EXPECT_EQ(*iter_s, *iter_r);
  }
  EXPECT_EQ(first.empty(), true);
  EXPECT_EQ(result.size(), second.size());
}
TEST(Set, Assignment_copy) {
  my::set<int> first{2, 5, 21, 14, 5, 0};
  my::set<int> second = first;
  std::set<int> result{2, 5, 21, 14, 5, 0};
  auto iter_f = first.begin(), eiter_f = first.end();
  auto iter_s = second.begin(), eiter_s = second.end();
  auto iter_r = result.begin(), eiter_r = result.end();
  for (; iter_f != eiter_f && iter_s != eiter_s && iter_r != eiter_r;
       ++iter_f, ++iter_s, ++iter_r) {
    EXPECT_EQ(*iter_f, *iter_s);
    EXPECT_EQ(*iter_s, *iter_r);
  }
  EXPECT_EQ(first.size(), second.size());
  EXPECT_EQ(result.size(), second.size());
}
TEST(Set, Assignment_move) {
  my::set<int> first{2, 5, 21, 14, 5, 0};
  my::set<int> second = std::move(first);
  std::set<int> result{2, 5, 21, 14, 5, 0};
  auto iter_s = second.begin(), eiter_s = second.end();
  auto iter_r = result.begin(), eiter_r = result.end();
  for (; iter_s != eiter_s && iter_r != eiter_r; ++iter_s, ++iter_r) {
    EXPECT_EQ(*iter_s, *iter_r);
  }
  EXPECT_EQ(first.empty(), true);
  EXPECT_EQ(result.size(), second.size());
}
TEST(Set, Iterator_begin) {
  my::set<int> first{2, 5, 21, 14, 5, 0};
  std::set<int> result{2, 5, 21, 14, 5, 0};
  auto iter_s = first.begin();
  auto iter_r = result.begin();
  EXPECT_EQ(*iter_s, *iter_r);
}
TEST(Set, Iterator_end) {
  my::set<int> first{2};
  auto iter_s = first.begin();
  EXPECT_TRUE(++iter_s == first.end());
}
TEST(Set, Size) {
  my::set<int> first{2, 4, 4, 5, 5};
  std::set<int> result{2, 4, 4, 5, 5};
  EXPECT_EQ(first.size(), result.size());
}
TEST(Set, Empty) {
  my::set<int> first;
  std::set<int> result;
  EXPECT_EQ(first.empty(), result.empty());
  first.insert(4);
  result.insert(4);
  EXPECT_EQ(first.empty(), result.empty());
}
TEST(Set, Max_size) {
  my::set<int> first{21, 5};
  auto before = first.max_size();
  first.insert(4);
  for (int i{0}; i != 100; ++i) first.insert(i);
  auto after = first.max_size();
  EXPECT_TRUE(before == after);
  EXPECT_TRUE(before > first.size());
}
TEST(Set, Insert_normal) {
  my::set<int> first{21, 5, 44};
  EXPECT_EQ(*(first.begin()), 5);
  EXPECT_EQ(first.size(), (my::set<int>::size_type)3);
  first.insert(0);
  EXPECT_EQ(*(first.begin()), 0);
  EXPECT_EQ(first.size(), (my::set<int>::size_type)4);
}
TEST(Set, Insert_hundred) {
  my::set<int> first_my{21, 5, 44};
  std::set<int> first_std{21, 5, 44};
  std::srand(std::time({}));
  for (int i{0}; i < 100; ++i) {
    const int num = std::rand() / 100;
    first_my.insert(num);
    first_std.insert(num);
  }
  auto iter_my = first_my.begin(), eiter_my = first_my.end();
  auto iter_std = first_std.begin(), eiter_std = first_std.end();
  for (; iter_my != eiter_my && iter_std != eiter_std;
       ++iter_my, ++iter_std) {
    EXPECT_EQ(*iter_my, *iter_std);
  }
  EXPECT_EQ(first_my.size(), first_std.size());
}
TEST(Set, Insert_existed) {
  my::set<int> first{21, 5, 44};
  EXPECT_EQ(*(first.begin()), 5);
  EXPECT_EQ(first.size(), (my::set<int>::size_type)3);
  first.insert(5);
  EXPECT_EQ(*(first.begin()), 5);
  EXPECT_EQ(first.size(), (my::set<int>::size_type)3);
}
TEST(Set, Erase) {
  my::set<int> first{21, 5, 44, 43, 100, 453, -1, 32};
  EXPECT_EQ(first.size(), (my::set<int>::size_type)8);
  first.erase(first.find(100));
  EXPECT_TRUE(first.find(100) == first.end());
  first.erase(first.find(44));
  EXPECT_TRUE(first.find(44) == first.end());
  first.erase(first.find(5));
  EXPECT_TRUE(first.find(5) == first.end());
  EXPECT_EQ(first.size(), (my::set<int>::size_type)5);
}
TEST(Set, Erase_end) {
  my::set<int> first{21, 5, 44};
  EXPECT_EQ(*(first.begin()), 5);
  EXPECT_EQ(first.size(), (my::set<int>::size_type)3);
  first.erase(first.end());
  EXPECT_EQ(*(first.begin()), 5);
  EXPECT_EQ(first.size(), (my::set<int>::size_type)3);
}
TEST(Set, Swap) {
  my::set<int> first{2, 5, 21, 14, 5, 0};
  my::set<int> second{5, 54, 15, 62};
  std::set<int> result{2, 5, 21, 14, 5, 0};
  first.swap(second);
  auto iter_s = second.begin(), eiter_s = second.end();
  auto iter_r = result.begin(), eiter_r = result.end();
  for (; iter_s != eiter_s && iter_r != eiter_r; ++iter_s, ++iter_r) {
    EXPECT_EQ(*iter_s, *iter_r);
  }
  EXPECT_EQ(result.size(), second.size());
}
TEST(Set, Merge) {
  my::set<int> first{2, 5, 21, 14, 5, 0};
  my::set<int> second{5, 54, 15, 62};
  std::set<int> first_std{2, 5, 21, 14, 5, 0};
  std::set<int> second_std{5, 54, 15, 62};
  first.merge(second);
  first_std.merge(second_std);
  auto iter_f = first.begin(), eiter_f = first.end();
  auto iter_r = first_std.begin(), eiter_r = first_std.end();
  for (; iter_f != eiter_f && iter_r != eiter_r; ++iter_f, ++iter_r) {
    EXPECT_EQ(*iter_f, *iter_r);
  }
  auto iter_s = second.begin(), eiter_s = second.end();
  auto iter_rs = second_std.begin(), eiter_rs = second_std.end();
  for (; iter_s != eiter_s && iter_rs != eiter_rs; ++iter_s, ++iter_rs) {
    EXPECT_EQ(*iter_s, *iter_rs);
  }
}
TEST(Set, Find) {
  my::set<int> first{21, 5, 44, 2, 1};
  auto it = first.begin();
  EXPECT_TRUE(it == first.find(1));
  EXPECT_TRUE(++it == first.find(2));
  EXPECT_TRUE(++it == first.find(5));
  EXPECT_TRUE(++it == first.find(21));
  EXPECT_TRUE(++it == first.find(44));
  EXPECT_TRUE(first.end() == first.find(101));
}
TEST(Set, Contains) {
  my::set<int> first{21, 5, 44, 2, 1};
  EXPECT_EQ(first.contains(21), true);
  EXPECT_EQ(first.contains(101), false);
}
TEST(Set, Insert_many) {
  my::set<int> first{2, 5, 21};
  std::set<int> result{2, 5, 21, 14, 5, 0};
  first.insert_many(0, 5, 14);
  auto iter_s = first.begin(), eiter_s = first.end();
  auto iter_r = result.begin(), eiter_r = result.end();
  for (; iter_s != eiter_s && iter_r != eiter_r; ++iter_s, ++iter_r) {
    EXPECT_EQ(*iter_s, *iter_r);
  }
  EXPECT_EQ(result.size(), first.size());
}
