#include <stdio.h>

int main() {
    int a = 0, b = 3;
    int *a_ptr, *b_ptr;

    a_ptr = &a;
    b_ptr = &b;

    // 0 - 3
    printf("value of a: %d\nvalue of b: %d\n\n", *a_ptr, *b_ptr);

    a_ptr = b_ptr;

    // 3 - 3
    printf("value of a: %d\nvalue of b: %d\n\n", *a_ptr, *b_ptr);

    *a_ptr = 5;

    // 5 - 5
    printf("value of a: %d\nvalue of b: %d\n\n", *a_ptr, *b_ptr);

    *b_ptr = 6;

    // 6 - 6
    printf("value of a: %d\nvalue of b: %d\n\n", *a_ptr, *b_ptr);
}