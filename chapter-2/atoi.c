#include <stdio.h>

int atoi(char str[]);
int is_digit(char c);

int main() {
    int res, c, i;
    char s[100];

    i = 0;
    while ((c = getchar()) != EOF && c >= '0' && c <= '9') {
        s[i++] = c;
    }

    s[i] = '\0';

    res = atoi(s);

    if (res >= 0)
        printf("string: %s, int: %d\n", s, res);
    else
        printf("String should start from digit\n");

    return 0;
}

int is_digit(char c) { return (c >= '0' && c <= '9') ? 1 : 0; }

int atoi(char str[]) {
    int i, n;

    n = i = 0;
    if (!is_digit(str[i]))
        return -1;

    while (str[i] > 0) {
        n = n * 10 + (str[i++] - '0');
    }

    return n;
}
