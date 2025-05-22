#include <stdio.h>

int main() {
    int c, sc;
    sc = 0;

    while((c = getchar()) != EOF) {
        if (c == ' ') {
            ++sc;
            if (sc == 1) putchar(c);
        } else {
            sc = 0;
            putchar(c);
        }
    }
}