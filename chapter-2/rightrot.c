#include <stdio.h>

unsigned int rightrot(unsigned int x, int n);

int main() {
    unsigned int passed = 172, count = 3;

    printf("passed:\t%d\ncount:\t%d\nres:\t%u\n", passed, count,
           rightrot(passed, count));
}

unsigned int rightrot(unsigned int x, int n) {
    int word_len = sizeof(unsigned int) * 8;
    n = n % word_len;

    unsigned int right = x & ((1U << n) - 1);
    x = x >> n;
    right = right << (word_len - n);
    return x | right;
}
