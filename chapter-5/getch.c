#include "getch.h"

int getch(void) {
    return (buf_p > 0) ? buf[--buf_p] : getchar();
}

void ungetch(int c) {
    if (buf_p >= BUF_SIZE)
        printf("ungetch: too many characters\n");
    else
        buf[buf_p++] = c;
}