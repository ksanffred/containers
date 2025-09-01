#include <map>

#include "tests_entry.h"

TEST(Map, Constructors_default) {
  my::map<int, std::string> first;
  EXPECT_TRUE(first.begin() == first.end());
  EXPECT_EQ(first.size(), (my::map<int, std::string>::size_type)0);
}
TEST(Map, Constructors_initializer_list_int) {
  my::map<int, std::string> first{{2, "school"},   {5, "twenty"}, {21, "one"},
                                   {14, "alpacas"}, {5, "let's"},  {0, "GO"}};
  std::map<int, std::string> result{{2, "school"},   {5, "twenty"}, {21, "one"},
                                    {14, "alpacas"}, {5, "let's"},  {0, "GO"}};
  auto iter_f = first.begin(), eiter_f = first.end();
  auto iter_r = result.begin(), eiter_r = result.end();
  for (; iter_f != eiter_f && iter_r != eiter_r; ++iter_f, ++iter_r) {
    EXPECT_EQ(iter_f->first, iter_r->first);
    EXPECT_EQ(iter_f->second, iter_r->second);
  }
}
TEST(Map, Constructors_initializer_list_string) {
  my::map<std::string, int> first{{"school", 2},   {"twenty", 5}, {"one", 21},
                                   {"alpacas", 14}, {"let's", 5},  {"GO", 0}};
  std::map<std::string, int> result{{"school", 2},   {"twenty", 5}, {"one", 21},
                                    {"alpacas", 14}, {"let's", 5},  {"GO", 0}};
  auto iter_f = first.begin(), eiter_f = first.end();
  auto iter_r = result.begin(), eiter_r = result.end();
  for (; iter_f != eiter_f && iter_r != eiter_r; ++iter_f, ++iter_r) {
    EXPECT_EQ(iter_f->first, iter_r->first);
    EXPECT_EQ(iter_f->second, iter_r->second);
  }
}
TEST(Map, Constructors_copy) {
  my::map<int, std::string> first{{2, "school"},   {5, "twenty"}, {21, "one"},
                                   {14, "alpacas"}, {5, "let's"},  {0, "GO"}};
  my::map<int, std::string> second{first};
  std::map<int, std::string> result{{2, "school"},   {5, "twenty"}, {21, "one"},
                                    {14, "alpacas"}, {5, "let's"},  {0, "GO"}};
  auto iter_f = first.begin(), eiter_f = first.end();
  auto iter_s = second.begin(), eiter_s = second.end();
  auto iter_r = result.begin(), eiter_r = result.end();
  for (; iter_f != eiter_f && iter_s != eiter_s && iter_r != eiter_r;
       ++iter_f, ++iter_s, ++iter_r) {
    EXPECT_EQ(iter_s->first, iter_r->first);
    EXPECT_EQ(iter_s->second, iter_r->second);
    EXPECT_EQ(iter_f->first, iter_s->first);
    EXPECT_EQ(iter_f->second, iter_s->second);
  }
  EXPECT_EQ(first.size(), second.size());
  EXPECT_EQ(result.size(), second.size());
}
TEST(Map, Constructors_move) {
  my::map<int, std::string> first{{2, "school"},   {5, "twenty"}, {21, "one"},
                                   {14, "alpacas"}, {5, "let's"},  {0, "GO"}};
  my::map<int, std::string> second{std::move(first)};
  std::map<int, std::string> result{{2, "school"},   {5, "twenty"}, {21, "one"},
                                    {14, "alpacas"}, {5, "let's"},  {0, "GO"}};
  auto iter_s = second.begin(), eiter_s = second.end();
  auto iter_r = result.begin(), eiter_r = result.end();
  for (; iter_s != eiter_s && iter_r != eiter_r; ++iter_s, ++iter_r) {
    EXPECT_EQ(iter_s->first, iter_r->first);
    EXPECT_EQ(iter_s->second, iter_r->second);
  }
  EXPECT_EQ(first.empty(), true);
  EXPECT_EQ(result.size(), second.size());
}
TEST(Map, Assignment_copy) {
  my::map<int, std::string> first{{2, "school"},   {5, "twenty"}, {21, "one"},
                                   {14, "alpacas"}, {5, "let's"},  {0, "GO"}};
  my::map<int, std::string> second = first;
  std::map<int, std::string> result{{2, "school"},   {5, "twenty"}, {21, "one"},
                                    {14, "alpacas"}, {5, "let's"},  {0, "GO"}};
  auto iter_f = first.begin(), eiter_f = first.end();
  auto iter_s = second.begin(), eiter_s = second.end();
  auto iter_r = result.begin(), eiter_r = result.end();
  for (; iter_f != eiter_f && iter_s != eiter_s && iter_r != eiter_r;
       ++iter_f, ++iter_s, ++iter_r) {
    EXPECT_EQ(iter_s->first, iter_r->first);
    EXPECT_EQ(iter_s->second, iter_r->second);
    EXPECT_EQ(iter_f->first, iter_s->first);
    EXPECT_EQ(iter_f->second, iter_s->second);
  }
  EXPECT_EQ(first.size(), second.size());
  EXPECT_EQ(result.size(), second.size());
}
TEST(Map, Assignment_move) {
  my::map<int, std::string> first{{2, "school"},   {5, "twenty"}, {21, "one"},
                                   {14, "alpacas"}, {5, "let's"},  {0, "GO"}};
  my::map<int, std::string> second = std::move(first);
  std::map<int, std::string> result{{2, "school"},   {5, "twenty"}, {21, "one"},
                                    {14, "alpacas"}, {5, "let's"},  {0, "GO"}};
  auto iter_s = second.begin(), eiter_s = second.end();
  auto iter_r = result.begin(), eiter_r = result.end();
  for (; iter_s != eiter_s && iter_r != eiter_r; ++iter_s, ++iter_r) {
    EXPECT_EQ(iter_s->first, iter_r->first);
    EXPECT_EQ(iter_s->second, iter_r->second);
  }
  EXPECT_EQ(first.empty(), true);
  EXPECT_EQ(result.size(), second.size());
}
TEST(Map, Iterator_begin) {
  my::map<int, std::string> first{{2, "school"},   {5, "twenty"}, {21, "one"},
                                   {14, "alpacas"}, {5, "let's"},  {0, "GO"}};
  std::map<int, std::string> result{{2, "school"},   {5, "twenty"}, {21, "one"},
                                    {14, "alpacas"}, {5, "let's"},  {0, "GO"}};
  auto iter_s = first.begin();
  auto iter_r = result.begin();
  EXPECT_EQ(iter_s->first, iter_r->first);
  EXPECT_EQ(iter_s->second, iter_r->second);
}
TEST(Map, Iterator_end) {
  my::map<int, std::string> first{{2, "school"}};
  auto iter_s = first.begin();
  EXPECT_TRUE(++iter_s == first.end());
}
TEST(Map, At) {
  my::map<int, std::string> first{{2, "school"},   {5, "twenty"}, {21, "one"},
                                   {14, "alpacas"}, {5, "let's"},  {0, "GO"}};
  EXPECT_EQ("school", first.at(2));
}
TEST(Map, Operator_square) {
  my::map<int, std::string> first{{2, "school"},   {5, "twenty"}, {21, "one"},
                                   {14, "alpacas"}, {5, "let's"},  {0, "GO"}};
  EXPECT_EQ(first[14], "");
  EXPECT_EQ(first.at(2), "school");
  first[2] = "SCHOOL";
  EXPECT_EQ(first.at(2), "SCHOOL");
  first[23] = "WRONG";
  EXPECT_EQ(first.at(23), "WRONG");
}
TEST(Map, Size) {
  my::map<int, std::string> first{{2, "school"},   {5, "twenty"}, {21, "one"},
                                   {21, "alpacas"}, {5, "let's"},  {0, "GO"}};
  std::map<int, std::string> result{{2, "school"},   {5, "twenty"}, {21, "one"},
                                    {21, "alpacas"}, {5, "let's"},  {0, "GO"}};
  EXPECT_EQ(first.size(), result.size());
}
TEST(Map, Empty) {
  my::map<int, std::string> first;
  std::map<int, std::string> result;
  EXPECT_EQ(first.empty(), result.empty());
  first.insert({2, "school"});
  result.insert({2, "school"});
  EXPECT_EQ(first.empty(), result.empty());
}
TEST(Map, Max_size) {
  my::map<int, std::string> first{{5, "twenty"}, {21, "one"}};
  auto before = first.max_size();
  first.insert({2, "school"});
  for (int i{0}; i != 100; ++i) first.insert({i, "loop"});
  auto after = first.max_size();
  EXPECT_TRUE(before == after);
  EXPECT_TRUE(before > first.size());
}
TEST(Map, Clear) {
  my::map<int, std::string> first{{2, "school"},   {5, "twenty"}, {21, "one"},
                                   {14, "alpacas"}, {5, "let's"},  {0, "GO"}};
  EXPECT_EQ(first.at(2), "school");
  EXPECT_EQ(first.size(), (my::map<int, std::string>::size_type)5);
  first.clear();
  EXPECT_TRUE(first.find(2) == first.end());
  EXPECT_EQ(first.size(), (my::map<int, std::string>::size_type)0);
}
TEST(Map, Insert_normal) {
  my::map<int, std::string> first{{2, "school"}, {5, "twenty"}, {21, "one"}};
  EXPECT_EQ(first.begin()->first, 2);
  EXPECT_EQ(first.begin()->second, "school");
  EXPECT_EQ(first.size(), (my::map<int, std::string>::size_type)3);
  first.insert({0, "GO"});
  EXPECT_EQ(first.begin()->first, 0);
  EXPECT_EQ(first.begin()->second, "GO");
  EXPECT_EQ(first.size(), (my::map<int, std::string>::size_type)4);
}
TEST(Map, Insert_existed) {
  my::map<int, std::string> first{{2, "school"}, {5, "twenty"}, {21, "one"}};
  EXPECT_EQ(first.begin()->first, 2);
  EXPECT_EQ(first.begin()->second, "school");
  EXPECT_EQ(first.size(), (my::map<int, std::string>::size_type)3);
  first.insert({21, "one"});
  EXPECT_EQ(first.begin()->first, 2);
  EXPECT_EQ(first.begin()->second, "school");
  EXPECT_EQ(first.size(), (my::map<int, std::string>::size_type)3);
}
TEST(Map, Insert_separately) {
  my::map<int, std::string> first{{2, "school"}, {5, "twenty"}, {21, "one"}};
  EXPECT_EQ(first.begin()->first, 2);
  EXPECT_EQ(first.begin()->second, "school");
  EXPECT_EQ(first.size(), (my::map<int, std::string>::size_type)3);
  first.insert(0, "GO");
  EXPECT_EQ(first.begin()->first, 0);
  EXPECT_EQ(first.begin()->second, "GO");
  EXPECT_EQ(first.size(), (my::map<int, std::string>::size_type)4);
}
TEST(Map, Insert_or_assign) {
  my::map<int, std::string> first{{2, "school"}, {5, "twenty"}, {21, "one"}};
  EXPECT_EQ(first.begin()->first, 2);
  EXPECT_EQ(first.begin()->second, "school");
  EXPECT_EQ(first.size(), (my::map<int, std::string>::size_type)3);
  first.insert_or_assign(2, "SCHOOL");
  EXPECT_EQ(first.begin()->first, 2);
  EXPECT_EQ(first.begin()->second, "SCHOOL");
  EXPECT_EQ(first.size(), (my::map<int, std::string>::size_type)3);
  first.insert_or_assign(0, "GO");
  EXPECT_EQ(first.begin()->first, 0);
  EXPECT_EQ(first.begin()->second, "GO");
  EXPECT_EQ(first.size(), (my::map<int, std::string>::size_type)4);
}
TEST(Map, Erase) {
  my::map<int, std::string> first{{2, "school"}, {5, "twenty"}, {21, "one"}};
  EXPECT_EQ(first.begin()->first, 2);
  EXPECT_EQ(first.begin()->second, "school");
  EXPECT_EQ(first.size(), (my::map<int, std::string>::size_type)3);
  first.erase(first.begin());
  EXPECT_EQ(first.begin()->first, 5);
  EXPECT_EQ(first.begin()->second, "twenty");
  EXPECT_EQ(first.size(), (my::map<int, std::string>::size_type)2);
}
TEST(Map, Erase_end) {
  my::map<int, std::string> first{{2, "school"}, {5, "twenty"}, {21, "one"}};
  EXPECT_EQ(first.begin()->first, 2);
  EXPECT_EQ(first.begin()->second, "school");
  EXPECT_EQ(first.size(), (my::map<int, std::string>::size_type)3);
  first.erase(first.end());
  EXPECT_EQ(first.begin()->first, 2);
  EXPECT_EQ(first.begin()->second, "school");
  EXPECT_EQ(first.size(), (my::map<int, std::string>::size_type)3);
}
TEST(Map, Swap) {
  my::map<int, std::string> first{{2, "school"},   {5, "twenty"}, {21, "one"},
                                   {14, "alpacas"}, {5, "let's"},  {0, "GO"}};
  my::map<int, std::string> second{
      {5, "blade"}, {55, "runner"}, {83, "jerry"}, {44, "perenchio"}};
  std::map<int, std::string> result{{2, "school"},   {5, "twenty"}, {21, "one"},
                                    {14, "alpacas"}, {5, "let's"},  {0, "GO"}};
  first.swap(second);
  auto iter_s = second.begin(), eiter_s = second.end();
  auto iter_r = result.begin(), eiter_r = result.end();
  for (; iter_s != eiter_s && iter_r != eiter_r; ++iter_s, ++iter_r) {
    EXPECT_EQ(iter_s->first, iter_r->first);
    EXPECT_EQ(iter_s->second, iter_r->second);
  }
  EXPECT_EQ(result.size(), second.size());
}
TEST(Map, Merge) {
  my::map<int, std::string> first{{2, "school"},   {5, "twenty"}, {21, "one"},
                                   {14, "alpacas"}, {5, "let's"},  {0, "GO"}};
  my::map<int, std::string> second{
      {5, "blade"}, {55, "runner"}, {83, "jerry"}, {44, "perenchio"}};
  std::map<int, std::string> first_std{{2, "school"}, {5, "twenty"},
                                       {21, "one"},   {14, "alpacas"},
                                       {5, "let's"},  {0, "GO"}};
  std::map<int, std::string> second_std{
      {5, "blade"}, {55, "runner"}, {83, "jerry"}, {44, "perenchio"}};
  first.merge(second);
  first_std.merge(second_std);
  auto iter_f = first.begin(), eiter_f = first.end();
  auto iter_r = first_std.begin(), eiter_r = first_std.end();
  for (; iter_f != eiter_f && iter_r != eiter_r; ++iter_f, ++iter_r) {
    EXPECT_EQ(iter_f->first, iter_r->first);
    EXPECT_EQ(iter_f->second, iter_r->second);
  }
  auto iter_s = second.begin(), eiter_s = second.end();
  auto iter_rs = second_std.begin(), eiter_rs = second_std.end();
  for (; iter_s != eiter_s && iter_rs != eiter_rs; ++iter_s, ++iter_rs) {
    EXPECT_EQ(iter_s->first, iter_rs->first);
    EXPECT_EQ(iter_s->second, iter_rs->second);
  }
}
TEST(Map, Find) {
  my::map<int, std::string> first{{2, "school"},   {5, "twenty"}, {21, "one"},
                                   {14, "alpacas"}, {5, "let's"},  {0, "GO"}};
  auto it = first.begin();
  EXPECT_TRUE(it == first.find(0));
  EXPECT_TRUE(++it == first.find(2));
  EXPECT_TRUE(++it == first.find(5));
  EXPECT_TRUE(++it == first.find(14));
  EXPECT_TRUE(++it == first.find(21));
  EXPECT_TRUE(first.end() == first.find(101));
}
TEST(Map, Contains) {
  my::map<int, std::string> first{{2, "school"},   {5, "twenty"}, {21, "one"},
                                   {14, "alpacas"}, {5, "let's"},  {0, "GO"}};
  EXPECT_EQ(first.contains(21), true);
  EXPECT_EQ(first.contains(101), false);
}
TEST(Map, Insert_many) {
  my::map<int, std::string> first{{2, "school"}, {5, "twenty"}, {21, "one"}};
  std::map<int, std::string> result{{2, "school"},   {5, "twenty"}, {21, "one"},
                                    {14, "alpacas"}, {5, "let's"},  {0, "GO"}};
  first.insert_many(std::pair{14, "alpacas"}, std::pair{5, "let's"},
                    std::pair{0, "GO"});
  auto iter_s = first.begin(), eiter_s = first.end();
  auto iter_r = result.begin(), eiter_r = result.end();
  for (; iter_s != eiter_s && iter_r != eiter_r; ++iter_s, ++iter_r) {
    EXPECT_EQ(iter_s->first, iter_r->first);
    EXPECT_EQ(iter_s->second, iter_r->second);
  }
  EXPECT_EQ(result.size(), first.size());
}
