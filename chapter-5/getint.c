#include "getch.h"
#include <ctype.h>
#include <stdio.h>

#define SIZE 100

int getch(void);
void ungetch(int);
int getint(int *n_ptr);

int main() {
    int n, array[SIZE], getint(int *);
    for (n = 0; n < SIZE && (getint(&array[n])) != EOF; n++)
        ;
}

int getint(int *n_ptr) {
    int c, sign;

    while (isspace(c = getch()))
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
        c = getch();

    for (*n_ptr = 0; isdigit(c); c = getch())
        *n_ptr = 10 * *n_ptr + (c - '0');

    *n_ptr *= sign;

    if (c != EOF)
        ungetch(c);
    return c;
}
