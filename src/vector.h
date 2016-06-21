#ifndef VECTOR_H_
#define VECTOR_H_

typedef struct vector Vector;
typedef int (*VectorCompare)(void *this, void *that);
extern Vector _Vector;

#define DEFAULT_CAPACITY 100

struct vector {
	void *contents[];
	int count, expansionRate, capacity;

	Vector *(*new)(void);
	void    (*free)(Vector **vector);
	Vector *(*clone)(Vector *this);
	int (*equals)(Vector *this, Vector *that);

	void *(*peek)(Vector *this);

	void (*push)(Vector *this, void *value);
	void *(*pop)(Vector *this);

	void (*shift)(Vector *this, void *value);
	void *(*unshift)(Vector *this);

	void (*set)(Vector *this, void *value, int index);
	void *(*get)(Vector *this, int index);

	int (*indexOf)(Vector *this, void *value);

	int (*contains)(Vector *this, void *value);
	int (*containsAll)(Vector *this, Vector *list);

	void (*clear)(Vector *this);
	void (*remove)(Vector *this, void *value);
	void (*removeAll)(Vector *this, Vector *list);

	void (*retain)(Vector *this, void *value);
	void (*retainAll)(Vector *this, Vector *list);

	int (*size)(Vector *this);

};

#endif /* VECTOR_H_ */
