namespace s21 {
template <class T>
Node<T>::Node(value_type val, Node<value_type> *next_node,
              Node<value_type> *prev_node)
    : value(val), next(next_node), prev(prev_node) {}
template <class T>
Node<T> *getMiddle(Node<T> *head) {
  Node<T> *slow = head;
  Node<T> *fast = head;

  while (fast && fast->next && fast->next->next) {
    fast = fast->next->next;
    slow = slow->next;
  }
  return slow;
}
template <class T>
Node<T> *mergeNodes(Node<T> *left, Node<T> *right) {
  Node<T> *result = nullptr;

  if (left == nullptr)
    result = right;
  else if (right == nullptr)
    result = left;
  else if (left->value < right->value) {
    result = left;
    result->next = mergeNodes(left->next, right);
  } else {
    result = right;
    result->next = mergeNodes(left, right->next);
  }
  return result;
}
template <class T>
Node<T> *mergeSort(Node<T> *head) {
  Node<T> *result = head;

  if (head && head->next) {
    Node<T> *middle = getMiddle(head);
    Node<T> *nextOfMiddle = middle->next;
    if (nextOfMiddle) {
      nextOfMiddle->prev = nullptr;
      middle->next = nullptr;
    }
    result = mergeNodes(mergeSort(head), mergeSort(nextOfMiddle));
  }
  return result;
}
}  // namespace s21