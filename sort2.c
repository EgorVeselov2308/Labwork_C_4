#include "sort.h"

void sort2(int *array, int n, long *s) {
    int i, k, j;
    for (i = 1; i < n; i++) {
        k = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > k) {
            array[j + 1] = array[j];
            j--;
            (*s)++;
        }
        array[j + 1] = k;
    }
}
