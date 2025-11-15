#include <stdio.h>

int binarySearch(int a[], int n, int key) {
	int i;
    if (a == NULL || n == 0) return -1;

    int start = 0, end = n - 1;

    while (start <= end) {
        int mid = (start + end) / 2;

        printf("\nCurrent search range: ");
        for(i = start; i <= end; i++)
            printf("%d ", a[i]);

        printf("\nMid index %d (value = %d)\n", mid, a[mid]);

        if (a[mid] == key)
            return mid;

        else if (key > a[mid]) {
            start = mid + 1;
            printf("Moving start to %d\n", start);
        }

        else {
            end = mid - 1;
            printf("Moving end to %d\n", end);
        }
    }

    return -1;
}

int main() {
    int n, i, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];

    printf("Enter %d sorted elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    int result = binarySearch(a, n, key);

    if (result == -1)
        printf("\nNot found.\n");
    else
        printf("\nFound at index %d\n", result);

    return 0;
}

