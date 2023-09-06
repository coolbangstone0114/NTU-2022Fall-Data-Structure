/**
 *  BinaryTree implements a Dictionary as a binary tree (unbalanced).
 *
 *  DO NOT CHANGE ANY PROTOTYPES IN THIS FILE.
 **/
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "BinaryTreeNode.h"
#include "BinaryTreeNode.cpp"
#include "Dictionary.h"

template <typename K, typename V>
class BinaryTree : public Dictionary<K, V>
{
  /**
   *  size is the number of items stored in the dictionary.
   *  root is the BinaryTreeNode that serves as root of the tree.  If there
   *  are no items (size is zero), root is null.
   **/
protected:
  int tsize;
  BinaryTreeNode<K, V> *root;

public:
  BinaryTree();

  /**
   *  Returns the number of entries stored in the dictionary.  Entries with
   *  the same key (or even the same key and value) each still count as
   *  a separate entry.
   *  @return number of entries in the dictionary.
   **/
  virtual int size();

  /**
   *  Tests if the dictionary is empty.
   *
   *  @return true if the dictionary has no entries; false otherwise.
   **/
  virtual bool isEmpty();

  /**
   *  Create a new Entry object referencing the input key and associated value,
   *  and insert the entry into the dictionary.
   *  Multiple entries with the same key (or even the same key and
   *  value) can coexist in the dictionary.
   *
   *  @param key the key by which the entry can be retrieved.
   *  @param value an arbitrary object.
   **/
  virtual void insert(const K &key, const V &value);

  /**
   *  Search for an entry with the specified key.  If such an entry is found,
   *  return true; otherwise return false.
   *
   *  @param key the search key.
   *  @return an entry containing the key and an associated value, or null if
   *          no entry contains the specified key.
   **/
  virtual Entry<K, V> *find(const K &key);

  /**
   *  Remove an entry with the specified key.  If such an entry is found,
   *  remove it from the table.
   *  If several entries have the specified key, choose one arbitrarily, then
   *  remove it.
   *
   *  @param key the search key.
   */
  virtual void remove(const K &key);

  /**
   *  Remove all entries from the dictionary.
   */
  virtual void makeEmpty();

  /**
   *  Convert the tree into a string.
   **/
  std::string toString();

private:
  void insertHelper(Entry<K, V> *entry, const K &key, BinaryTreeNode<K, V> *node);

  BinaryTreeNode<K, V> *findHelper(const K &key, BinaryTreeNode<K, V> *node);

  // replace node a with subtree rooted from b
  void replaceHelper(BinaryTreeNode<K, V> *a, BinaryTreeNode<K, V> *b);

  // find the min in the subtree rooted from node a
  BinaryTreeNode<K, V> *findMinNode(BinaryTreeNode<K, V> *node);

  void emptyHelper(BinaryTreeNode<K, V> *node);
};

#endif
