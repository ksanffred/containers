namespace s21 {
template <class T>
deque<T>::deque() : size_(0), head_(nullptr), tail_(nullptr) {}
template <class T>
deque<T>::deque(std::initializer_list<value_type> const &items) : deque() {
  for (auto i = items.begin(); i != items.end(); i++) push_back(*i);
}
template <class T>
deque<T>::deque(const deque &other) : deque() {
  Node<T> *current = other.head_;

  while (current) {
    push_back(current->value);
    current = current->next;
  }
}
template <class T>
deque<T>::deque(deque &&other)
    : size_(other.size_), head_(other.head_), tail_(other.tail_) {
  other.size_ = 0;
  other.head_ = nullptr;
  other.tail_ = nullptr;
}
template <class T>
deque<T>::~deque() {
  clear();
}
template <class T>
deque<T> &deque<T>::operator=(deque &&other) {
  if (this != &other) {
    clear();
    size_ = other.size_;
    head_ = other.head_;
    tail_ = other.tail_;
    other.size_ = 0;
    other.head_ = nullptr;
    other.tail_ = nullptr;
  }
  return *this;
}
template <class T>
typename deque<T>::const_reference deque<T>::front() const {
  return head_->value;
}
template <class T>
typename deque<T>::const_reference deque<T>::back() const {
  return tail_->value;
}
template <class T>
bool deque<T>::empty() const {
  return head_ == nullptr;
}
template <class T>
typename deque<T>::size_type deque<T>::size() const {
  return size_;
}
template <class T>
void deque<T>::clear() {
  while (!empty()) {
    pop_front();
  }
}
template <class T>
void deque<T>::push_back(const_reference value) {
  Node<value_type> *node = new Node<value_type>(value);

  node->prev = tail_;
  node->next = nullptr;
  if (tail_) tail_->next = node;
  tail_ = node;
  if (head_ == nullptr) head_ = node;
  size_++;
}
template <class T>
void deque<T>::pop_back() {
  if (tail_) {
    Node<value_type> *node = tail_;

    tail_ = tail_->prev;
    if (tail_)
      tail_->next = nullptr;
    else
      head_ = nullptr;
    delete node;
    size_--;
  }
}
template <class T>
void deque<T>::push_front(const_reference value) {
  Node<value_type> *node = new Node<value_type>(value);

  node->next = head_;
  node->prev = nullptr;
  if (head_) head_->prev = node;
  head_ = node;
  if (tail_ == nullptr) tail_ = node;
  size_++;
}
template <class T>
void deque<T>::pop_front() {
  if (head_) {
    Node<value_type> *node = head_;

    head_ = head_->next;
    if (head_)
      head_->prev = nullptr;
    else
      tail_ = nullptr;
    delete node;
    size_--;
  }
}
template <class T>
void deque<T>::swap(deque &other) {
  std::swap(size_, other.size_);
  std::swap(head_, other.head_);
  std::swap(tail_, other.tail_);
}
}  // namespace s21