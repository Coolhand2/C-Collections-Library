#ifndef SLIST_H_
#define SLIST_H_

#include <slistnode.h>

typedef struct slist SList;
extern SList _SList;

struct slist {
	SListNode *front;
	int count;

	SList *(*new)(void);
	void (*free)(SList **list);
	SList *(*clone)(SList *this);
	int (*equals)(SList *this, SList *that);

	void *(*peek)(SList *this);

	void (*push)(SList *this, void *value);
	void *(*pop)(SList *this);

	void (*shift)(SList *this, void *value);
	void *(*unshift)(SList *this);

	void (*set)(SList *this, void *value, int index);
	void *(*get)(SList *this, int index);

	int (*indexOf)(SList *this, void *value);

	int (*contains)(SList *this, void *value);
	int (*containsAll)(SList *this, SList *list);

	void (*clear)(SList *this);
	void (*remove)(SList *this, void *value);
	void (*removeAll)(SList *this, SList *list);

	void (*retain)(SList *this, void *value);
	void (*retainAll)(SList *this, SList *list);

	int (*size)(SList *this);
};

#endif /* SLIST_H_ */
