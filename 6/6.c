#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

void search(struct Node* root, int key) {
    if (root == NULL) {
        printf("NULL\n");
        return;
    }
    if (root->data == key)
        printf("Found\n");
    else if (key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}

struct Node* deleteLeaf(struct Node* root, int key) {
    if (root == NULL) return NULL;

    if (key < root->data)
        root->left = deleteLeaf(root->left, key);
    else if (key > root->data)
        root->right = deleteLeaf(root->right, key);
    else {
        if (root->left == NULL && root->right == NULL) {
            printf("Leaf node %d deleted.\n", key);
            free(root);
            return NULL;
        } else {
            printf("%d is not a leaf node.\n", key);
        }
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    int ch, val;

    while (1) {
        printf("\n BST MENU:\n");
        printf("1. Search Element\n2. Insert Element\n3. Delete Leaf Element\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element to search: ");
                scanf("%d", &val);
                search(root, val);
                break;

            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;

            case 3:
                printf("Enter leaf element to delete: ");
                scanf("%d", &val);
                root = deleteLeaf(root, val);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
