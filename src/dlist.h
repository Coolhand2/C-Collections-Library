#ifndef DLIST_H_
#define DLIST_H_

#include "dlistnode.h"

typedef struct dlist DList;
extern DList _DList;

struct dlist {
	DListNode *front, *back;
	int count;

	DList *(*new)(void);
	void   (*free)(DList **list);
	DList *(*clone)(DList *this);
	int    (*equals)(DList *this, DList *that);

	void *(*peekFront)(DList *this);
	void *(*peekBack)(DList *this);

	void  (*push)(DList *this, void *value);
	void *(*pop)(DList *this);

	void  (*shift)(DList *this, void *value);
	void *(*unshift)(DList *this);

	void  (*set)(DList *this, void *value, int index);
	void *(*get)(DList *this, int index);

	int (*indexOf)(DList *this, void *value);

	int (*contains)(DList *this, void *value);
	int (*containsAll)(DList *this, DList *list);

	void (*clear)(DList *this);
	void (*remove)(DList *this, void *value);
	void (*removeAll)(DList *this, DList *list);

	void (*retain)(DList *this, void *value);
	void (*retainAll)(DList *this, DList *list);

	int (*size)(DList *this);
};

#endif /* DLIST_H_ */
