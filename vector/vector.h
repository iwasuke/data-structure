#define VECTOR_INIT_CAPACITY 6
#define UNDEFINE -1
#define SUCCESS 0
#define TRUE 1
#define FALSE 0
#define VECTOR_INIT(vec) vector vec; \
    vector_init(&vec)

typedef struct sVectorList {
    void **items;
    int capacity;
    int total;
} sVectorList;

typedef struct sVector vector;

struct sVector {
    sVectorList vectorList;

    int (*pfVectorTotal)(vector *);

    int (*pfVectorResize)(vector *, int);

    int (*pfVectorAdd)(vector *, void *);

    int (*pfVectorSet)(vector *, int, void *);

    void *(*pfVectorGet)(vector *, int);

    int (*pfVectorDelete)(vector *, int);

    int (*pfVectorFree)(vector *);

    int (*pfVectorIsEmpty)(vector *);

    int (*pfVectorInsert)(vector *, int, void *);

    int (*pfVectorRemove)(vector *, void *);

    int (*pfVectorFind)(vector *, void *);
};

int vectorTotal(vector *v);

int vectorResize(vector *v, int capacity);

int vectorPushBack(vector *v, void *item);

int vectorSet(vector *v, int index, void *item);

void *vectorGet(vector *v, int index);

int vectorDelete(vector *v, int index);

int vectorFree(vector *v);

int vectorIsEmpty(vector *v);

int vectorInsert(vector *v, int index, void *item);

int vectorRemove(vector *v, void *item);

int vectorFind(vector *v, void *item);

void vector_init(vector *v);