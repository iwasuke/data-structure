#include <stdio.h>
#include "vector.h"

int main() {
    int i = 0;
    VECTOR_INIT(v);
    v.pfVectorAdd(&v, "aiueo\n");
    v.pfVectorAdd(&v, "あいうえお\n");
    v.pfVectorAdd(&v, "kakikukeko\n");
    v.pfVectorAdd(&v, "あいうえお\n");
    v.pfVectorAdd(&v, "sasisuseso\n");
    v.pfVectorAdd(&v, "あいうえお\n");

    for (i = 0; i < v.pfVectorTotal(&v); i++) {
        printf("%s", (char*)v.pfVectorGet(&v, i));
    }

    v.pfVectorSet(&v, 0, "あいうえお\n");
    v.pfVectorInsert(&v, 2, "かきくけこ\n");
    v.pfVectorRemove(&v, "あいうえお\n");
    printf("\n\n\nVector list after changes\n\n\n");

    for (i = 0; i < v.pfVectorTotal(&v); i++) {
        printf("%s", (char*)v.pfVectorGet(&v, i));
    }

    printf("%d\n", vectorFind(&v, "sasisuseso\n"));
    printf("%d\n", vectorFind(&v, "ああ\n"));
    return 0;
}
