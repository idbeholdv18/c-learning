#include <stdio.h>
#include <string.h>

#define BUF_SIZE 100

void itoa(int n, char s[], int min_width);
void create_spaces(char s[], int count);
void reverse(char s[]);

int main() {
    int passed = -123, min_width = 12;
    char s[BUF_SIZE];
    char spaces[min_width + 1];

    itoa(passed, s, min_width);
    create_spaces(spaces, min_width);

    printf("passed: %d\n%s\n%s\n", passed, spaces, s);

    return 0;
}

void create_spaces(char s[], int count) {
    int i = 0;
    for (i = 0; i < count; i++)
        s[i] = '_';

    s[i] = '\0';
}

void reverse(char s[]) {
    int i, k, c;

    for (i = 0, k = strlen(s) - 1; i < k; i++, k--) {
        c = s[i];
        s[i] = s[k];
        s[k] = c;
    }
}

void itoa(int n, char s[], int min_width) {
    int i = 0;
    int is_negative = 0;
    unsigned int num;

    if (n < 0) {
        is_negative = 1;
        num = -n;
    } else {
        num = n;
    }

    if (num == 0) {
        s[i++] = '0';
    } else {
        while (num > 0) {
            s[i++] = '0' + (num % 10);
            num /= 10;
        }
    }

    if (is_negative)
        s[i++] = '-';

    while (i < min_width) {
        s[i++] = ' ';
    }

    s[i] = '\0';

    reverse(s);
}