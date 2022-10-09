#include "geek.h"

void bubbleSort(int* a, int size) {
int i, j;
int tmp;
for (i = 0; i < size; i++)
	for (j = 0; j < size - 1; j++)
		if (a[j] > a[j + 1]) {
			tmp = a[j];
			a[j] = a[j + 1];
			a[j + 1] = tmp;
		}
}
void mathSequence(double* seq, int size) {
    printf("3. Do math on a sequence.\n");
    for (int i = 0; i < size; ++i) {
        double x = sqrt(fabs(seq[i])) + 5 * pow(seq[i], 3);
        if (x > 400)
            printf(" %d. Number %lf (of %.3lf) bigger than 400\n", i + 1, x, seq[i]);
        else
            printf(" %d. %lf\n", i + 1, x);
    }
}
int main()
{
    int arr[] = {
        1, 9, 2,
        5, 7, 6,
        4, 3, 8
    };
    bubbleSort(arr, 9);
    printIntArray(arr, 9, 2);
    printf("\n");
}
