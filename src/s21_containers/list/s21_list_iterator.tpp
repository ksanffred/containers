namespace s21 {
template <class T>
list<T>::ListIterator::ListIterator(Node<T> *node) : node_(node) {}
template <class T>
list<T>::ListIterator::ListIterator(ListConstIterator &other)
    : node_((Node<T> *)other.node_) {}
template <class T>
typename list<T>::reference list<T>::ListIterator::operator*() {
  return node_->value;
}
template <class T>
typename list<T>::value_type *list<T>::ListIterator::operator->() {
  return &(node_->value);
}
template <class T>
typename list<T>::ListIterator &list<T>::ListIterator::operator++() {
  if (node_ != nullptr) node_ = node_->next;
  return *this;
}
template <class T>
typename list<T>::ListIterator list<T>::ListIterator::operator++(int) {
  ListIterator it = *this;

  if (node_ != nullptr) node_ = node_->next;
  return it;
}
template <class T>
typename list<T>::ListIterator &list<T>::ListIterator::operator--() {
  if (node_ != nullptr) node_ = node_->prev;
  return *this;
}
template <class T>
typename list<T>::ListIterator list<T>::ListIterator::operator--(int) {
  ListIterator it = *this;

  if (node_ != nullptr) node_ = node_->prev;
  return it;
}
template <class T>
bool list<T>::ListIterator::operator==(const ListIterator &other) const {
  return node_ == other.node_;
}
template <class T>
bool list<T>::ListIterator::operator!=(const ListIterator &other) const {
  return node_ != other.node_;
}
template <class T>
list<T>::ListConstIterator::ListConstIterator(const Node<T> *node)
    : node_(node) {}
template <class T>
list<T>::ListConstIterator::ListConstIterator(const ListIterator &other)
    : ListConstIterator(other.node_) {}
template <class T>
typename list<T>::const_reference list<T>::ListConstIterator::operator*()
    const {
  return node_->value;
}
template <class T>
const typename list<T>::value_type *list<T>::ListConstIterator::operator->()
    const {
  return &(node_->value);
}
template <class T>
typename list<T>::ListConstIterator &list<T>::ListConstIterator::operator++() {
  if (node_ != nullptr) node_ = node_->next;
  return *this;
}
template <class T>
typename list<T>::ListConstIterator list<T>::ListConstIterator::operator++(
    int) {
  ListConstIterator it = *this;

  if (node_ != nullptr) node_ = node_->next;
  return it;
}
template <class T>
typename list<T>::ListConstIterator &list<T>::ListConstIterator::operator--() {
  if (node_ != nullptr) node_ = node_->prev;
  return *this;
}
template <class T>
typename list<T>::ListConstIterator list<T>::ListConstIterator::operator--(
    int) {
  ListIterator it = *this;

  if (node_ != nullptr) node_ = node_->prev;
  return it;
}
template <class T>
bool list<T>::ListConstIterator::operator==(
    const ListConstIterator &other) const {
  return node_ == other.node_;
}
template <class T>
bool list<T>::ListConstIterator::operator!=(
    const ListConstIterator &other) const {
  return node_ != other.node_;
}
}  // namespace s21