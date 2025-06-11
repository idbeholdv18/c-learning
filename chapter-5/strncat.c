#include <stdio.h>
#include <string.h>

#define BUF_SIZE 100

void my_strncat(char *s, char *t, int n);

int main() {
    char str_1[BUF_SIZE] = "hello";
    char *str_2 = ", world";
    my_strncat(str_1, str_2, 3);
    printf("res: %s\n", str_1);
    return 0;
}

void my_strncat(char *s, char *t, int n) {
    while (*s) {
        s++;
    }

    while (n-- > 0 && *t) {
        *s++ = *t++;
    }

    *s = '\0';
}