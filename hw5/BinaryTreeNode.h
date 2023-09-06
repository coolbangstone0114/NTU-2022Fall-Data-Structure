/**
 *  BinaryTreeNode represents a node in a binary tree.
 *
 *  DO NOT CHANGE THIS FILE.
 **/

#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H 

#include "Entry.h"
#include <string>

template<typename K, typename V>
class BinaryTreeNode {

  /**
   *  entry is the key/value pair stored in this node.
   *  parent is the parent of this node.
   *  leftChild and rightChild are the children of this node.
   **/
protected:  

public:
  Entry<K, V>* entry;
  BinaryTreeNode<K, V>* parent;
  BinaryTreeNode<K, V>* leftChild;
  BinaryTreeNode<K, V>* rightChild;

  /** Simple constructor that sets the entry.
   *  The rest of the fields are set to null. */
  BinaryTreeNode(Entry<K, V>* e);

  /** Simple constructor that sets the entry and parent.
   *  The rest of the fields are set to null. */
  BinaryTreeNode(Entry<K, V>* e, BinaryTreeNode<K, V>* p);

  /** Simple constructor that sets all of the node's fields. */
  BinaryTreeNode(Entry<K, V>* e, BinaryTreeNode<K, V>* p, BinaryTreeNode<K, V>* l, BinaryTreeNode<K, V>* r);
  ~BinaryTreeNode();

  std::string toString();
};

#endif
