namespace my {
template <typename T, std::size_t N>
array<T, N>::array() : size_(N) {}
template <typename T, std::size_t N>
array<T, N>::array(std::initializer_list<value_type> const &items) {
  std::copy(items.begin(), items.end(), values_);
}
template <typename T, std::size_t N>
array<T, N>::array(const array<T, N> &a) {
  std::copy(a.values_, a.values_ + size_, values_);
}
template <typename T, std::size_t N>
array<T, N>::array(array<T, N> &&a) {
  std::move(a.values_, a.values_ + size_, values_);
}
template <typename T, std::size_t N>
typename array<T, N>::array &array<T, N>::operator=(array<T, N> &&a) {
  for (size_type i = 0; i < size_; i++) values_[i] = std::move(a.values_[i]);
  return *this;
}
template <typename T, std::size_t N>
typename array<T, N>::reference array<T, N>::at(size_type pos) {
  if (pos >= N) throw std::out_of_range("Index out of range.");
  return values_[pos];
}
template <typename T, std::size_t N>
typename array<T, N>::reference array<T, N>::operator[](size_type pos) {
  return values_[pos];
}
template <typename T, std::size_t N>
typename array<T, N>::reference array<T, N>::front() {
  return values_[0];
}
template <typename T, std::size_t N>
typename array<T, N>::reference array<T, N>::back() {
  return values_[size_ - 1];
}
template <typename T, std::size_t N>
typename array<T, N>::iterator array<T, N>::data() {
  return values_;
}
template <typename T, std::size_t N>
typename array<T, N>::iterator array<T, N>::begin() {
  return values_;
}
template <typename T, std::size_t N>
typename array<T, N>::iterator array<T, N>::end() {
  return values_ + size_;
}
template <typename T, std::size_t N>
bool array<T, N>::empty() {
  return size_ == 0;
}
template <typename T, std::size_t N>
typename array<T, N>::size_type array<T, N>::size() {
  return size_;
}
template <typename T, std::size_t N>
typename array<T, N>::size_type array<T, N>::max_size() {
  return std::numeric_limits<std::size_t>::max() / sizeof(value_type);
}
template <typename T, std::size_t N>
void array<T, N>::swap(array<T, N> &other) {
  std::swap_ranges(values_, values_ + size_, other.values_);
}
template <typename T, std::size_t N>
void array<T, N>::fill(const_reference value) {
  std::fill(values_, values_ + size_, value);
}
}  // namespace my
