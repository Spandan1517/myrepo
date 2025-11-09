#include <stdio.h>
#define SIZE 7

int main() {
    int hash[SIZE];
    for (int i = 0; i < SIZE; i++) hash[i] = -1;

    int n, key, index, i;
    printf("Enter number of keys: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter key %d: ", i + 1);
        scanf("%d", &key);
        index = key % SIZE;

        int original = index;
        while (hash[index] != -1) {
            index = (index + 1) % SIZE;
            if (index == original) {
                printf("Hash table full!\n");
                break;
            }
        }
        if (hash[index] == -1)
            hash[index] = key;
    }

    printf("\nFinal Hash Table:\n");
    for (i = 0; i < SIZE; i++)
        printf("Slot %d -> %d\n", i, hash[i]);
    return 0;
}
