#include "../geek.h"

void sortInserts(int *array, int first, int last) {
    int temp, pos, i;
    for (i = first + 1; i <= last; i++) {
        temp = array[i];
        pos = i - 1;
        while (pos >= first && array[pos] > temp) {
            array[pos + 1] = array[pos];
            pos = pos - 1;
        }
        array[pos + 1] = temp;
    }
}

int median(int *arr, int first, int last){
    int result;
    int min, max;
    int middle = arr[(first + last) / 2];
    if (arr[first] > arr[middle]) {
        min = arr[middle];
        max = arr[first];
    } else {
        min = arr[first];
        max = arr[middle];
    }
    if (min > arr[last]) result = min;
    else if (arr[last] > max) result = max;
    else result = arr[last];

    if (result == arr[first]) return first;
    else if (result == arr[middle]) return middle;
    else return last;
}


void quicksort(int* arr, int first, int last){
    if (last - first > 10){
        int med = median(arr, first, last);
        swapInt(&arr[med], &arr[(first + last) / 2]);
        int i = first;
        int j = last;
        int x = arr[(first + last) / 2];
        do {
            while (arr[i] < x) i++;
            while (arr[j] > x) j--;
            if(i <= j) {
                swapInt(&arr[i], &arr[j]);
                i++;
                j--;
            }
        } while (i <= j);

        quicksort(arr, i, last);
        quicksort(arr, first, j);
    } else {
        sortInserts(arr, first, last);
        return;
    }
}

void bucketSort(int* arr, int len) {
    const int max = len;
    const int b = 10;

    int buckets[b][max + 1];
    for (int i = 0; i < b; ++i) {
        buckets[i][max] = 0;
    }

    for (int digit = 1; digit < 1000000000; digit*=10) {
        for (int i = 0; i < max; ++i) {
            if (arr[i] % 2 == 0) {
                int d = (arr[i] / digit) % b;
                buckets[d][buckets[d][max]++] = arr[i];
                arr[i] = -1;
            }
        }
        int idx = 0;
        for (int i = 0; i < b; ++i) {
            for (int j = 0; j < buckets[i][max]; ++j) {
                while (arr[idx] != -1) idx++;
                arr[idx++] = buckets[i][j];
            }
            buckets[i][max] = 0;
        }
    }
}

int main() {
    const int SZ = 20;
    int a[SZ];
    int b[SZ];
    fillIntRandom(a, SZ, 100);
    fillIntRandom(b, SZ, 100);
    printf("qsort:\n");
    printIntArray(a, SZ, 3);
    quicksort(a, 0, SZ - 1);
    printIntArray(a, SZ, 3);
    printf("bsort:\n");
    printIntArray(b, SZ, 3);
    bucketSort(b, SZ);
    printIntArray(b, SZ, 3);
    return 0;
}
