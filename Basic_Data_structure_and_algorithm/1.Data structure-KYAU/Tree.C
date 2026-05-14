#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define tree node
struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode Tree;

// Function declarations
Tree* insert(Tree* root, int value);
void inorder(Tree* root);
void preorder(Tree* root);
void postorder(Tree* root);

// Main function with menu
int main() {
    Tree* root = NULL;
    int choice, value, n;
    srand(time(NULL));

    while (1) {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Create a Binary Search Tree (Random Data)\n");
        printf("2. Display In-order Traversal\n");
        printf("3. Display Pre-order Traversal\n");
        printf("4. Display Post-order Traversal\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("How many elements to insert? ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++) {
                value = rand() % 100;
                printf("%d ", value);
                root = insert(root, value);
            }
            printf("\nBST created.\n");
            break;
        case 2:
            printf("In-order Traversal:\n");
            inorder(root);
            printf("\n");
            break;
        case 3:
            printf("Pre-order Traversal:\n");
            preorder(root);
            printf("\n");
            break;
        case 4:
            printf("Post-order Traversal:\n");
            postorder(root);
            printf("\n");
            break;
        case 0:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// Insert function
Tree* insert(Tree* root, int value) {
    if (root == NULL) {
        Tree* newNode = (Tree*)malloc(sizeof(Tree));
        newNode->data = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

// In-order traversal (Left, Root, Right)
void inorder(Tree* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Pre-order traversal (Root, Left, Right)
void preorder(Tree* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Post-order traversal (Left, Right, Root)
void postorder(Tree* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
