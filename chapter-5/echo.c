#include <stdio.h>

int main(int argc, char * argv[]) {
    int i = 1;
    while (i < argc) {
        printf("%s%s", argv[i], (i < argc - 1) ? " " : "\n");
        i++;
    }
    return 0;
}
