#include <stdlib.h>

#define UNDEFINED -1
#define SUCCESS 0

#define QUEUE_INIT(queue) Queue queue; \
    queue_init(&queue)

typedef struct sNode Node;
struct sNode {
    Node *next;
    void **item;
};

typedef struct sQueue Queue;

struct sQueue {
    Node *head;
    Node *tail;
    int (*enqueue)(Queue *, void *);
    void *(*dequeue)(Queue *);
};

void queue_init(Queue *queue);

int enqueue(Queue *queue, void *item);

void *dequeue(Queue *queue);