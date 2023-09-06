
#ifndef LOCKDLIST_H
#define LOCKDLIST_H

#include "LockDListNode.h"
#include "DList.h"
#include <iostream>
template <typename T>
class LockDList : public DList<T>
{
public:
	LockDList();
	void lockNode(DListNode<T> *node);
	void remove(DListNode<T> *node);

protected:
	virtual DListNode<T> *newNode(const T &item, DListNode<T> *prev, DListNode<T> *next)
	{
		return new LockDListNode<T>(item, prev, next);
	}
};
#endif

template <typename T>
void LockDList<T>::remove(DListNode<T> *node)
{
	LockDListNode<T> *b = static_cast<LockDListNode<T> *>(node);
	if (b != NULL && b->lock == false)
	{
		DList<T>::remove(node);
	}
}
template <typename T>
void LockDList<T>::lockNode(DListNode<T> *node)
{
	if (node != NULL)
	{
		LockDListNode<T> *b = static_cast<LockDListNode<T> *>(node);
		b->lock = true;
	}
}
template <typename T>
LockDList<T>::LockDList() : DList<T>::DList(){}
