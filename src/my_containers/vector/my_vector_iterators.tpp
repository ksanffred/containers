namespace my {
template <typename T>
vector<T>::VectorIterator::VectorIterator(value_type *ptr) : ptr_(ptr) {}
template <typename T>
typename vector<T>::reference vector<T>::VectorIterator::operator*() {
  return *ptr_;
}
template <typename T>
vector<T>::VectorIterator::VectorIterator(VectorConstIterator &other)
    : ptr_((value_type *)other.ptr_) {}
template <typename T>
typename vector<T>::VectorIterator vector<T>::VectorIterator::operator++(int) {
  VectorIterator temp(*this);

  ++ptr_;
  return temp;
}
template <typename T>
typename vector<T>::VectorIterator vector<T>::VectorIterator::operator--(int) {
  VectorIterator temp(*this);

  --ptr_;
  return temp;
}
template <typename T>
typename vector<T>::VectorIterator &vector<T>::VectorIterator::operator++() {
  ++ptr_;
  return *this;
}
template <typename T>
typename vector<T>::VectorIterator &vector<T>::VectorIterator::operator--() {
  --ptr_;
  return *this;
}
template <typename T>
bool vector<T>::VectorIterator::operator==(const VectorIterator &other) const {
  return ptr_ == other.ptr_;
}
template <typename T>
bool vector<T>::VectorIterator::operator!=(const VectorIterator &other) const {
  return ptr_ != other.ptr_;
}
template <typename T>
typename vector<T>::VectorIterator vector<T>::VectorIterator::operator+(
    int n) const {
  VectorIterator temp(*this);

  for (int i = 0; i < n; i++) temp++;
  return temp;
}
template <typename T>
typename vector<T>::VectorIterator vector<T>::VectorIterator::operator-(
    int n) const {
  VectorIterator temp(*this);

  for (int i = 0; i < n; i++) temp--;
  return temp;
}
template <typename T>
ptrdiff_t vector<T>::VectorIterator::operator-(
    const VectorIterator &other) const {
  return ptr_ - other.ptr_;
}
template <typename T>
vector<T>::VectorConstIterator::VectorConstIterator(const value_type *ptr)
    : ptr_(ptr) {}
template <typename T>
vector<T>::VectorConstIterator::VectorConstIterator(const VectorIterator &other)
    : ptr_(other.ptr_) {}
template <typename T>
typename vector<T>::const_reference vector<T>::VectorConstIterator::operator*()
    const {
  return *ptr_;
}
template <typename T>
typename vector<T>::VectorConstIterator
vector<T>::VectorConstIterator::operator++(int) {
  VectorConstIterator temp(*this);

  ++ptr_;
  return temp;
}
template <typename T>
typename vector<T>::VectorConstIterator
vector<T>::VectorConstIterator::operator--(int) {
  VectorConstIterator temp(*this);

  --ptr_;
  return temp;
}
template <typename T>
typename vector<T>::VectorConstIterator &
vector<T>::VectorConstIterator::operator++() {
  ++ptr_;
  return *this;
}
template <typename T>
typename vector<T>::VectorConstIterator &
vector<T>::VectorConstIterator::operator--() {
  --ptr_;
  return *this;
}
template <typename T>
bool vector<T>::VectorConstIterator::operator==(
    const VectorConstIterator &other) const {
  return ptr_ == other.ptr_;
}
template <typename T>
bool vector<T>::VectorConstIterator::operator!=(
    const VectorConstIterator &other) const {
  return ptr_ != other.ptr_;
}
template <typename T>
typename vector<T>::VectorConstIterator
vector<T>::VectorConstIterator::operator+(int n) const {
  VectorConstIterator temp(*this);

  for (int i = 0; i < n; i++) temp++;
  return temp;
}
template <typename T>
typename vector<T>::VectorConstIterator
vector<T>::VectorConstIterator::operator-(int n) const {
  VectorConstIterator temp(*this);

  for (int i = 0; i < n; i++) temp--;
  return temp;
}
template <typename T>
ptrdiff_t vector<T>::VectorConstIterator::operator-(
    const VectorConstIterator &other) const {
  return ptr_ - other.ptr_;
}
}  // namespace my
