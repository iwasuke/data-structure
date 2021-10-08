#include <stdlib.h>

#define UNDEFINED -1
#define SUCCESS 0

#define SINGLE_LINKED_LIST_INIT(sll) singleLinkedList sll; \
    singleLinkedList_init(&sll)

typedef struct sNode sNode;
struct sNode {
    sNode *next;
    void **item;
};

typedef struct sSingleLinkedList singleLinkedList;

struct sSingleLinkedList {
    sNode *head;
    int size;
    int (*pushFront)(singleLinkedList *, void *);
    void *(*popFront)(singleLinkedList *);
    void *(*valueAt)(singleLinkedList *, int);
    int (*empty)(singleLinkedList *);
    int (*pushBack)(singleLinkedList *, void *);
    void *(*popBack)(singleLinkedList *);
};

int pushFront(singleLinkedList *sll, void *item);

void *popFront(singleLinkedList *sll);

void singleLinkedList_init(singleLinkedList *sll);

void *valueAt(singleLinkedList *sll, int index);

int empty(singleLinkedList *sll);

int pushBack(singleLinkedList *sll, void *item);

void *popBack(singleLinkedList *sll);