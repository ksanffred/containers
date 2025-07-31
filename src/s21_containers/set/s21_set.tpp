namespace s21 {
template <typename Key>
set<Key>::set() : base_() {}
template <typename Key>
set<Key>::set(std::initializer_list<value_type> const& items) : base_() {
  for (auto it = items.begin(), ite = items.end(); it != ite; ++it) {
    base_.insert(*it, *it);
  }
}
template <typename Key>
set<Key>::set(const set& s) : base_(s.base_) {}
template <typename Key>
set<Key>::set(set&& s) {
  base_ = std::move(s.base_);
}
template <typename Key>
set<Key>& set<Key>::operator=(const set& s) {
  base_ = s.base_;
  return *this;
}
template <typename Key>
set<Key>& set<Key>::operator=(set&& s) {
  base_ = std::move(s.base_);
  return *this;
}
template <typename Key>
typename set<Key>::iterator set<Key>::begin() const {
  iterator iter{base_.getMin(base_.GetTreeRoot())};
  return iter;
}
template <typename Key>
typename set<Key>::iterator set<Key>::end() const {
  iterator iter{};
  return iter;
}
template <typename Key>
typename set<Key>::size_type set<Key>::size() {
  return base_.GetSize();
}
template <typename Key>
bool set<Key>::empty() {
  return size() == 0;
}
template <typename Key>
typename set<Key>::size_type set<Key>::max_size() {
  return base_.GetMaxSize();
}
template <typename Key>
void set<Key>::clear() {
  return base_.clear();
}
template <typename Key>
std::pair<typename set<Key>::iterator, bool> set<Key>::insert(
    const value_type& value) {
  return base_.insert(value, value);
}
template <typename Key>
void set<Key>::erase(iterator pos) {
  if (pos != end()) {
    base_.remove(pos.GetNode());
    delete pos.GetNode();
  }
}
template <typename Key>
void set<Key>::swap(set& other) {
  base_.SwapRoot(other.base_);
}
template <typename Key>
void set<Key>::merge(set& other) {
  base_.MergeTree(other.base_);
}
template <typename Key>
typename set<Key>::iterator set<Key>::find(const key_type& key) {
  return base_.search(key);
}
template <typename Key>
bool set<Key>::contains(const key_type& key) {
  return find(key) != end();
}
template <typename Key>
template <class... Args>
std::vector<std::pair<typename set<Key>::iterator, bool>> set<Key>::insert_many(
    Args&&... args) {
  std::vector<std::pair<iterator, bool>> vec;
  for (const auto& arg : {args...}) {
    vec.push_back(insert(arg));
  }
  return vec;
}
}  // namespace s21