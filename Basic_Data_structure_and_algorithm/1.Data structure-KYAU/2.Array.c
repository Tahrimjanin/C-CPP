#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void Insert(int *LA, int *N, int K, int Item) {
    int J = *N - 1;
    while (J >= K) {
        LA[J + 1] = LA[J];
        J = J - 1;
    }
    LA[K] = Item;
    *N = *N + 1;
}

int LinerSearch(int *Data, int N, int Item, int *Count) {
    int Loc = 0;
    while (Loc < N) {
        (*Count)++;
        if (Data[Loc] == Item) break;
        Loc = Loc + 1;
    }
    if (Loc == N)
        return -1;
    else
        return Loc;
}

void Bubble_Sort(int *Data, int N) {
    int k, Item, Ptr;
    for (k = 0; k < (N - 1); k++) {
        Ptr = 0;
        while (Ptr < (N - k - 1)) {
            if (Data[Ptr] > Data[Ptr + 1]) {
                Item = Data[Ptr];
                Data[Ptr] = Data[Ptr + 1];
                Data[Ptr + 1] = Item;
            }
            Ptr = Ptr + 1;
        }
    }
}

int BinarySearch(int *Data, int LB, int UB, int Item, int *Count) {
    int Beg, End, Mid, Loc;
    Beg = LB; End = UB; Mid = (int)((Beg + End) / 2);
    while (Beg <= End && Data[Mid] != Item) {
        (*Count)++;
        if (Item < Data[Mid])
            End = Mid - 1;
        else
            Beg = Mid + 1;
        Mid = (int)((Beg + End) / 2);
    }
    (*Count)++;
    if (Data[Mid] == Item)
        Loc = Mid;
    else
        Loc = -1;
    return Loc;
}

void Delete(int *LA, int *N, int K) {
    int J = K;
    while (J < *N - 1) {
        LA[J] = LA[J + 1];
        J = J + 1;
    }
    *N = *N - 1;
}

int Search(int *LA, int N, int Item) {
    for (int i = 0; i < N; i++) {
        if (LA[i] == Item) {
            return i;
        }
    }
    return -1;
}

int main() {
    int i, n = 0, Item, K, Data[10000];
    int Loc, LS = 0, BS = 0;
    srand(time(NULL));

    char op;
    while (1) {
        printf("\n1. Create an Array\n");
        printf("2. Display the Array\n");
        printf("3. Search an item from the Array\n");
        printf("4. Insert an item into the Array\n");
        printf("5. Delete an item from the Array\n");
        printf("6. Search (Binary) an item from the Array\n");
        printf("7. Search (Linear) an item from the Array with Complexity\n");
        printf("8. Bubble Sort the Array\n");
        printf("0. Exit\nEnter  option: ");
        op = getche();
        switch (op) {

        case '1':
            printf("\nEnter the amount of num: ");
            scanf("%d", &n);
            for (i = 0; i < n; i++) {
                Data[i] = (rand() % 1000);
            }
            printf("Array created successfully!\n");
            break;

        case '2':
            if (n == 0) {
                printf("\nArray is empty. Please create an array first.\n");
            } else {
                printf("\nThe %d num are as follows:\n", n);
                for (i = 0; i < n; i++) {
                    printf("%5d", Data[i]);
                }
                printf("\n");
            }
            break;

        case '3':
            if (n == 0) {
                printf("\nArray is empty. Please create an array first.\n");
            } else {
                printf("\nEnter the item to search: ");
                scanf("%d", &Item);
                int pos = Search(Data, n, Item);
                if (pos != -1) {
                    printf("Item %d found at position %d.\n", Item, pos + 1);
                } else {
                    printf("Item %d not found in the array.\n", Item);
                }
            }
            break;

      

        case '4':
            
                printf("\nEnter the location to insert item (1 to %d): ", n + 1);
                scanf("%d", &K);
                if (K < 1 || K > n + 1) {
                    printf("Invalid location. Please enter a valid position.\n");
                } else {
                    printf("Enter the item to insert: ");
                    scanf("%d", &Item);
                    clock_t start = clock(); // Start time measurement
                    Insert(Data, &n, K - 1, Item);
                    clock_t end = clock(); // End time measurement
                    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; // Calculate time
                    printf("Item inserted successfully!\n");
                    printf("Time taken for Insertion: %f seconds\n", time_taken);
                    printf("Theoretical Time Complexity: O(n)\n");
                }
        
            break;

        case '5':
            if (n == 0) {
                printf("\nArray is empty. Please create an array first.\n");
            } else {
                printf("\nEnter the location to delete item (1 to %d): ", n);
                scanf("%d", &K);
                if (K < 1 || K > n) {
                    printf("Invalid location. Please enter a valid position.\n");
                } else {
                    clock_t start = clock(); // Start time measurement
                    Delete(Data, &n, K - 1);
                    clock_t end = clock(); // End time measurement
                    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; // Calculate time
                    printf("Item deleted successfully!\n");
                    printf("Time taken for Deletion: %f seconds\n", time_taken);
                    printf("Theoretical Time Complexity: O(n)\n");
                }
            }
            break;

        case '6':
            printf("\nEnter an Item for Search(Binary) : ");
            scanf("%d", &Item);
            if (n >= 1) {
                clock_t start = clock(); // Start time measurement
                Loc = BinarySearch(Data, 0, n - 1, Item, &BS);
                clock_t end = clock(); // End time measurement
                double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; // Calculate time
                if (Loc >= 0)
                    printf("\nItem Found in Location %d", Loc);
                else
                    printf("\nItem Not Found......\n");
                printf("\nBinary Search Compare Complexity: %d", BS);
                printf("\nTime taken for Binary Search: %f seconds\n", time_taken);
                printf("Theoretical Time Complexity: O(log n)\n");
            } else
                printf("\nThere is no Items in Array\n");
            break;

        case '7':
                printf("\nEnter the item to search: ");
                scanf("%d", &Item);
                LS = 0;
                clock_t start_linear = clock(); // Start time measurement for Linear Search
                int linearPos = LinerSearch(Data, n, Item, &LS);
                clock_t end_linear = clock(); // End time measurement for Linear Search
                double time_linear = ((double)(end_linear - start_linear)) / CLOCKS_PER_SEC; // Calculate time



                if (linearPos != -1) {
                    printf("Item %d found at position %d using Linear Search.\n", Item, linearPos + 1);
                } else {
                    printf("Item %d not found in the array using Linear Search.\n", Item);
                }

                printf("Linear Search Complexity: %d\n", LS);
                printf("Time taken for Linear Search: %f seconds\n", time_linear);
                printf("Theoretical Time Complexity: O(n)\n");


            
            break;

        case '8':
            if (n == 0) {
                printf("\nArray is empty. Please create an array first.\n");
            } else {
                clock_t start = clock(); // Start time measurement
                Bubble_Sort(Data, n);
                clock_t end = clock(); // End time measurement
                double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; // Calculate time
                printf("Array sorted successfully using Bubble Sort!\n");
                printf("Time taken for Bubble Sort: %f seconds\n", time_taken);
                printf("Theoretical Time Complexity: O(n^2)\n");
            }
            break;

        case '0':
            exit(0);
        default:
            printf("\nInvalid option. Please try again.\n");
        }
    }
    return 0;
}