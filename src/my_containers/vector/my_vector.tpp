namespace my {
template <typename T>
vector<T>::vector() : data_(nullptr), size_(0), capacity_(0) {}
template <typename T>
vector<T>::vector(size_type n)
    : data_(new value_type[n]), size_(n), capacity_(n) {
  for (size_type i = 0; i < size_; i++) data_[i] = value_type();
}
template <typename T>
vector<T>::vector(std::initializer_list<value_type> const &items)
    : vector(items.size()) {
  std::copy(items.begin(), items.end(), data_);
}
template <typename T>
vector<T>::vector(const vector<T> &other)
    : data_(new value_type[other.capacity_]),
      size_(other.size_),
      capacity_(other.capacity_) {
  std::copy(other.data_, other.data_ + other.size_, data_);
};
template <typename T>
vector<T>::vector(vector &&other) {
  data_ = std::exchange(other.data_, nullptr);
  size_ = std::exchange(other.size_, 0);
  capacity_ = std::exchange(other.capacity_, 0);
}
template <typename T>
vector<T>::~vector() {
  delete[] data_;
  data_ = nullptr;
  size_ = 0;
  capacity_ = 0;
}
template <typename T>
vector<T> &vector<T>::operator=(vector<T> &&other) {
  if (this != &other) {
    swap(other);
    other.~vector();
  }
  return *this;
}
template <typename T>
typename vector<T>::reference vector<T>::at(size_type pos) {
  if (pos >= size_) throw std::out_of_range("Index out of range.");
  return data_[pos];
}
template <typename T>
typename vector<T>::reference vector<T>::operator[](size_type pos) {
  return data_[pos];
}
template <typename T>
typename vector<T>::const_reference vector<T>::front() const {
  if (empty()) throw std::out_of_range("Vector is empty.");
  return data_[0];
}
template <typename T>
typename vector<T>::const_reference vector<T>::back() const {
  if (empty()) throw std::out_of_range("Vector is empty.");
  return data_[size_ - 1];
}
template <typename T>
typename vector<T>::value_type *vector<T>::data() {
  return data_;
}
template <typename T>
typename vector<T>::iterator vector<T>::begin() {
  return iterator(data_);
}
template <typename T>
typename vector<T>::iterator vector<T>::end() {
  return iterator(data_ + size_);
}
template <typename T>
bool vector<T>::empty() const {
  return size_ == 0;
}
template <typename T>
typename vector<T>::size_type vector<T>::size() const {
  return size_;
}
template <typename T>
typename vector<T>::size_type vector<T>::max_size() const {
  return std::numeric_limits<std::size_t>::max() / sizeof(value_type);
}
template <typename T>
void vector<T>::reserve(size_type size) {
  if (size > max_size())
    throw std::length_error("Too large size to reserve.");
  else if (size > capacity_) {
    value_type *new_data = new value_type[size];
    std::copy(data_, data_ + size_, new_data);
    delete[] data_;
    data_ = new_data;
    capacity_ = size;
  }
}
template <typename T>
typename vector<T>::size_type vector<T>::capacity() const {
  return capacity_;
}

template <typename T>
void vector<T>::shrink_to_fit() {
  if (size_ < capacity_) {
    value_type *new_data = new value_type[size_];
    std::copy(data_, data_ + size_, new_data);
    delete[] data_;
    data_ = new_data;
    capacity_ = size_;
  }
}
template <typename T>
void vector<T>::clear() {
  size_ = 0;
}
template <typename T>
typename vector<T>::iterator vector<T>::insert(iterator pos,
                                               const_reference value) {
  size_type idx = pos - begin();

  if (idx > size_) throw std::out_of_range("The position is out of range.");
  if (size_ == capacity_) reserve(capacity_ ? capacity_ * 2 : 1);

  iterator new_pos = begin() + idx;

  for (iterator it = end(); it != new_pos; it--) *it = *(it - 1);
  *new_pos = value;
  size_++;

  return new_pos;
}
template <typename T>
void vector<T>::erase(iterator pos) {
  size_type position = pos - data_;

  if (position > size_) throw std::out_of_range("Position out of range");

  for (iterator it = pos; it != end() - 1; it++) *it = *(it + 1);
  size_--;
}
template <typename T>
void vector<T>::push_back(const_reference value) {
  if (size_ == capacity_) reserve(capacity_ ? capacity_ * 2 : 1);
  data_[size_++] = value;
}
template <typename T>
void vector<T>::pop_back() {
  if (size_ > 0) size_--;
}
template <typename T>
void vector<T>::swap(vector<T> &other) {
  std::swap(data_, other.data_);
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
}
template <typename T>
template <typename... Args>
typename vector<T>::iterator vector<T>::insert_many(const_iterator pos,
                                                    Args &&...args) {
  vector<value_type> temp{args...};
  iterator current_pos = (iterator)pos;

  for (size_type i = 0; i < temp.size(); i++, current_pos++)
    current_pos = insert(current_pos, temp[i]);
  return current_pos;
}
template <typename T>
template <typename... Args>
void vector<T>::insert_many_back(Args &&...args) {
  insert_many(end(), args...);
}
}  // namespace my
