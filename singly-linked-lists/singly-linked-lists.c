#include "singly-linked-lists.h"

int pushFront(singleLinkedList *sll, void *item) {
    int status = UNDEFINED;
    if (sll) {
        sNode *node = (sNode *) malloc(sizeof(sNode));
        if (node) {
            node->item = item;
            if (sll->head)
                node->next = sll->head;
            else
                node->next = NULL;
            sll->head = node;
            sll->size++;
            status = SUCCESS;
        }
    }

    return status;
}

void *popFront(singleLinkedList *sll) {
    if (sll && sll->head) {
        sNode *head = sll->head;
        sll->head = sll->head->next;
        void *item = head->item;
        free(head);
        sll->size--;
        return item;
    }
    return NULL;
}

void *valueAt(singleLinkedList *sll, int index) {
    if (sll && sll->head) {
        if (sll->size < index)
            return NULL;

        sNode *current = sll->head;
        if (index == 0)
            return current->item;
        for (int i = 1; i <= index; ++i) {
            current = current->next;
        }
        return current->item;
    }

    return NULL;
}

void singleLinkedList_init(singleLinkedList *sll) {
    sll->pushFront = pushFront;
    sll->popFront = popFront;
    sll->valueAt = valueAt;
    sll->empty = empty;
    sll->pushBack = pushBack;
    sll->popBack = popBack;
    sll->head = NULL;
    sll->size = 0;
}

int empty(singleLinkedList *sll) {
    return sll->size == 0;
}

int pushBack(singleLinkedList *sll, void *item) {
    int status = UNDEFINED;
    if (sll) {
        sNode *newNode = (sNode *) malloc(sizeof(sNode));
        newNode->item = item;
        if (!sll->head) {
            sll->head = newNode;
        } else {
            sNode *node = sll->head;
            while (node->next != NULL) {
                node = node->next;
            }
            node->next = newNode;
        }
        sll->size++;
        status = SUCCESS;
    }
    return status;
}

void *popBack(singleLinkedList *sll) {
    if (!sll || !sll->head)
        return NULL;

    sNode *node = sll->head;
    sNode *prevNode = NULL;
    while (node->next != NULL) {
        prevNode = node;
        node = node->next;
    }
    prevNode->next = NULL;
    void *item = node->item;
    free(node);
    sll->size--;
    return item;
}