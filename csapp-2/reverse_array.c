#include "./swap.c"
#include <stdio.h>

void reverse_array(int *arr, int cnt) {
    int first, last;

    for (first = 0, last = cnt - 1; first < last; first++, last--) {
        swap(&arr[first], &arr[last]);
    }
}

int main() {
    const int cnt = 5;
    int arr[cnt] = {1, 2, 3, 4, 5};

    reverse_array(arr, cnt);

    for (int i = 0; i < cnt; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
