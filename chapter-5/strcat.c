#include <stdio.h>
#include <string.h>

char *my_strcat(char *s, char *t);

int main() {
    char *str_1 = "hello";
    char *str_2 = ", world";

    printf("res: %s\n", my_strcat(str_1, str_2));
}

char *my_strcat(char *s, char *t) {
    char *cat;
    int i = 0;
    for (; *s != '\0';) {
        cat[i++] = *s++;
    }

    for (; *t != '\0';) {
        cat[i++] = *t++;
    }

    cat[i] = '\0';

    return cat;
}