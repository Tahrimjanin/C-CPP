#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ---------- Singly Linked List Stack ----------
struct Node {
    int data;
    struct Node *next;
};
typedef struct Node SNode;

SNode *pushSingly(SNode *top, int value) {
    SNode *newNode = (SNode *)malloc(sizeof(SNode));
    newNode->data = value;
    newNode->next = top;
    return newNode;
}

SNode *popSingly(SNode *top, int *value) {
    if (top == NULL) {
        printf("\nStack is Empty!\n");
        *value = -1;
    } else {
        *value = top->data;
        SNode *temp = top;
        top = top->next;
        free(temp);
    }
    return top;
}

void displaySingly(SNode *top) {
    printf("\nStack (Top to Bottom): ");
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

// ---------- Doubly Linked List Stack ----------
struct DNode {
    int data;
    struct DNode *prev;
    struct DNode *next;
};

typedef struct DNode DNode;

DNode *pushDoubly(DNode *top, int value) {
    DNode *newNode = (DNode *)malloc(sizeof(DNode));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = top;
    if (top != NULL) {
        top->prev = newNode;
    }
    return newNode;
}

DNode *popDoubly(DNode *top, int *value) {
    if (top == NULL) {
        printf("\nStack is Empty!\n");
        *value = -1;
    } else {
        *value = top->data;
        DNode *temp = top;
        top = top->next;
        if (top != NULL) top->prev = NULL;
        free(temp);
    }
    return top;
}

void displayDoubly(DNode *top) {
    printf("\nStack (Top to Bottom): ");
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

//Main Menu

int main() {
    char type;
    int item, choice;
    SNode *sTop = NULL;
    DNode *dTop = NULL;

    printf("Choose Stack Type:\n");
    printf("a) One Way Linked List\n");
    printf("b) Two Way Linked List\n");
    printf("Enter your option (a/b): ");
    scanf(" %c", &type);

    while (1) {
        printf("\n=== Stack Menu ===\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter item to push: ");
            scanf("%d", &item);
            if (type == 'a')
                sTop = pushSingly(sTop, item);
            else
                dTop = pushDoubly(dTop, item);
            break;
        case 2:
            if (type == 'a')
                sTop = popSingly(sTop, &item);
            else
                dTop = popDoubly(dTop, &item);
            if (item != -1)
                printf("Popped item: %d\n", item);
            break;
        case 3:
            if (type == 'a')
                displaySingly(sTop);
            else
                displayDoubly(dTop);
            break;
        case 0:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
