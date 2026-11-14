#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "sort.h"

int main() {
    srand((unsigned)time(NULL));

    int sizes[] = {10, 1000, 10000, 100000};
    int num_sizes = 4;

    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        int *original = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) original[j] = rand();

        int *arr = malloc(n * sizeof(int));
        long swaps = 0;
        clock_t start, end;
        double t1, t2, t3;

        memcpy(arr, original, n * sizeof(int));
        swaps = 0;
        start = clock();
        sort1(arr, n, &swaps);
        end = clock();
        t1 = (double)(end - start) / CLOCKS_PER_SEC;
        long s1 = swaps;

        memcpy(arr, original, n * sizeof(int));
        swaps = 0;
        start = clock();
        sort2(arr, n, &swaps);
        end = clock();
        t2 = (double)(end - start) / CLOCKS_PER_SEC;
        long s2 = swaps;

        memcpy(arr, original, n * sizeof(int));
        swaps = 0;
        start = clock();
        sort3(arr, n, &swaps);
        end = clock();
        t3 = (double)(end - start) / CLOCKS_PER_SEC;
        long s3 = swaps;

        printf("%d %f %ld %f %ld %f %ld\n", n, t1, s1, t2, s2, t3, s3);

        free(original);
        free(arr);
    }

    return 0;
}
