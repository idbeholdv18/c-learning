#include <stdio.h>

float fahr_to_celsius(int fahr);

int main() {
    printf("fahrenheit\tcelsius\n");
    for (int fahr = 0; fahr <= 300; fahr += 20) {
        printf("%10d\t%7.1f\n", fahr, fahr_to_celsius(fahr));
    }
}

float fahr_to_celsius(int fahr) {
    return (5.0 / 9.0) * (fahr - 32);
}