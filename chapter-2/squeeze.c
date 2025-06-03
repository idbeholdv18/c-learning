#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main() {
    char s[1000] = "hello world";

    squeeze(s, "h wrd");
    printf("\"hello world\" | \"h wrd\": %s\n", s);
}

void squeeze(char s1[], char s2[]) {
    int j;

    for (int i = j = 0; s1[i] != '\0'; i++) {
        int is_to_remove = 0;

        for (int k = 0; s2[k] != '\0'; k++) {
            if (s1[i] == s2[k])
                is_to_remove = 1;
        }

        if (!is_to_remove)
            s1[j++] = s1[i];
    }

    s1[j] = '\0';
}