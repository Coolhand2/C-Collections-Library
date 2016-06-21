#ifndef DLISTNODE_H_
#define DLISTNODE_H_

typedef struct dlistode DListNode;
typedef int (*DListNodeCompare)(DListNode *this, DListNode *that);
extern DListNode _DListNode;

struct dlistnode {
	void *value;
	DListNode *previous;
	DListNode *next;
	DListNodeCompare comparator;

	DListNode *(*new)(void *value);
	void (*free)(DListNode **node);
	int (*clone)(DListNode *this);
	int (*equals)(DListNode *this, DListNode *that);

	void *(*getValue)(DListNode *this);
	void  (*setValue)(DListNode *this, void *value);

	DListNode *(*getPrevious)(DListNode *this);
	void       (*setPrevious)(DListNode *this, DListNode *previous);

	DListNode *(*getNext)(DListNode *this);
	void       (*setNext)(DListNode *this, DListNode *next);

	void (*setComparator)(DListNode *this, DListNodeCompare comparator);
};

#endif /* DLISTNODE_H_ */
