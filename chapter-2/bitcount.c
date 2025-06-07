#include <stdio.h>

int bitcount(unsigned int x);

int main() {
    int x = 342;
    printf("%d has %d 1 bits\n", x, bitcount(342));

    return 0;
}

int bitcount(unsigned int x) {
    int b;

    for (b = 0; x != 0; x >>= 1)
        if (x & 0b1)
            b++;

    return b;
}
