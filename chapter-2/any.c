#include <stdio.h>

int any(char s1[], char s2[]);

int main() {
    printf("\"hello world\" | \"od\": %d\n", any("hello world", "od"));
}

int any(char s1[], char s2[]) {
    for (int i = 0; s1[i] != '\0'; i++) {
        for (int k = 0; s2[k] != '\0'; k++) {
            if (s1[i] == s2[k])
                return i;
        }
    }

    return -1;
}