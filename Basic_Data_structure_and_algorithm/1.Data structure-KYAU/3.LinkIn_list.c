#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct N {
    int Info;
    struct N *Next;
};
typedef struct N Linked_List;

// Create a random linked list
Linked_List *Create_Linked_List(Linked_List *Start, int n) {
    Linked_List *Ptr;
    
    if (n > 0) {
        while (n--) {
            if (Start == NULL) {
                Start = (Linked_List *)malloc(sizeof(Linked_List)); // 1st node ar jonno memory allocate korbe
                Start->Info = (rand() % 1000) + 1;
                Start->Next = NULL;
                Ptr = Start;
            } else {
                Ptr->Next = (Linked_List *)malloc(sizeof(Linked_List));
                Ptr = Ptr->Next;
                Ptr->Info = (rand() % 1000) + 1;
                Ptr->Next = NULL;
            }
        }
    } else {
        Start = NULL;
    }
    return Start;
}

// Free list memory
void Free_List(Linked_List *Start) {
    Linked_List *temp;
    while (Start != NULL) {
        temp = Start;
        Start = Start->Next;
        free(temp);
    }
}

// Display linked list
void Display_List(Linked_List *Start) {
    if (Start == NULL) {
        printf("List is empty.\n");
        return;
    }
    Linked_List *Ptr = Start;
    while (Ptr != NULL) {
        printf("%5d", Ptr->Info);
        Ptr = Ptr->Next;
    }
    printf("\n");
}

// Count elements
int Count_List(Linked_List *Start) {
    int count = 0;
    while (Start != NULL) {
        count++;
        Start = Start->Next;
    }
    return count;
}

// Sum elements
int Sum_List(Linked_List *Start) {
    int sum = 0;
    while (Start != NULL) {
        sum += Start->Info;
        Start = Start->Next;
    }
    return sum;
}

// Insert 
Linked_List *Insert_Item(Linked_List *Start, int Item) {
    Linked_List *New = (Linked_List *)malloc(sizeof(Linked_List));
    New->Info = Item;
    New->Next = NULL;
    if (Start == NULL) {
        Start = New;
    } else {
        Linked_List *Ptr = Start;
        while (Ptr->Next != NULL) {
            Ptr = Ptr->Next;
        }
        Ptr->Next = New;
    }
    return Start;
}

// Delete an item
Linked_List *Delete_Item(Linked_List *Start, int Item) {
    Linked_List *LOC = Start, *LOCP = NULL;
    while (LOC != NULL && LOC->Info != Item) {
        LOCP = LOC;
        LOC = LOC->Next;
    }
    if (LOC == NULL) {
        printf("Item not found!\n");
        return Start;
    }
    if (LOCP == NULL) {
        Start = LOC->Next;
    } else {
        LOCP->Next = LOC->Next;
    }
    free(LOC);
    printf("Item %d deleted successfully.\n", Item);
    return Start;
}

int main() {
    Linked_List *Start = NULL;
    int n, item;
    char op;
    srand(time(NULL));

    while (1) {
        printf("\n=== LINKED LIST MENU ===\n");
        printf("1. Create a Random Linked List\n");
        printf("2. Display the Linked List\n");
        printf("3. Insert an Item (at End)\n");
        printf("4. Count the Elements in the List\n");
        printf("5. Sum the Elements in the List\n");
        printf("6. Delete an Item from the List\n");
        printf("0. Exit\nEnter option: ");
        scanf(" %c", &op);

        switch (op) {
            case '1':
                printf("Enter number of elements: ");
                scanf("%d", &n);
                Free_List(Start);
                Start = Create_Linked_List(NULL, n);
                break;

            case '2':
                printf("Linked List:\n");
                Display_List(Start);
                break;

            case '3':
                printf("Enter an item to insert: ");
                scanf("%d", &item);
                Start = Insert_Item(Start, item);
                break;

            case '4':
                printf("Count = %d\n", Count_List(Start));
                break;

            case '5':
                printf("Sum = %d\n", Sum_List(Start));
                break;

            case '6':
                printf("Enter an item to delete: ");
                scanf("%d", &item);
                Start = Delete_Item(Start, item);
                break;

            case '0':
                Free_List(Start);
                printf("Exiting.\n");
                return 0;

            default:
                printf("Invalid option!\n");
        }
    }
}
