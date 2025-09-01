namespace my {

template <typename Key, typename Value, typename Compare>
Tree<Key, Value, Compare>::Node::Node() {}

template <typename Key, typename Value, typename Compare>
Tree<Key, Value, Compare>::Node::Node(key_type key, value_type value)
    : key_(key),
      value_(value),
      color_(BLACK),
      parent_(nil_),
      left_(nil_),
      right_(nil_) {}

template <typename Key, typename Value, typename Compare>
Tree<Key, Value, Compare>::Node::Node(key_type key, value_type value,
                                      Node* parent)
    : key_(key),
      value_(value),
      color_(RED),
      parent_(parent),
      left_(nil_),
      right_(nil_) {}

template <typename Key, typename Value, typename Compare>
Tree<Key, Value, Compare>::Node::Node(Node& node)
    : key_(node.key_),
      value_(node.value_),
      color_(node.color_),
      parent_(node.parent_),
      left_(node.left_),
      right_(node.right_) {}
template <typename Key, typename Value, typename Compare>
typename Tree<Key, Value, Compare>::Node&
Tree<Key, Value, Compare>::Node::operator=(const Node& other) {
  if (this == &other) return *this;
  key_ = other.key_;
  value_ = other.value_;
  color_ = other.color_;
  parent_ = other.parent_;
  left_ = other.left_;
  right_ = other.right_;
  return *this;
}

template <typename Key, typename Value, typename Compare>
typename Tree<Key, Value, Compare>::Node&
Tree<Key, Value, Compare>::Node::operator=(Node&& other) {
  if (this == &other) return *this;
  key_ = other.key_;
  value_ = other.value_;
  color_ = other.color_;
  parent_ = other.parent_;
  left_ = other.left_;
  right_ = other.right_;
  other.parent_ = nil_;
  other.left_ = nil_;
  other.right_ = nil_;
  return *this;
}

template <typename Key, typename Value, typename Compare>
Tree<Key, Value, Compare>::Tree() : root_(nil_), size_(0) {}
template <typename Key, typename Value, typename Compare>
Tree<Key, Value, Compare>::Tree(key_type key, value_type value)
    : root_(new Node{key, value}), size_(1) {}
template <typename Key, typename Value, typename Compare>
Tree<Key, Value, Compare>::Tree(const Tree& other) : Tree() {
  for (Iterator it = other.getMin(other.root_); it != other.nil_; ++it) {
    insert(it.GetNode()->GetKey(), it.GetNode()->GetValue());
  }
}

template <typename Key, typename Value, typename Compare>
Tree<Key, Value, Compare>::Tree(Tree&& other) : Tree() {
  root_ = other.root_;
  size_ = other.size_;
  other.root_ = nil_;
  other.size_ = 0;
}

template <typename Key, typename Value, typename Compare>
Tree<Key, Value, Compare>::~Tree() {
  clear();
}

template <typename Key, typename Value, typename Compare>
Tree<Key, Value, Compare>& Tree<Key, Value, Compare>::operator=(
    const Tree& other) {
  root_ = nil_;
  size_ = 0;
  for (Iterator it = other.getMin(other.root_); it != other.nil_; ++it) {
    insert(it.GetNode()->GetKey(), it.GetNode()->GetValue());
  }
  return *this;
}

template <typename Key, typename Value, typename Compare>
Tree<Key, Value, Compare>& Tree<Key, Value, Compare>::operator=(Tree&& other) {
  root_ = other.root_;
  size_ = other.size_;
  other.root_ = nil_;
  other.size_ = 0;
  return *this;
}

template <typename Key, typename Value, typename Compare>
void Tree<Key, Value, Compare>::clear() {
  destroyTree(root_);
  root_ = nil_;
  size_ = 0;
}

template <typename Key, typename Value, typename Compare>
void Tree<Key, Value, Compare>::destroyTree(Node* node) {
  if (node != nil_) {
    destroyTree(node->GetLeft());
    if (node != nil_) destroyTree(node->GetRight());
    delete node;
  }
}

template <typename Key, typename Value, typename Compare>
std::pair<typename Tree<Key, Value, Compare>::Node*, bool>
Tree<Key, Value, Compare>::insert(key_type key, value_type value) {
  bool is_possible = true;
  Node* newNode;
  if (root_ != nil_) {
    Node* parent_node = searchPlace(key);
    if (parent_node == nil_) {
      newNode = parent_node;
      is_possible = false;
    } else {
      newNode = new Node{key, value, parent_node};
      if (key_compare{}(key, parent_node->GetKey()))
        parent_node->SetLeft(newNode);
      else
        parent_node->SetRight(newNode);
      balanceTree(newNode);
      size_++;
    }
  } else {
    newNode = new Node{key, value};
    root_ = newNode;
    size_ = 1;
  }
  return {newNode, is_possible};
}

template <typename Key, typename Value, typename Compare>
void Tree<Key, Value, Compare>::insert(Node* parent, Node* child) {
  if (key_compare{}(child->GetKey(), parent->GetKey()))
    parent->SetLeft(child);
  else
    parent->SetRight(child);
  child->SetParent(parent);
  child->SetLeft(nil_);
  child->SetRight(nil_);
  child->SetColor(RED);
  balanceTree(child);
  size_++;
}

template <typename Key, typename Value, typename Compare>
typename Tree<Key, Value, Compare>::Node*
Tree<Key, Value, Compare>::searchPlace(key_type key) {
  Node* current_node = root_;
  Node* parent_node = current_node;

  while (current_node != nil_) {
    if (key == current_node->GetKey() && !key_compare{}(key, key)) {
      current_node = nil_;
      parent_node = nil_;
    } else {
      parent_node = current_node;
      current_node = key_compare{}(key, current_node->GetKey())
                         ? current_node->GetLeft()
                         : current_node->GetRight();
    }
  }
  return parent_node;
}

template <typename Key, typename Value, typename Compare>
void Tree<Key, Value, Compare>::rightRotate(Node* node) {
  Node* node_left = node->GetLeft();
  Node* node_left_right = node_left->GetRight();

  node_left->SetParent(node->GetParent());
  node_left->SetRight(node);
  node->SetParent(node_left);
  node->SetLeft(node_left_right);

  if (node_left_right != nil_) {
    node_left_right->SetParent(node);
  }

  if (node_left->GetParent() == nil_) {
    root_ = node_left;
  } else if (node_left->GetParent()->GetLeft() == node) {
    node_left->GetParent()->SetLeft(node_left);
  } else {
    node_left->GetParent()->SetRight(node_left);
  }
}

template <typename Key, typename Value, typename Compare>
void Tree<Key, Value, Compare>::leftRotate(Node* node) {
  Node* node_right = node->GetRight();
  Node* node_right_left = node_right->GetLeft();

  node_right->SetParent(node->GetParent());
  node_right->SetLeft(node);
  node->SetParent(node_right);
  node->SetRight(node_right_left);

  if (node_right_left != nil_) {
    node_right_left->SetParent(node);
  }

  if (node_right->GetParent() == nil_) {
    root_ = node_right;
  } else if (node_right->GetParent()->GetLeft() == node) {
    node_right->GetParent()->SetLeft(node_right);
  } else {
    node_right->GetParent()->SetRight(node_right);
  }
}

template <typename Key, typename Value, typename Compare>
void Tree<Key, Value, Compare>::balanceTree(Node* newNode) {
  while (newNode->GetParent() != nil_ &&
         newNode->GetParent()->GetColor() == RED) {
    if (newNode->GetParent() == newNode->GetParent()->GetParent()->GetLeft()) {
      parentIsLeft(newNode);
    } else
      parentIsRight(newNode);
    if (newNode == root_) break;
  }
  root_->SetColor(BLACK);
}

template <typename Key, typename Value, typename Compare>
void Tree<Key, Value, Compare>::parentIsLeft(Node* newNode) {
  Node* uncle = newNode->GetParent()->GetParent()->GetRight();
  if (uncle != nil_ && uncle->GetColor() == RED) {  // Case 1: Uncle is RED
    newNode->GetParent()->SetColor(BLACK);
    uncle->SetColor(BLACK);
    newNode->GetParent()->GetParent()->SetColor(RED);
    newNode = newNode->GetParent()->GetParent();
  } else {  // Case 2 & 3: Uncle is BLACK or nil_
    if (newNode ==
        newNode->GetParent()->GetRight()) {  // Case 2: New node is right child
      newNode = newNode->GetParent();
      leftRotate(newNode);
    }
    // Case 3: New node is left child
    newNode->GetParent()->SetColor(BLACK);
    if (newNode->GetParent()->GetParent() != nil_) {
      newNode->GetParent()->GetParent()->SetColor(RED);
      rightRotate(newNode->GetParent()->GetParent());
    }
  }
}

template <typename Key, typename Value, typename Compare>
void Tree<Key, Value, Compare>::parentIsRight(Node* newNode) {
  Node* uncle = newNode->GetParent()->GetParent()->GetLeft();
  if (uncle != nil_ && uncle->GetColor() == RED) {  // Case 1: Uncle is RED
    newNode->GetParent()->SetColor(BLACK);
    uncle->SetColor(BLACK);
    newNode->GetParent()->GetParent()->SetColor(RED);
    newNode = newNode->GetParent()->GetParent();
  } else {  // Case 2 & 3: Uncle is BLACK or nil_
    if (newNode ==
        newNode->GetParent()->GetLeft()) {  // Case 2: New node is left child
      newNode = newNode->GetParent();
      rightRotate(newNode);
    }
    // Case 3: New node is right child
    newNode->GetParent()->SetColor(BLACK);
    if (newNode->GetParent()->GetParent() != nil_) {
      newNode->GetParent()->GetParent()->SetColor(RED);
      leftRotate(newNode->GetParent()->GetParent());
    }
  }
}

template <typename Key, typename Value, typename Compare>
typename Tree<Key, Value, Compare>::Node* Tree<Key, Value, Compare>::search(
    key_type key) {
  Node* current_node = root_;
  Node* ret = nil_;

  while (current_node != nil_) {
    if (key == current_node->GetKey()) ret = current_node;
    current_node = key_compare{}(key, current_node->GetKey())
                       ? current_node->GetLeft()
                       : current_node->GetRight();
  }
  return ret;
}

template <typename Key, typename Value, typename Compare>
typename Tree<Key, Value, Compare>::Node* Tree<Key, Value, Compare>::getMin(
    Node* node) const {
  Node* current_node = node;
  while (current_node != nil_ && current_node->GetLeft() != nil_) {
    current_node = current_node->GetLeft();
  }
  return current_node;
}

template <typename Key, typename Value, typename Compare>
typename Tree<Key, Value, Compare>::Node* Tree<Key, Value, Compare>::getMax(
    Node* node) const {
  Node* current_node = node;

  while (current_node != nil_ && current_node->GetRight() != nil_) {
    current_node = current_node->GetRight();
  }
  return current_node;
}

template <typename Key, typename Value, typename Compare>
void Tree<Key, Value, Compare>::transplant(Node* to, Node* from) {
  if (to == root_)
    root_ = from;
  else if (to == to->GetParent()->GetLeft())
    to->GetParent()->SetLeft(from);
  else
    to->GetParent()->SetRight(from);
  if (from != nil_) from->SetParent(to->GetParent());
}

template <typename Key, typename Value, typename Compare>
void Tree<Key, Value, Compare>::remove(Node* node) {
  if (node == nil_) return;
  key_type key_removable = node->GetKey();
  Node* deleted = new Node{*node};
  Color deleted_color = deleted->GetColor();
  Node* child = nil_;
  if (deleted->GetLeft() != nil_) deleted->GetLeft()->SetParent(deleted);
  if (deleted->GetRight() != nil_) deleted->GetRight()->SetParent(deleted);
  transplant(node, deleted);
  node->SetParent(nil_);
  node->SetLeft(nil_);
  node->SetRight(nil_);
  if (deleted->GetLeft() != nil_ && deleted->GetRight() != nil_) {
    Node* min = getMax(deleted->GetLeft());
    deleted->SetKey(min->GetKey());
    deleted->SetValue(min->GetValue());
    deleted_color = min->GetColor();
    child = min->GetLeft() != nil_ ? min->GetLeft() : min->GetRight();
    transplant(min, child);
    delete min;
  } else {
    child =
        deleted->GetLeft() != nil_ ? deleted->GetLeft() : deleted->GetRight();
    transplant(deleted, child);
    delete deleted;
  }
  if (deleted_color == BLACK) fixTree(child);
  size_--;
  Node* check = search(key_removable);
  if (check != nil_) remove(check);
}

template <typename Key, typename Value, typename Compare>
void Tree<Key, Value, Compare>::fixTree(Node* node) {
  while (node != nil_ && node != GetTreeRoot() && node->GetColor() == BLACK) {
    if (node == node->GetParent()->GetLeft())
      nodeIsLeft(node);
    else
      nodeIsRight(node);
  }
  node->SetColor(BLACK);
}

template <typename Key, typename Value, typename Compare>
void Tree<Key, Value, Compare>::nodeIsLeft(Node* node) {
  Node* brother = node->GetParent()->GetRight();
  if (brother->GetColor() == RED) {
    brother->SetColor(BLACK);
    node->GetParent()->SetColor(RED);
    leftRotate(node->GetParent());
    brother = node->GetParent()->GetRight();
  }
  if (brother->GetLeft()->GetColor() == BLACK &&
      brother->GetRight()->GetColor() == BLACK) {
    brother->SetColor(RED);
    node = node->GetParent();
  } else {
    if (brother->GetRight()->GetColor() == BLACK) {
      brother->GetLeft()->SetColor(BLACK);
      brother->SetColor(RED);
      rightRotate(brother);
      brother = node->GetParent()->GetRight();
    }
    brother->SetColor(node->GetParent()->GetColor());
    node->GetParent()->SetColor(BLACK);
    brother->GetRight()->SetColor(BLACK);
    leftRotate(node->GetParent());
    node = GetTreeRoot();
  }
}

template <typename Key, typename Value, typename Compare>
void Tree<Key, Value, Compare>::nodeIsRight(Node* node) {
  Node* brother = node->GetParent()->GetLeft();
  if (brother->GetColor() == RED) {
    brother->SetColor(BLACK);
    node->GetParent()->SetColor(RED);
    rightRotate(node->GetParent());
    brother = node->GetParent()->GetLeft();
  }
  if (brother->GetLeft()->GetColor() == BLACK &&
      brother->GetRight()->GetColor() == BLACK) {
    rightRotate(node->GetParent());
    brother = node->GetParent()->GetLeft();
  } else {
    if (brother->GetLeft()->GetColor() == BLACK) {
      brother->GetLeft()->SetColor(BLACK);
      brother->SetColor(RED);
      leftRotate(brother);
      brother = node->GetParent()->GetLeft();
    }
    brother->SetColor(node->GetParent()->GetColor());
    node->GetParent()->SetColor(BLACK);
    brother->GetLeft()->SetColor(BLACK);
    rightRotate(node->GetParent());
    node = GetTreeRoot();
  }
}

template <typename Key, typename Value, typename Compare>
void Tree<Key, Value, Compare>::SwapRoot(Tree& other) {
  Node* temp_root = root_;
  root_ = other.root_;
  other.root_ = temp_root;
  size_type temp_size = size_;
  size_ = other.size_;
  other.size_ = temp_size;
}

template <typename Key, typename Value, typename Compare>
void Tree<Key, Value, Compare>::MergeTree(Tree& other) {
  for (Iterator elem = other.getMin(other.GetTreeRoot()), elem_end = nil_;
       elem != elem_end;) {
    Iterator parent{searchPlace(elem.GetNode()->GetKey())};
    Iterator child = elem;
    ++elem;
    if (parent != nil_) {
      other.remove(child.GetNode());
      insert(parent.GetNode(), child.GetNode());
    }
  }
}

template <typename Key, typename Value, typename Compare>
Tree<Key, Value, Compare>::Iterator::Iterator() : node_(nil_) {}

template <typename Key, typename Value, typename Compare>
Tree<Key, Value, Compare>::Iterator::Iterator(Node* other) : node_(other) {}

template <typename Key, typename Value, typename Compare>
typename Tree<Key, Value, Compare>::Iterator&
Tree<Key, Value, Compare>::Iterator::operator++() {
  if (node_->GetRight() != nil_) {
    node_ = node_->GetRight();
    while (node_->GetLeft() != nil_) node_ = node_->GetLeft();
  } else {
    while (node_->GetParent() != nil_ && node_->GetParent()->GetLeft() != node_)
      node_ = node_->GetParent();
    node_ = node_->GetParent();
  }
  return *this;
}

template <typename Key, typename Value, typename Compare>
typename Tree<Key, Value, Compare>::Iterator
Tree<Key, Value, Compare>::Iterator::operator++(int) {
  Node* newNode = node_;
  ++(*this);
  return newNode;
}

template <typename Key, typename Value, typename Compare>
bool Tree<Key, Value, Compare>::Iterator::operator==(
    const Iterator& other) const {
  return node_ == other.node_;
}

template <typename Key, typename Value, typename Compare>
bool Tree<Key, Value, Compare>::Iterator::operator!=(
    const Iterator& other) const {
  return node_ != other.node_;
}

template <typename Key, typename Value, typename Compare>
typename Tree<Key, Value, Compare>::reference
Tree<Key, Value, Compare>::Iterator::operator*() {
  return node_->GetValue();
}

template <typename Key, typename Value, typename Compare>
typename Tree<Key, Value, Compare>::value_type*
Tree<Key, Value, Compare>::Iterator::operator->() {
  return &node_->GetValue();
}

template <typename Key, typename Value, typename Compare>
Tree<Key, Value, Compare>::ConstIterator::ConstIterator() : node_(nil_) {}

template <typename Key, typename Value, typename Compare>
Tree<Key, Value, Compare>::ConstIterator::ConstIterator(Node* other)
    : node_(other) {}

template <typename Key, typename Value, typename Compare>
bool Tree<Key, Value, Compare>::ConstIterator::operator==(
    const ConstIterator& other) const {
  return node_ == other.node_;
}

template <typename Key, typename Value, typename Compare>
bool Tree<Key, Value, Compare>::ConstIterator::operator!=(
    const ConstIterator& other) const {
  return node_ != other.node_;
}

template <typename Key, typename Value, typename Compare>
typename Tree<Key, Value, Compare>::reference
Tree<Key, Value, Compare>::ConstIterator::operator*() {
  return node_->GetValue();
}

}  // namespace my