#include <stdio.h>

typedef unsigned char *byte_ptr;

void show_bytes(byte_ptr, size_t);

void show_int(int);
void show_float(float);
void show_ptr(void *);

int main() {
    int a = 5;
    float b = (float) a;
    int *c = &a;

    show_int(a);
    show_float(b);
    show_ptr(c);
}

void show_bytes(byte_ptr ptr, size_t len) {
    for (register int i = 0; i < len; i++) {
        printf(" %2x", ptr[i]);
    }
    printf("\n");
}

void show_int(int a) { show_bytes((byte_ptr)&a, sizeof(int)); }

void show_float(float a) { show_bytes((byte_ptr)&a, sizeof(float)); }

void show_ptr(void *a) { show_bytes((byte_ptr)&a, sizeof(void *)); }