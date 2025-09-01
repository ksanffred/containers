namespace my {
template <class T>
list<T>::list() : deque<T>::deque() {}
template <class T>
list<T>::list(size_type n) {
  for (size_type i = 0; i < n; i++) push_back(value_type());
}
template <class T>
list<T>::list(std::initializer_list<value_type> const &items)
    : deque<T>::deque(items) {}
template <class T>
list<T>::list(const list &other) : deque<T>::deque(other) {}
template <class T>
list<T>::list(list &&other) : deque<T>::deque(std::move(other)) {}
template <class T>
typename list<T>::iterator list<T>::begin() {
  return iterator(this->head_);
}
template <class T>
typename list<T>::iterator list<T>::end() {
  return this->head_ ? iterator(this->tail_->next) : begin();
}
template <class T>
typename list<T>::size_type list<T>::max_size() const {
  return std::numeric_limits<size_type>::max() / sizeof(struct Node<T>);
}
template <class T>
typename list<T>::iterator list<T>::insert(iterator pos,
                                           const_reference value) {
  iterator result;

  if (pos == begin()) {
    push_front(value);
    pos = this->head_;
    result = pos;
  } else if (pos == end()) {
    push_back(value);
    pos = this->tail_;
    result = pos;
  } else {
    Node<value_type> *current = pos.node_;
    Node<value_type> *blank = new Node<value_type>(value);
    blank->next = current;
    blank->prev = current->prev;
    current->prev->next = blank;
    current->prev = blank;
    this->size_++;
    result = iterator(blank);
  }
  return result;
}
template <class T>
void list<T>::erase(iterator pos) {
  if (pos == begin()) {
    pop_front();
  } else if (pos == end()) {
    pop_back();
  } else {
    Node<T> *node = pos.node_;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
    this->size_--;
  }
}
template <class T>
void list<T>::merge(list &other) {
  if (this != &other) {
    iterator it_this = begin();
    iterator it_other = other.begin();
    while (!other.empty()) {
      if (this->empty()) {
        insert(it_this, *it_other);
        other.erase(it_other);
        ++it_other;
      } else {
        if (it_this == end() || *it_other < *it_this) {
          insert(it_this, *it_other);
          other.erase(it_other);
          ++it_other;
        } else
          ++it_this;
      }
    }
  }
}
template <class T>
void list<T>::splice(const_iterator pos, list<T> &other) {
  if (!other.empty())
    for (iterator it = other.begin(); it != other.end(); ++it) insert(pos, *it);
}
template <class T>
void list<T>::reverse() {
  if (this->size_ > 1) {
    Node<T> *current = this->head_;
    for (size_type i = 0; i < this->size_; i++) {
      std::swap(current->prev, current->next);
      current = current->prev;
    }
    std::swap(this->head_, this->tail_);
  }
}
template <class T>
void list<T>::unique() {
  Node<T> *current = this->head_;
  while (current && current->next) {
    if (current->value == current->next->value) {
      Node<T> *duplicate = current->next;
      current->next = duplicate->next;
      delete duplicate;
      this->size_--;
    } else
      current = current->next;
  }
}
template <class T>
void list<T>::sort() {
  this->tail_ = this->head_ = mergeSort(this->head_);
  while (this->tail_->next) this->tail_ = this->tail_->next;
}
template <class T>
template <class... Args>
typename list<T>::iterator list<T>::insert_many(const_iterator pos,
                                                Args &&...args) {
  for (const auto &arg : {args...}) insert(pos, arg);
  return pos;
}
template <class T>
template <class... Args>
void list<T>::insert_many_back(Args &&...args) {
  for (const auto &arg : {args...}) push_back(arg);
}
template <class T>
template <class... Args>
void list<T>::insert_many_front(Args &&...args) {
  for (const auto &arg : {args...}) push_front(arg);
}
}  // namespace my