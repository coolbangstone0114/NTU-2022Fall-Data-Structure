#ifndef LOCKDLISTNODE_H
#define LOCKDLISTNODE_H

#include "DListNode.h"
template <typename T>
class LockDList;

template <typename T>
class LockDListNode : DListNode<T>
{
protected:
	bool lock;
	friend class LockDList<T>;

public:
	LockDListNode(const T &i, DListNode<T> *p, DListNode<T> *n) : DListNode<T>(i, p, n)
	{
		lock = false;
	}
};
#endif
