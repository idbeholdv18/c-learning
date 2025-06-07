#include <stdio.h>

int binsearch(int x, int v[], int n);
int binsearch_v2(int x, int v[], int n);

int main() {
    int values[12] = {1, 2, 2, 4, 5, 6, 7, 7, 8, 10, 12, 22};
    int to_find = 10;

    printf("%d has index: %d\n", to_find, binsearch(to_find, values, 12));
    printf("%d has index: %d\n", to_find, binsearch_v2(to_find, values, 12));
}

int binsearch(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid]) {
            high = mid - 1;
        } else if (x > v[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int binsearch_v2(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low < high) {
        mid = (low + high) / 2;
        if (x <= v[mid]) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    if (v[low] == x)
        return low;
    else
        return -1;
}
