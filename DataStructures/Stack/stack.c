#include <stdio.h>

#define N 8

typedef int Data;
typedef struct {
    Data a[N];
    unsigned int n;
} Stack;

int main() {

    Stack s = {{7, 4, 1}, 3};
    Stack* st = &s;

    return 0;
}
