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


int main() {
    Stack s = {{7, 4, 1}, 3};
    Stack* st = &s;

    print(st);

    return 0;
}
