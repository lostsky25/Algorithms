#include <stdio.h>

#define N 8

typedef int Data;
typedef struct {
    Data a[N];
    unsigned int n;
} Stack;

void print(Stack* st) {
    for (unsigned int i = 0; i < st->n; ++i) {
        printf("%d ", st->a[i]);
    }
    printf("\n");
}

void init(Stack* st) {
    st->n = 0;
}

void push(Stack* st, Data data) {
    st->a[st->n] = data;
    st->n++;
}

int main() {
    Stack s = {{7, 4, 1}, 3};
    Stack* st = &s;

    init(st);
    print(st);

    push(st, 5);
    print(st);      // 5
    push(st, 17);
    print(st);      // 5 17
    push(st, -3);
    print(st);      // 5 17 -3

    return 0;
}
