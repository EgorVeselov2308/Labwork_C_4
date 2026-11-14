#include "sort.h"

static int line[MAX_N]; 

void sort3(int array[], int n, long *s) {
    *s = 0;

    if (n < 2) return;

    for (int w = 1; w < n; w *= 2) {
        for (int left = 0; left < n; left += 2 * w) {
            int mid = left + w - 1;
            int right = left + 2 * w - 1;
            
            if (mid >= n) mid = n - 1;
            if (right >= n) right = n - 1;

            int i = left, j = mid + 1, k = left;

            while (i <= mid && j <= right) {
                if (array[i] <= array[j]) {
                    line[k++] = array[i++];
                } else {
                    line[k++] = array[j++];
                }
                (*s)++;
            }

            while (i <= mid) { 
                line[k++] = array[i++]; 
                (*s)++; 
            }
            
            while (j <= right) { 
                line[k++] = array[j++]; 
                (*s)++; 
            }

            for (i = left; i <= right; i++) {
                array[i] = line[i];
            }
        }
    }
}
