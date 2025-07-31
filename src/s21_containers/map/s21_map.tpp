namespace s21 {
template <typename Key, typename T>
map<Key, T>::map() : base_() {}
template <typename Key, typename T>
map<Key, T>::map(std::initializer_list<value_type> const& items) : base_() {
  for (auto it = items.begin(), ite = items.end(); it != ite; ++it) {
    base_.insert(it->first, *it);
  }
}
template <typename Key, typename T>
map<Key, T>::map(const map& m) : base_(m.base_) {}
template <typename Key, typename T>
map<Key, T>::map(map&& m) {
  base_ = std::move(m.base_);
}
template <typename Key, typename T>
map<Key, T>& map<Key, T>::operator=(map&& m) {
  base_ = std::move(m.base_);
  return *this;
}
template <typename Key, typename T>
typename map<Key, T>::iterator map<Key, T>::begin() const {
  iterator iter{base_.getMin(base_.GetTreeRoot())};
  return iter;
}
template <typename Key, typename T>
typename map<Key, T>::iterator map<Key, T>::end() const {
  iterator iter{};
  return iter;
}
template <typename Key, typename T>
T& map<Key, T>::at(const Key& key) {
  auto it = find(key);
  if (it == end()) throw std::out_of_range{"Element not found."};
  return it->second;
}
template <typename Key, typename T>
T& map<Key, T>::operator[](const Key& key) {
  auto pr = insert_or_assign(key, T());
  auto it = pr.first;
  return it->second;
}
template <typename Key, typename T>
typename map<Key, T>::size_type map<Key, T>::size() {
  return base_.GetSize();
}
template <typename Key, typename T>
bool map<Key, T>::empty() {
  return size() == 0;
}
template <typename Key, typename T>
typename map<Key, T>::size_type map<Key, T>::max_size() {
  return base_.GetMaxSize();
}
template <typename Key, typename T>
void map<Key, T>::clear() {
  return base_.clear();
}
template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(
    const value_type& value) {
  return base_.insert(value.first, value);
}
template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(
    const Key& key, const T& obj) {
  return base_.insert(key, value_type{key, obj});
}
template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert_or_assign(
    const Key& key, const T& obj) {
  std::pair<iterator, bool> ret = base_.insert(key, value_type{key, obj});
  if (ret.first == end()) {
    ret.first = find(key);
    ret.first.GetNode()->SetValue({key, obj});
  }
  return ret;
}
template <typename Key, typename T>
void map<Key, T>::erase(iterator pos) {
  if (pos != end()) {
    base_.remove(pos.GetNode());
    delete pos.GetNode();
  }
}
template <typename Key, typename T>
void map<Key, T>::swap(map& other) {
  base_.SwapRoot(other.base_);
}
template <typename Key, typename T>
void map<Key, T>::merge(map& other) {
  base_.MergeTree(other.base_);
}
template <typename Key, typename T>
typename map<Key, T>::iterator map<Key, T>::find(const Key& key) {
  return base_.search(key);
}
template <typename Key, typename T>
bool map<Key, T>::contains(const Key& key) {
  return find(key) != end();
}
template <typename Key, typename T>
template <class... Args>
std::vector<std::pair<typename map<Key, T>::iterator, bool>>
map<Key, T>::insert_many(Args&&... args) {
  std::vector<std::pair<iterator, bool>> vec;
  for (const auto& arg : {args...}) {
    vec.push_back(insert(arg));
  }
  return vec;
}
}  // namespace s21