#include <stdio.h>

int main()
{
    int c;
    c = getchar() != EOF;

    printf("Result: %d\n", c);
}