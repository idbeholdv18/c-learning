#include <stdio.h>

int setbits(int x, int p, int n, int y);

int main() {
    int passed = 170, mask = 15, start = 4, count = 3;

    printf("passed:\t%d\nmask:\t%d\nstart:\t%d\ncount:\t%d\nres:\t%d\n", passed, mask,
           start, count, setbits(passed, start, count, mask));
}

int setbits(int x, int p, int n, int y) {
    unsigned int mask = (1U << n) - 1;
    unsigned int y_bits = y & mask;
    y_bits = y_bits << (p - n + 1);
    x = x & ~(mask << (p - n + 1));
    return x | y_bits;
}