#include "queue.h"

void queue_init(Queue *queue) {
    queue->enqueue = enqueue;
    queue->dequeue = dequeue;
    queue->head = NULL;
    queue->tail = NULL;
}

int enqueue(Queue *queue, void *item) {
    int status = UNDEFINED;
    if (queue) {
        Node *node = (Node *) malloc(sizeof(Node));
        node->item = item;
        if (queue->head) {
            queue->head->next = node;
        }
        queue->head = node;
        if (!queue->tail) {
            queue->tail = node;
        }
        status = SUCCESS;
    }

    return status;
}

void *dequeue(Queue *queue) {
    if (!queue || !queue->tail)
        return NULL;

    Node *node = queue->tail;
    queue->tail = node->next;
    void *item = node->item;
    free(node);
    return item;
}