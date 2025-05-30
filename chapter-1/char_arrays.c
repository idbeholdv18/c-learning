#include <stdio.h>

#define MAXLENGTH 1000

int user_getline(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
    int len, max;

    char line[MAXLENGTH];
    char longest[MAXLENGTH];

    max = 0;

    while ((len = user_getline(line, MAXLENGTH)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0)
        printf("longes: %s", longest);
    return 0;
}

int user_getline(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
