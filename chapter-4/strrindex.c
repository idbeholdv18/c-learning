#include <stdio.h>
#include <string.h>

int strrindex(char s[], char t[]);

int main() {
    char s[] = "look into the mirror, and see the truth";
    char t[] = "the";

    int index = strrindex(s, t);
    printf("Rightmost index: %d\n", index);
}

int strrindex(char s[], char t[]) {
    int match_counter;
    int i = strlen(s) - 1;

    while (i >= strlen(t) - 1) {
        match_counter = 0;

        for (int k = strlen(t) - 1, j = i; k >= 0; k--, j--) {
            if (s[j] != t[k])
                break;
            match_counter++;
        }
        if (match_counter == strlen(t))
            return i;
        i--;
    }

    return -1;
}