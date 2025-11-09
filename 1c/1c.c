#include <stdio.h>
#include <string.h>

struct Student {
    int roll;
    char name[30];
    float avg;
};

int main() {
    int n, i, j;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n], temp;

    for (i = 0; i < n; i++) {
        printf("\nEnter details for student %d\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &s[i].roll);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Average Marks: ");
        scanf("%f", &s[i].avg);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (s[j].avg < s[j + 1].avg) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    printf("\nStudents sorted by Average Marks (Descending):\n");
    for (i = 0; i < n; i++)
        printf("%d\t%s\t%.2f\n", s[i].roll, s[i].name, s[i].avg);

    return 0;
}
