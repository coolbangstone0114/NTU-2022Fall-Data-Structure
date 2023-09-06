/**
 *  A DList is a mutable doubly-linked list ADT.  Its implementation is
 *  circularly-linked and employs a sentinel (dummy) node at the head
 *  of the list.
 *
 *  DO NOT CHANGE ANY METHOD PROTOTYPES IN THIS FILE.
 */

#ifndef DLIST_H
#define DLIST_H

#include "DListNode.h"

template<typename T>
class DList {

	/**
	 *  head references the sentinel node.
	 *  size is the number of items in the list.  (The sentinel node does not
	 *       store an item.)
	 *
	 *  DO NOT CHANGE THE FOLLOWING FIELD DECLARATIONS.
	 */

protected:
	DListNode<T>* head;
	int size;

	/* DList invariants:
	 *  1)  head != null.
	 *  2)  For any DListNode x in a DList, x.next != null.
	 *  3)  For any DListNode x in a DList, x.prev != null.
	 *  4)  For any DListNode x in a DList, if x.next == y, then y.prev == x.
	 *  5)  For any DListNode x in a DList, if x.prev == y, then y.next == x.
	 *  6)  size is the number of DListNodes, NOT COUNTING the sentinel,
	 *      that can be accessed from the sentinel (head) by a sequence of
	 *      "next" references.
	 */

	/**
	 *  newNode() calls the DListNode constructor.  Use this class to allocate
	 *  new DListNodes rather than calling the DListNode constructor directly.
	 *  That way, only this method needs to be overridden if a subclass of DList
	 *  wants to use a different kind of node.
	 *  @param item the item to store in the node.
	 *  @param prev the node previous to this node.
	 *  @param next the node following this node.
	 */
	virtual DListNode<T>* newNode(const T& item, DListNode<T>* prev, DListNode<T>* next);

public:
	/**
	 *  DList() constructor for an empty DList.
	 */
	DList();

	/**
	 *  isEmpty() returns true if this DList is empty, false otherwise.
	 *  @return true if this DList is empty, false otherwise. 
	 *  Performance:  runs in O(1) time.
	 */
	bool isEmpty();

	/** 
	 *  length() returns the length of this DList. 
	 *  @return the length of this DList.
	 *  Performance:  runs in O(1) time.
	 */
	int length();

	/**
	 *  insertFront() inserts an item at the front of this DList.
	 *  @param item is the item to be inserted.
	 *  Performance:  runs in O(1) time.
	 */
	void insertFront(const T& item);

	/**
	 *  insertBack() inserts an item at the back of this DList.
	 *  @param item is the item to be inserted.
	 *  Performance:  runs in O(1) time.
	 */
	void insertBack(const T& item);

	/**
	 *  front() returns the node at the front of this DList.  If the DList is
	 *  empty, return null.
	 *
	 *  Do NOT return the sentinel under any circumstances!
	 *
	 *  @return the node at the front of this DList.
	 *  Performance:  runs in O(1) time.
	 */
	DListNode<T>* front();

	/**
	 *  back() returns the node at the back of this DList.  If the DList is
	 *  empty, return null.
	 *
	 *  Do NOT return the sentinel under any circumstances!
	 *
	 *  @return the node at the back of this DList.
	 *  Performance:  runs in O(1) time.
	 */
	DListNode<T>* back();

	/**
	 *  next() returns the node following "node" in this DList.  If "node" is
	 *  null, or "node" is the last node in this DList, return null.
	 *
	 *  Do NOT return the sentinel under any circumstances!
	 *
	 *  @param node the node whose successor is sought.
	 *  @return the node following "node".
	 *  Performance:  runs in O(1) time.
	 */
	DListNode<T>* next(DListNode<T>* node);

	/**
	 *  prev() returns the node prior to "node" in this DList.  If "node" is
	 *  null, or "node" is the first node in this DList, return null.
	 *
	 *  Do NOT return the sentinel under any circumstances!
	 *
	 *  @param node the node whose predecessor is sought.
	 *  @return the node prior to "node".
	 *  Performance:  runs in O(1) time.
	 */
	DListNode<T>* prev(DListNode<T>* node);

	/**
	 *  insertAfter() inserts an item in this DList immediately following "node".
	 *  If "node" is null, do nothing.
	 *  @param item the item to be inserted.
	 *  @param node the node to insert the item after.
	 *  Performance:  runs in O(1) time.
	 */
	void insertAfter(const T& item, DListNode<T>* node);

	/**
	 *  insertBefore() inserts an item in this DList immediately before "node".
	 *  If "node" is null, do nothing.
	 *  @param item the item to be inserted.
	 *  @param node the node to insert the item before.
	 *  Performance:  runs in O(1) time.
	 */
	void insertBefore(const T& item, DListNode<T>* node);

	/**
	 *  remove() removes "node" from this DList.  If "node" is null, do nothing.
	 *  Performance:  runs in O(1) time.
	 */
	void remove(DListNode<T>* node);

	/**
	 *  toString() prints a string representation of this DList.
	 *
	 *  DO NOT CHANGE THIS METHOD.
	 *
	 *  Performance:  runs in O(n) time, where n is the length of the list.
	 */
	void toString();
};

#endif
