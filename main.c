#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

int main() {
    srand((unsigned)time(NULL));

    int sizes[4] =  {10, 1000, 10000, 100000};
    int num_sizes = 4;

    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        int *original = malloc(n * sizeof(int));
        int *arr = malloc(n * sizeof(int));

        for (int j = 0; j < n; j++) original[j] = rand();

        long s1, s2, s3;
        double t1, t2, t3;
        clock_t start, end;

        for (int j = 0; j < n; j++) arr[j] = original[j];
        s1 = 0;
        start = clock();
        sort1(arr, n, &s1);
        end = clock();
        t1 = (double)(end - start) / CLOCKS_PER_SEC;

        for (int j = 0; j < n; j++) arr[j] = original[j];
        s2 = 0;
        start = clock();
        sort2(arr, n, &s2);
        end = clock();
        t2 = (double)(end - start) / CLOCKS_PER_SEC;

        for (int j = 0; j < n; j++) arr[j] = original[j];
        s3 = 0;
        start = clock();
        sort3(arr, n, &s3);
        end = clock();
        t3 = (double)(end - start) / CLOCKS_PER_SEC;

        printf("%d %f %ld %f %ld %f %ld\n", n, t1, s1, t2, s2, t3, s3);

        free(original);
        free(arr);
    }
    return 0;
}
