#include <stdio.h>

int main() {
    int c, lim;
    char s[lim];

    for (int i = 0; i < lim - 1; ++i) {
        c = getchar();
        if (c == '\n')
            break;
        if (c == EOF)
            break;
        s[i] = c;
    }
}