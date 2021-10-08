#include <stdio.h>
#include "singly-linked-lists.h"

int main() {
    SINGLE_LINKED_LIST_INIT(sll);

    printf("%d\n", sll.empty(&sll));
    sll.pushFront(&sll, "かきくけこ");
    sll.pushFront(&sll, "あいうえお");
    sll.pushBack(&sll, "さしすえそ");
    printf("%d\n", sll.size);
    printf("%s\n", (char*)sll.valueAt(&sll, 1));
    printf("%s\n", (char*)sll.popFront(&sll));
    printf("%s\n", (char*)sll.popBack(&sll));
}