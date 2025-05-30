#include <stdio.h>

#define MAX_LINE_LENGTH 1000
#define TAB_SIZE 4

int get_line(char line[], int limit);
void entab(char line[], int size);

int main() {
    int c, line_size;
    char line[MAX_LINE_LENGTH];

    while ((line_size = get_line(line, MAX_LINE_LENGTH)) > 0) {
        entab(line, line_size);
        printf("%s", line);
    }
}

int get_line(char line[], int limit) {
    int c, i;

    for (i = 0; (c = getchar()) != EOF && c != '\n' && i < limit - 1; ++i)
        line[i] = c;

    if (c == '\n') {
        line[i] = c;
        i++;
    }

    line[i] = '\0';

    return i;
}
void entab(char line[], int size) {
    int pos = 0;
    int out_pos = 0;
    int spaces_count = 0;

    char output[size];

    while (pos < size && line[pos] != '\0') {
        if (line[pos] == ' ') {
            spaces_count++;

            if (spaces_count == TAB_SIZE) {
                output[out_pos++] = '\t';
                spaces_count = 0;
            }

            pos++;
        } else {
            while (spaces_count > 0) {
                output[out_pos++] = ' ';
                spaces_count--;
            }

            output[out_pos++] = line[pos++];
        }
    }

    while (spaces_count > 0) {
        output[out_pos++] = ' ';
        spaces_count--;
    }

    output[out_pos] = '\0';

    for (int j = 0; j <= out_pos; j++) {
        line[j] = output[j];
    }
}