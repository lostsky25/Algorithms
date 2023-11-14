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

int main() {
    Stack s = {{7, 4, 1}, 3};
    Stack* st = &s;

    init(st);
    print(st);

    Data d;
    d = 5;
    printf("push %d :", d);
    push(st, 5);
    print(st);      // 5

    d = 17;
    printf("push %d :", d);
    push(st, 17);
    print(st);      // 5 17

    d = -3;
    printf("push %d :", d);
    push(st, d);
    print(st);      // 5 17 -3

    d = pop(st);
    printf("pop %d :", d);
    print(st);      // pop -3: 5 17
    
    d = pop(st);
    printf("pop %d :", d);
    print(st);      // pop 17: 5
    
    d = pop(st);
    printf("pop %d :", d);
    print(st);      // pop 5:
    return 0;
}
