#include <stdio.h>

int main() {
    int original = 0x87654321;

    printf("%8x\n", original & 0xFF);
    printf("%8x\n", original ^ ~0xFF);
    printf("%8x\n", original | 0xFF);
}