#include <stdio.h>

int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int even = 0, sum = 0;
    for (i = 0; i < n; i++) {
        if ((i + 1) % 2 == 0)
            even += a[i];
        else
            sum += a[i];
    }

    printf("Sum of elements at odd positions = %d\n", sum);
    printf("Sum of elements at even positions = %d\n", even);
    return 0;
}
