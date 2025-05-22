#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
    int c, state;
    int words_count;

    state = OUT;
    words_count = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            if (state == IN)
                ++words_count;
            state = OUT;
        }
        else
        {
            state = IN;
        }
    }
    if (state == IN) ++words_count;

    printf("words count: %d\n", words_count);
}
