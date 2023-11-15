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

Data pop(Stack* st) {
    Data res = st->a[st->n - 1];
    st->n--;
    return res;
}

int is_empty(Stack* st) {
    return st->n == 0;
}

int is_full(Stack* st) {
    return st->n == sizeof(st->a) / sizeof(st->a[0]);
}

int main() {
    Data test[N] = { 5, 17, -3, 0, 1, 2, 3, 4 };

    Stack s = {{7, 4, 1}, 3};
    Stack* st = &s;

    init(st);
    printf("empty: %s\n", is_empty(st) ? "YES" : "NO");         // YES
    printf("full: %s\n", is_full(st) ? "YES" : "NO");           // NO
    print(st);

    Data d;
    for (int i = 0; i < N; ++i) {
        d = test[i];
        printf("push %d :", d);
        push(st, d);
        print(st);      // 5
        printf("empty: %s\n", is_empty(st) ? "YES" : "NO");     // NO
    }

    printf("full: %s\n", is_full(st) ? "YES" : "NO");           // YES

    while (!is_empty(st)) {
        d = pop(st);
        printf("pop %d :", d);
        print(st);
    }
    printf("empty: %s\n", is_empty(st) ? "YES" : "NO");     // YES

    return 0;
}
