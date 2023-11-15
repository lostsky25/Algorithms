#include <stdio.h>
#include <stdlib.h>

#define ERR_OUT_OF_RANGE    1
#define ERR_EMPTY_STACK     2
#define ERR_BAD_ALLOC       3

#define ALLOCATED_MEM_SIZE  10

#define TEST_ARR_SIZE       10

typedef int Data;
typedef struct {
    Data* a;
    unsigned int n;
    size_t size;
} Stack;

void print(Stack*);

void init(Stack*);
void push(Stack*, Data);
Data pop(Stack*);
int is_empty(Stack*);
int is_full(Stack*);
void destroy(Stack*);

int main() {
    Data test[TEST_ARR_SIZE] = { 5, 17, -3, 0, 1, 2, 3, 4, 0, 1 };

    Stack s;
    Stack* st = &s;

    init(st);
    printf("empty: %s\n", is_empty(st) ? "YES" : "NO");         // YES
    printf("full: %s\n", is_full(st) ? "YES" : "NO");           // NO
    print(st);

    Data d;
    for (int i = 0; i < TEST_ARR_SIZE; ++i) {
        d = test[i];
        printf("push %d : ", d);
        push(st, d);
        print(st);
        printf("empty: %s\n", is_empty(st) ? "YES" : "NO");     // NO
    }

    printf("full: %s\n", is_full(st) ? "YES" : "NO");           // YES

    while (!is_empty(st)) {
        d = pop(st);
        printf("pop %d : ", d);
        print(st);
    }
    printf("empty: %s\n", is_empty(st) ? "YES" : "NO");         // YES

    destroy(st);

    return 0;
}

void destroy(Stack* st) {
    if (st->a != NULL) {
        free(st->a);
        st->n = 0;
        st->size = 0;
        st->a = NULL;
    }
}

void print(Stack* st) {
    for (unsigned int i = 0; i < st->n; ++i) {
        printf("%d ", st->a[i]);
    }
    printf("\n");
}

void init(Stack* st) {
    st->n = 0;
    st->size = ALLOCATED_MEM_SIZE;
    st->a = NULL;
}

void push(Stack* st, Data data) {

    if (st->a == NULL) {
        st->a = (Data*)malloc(st->size * sizeof(Data));
    }

    if (is_full(st)) {
        st->size += ALLOCATED_MEM_SIZE;
        st->a = (Data*)realloc(st->a, st->size * sizeof(Data));
    }

    if (st->a == NULL) {
        exit(ERR_BAD_ALLOC);
    }

    st->a[st->n] = data;
    st->n++;
}

Data pop(Stack* st) {
    if (!is_empty(st)) {
        Data res = st->a[st->n - 1];
        st->n--;
        return res;
    }
    else {
        exit(ERR_EMPTY_STACK);
    }
}

int is_empty(Stack* st) {
    return st->n == 0;
}

int is_full(Stack* st) {
    return st->n == st->size && st->n != 0;
}