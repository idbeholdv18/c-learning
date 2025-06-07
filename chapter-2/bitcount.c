#include <stdio.h>

int bitcount(unsigned int x);
int fast_bitcount(unsigned int x);

int main() {
    int x = 342;
    printf("%d has %d bits\n", x, bitcount(x));
    printf("%d has %d bits\n", x, fast_bitcount(x));

    return 0;
}

int bitcount(unsigned int x) {
    int b;

    for (b = 0; x != 0; x >>= 1)
        if (x & 0b1)
            b++;

    return b;
}

int fast_bitcount(unsigned int x) {
    int i = 0;
    for (; x != 0; x &= (x - 1))
        i++;

    return i;
}
