#include <stdio.h>

int htoi(char str[]);
int my_pow(int a, int p);
int hex_val(char c);

int main() {
    printf("%d\n", htoi("0x1A"));
    printf("%d\n", htoi("FF"));
    printf("%d\n", htoi("0Xabc"));
    return 0;
}

int my_pow(int a, int p) {
    int res = a;

    for (int i = 0; i < p; i++) {
        res *= a;
    }

    return res;
}

int hex_val(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    return -1;
}

int htoi(char str[]) {
    int n, i, res, p;
    int chars[1000];

    i = n = res = 0;

    if (str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X'))
        i = 2;

    while ((p = hex_val(str[i])) >= 0) {
        chars[n++] = p;
        i++;
    }

    for (int k = 0; k < n; k++) {
        res += my_pow(16, n - k - 1) * chars[k];
    }

    return res;
}