#include <stdio.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int a[], int p, int q) {
    int pivot = a[q];
    int i = p - 1;

    for (int j = p; j <= q - 1; j++) {
        if (a[j] < pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }

    swap(&a[i + 1], &a[q]);
    return i + 1;
}

void quickSort(int a[], int p, int q) {
    if (p < q) {
        int pi = partition(a, p, q);
        quickSort(a, p, pi - 1);
        quickSort(a, pi + 1, q);
    }
}

int main() {
    int n = 10;
    int a[n];
    printf("enter array : ");
    for (int i = 0; i < n; i++) {
        scanf("%d ", &a[i]);
    }

    quickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}

