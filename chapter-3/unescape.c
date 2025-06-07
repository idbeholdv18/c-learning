#include <stdio.h>

#define MAX_LEN 100

void unescape(char from[], char to[]);

int main() {
    char from[] = "tesing\\tstring\\nfor\\t this task\\";
    char to[MAX_LEN];
    unescape(from, to);

    printf("was: %s\n", from);
    printf("become: %s\n", to);
    return 0;
}

void unescape(char from[], char to[]) {
    int k = 0, i = 0;
    while (from[i] != '\0') {
        switch (from[i]) {
        case '\\':
            if (from[i + 1] == '\0') {
                to[k++] = '\\';
                i++;
            } else {
                switch (from[i + 1]) {
                case 't':
                    to[k++] = '\t';
                    i += 2;
                    break;
                case 'n':
                    to[k++] = '\n';
                    i += 2;
                    break;
                default:
                    to[k++] = '\\';
                    i += 2;
                }
                break;
            }
        default:
            to[k++] = from[i++];
        }
    }
    to[k] = '\0';
}
