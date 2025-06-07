#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

void escape(char from[], char to[]);

int main() {
    char from[] = "tesing\tstring\nfor\t this task";
    char to[MAX_LEN];
    escape(from, to);

    printf("was: %s\n", from);
    printf("become: %s\n", to);
    return 0;
}

void escape(char from[], char to[]) {
    int k = 0;
    for (int i = 0; from[i] != '\0'; i++) {
        switch (from[i]) {

        case '\t':
            to[k++] = '\\';
            to[k++] = 't';
            break;
        case '\n':
            to[k++] = '\\';
            to[k++] = 'n';
            break;
        default:
            to[k++] = from[i];
        }
    }
    to[k] = '\0';
}