#ifndef __S21_RBTREE_H__
#define __S21_RBTREE_H__

#include <limits>

namespace s21 {
enum Color { BLACK, RED };
template <class Key, class Value, class Compare = std::less<Key>>
class Tree {
 public:
  typedef Key key_type;
  typedef Value value_type;
  typedef value_type& reference;
  typedef Compare key_compare;
  typedef const value_type& const_reference;
  typedef size_t size_type;

 public:
  class Node {
    key_type key_;
    value_type value_;
    Color color_;
    Node* parent_;
    Node* left_;
    Node* right_;

   public:
    Node();
    Node(key_type key, value_type value);
    Node(key_type key, value_type value, Node* parent);
    Node(Node& node);

   public:
    Node& operator=(const Node& other);
    Node& operator=(Node&& other);

   public:
    key_type& GetKey() { return key_; }
    value_type& GetValue() { return value_; }
    Node* GetLeft() const { return left_; }
    Node* GetRight() const { return right_; }
    Node* GetParent() const { return parent_; }
    Color GetColor() const { return color_; }

    void SetKey(key_type key) { key_ = key; }
    void SetValue(value_type value) { value_ = value; }
    void SetLeft(Node* ref) { left_ = ref; }
    void SetRight(Node* ref) { right_ = ref; }
    void SetParent(Node* ref) { parent_ = ref; }
    void SetColor(Color color) { color_ = color; }
  };

 public:
  class Iterator {
    Node* node_;

   public:
    Iterator();
    Iterator(Node* other);

   public:
    Iterator& operator++();
    Iterator operator++(int);
    reference operator*();
    value_type* operator->();
    bool operator==(const Iterator& other) const;
    bool operator!=(const Iterator& other) const;
    Node* GetNode() { return node_; }
  };

  class ConstIterator {
    const Node* node_;

   public:
    ConstIterator();
    ConstIterator(Node* other);

   public:
    reference operator*();
    bool operator==(const ConstIterator& other) const;
    bool operator!=(const ConstIterator& other) const;
    Node* GetNode() { return node_; }
  };

 private:
  Node* root_;
  size_type size_;

  static inline Node s_nil_;

 public:
  static inline Node* const nil_ = [] {
    auto* p = &Tree<Key, Value, Compare>::s_nil_;
    p->SetColor(BLACK);
    p->SetParent(p);
    p->SetLeft(p);
    p->SetRight(p);
    return p;
  }();

 public:
  Tree();
  Tree(key_type key, value_type value);
  Tree(const Tree& other);
  Tree(Tree&& other);
  ~Tree();

 public:
  Tree& operator=(const Tree& other);
  Tree& operator=(Tree&& other);

 public:
  Node* GetTreeRoot() const { return root_; }
  size_type GetSize() const { return size_; }
  size_type GetMaxSize() const {
    return std::numeric_limits<size_type>::max() /
           sizeof(typename Tree<Key, Key>::Node);
  }
  std::pair<Node*, bool> insert(key_type key, value_type value);
  void insert(Node* parent, Node* child);
  Node* search(key_type key);
  Node* searchPlace(key_type key);
  void remove(Node* node);
  void clear();
  Node* getMin(Node* node) const;
  Node* getMax(Node* node) const;
  void SwapRoot(Tree& other);
  void MergeTree(Tree& other);

 private:
  void rightRotate(Node* node);
  void leftRotate(Node* node);
  void balanceTree(Node* newNode);
  void parentIsLeft(Node* newNode);
  void parentIsRight(Node* newNode);
  void destroyTree(Node* node);
  void transplant(Node* to, Node* from);
  void fixTree(Node* node);
  void nodeIsLeft(Node* node);
  void nodeIsRight(Node* node);
};
}  // namespace s21
#include "s21_rbtree.tpp"
#endif