#include <stdio.h>

#define MAXLENGTH 20

int user_getline(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
    int len, max, overflow, total_len;

    char line[MAXLENGTH];
    char longest[MAXLENGTH];

    max = overflow = total_len = 0;

    while ((len = user_getline(line, MAXLENGTH)) > 0) {
        if (len == MAXLENGTH - 1 && line[len - 1] != '\n') {
            total_len += len;
            overflow = 1;
            if (total_len == len && total_len > max)
                copy(longest, line);
        } else {
            total_len += len;
            overflow = 0;
            if (total_len > max) {
                max = total_len;
                if (total_len < MAXLENGTH)
                    copy(longest, line);
            }
            total_len = 0;
        }
    }

    if (max > 0)
        printf("longest: (%d) %s", max, longest);
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
