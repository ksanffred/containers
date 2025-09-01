#include <set>

#include "tests_entry.h"

TEST(Multimultiset, Constructors_default) {
  my::multiset<int> first;
  EXPECT_TRUE(first.begin() == first.end());
  EXPECT_EQ(first.size(), (my::multiset<int>::size_type)0);
}
TEST(Multimultiset, Constructors_initializer_list_int) {
  my::multiset<int> first{2, 5, 21, 14, 5, 0};
  std::multiset<int> result{2, 5, 21, 14, 5, 0};
  auto iter_f = first.begin(), eiter_f = first.end();
  auto iter_r = result.begin(), eiter_r = result.end();
  for (; iter_f != eiter_f && iter_r != eiter_r; ++iter_f, ++iter_r) {
    EXPECT_EQ(*iter_f, *iter_r);
  }
}
TEST(Multimultiset, Constructors_initializer_list_string) {
  my::multiset<std::string> first{"hello", "apple", "hell", "apple", ""};
  std::multiset<std::string> result{"hello", "apple", "hell", "apple", ""};
  auto iter_f = first.begin(), eiter_f = first.end();
  auto iter_r = result.begin(), eiter_r = result.end();
  for (; iter_f != eiter_f && iter_r != eiter_r; ++iter_f, ++iter_r) {
    EXPECT_EQ(*iter_f, *iter_r);
  }
}
TEST(Multimultiset, Constructors_copy) {
  my::multiset<int> first{2, 5, 21, 14, 5, 0};
  my::multiset<int> second{first};
  std::multiset<int> result{2, 5, 21, 14, 5, 0};
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
TEST(Multimultiset, Constructors_move) {
  my::multiset<int> first{2, 5, 21, 14, 5, 0};
  my::multiset<int> second{std::move(first)};
  std::multiset<int> result{2, 5, 21, 14, 5, 0};
  auto iter_s = second.begin(), eiter_s = second.end();
  auto iter_r = result.begin(), eiter_r = result.end();
  for (; iter_s != eiter_s && iter_r != eiter_r; ++iter_s, ++iter_r) {
    EXPECT_EQ(*iter_s, *iter_r);
  }
  EXPECT_EQ(first.empty(), true);
  EXPECT_EQ(result.size(), second.size());
}
TEST(Multimultiset, Assignment_copy) {
  my::multiset<int> first{2, 5, 21, 14, 5, 0};
  my::multiset<int> second = first;
  std::multiset<int> result{2, 5, 21, 14, 5, 0};
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
TEST(Multimultiset, Assignment_move) {
  my::multiset<int> first{2, 5, 21, 14, 5, 0};
  my::multiset<int> second = std::move(first);
  std::multiset<int> result{2, 5, 21, 14, 5, 0};
  auto iter_s = second.begin(), eiter_s = second.end();
  auto iter_r = result.begin(), eiter_r = result.end();
  for (; iter_s != eiter_s && iter_r != eiter_r; ++iter_s, ++iter_r) {
    EXPECT_EQ(*iter_s, *iter_r);
  }
  EXPECT_EQ(first.empty(), true);
  EXPECT_EQ(result.size(), second.size());
}
TEST(Multimultiset, Iterator_begin) {
  my::multiset<int> first{2, 5, 21, 14, 5, 0};
  std::multiset<int> result{2, 5, 21, 14, 5, 0};
  auto iter_s = first.begin();
  auto iter_r = result.begin();
  EXPECT_EQ(*iter_s, *iter_r);
}
TEST(Multimultiset, Iterator_end) {
  my::multiset<int> first{2};
  auto iter_s = first.begin();
  EXPECT_TRUE(++iter_s == first.end());
}
TEST(Multimultiset, Size) {
  my::multiset<int> first{2, 4, 4, 5, 5};
  std::multiset<int> result{2, 4, 4, 5, 5};
  EXPECT_EQ(first.size(), result.size());
}
TEST(Multimultiset, Empty) {
  my::multiset<int> first;
  std::multiset<int> result;
  EXPECT_EQ(first.empty(), result.empty());
  first.insert(4);
  result.insert(4);
  EXPECT_EQ(first.empty(), result.empty());
}
TEST(Multimultiset, Max_size) {
  my::multiset<int> first{21, 5};
  auto before = first.max_size();
  first.insert(4);
  for (int i{0}; i != 100; ++i) first.insert(i);
  auto after = first.max_size();
  EXPECT_TRUE(before == after);
  EXPECT_TRUE(before > first.size());
}
TEST(Multimultiset, Insert_normal) {
  my::multiset<int> first{21, 5, 44};
  EXPECT_EQ(*(first.begin()), 5);
  EXPECT_EQ(first.size(), (my::multiset<int>::size_type)3);
  first.insert(0);
  EXPECT_EQ(*(first.begin()), 0);
  EXPECT_EQ(first.size(), (my::multiset<int>::size_type)4);
}
TEST(Multimultiset, Insert_hundred) {
  my::multiset<int> first_my{21, 5, 44};
  std::multiset<int> first_std{21, 5, 44};
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
TEST(Multimultiset, Insert_existed) {
  my::multiset<int> first{21, 5, 44};
  EXPECT_EQ(*(first.begin()), 5);
  EXPECT_EQ(first.size(), (my::multiset<int>::size_type)3);
  first.insert(5);
  EXPECT_EQ(*(first.begin()), 5);
  EXPECT_EQ(first.size(), (my::multiset<int>::size_type)4);
}
TEST(Multimultiset, Erase) {
  my::multiset<int> first{21, 5, 44};
  EXPECT_EQ(*(first.begin()), 5);
  EXPECT_EQ(first.size(), (my::multiset<int>::size_type)3);
  first.erase(first.begin());
  EXPECT_EQ(*(first.begin()), 21);
  EXPECT_EQ(first.size(), (my::multiset<int>::size_type)2);
}
TEST(Multimultiset, Erase_end) {
  my::multiset<int> first{21, 5, 44};
  EXPECT_EQ(*(first.begin()), 5);
  EXPECT_EQ(first.size(), (my::multiset<int>::size_type)3);
  first.erase(first.end());
  EXPECT_EQ(*(first.begin()), 5);
  EXPECT_EQ(first.size(), (my::multiset<int>::size_type)3);
}
TEST(Multimultiset, Swap) {
  my::multiset<int> first{2, 5, 21, 14, 5, 0};
  my::multiset<int> second{5, 54, 15, 62};
  std::multiset<int> result{2, 5, 21, 14, 5, 0};
  first.swap(second);
  auto iter_s = second.begin(), eiter_s = second.end();
  auto iter_r = result.begin(), eiter_r = result.end();
  for (; iter_s != eiter_s && iter_r != eiter_r; ++iter_s, ++iter_r) {
    EXPECT_EQ(*iter_s, *iter_r);
  }
  EXPECT_EQ(result.size(), second.size());
}
TEST(Multimultiset, Merge) {
  my::multiset<int> first{2, 5, 21, 14, 5, 0};
  my::multiset<int> second{5, 54, 15, 62};
  std::multiset<int> first_std{2, 5, 21, 14, 5, 0};
  std::multiset<int> second_std{5, 54, 15, 62};
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
TEST(Multimultiset, Count) {
  my::multiset<int> first{21, 5, 44, 2, 1, 5, 23, 5};
  EXPECT_EQ(first.count(21), (my::multiset<int>::size_type)1);
  EXPECT_EQ(first.count(5), (my::multiset<int>::size_type)3);
  EXPECT_EQ(first.count(404), (my::multiset<int>::size_type)0);
}
TEST(Multimultiset, Equal_range) {
  my::multiset<int> first{21, 5, 44, 2, 1, 5, 23, 5};
  auto iters = first.equal_range(5);
  int num = 0;
  for (auto it = iters.first; it != iters.second; ++it) {
    EXPECT_EQ(*it, 5);
    ++num;
  };
  EXPECT_EQ(first.count(5), (my::multiset<int>::size_type)num);
  auto iters_2 = first.equal_range(21);
  int num_2 = 0;
  for (auto it = iters_2.first; it != iters_2.second; ++it) {
    EXPECT_EQ(*it, 21);
    ++num_2;
  };
  EXPECT_EQ(first.count(21), (my::multiset<int>::size_type)num_2);
}
TEST(Multimultiset, Lower_bound) {
  my::multiset<int> first{21, 5, 44, 2, 1, 5, 23, 5};
  auto it = first.lower_bound(5);
  EXPECT_EQ(*it, 5);
  EXPECT_EQ(*(++it), 5);
}
TEST(Multimultiset, Upper_bound) {
  my::multiset<int> first{21, 5, 44, 2, 1, 5, 23, 5};
  auto it = first.lower_bound(21);
  EXPECT_EQ(*it, 21);
  EXPECT_TRUE(++it == first.upper_bound(21));
}
TEST(Multimultiset, Find) {
  my::multiset<int> first{21, 5, 44, 2, 1};
  auto it = first.begin();
  EXPECT_TRUE(it == first.find(1));
  EXPECT_TRUE(++it == first.find(2));
  EXPECT_TRUE(++it == first.find(5));
  EXPECT_TRUE(++it == first.find(21));
  EXPECT_TRUE(++it == first.find(44));
  EXPECT_TRUE(first.end() == first.find(101));
}
TEST(Multimultiset, Contains) {
  my::multiset<int> first{21, 5, 44, 2, 1};
  EXPECT_EQ(first.contains(21), true);
  EXPECT_EQ(first.contains(101), false);
}
TEST(Multimultiset, Insert_many) {
  my::multiset<int> first{2, 5, 21};
  std::multiset<int> result{2, 5, 21, 14, 5, 0};
  first.insert_many(0, 5, 14);
  auto iter_s = first.begin(), eiter_s = first.end();
  auto iter_r = result.begin(), eiter_r = result.end();
  for (; iter_s != eiter_s && iter_r != eiter_r; ++iter_s, ++iter_r) {
    EXPECT_EQ(*iter_s, *iter_r);
  }
  EXPECT_EQ(result.size(), first.size());
}
