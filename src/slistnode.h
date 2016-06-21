#ifndef SLISTNODE_H_
#define SLISTNODE_H_

typedef struct slistnode SListNode;
typedef int (*SListNodeCompare)(SListNode *this, SListNode *that);
extern SListNode _SListNode;

struct slistnode {
	void *value;
	SListNode *next;
	SListNodeCompare comparator;

	SListNode *(*new)(void *value);
	void       (*free)(SListNode **node);
	SListNode *(*clone)(SListNode *this);
	int        (*equals)(SListNode *this, SListNode *that);

	void *(*getValue)(SListNode *this);
	void  (*setValue)(SListNode *this, void *value);

	SListNode *(*getNext)(SListNode *this);
	void       (*setNext)(SListNode *this, void *value);

	void (*setComparator)(SListNode *this, SListNodeCompare comparator);
};

#endif /* SLISTNODE_H_ */
