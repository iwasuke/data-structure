#include <stdio.h>
#include "queue.h"

int main() {
    QUEUE_INIT(queue);
    int a = 1;
    int b = 2;
    int c = 3;
    queue.enqueue(&queue, &a);
    queue.enqueue(&queue, &b);
    queue.enqueue(&queue, &c);

    printf("%d\n", *(int *)queue.dequeue(&queue));
    printf("%d\n", *(int *)queue.dequeue(&queue));
}