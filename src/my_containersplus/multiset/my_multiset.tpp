namespace my {
template <typename Key>
multiset<Key>::multiset() : base_() {}
template <typename Key>
multiset<Key>::multiset(std::initializer_list<value_type> const& items)
    : base_() {
  for (auto it = items.begin(), ite = items.end(); it != ite; ++it) {
    base_.insert(*it, *it);
  }
}
template <typename Key>
multiset<Key>::multiset(const multiset& ms) : base_(ms.base_) {}
template <typename Key>
multiset<Key>::multiset(multiset&& ms) {
  base_ = std::move(ms.base_);
}
template <typename Key>
multiset<Key>& multiset<Key>::operator=(multiset&& ms) {
  base_ = std::move(ms.base_);
  return *this;
}
template <typename Key>
typename multiset<Key>::iterator multiset<Key>::begin() const {
  iterator iter{base_.getMin(base_.GetTreeRoot())};
  return iter;
}
template <typename Key>
typename multiset<Key>::iterator multiset<Key>::end() const {
  iterator iter{};
  return iter;
}
template <typename Key>
typename multiset<Key>::size_type multiset<Key>::size() {
  return base_.GetSize();
}
template <typename Key>
bool multiset<Key>::empty() {
  return size() == 0;
}
template <typename Key>
typename multiset<Key>::size_type multiset<Key>::max_size() {
  return base_.GetMaxSize();
}
template <typename Key>
void multiset<Key>::clear() {
  return base_.clear();
}
template <typename Key>
std::pair<typename multiset<Key>::iterator, bool> multiset<Key>::insert(
    const value_type& value) {
  return base_.insert(value, value);
}
template <typename Key>
void multiset<Key>::erase(iterator pos) {
  if (pos != end()) {
    base_.remove(pos.GetNode());
    delete pos.GetNode();
  }
}
template <typename Key>
void multiset<Key>::swap(multiset& other) {
  base_.SwapRoot(other.base_);
}
template <typename Key>
void multiset<Key>::merge(multiset& other) {
  base_.MergeTree(other.base_);
}
template <typename Key>
typename multiset<Key>::size_type multiset<Key>::count(const Key& key) {
  size_type num = 0;
  for (multiset<Key>::iterator it = base_.search(key), ite = end();
       it != ite && key == *it; ++it)
    num++;
  return num;
}
template <typename Key>
typename multiset<Key>::iterator multiset<Key>::find(const Key& key) {
  return base_.search(key);
}
template <typename Key>
bool multiset<Key>::contains(const Key& key) {
  return find(key) != end();
}
template <typename Key>
std::pair<typename multiset<Key>::iterator, typename multiset<Key>::iterator>
multiset<Key>::equal_range(const Key& key) {
  return {lower_bound(key), upper_bound(key)};
}
template <typename Key>
typename multiset<Key>::iterator multiset<Key>::lower_bound(const Key& key) {
  return base_.search(key);
}
template <typename Key>
typename multiset<Key>::iterator multiset<Key>::upper_bound(const Key& key) {
  multiset<Key>::iterator it = base_.search(key);
  for (auto ite = end(); it != ite && key == *it; ++it) {
  };
  return it;
}
template <typename Key>
template <class... Args>
std::vector<std::pair<typename multiset<Key>::iterator, bool>>
multiset<Key>::insert_many(Args&&... args) {
  std::vector<std::pair<iterator, bool>> vec;
  for (const auto& arg : {args...}) {
    vec.push_back(insert(arg));
  }
  return vec;
}
}  // namespace my