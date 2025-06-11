#include <stdio.h>
#include <string.h>

int strend(char *s, char *t);

int main() {
    char *str_1 = "hello, world";
    char *str_2 = ", world";

    printf("res: %d\n", strend(str_1, str_2));
}

int strend(char *s, char *t) {
    s += strlen(s) - strlen(t);
    printf("s is: %s\n", s);
    for (int i = 0; i < strlen(t) - 1; i++) {
        if (s[i] != t[i])
            return 0;
    }

    return 1;
}
