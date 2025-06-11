#include <stdio.h>
#include <string.h>

void my_for(int *nums, int size, void (*handler)(int *));
void print_num(int *);

int main() {
    int nums[] = {1, 22, 8, 42, 5};
    int size = sizeof(nums) / sizeof(nums[0]);
    my_for(nums, size, print_num);
}

void my_for(int *nums, int size, void (*h)(int *)) {
    int i = 0;
    while (i < size) {
        (*h)(&nums[i++]);
    }
}

void print_num(int *num) { printf("digit: %d\n", *num); }