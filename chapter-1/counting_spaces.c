#include <stdio.h>

int main() {
    int c;
    int space_count, tab_count, newline_count;
    space_count = tab_count = newline_count = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') ++space_count;
        if (c == '\t') ++tab_count;
        if (c == '\n') ++newline_count;
    }

    printf("spaces: \t%5d\ntabs: \t%5d\nnew_lines: \t%5d\n", space_count, tab_count, newline_count);
}