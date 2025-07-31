#include "tests_entry.h"
using namespace s21;

TEST(node, DefaultConstructor) {
  Node<int> node;

  ASSERT_EQ(node.value, 0);
  ASSERT_EQ(node.next, nullptr);
  ASSERT_EQ(node.prev, nullptr);
  node.~Node();
}
TEST(node, ParametrizedConstructor) {
  Node<int> node(5, nullptr, nullptr);

  ASSERT_EQ(node.value, 5);
  ASSERT_EQ(node.next, nullptr);
  ASSERT_EQ(node.prev, nullptr);
  node.~Node();
}
TEST(node, GetMiddle) {
  Node<int> head(0, nullptr, nullptr);
  Node<int> middle(1, nullptr, nullptr);
  Node<int> tail(2, nullptr, nullptr);

  head.next = &middle;
  middle.prev = &head;
  middle.next = &tail;
  tail.prev = &middle;

  Node<int> result = *getMiddle(&head);

  ASSERT_EQ(result.value, middle.value);
  ASSERT_EQ(result.next, middle.next);
  ASSERT_EQ(result.prev, middle.prev);
  head.~Node();
  middle.~Node();
  tail.~Node();
  result.~Node();
}
TEST(node, MergeNodes) {
  Node<int> head(0, nullptr, nullptr);
  Node<int> middle_left(3, nullptr, nullptr);
  Node<int> middle_right(1, nullptr, nullptr);
  Node<int> tail(2, nullptr, nullptr);

  head.next = &middle_left;
  middle_left.prev = &head;
  middle_right.next = &tail;
  tail.prev = &middle_right;
  head = *mergeNodes(&head, &middle_right);
  ASSERT_EQ(head.value, 0);
  ASSERT_EQ(head.next->value, 1);
  ASSERT_EQ(head.next->next->value, 2);
  ASSERT_EQ(head.next->next->next->value, 3);
  head.~Node();
  middle_left.~Node();
  middle_right.~Node();
  tail.~Node();
}
TEST(node, MergeSort) {
  Node<int> head(3, nullptr, nullptr);
  Node<int> middle_left(1, nullptr, nullptr);
  Node<int> middle_right(2, nullptr, nullptr);
  Node<int> tail(0, nullptr, nullptr);
  Node<int> result;

  head.next = &tail;
  tail.prev = &head;
  result = *mergeSort(&head);
  ASSERT_EQ(result.value, 0);
  ASSERT_EQ(result.next->value, 3);
  head.~Node();
  tail.~Node();
  result.~Node();

  head = Node<int>(3, nullptr, nullptr);
  tail = Node<int>(0, nullptr, nullptr);
  head.next = &middle_left;
  middle_left.prev = &head;
  middle_left.next = &middle_right;
  middle_right.prev = &middle_left;
  middle_right.next = &tail;
  tail.prev = &middle_right;
  result = *mergeSort(&head);
  ASSERT_EQ(result.value, 0);
  ASSERT_EQ(result.next->value, 1);
  ASSERT_EQ(result.next->next->value, 2);
  ASSERT_EQ(result.next->next->next->value, 3);
  head.~Node();
  middle_left.~Node();
  middle_right.~Node();
  tail.~Node();
  result.~Node();
}