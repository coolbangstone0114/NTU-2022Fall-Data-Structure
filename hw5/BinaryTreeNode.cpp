#include <iostream>
#include <sstream>
#include "BinaryTreeNode.h"
using namespace std;

/** Simple constructor that sets the entry.
 *  The rest of the fields are set to null. */
template<typename K, typename V>
BinaryTreeNode<K, V>::BinaryTreeNode(Entry<K, V>* e):entry(e), parent(NULL), leftChild(NULL), rightChild(NULL){
}

/** Simple constructor that sets the entry and parent.
 *  The rest of the fields are set to null. */
template<typename K, typename V>
BinaryTreeNode<K, V>::BinaryTreeNode(Entry<K, V>* e, BinaryTreeNode<K, V>* p):entry(e), parent(p), leftChild(NULL), rightChild(NULL){
}

/** Simple constructor that sets all of the node's fields. */
template<typename K, typename V>
BinaryTreeNode<K, V>::BinaryTreeNode(Entry<K, V>* e, BinaryTreeNode<K, V>* p, BinaryTreeNode<K, V>* l, BinaryTreeNode<K, V>* r):entry(e), parent(p), leftChild(l), rightChild(r){
}

template<typename K, typename V>
BinaryTreeNode<K, V>::~BinaryTreeNode() {
  delete entry;
}

template<typename K, typename V>
string BinaryTreeNode<K, V>::toString(){
  stringstream ss;
  string str;
  if (this->leftChild != NULL) {
      ss << '(' << this->leftChild->toString() << ')';
  }
  ss << entry->getkey().getvalue() << entry->getvalue().getvalue();
  if (rightChild != NULL) {
      ss << '(' << this->rightChild->toString() << ')';
  }
  ss >> str;
  return str;
}

