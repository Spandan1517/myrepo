#include <stdio.h>
#define MAX 5

int stack[MAX], top = -1;

void push() {
    int val;
    if (top == MAX - 1)
        printf("Stack Overflow.\n");
    else {
        printf("Enter element: ");
        scanf("%d", &val);
        stack[++top] = val;
    }
}

void pop() {
    if (top == -1)
        printf("Stack Underflow.\n");
    else
        printf("Popped element: %d\n", stack[top--]);
}

void display() {
    if (top == -1)
        printf("Stack is Empty.\n");
    else {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}

void palindrome() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    int flag = 1;
    for (int i = 0; i <= top / 2; i++) {
        if (stack[i] != stack[top - i]) {
            flag = 0;
            break;
        }
    }
    if (flag)
        printf("Stack content forms a Palindrome.\n");
    else
        printf("Not a Palindrome.\n");
}

int main() {
    int ch;
    while (1) {
        printf("\nSelect Here:-\n1.Push\n2.Pop\n3.Check Palindrome\n4.Display\n5.Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: palindrome(); break;
            case 4: display(); break;
            case 5: return 0;
            default: printf("Invalid choice.\n");
        }
    }
}
