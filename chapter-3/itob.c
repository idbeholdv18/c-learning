#include <stdio.h>
#include <string.h>

#define BUF_SIZE 100

void itob(int n, char s[], int b);
void reverse(char s[]);

int main() {
    int passed = -123456;
    int base = 16;
    char s[BUF_SIZE];
    itob(passed, s, base);

    printf("passed: %d\nbase: %d\noutput: %s\n", passed, base, s);
}

void reverse(char s[]) {
    int c, i, k;
    for (i = 0, k = strlen(s) - 1; i < k; i++, k--) {
        c = s[i];
        s[i] = s[k];
        s[k] = c;
    }
}

void itob(int n, char s[], int b) {
    int i = 0, is_negative = 0, l;
    if (!n) {
        s[i++] = '0';
        s[i] = '\0';
        return;
    }
    if (n < 0) {
        is_negative = 1;
        n *= -1;
    }

    while (n > 0) {
        l = n % b;
        n /= b;
        if (b > 10 && l >= 10) {
            s[i++] = 'a' + (l - 10);
            continue;
        }
        s[i++] = '0' + l;
    }

    if (is_negative)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}
