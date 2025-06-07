#include <stdio.h>

#define MAX_STR_SIZE 200

void lower(char str[]);

int main() {
    char str[MAX_STR_SIZE] = "tEsT sTrInG";

    printf("initial:\t%s\n", str);

    lower(str);
    printf("lower:\t\t%s\n", str);
}

void lower(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = (str[i] >= 'A' && str[i] <= 'Z') ? str[i] += 32 : str[i];
    }
}