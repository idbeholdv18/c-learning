#include <stdio.h>

#define BUF_SIZE 100

void my_strncpy(char *s, char *t, int n);

int main() {
    char *str_1 = "hello, world";
    char str_2[BUF_SIZE];

    my_strncpy(str_1, str_2, 5);

    printf("res: %s\n", str_2);
}

void my_strncpy(char *s, char *t, int n) {
    int i = 0;
    while (i < n) {
        t[i] = s[i];
        i++;
    }
    t[i] = '\0';
}
