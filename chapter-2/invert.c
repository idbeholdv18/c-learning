#include <stdio.h>

int invert(int x, int p, int n);

int main() {
    int passed = 172, start = 4, count = 3;

    printf("passed:\t%d\nstart:\t%d\ncount:\t%d\nres:\t%d\n", passed, start,
           count, invert(passed, start, count));
}

int invert(int x, int p, int n) {
    int res = 0;
    int mask = (1U << n) - 1;
    mask = mask << (p - n + 1);
    return x ^ mask;
}