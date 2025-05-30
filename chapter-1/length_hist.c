#include <stdio.h>

int main() {
    int c, wl, wc;
    int hist[100];

    wl = wc = 0;

    for (int i = 0; i < 100; i++) {
        hist[i] = 0;
    }

    while((c = getchar()) != EOF) {
        if ((c == ' ' || c == '\n' || c == '\t') && wl > 0) {
            ++hist[wl];
            ++wc;
            wl = 0;
        } else ++wl;
    }

    if (wl > 0) {
        ++hist[wl];
        ++wc;
    }

    printf("words count: %d\n", wc);
    for (int i = 0; i < 100; i++) {
        if (hist[i] > 0) {
          printf("%3d: ", i);
          int hist_percent = hist[i] * 100 / wc;
          for (int k = 0; k < hist_percent; k++) {
            printf("#");
          }
          printf(" (%d)\n", hist_percent);
        } 
    }
}