#include "BinaryTree.h"
using namespace std;

template <typename K, typename V>
BinaryTree<K, V>::BinaryTree()
{
  makeEmpty();
}

/**
 *  Returns the number of entries stored in the dictionary.  Entries with
 *  the same key (or even the same key and value) each still count as
 *  a separate entry.
 *  @return number of entries in the dictionary.
 **/
template <typename K, typename V>
int BinaryTree<K, V>::size()
{
  return tsize;
}

/**
 *  Tests if the dictionary is empty.
 *
 *  @return true if the dictionary has no entries; false otherwise.
 **/
template <typename K, typename V>
bool BinaryTree<K, V>::isEmpty()
{
  return size() == 0;
}

template <typename K, typename V>
void BinaryTree<K, V>::insertHelper(Entry<K, V> *entry, const K &key, BinaryTreeNode<K, V> *node)
{
  if (key.compareTo(node->entry->getkey()) <= 0)
  {
    if (node->leftChild == NULL)
    {
      node->leftChild = new BinaryTreeNode<K, V>(entry, node);
    }
    else
    {
      insertHelper(entry, key, node->leftChild);
    }
  }
  else
  {
    if (node->rightChild == NULL)
    {
      node->rightChild = new BinaryTreeNode<K, V>(entry, node);
    }
    else
    {
      insertHelper(entry, key, node->rightChild);
    }
  }
}

/**
 *  Create a new Entry object referencing the input key and associated value,
 *  and insert the entry into the dictionary.
 *  Multiple entries with the same key (or even the same key and
 *  value) can coexist in the dictionary.
 *
 *  @param key the key by which the entry can be retrieved.
 *  @param value an arbitrary object.
 **/
template <typename K, typename V>
void BinaryTree<K, V>::insert(const K &key, const V &value)
{
  Entry<K, V> *entry = new Entry<K, V>(key, value);
  if (root == NULL)
  {
    root = new BinaryTreeNode<K, V>(entry);
  }
  else
  {
    insertHelper(entry, key, root);
  }
  tsize++;
}

/**
 *  Search for a node with the specified key, starting from "node".  If a
 *  matching key is found (meaning that key1.compareTo(key2) == 0), return
 *  a node containing that key.  Otherwise, return null.
 *
 *  Be sure this method returns null if node == null.
 **/
template <typename K, typename V>
BinaryTreeNode<K, V> *BinaryTree<K, V>::findHelper(const K &key, BinaryTreeNode<K, V> *node)
{
  if (node == NULL)
    return NULL;
  if (key.compareTo(node->entry->getkey()) == 0)
    return node;
  if (key.compareTo(node->entry->getkey()) < 0)
    return findHelper(key, node->leftChild);
  return findHelper(key, node->rightChild);
}

/**
 *  Search for an entry with the specified key.  If such an entry is found,
 *  return true; otherwise return false.
 *
 *  @param key the search key.
 *  @return an entry containing the key and an associated value, or null if
 *          no entry contains the specified key.
 **/
template <typename K, typename V>
Entry<K, V> *BinaryTree<K, V>::find(const K &key)
{
  BinaryTreeNode<K, V> *node = findHelper(key, root);
  if (node != NULL)
  {
    return node->entry;
  }
  else
  {
    return NULL;
  }
}

/**
 *  Remove an entry with the specified key.  If such an entry is found,
 *  remove it from the table.
 *  If several entries have the specified key, choose one arbitrarily, then
 *  remove it.
 *
 *  @param key the search key.
 */
template <typename K, typename V>
void BinaryTree<K, V>::remove(const K &key)
{
  BinaryTreeNode<K, V> *node = findHelper(key, root);
  if (node != NULL)
  {

    // case 1: two child
    if (node->leftChild != NULL && node->rightChild != NULL)
    {
      BinaryTreeNode<K, V> *min = findMinNode(node->rightChild);
      if (min != NULL)
      {
        delete node->entry;
        node->entry = new Entry<K, V>(min->entry->getkey(), min->entry->getvalue());
        replaceHelper(min, min->rightChild);
      }
    }

    // case 2: one child
    else if (node->leftChild != NULL)
      replaceHelper(node, node->leftChild);
    else if (node->rightChild != NULL)
      replaceHelper(node, node->rightChild);

    // case 3: no childs
    else
      replaceHelper(node, NULL);
  }
}

/**
 *  Remove all entries from the dictionary.
 */
template <typename K, typename V>
void BinaryTree<K, V>::makeEmpty()
{
  emptyHelper(root);
  tsize = 0;
}

/**
 *  Convert the tree into a string.
 **/
template <typename K, typename V>
std::string BinaryTree<K, V>::toString()
{
  if (root == NULL)
  {
    return "";
  }
  else
  {
    return root->toString();
  }
}

template <typename K, typename V>
void BinaryTree<K, V>::replaceHelper(BinaryTreeNode<K, V> *a, BinaryTreeNode<K, V> *b)
{
  if (a == NULL)
    return;

  if (a == root)
    root = b;
  else
  {
    if (a->parent->leftChild == a)
      a->parent->leftChild = b;
    else
      a->parent->rightChild = b;
    if (b != NULL)
      b->parent = a->parent;
  }

  delete a;
  tsize--;
}

template <typename K, typename V>
BinaryTreeNode<K, V> *BinaryTree<K, V>::findMinNode(BinaryTreeNode<K, V> *node)
{
  if (node == NULL)
    return NULL;
  if (node->leftChild == NULL)
    return node;
  return findMinNode(node->leftChild);
}

template <typename K, typename V>
void BinaryTree<K, V>::emptyHelper(BinaryTreeNode<K, V> *node)
{
  if (node != NULL)
  {
    emptyHelper(node->leftChild);
    emptyHelper(node->rightChild);
    delete node;
  }
}