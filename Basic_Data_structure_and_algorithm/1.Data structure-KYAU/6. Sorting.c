#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct N {
    int info;
    struct N *next;
};
typedef struct N STACK;

long int isi = 0, bsi = 0, qsi = 0, ssi = 0;


int Min(int *Data, int k, int n) {
    int j, minimum, Loc;
    minimum = Data[k];
    Loc = k;
    for (j = k + 1; j < n; j++) {
        if (minimum > Data[j]) {
            minimum = Data[j];
            Loc = j;
        }
    }
    return Loc;
}

void Selection_Sort(int *Data, int n) {
    int k, Temp, Loc;
    for (k = 0; k < n - 1; k++) {
        ssi++;
        Loc = Min(Data, k, n);
        Temp = Data[Loc];
        Data[Loc] = Data[k];
        Data[k] = Temp;
    }
}

void Insertion_Sort(int *Data, int n) {
    int Temp, k, Ptr;
    for (k = 1; k < n; k++) {
        Temp = Data[k];
        Ptr = k - 1;
        while (Temp < Data[Ptr] && Ptr >= 0) {
            Data[Ptr + 1] = Data[Ptr];
            Ptr = Ptr - 1;
            isi++;
        }
        Data[Ptr + 1] = Temp;
        isi++;
    }
}

void Display(int *D, int n) {
    int i;
    printf("\nThe List is\n");
    for (i = 0; i < n; i++) {
        printf("%5d", D[i]);
    }
    printf("\n");
}

void BubbleSort(int *Data, int n) {
    int i, j, Temp;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (Data[i] > Data[j]) {
                bsi++;
                Temp = Data[i];
                Data[i] = Data[j];
                Data[j] = Temp;
            }
        }
    }
}

STACK *Push(STACK *A, int item) {
    STACK *New = (STACK *)malloc(sizeof(STACK));
    New->info = item;
    New->next = A;
    return New;
}

STACK *Pop(STACK *A, int *item) {
    if (A == NULL) {
        *item = -1;
    } else {
        *item = A->info;
        A = A->next;
    }
    return A;
}

int Quick(int *Data, int N, int BEG, int END) {
    int Temp, LEFT, RIGHT, LOC;
    LEFT = BEG; RIGHT = END; LOC = BEG;
S2:
    while (Data[LOC] <= Data[RIGHT] && LOC != RIGHT)
        RIGHT--;
    if (LOC == RIGHT) return LOC;
    if (Data[LOC] > Data[RIGHT]) {
        qsi++;
        Temp = Data[LOC]; Data[LOC] = Data[RIGHT]; Data[RIGHT] = Temp;
        LOC = RIGHT;
        goto S3;
    }

S3:
    while (Data[LEFT] <= Data[LOC] && LEFT != LOC)
        LEFT++;
    if (LEFT == LOC) return LOC;
    if (Data[LEFT] > Data[LOC]) {
        qsi++;
        Temp = Data[LEFT]; Data[LEFT] = Data[LOC]; Data[LOC] = Temp;
        LOC = LEFT;
        goto S2;
    }
    return LOC;
}

void QuickSort(int *Data, int n) {
    int Loc;
    STACK *LOWER = NULL, *UPPER = NULL;
    int BEG, END;
    if (n > 1) {
        LOWER = Push(LOWER, 0);
        UPPER = Push(UPPER, n - 1);
    }
    while (LOWER != NULL) {
        LOWER = Pop(LOWER, &BEG);
        UPPER = Pop(UPPER, &END);
        Loc = Quick(Data, n, BEG, END);
        if (BEG < (Loc - 1)) {
            LOWER = Push(LOWER, BEG);
            UPPER = Push(UPPER, Loc - 1);
        }
        if ((Loc + 1) < END) {
            LOWER = Push(LOWER, Loc + 1);
            UPPER = Push(UPPER, END);
        }
    }
}


void main() {
    int i, n, item, Data1[10000], Data2[10000], Data3[10000], Data4[10000];
    srand(time(NULL));
    char op;
    clock_t start, end;
    double cpu_time_used;

    while (1) {
        printf("\nWell come Sorting Programs\n");
        printf("1. Read an Array\n");
        printf("2. Display Array\n");
        printf("3. Quick Sort\n");
        printf("4. Bubble Sort\n");
        printf("5. Insertion Sort\n");
        printf("6. Selection Sort\n");
        printf("0. Exit\nEnter your option : ");

        op = getche();
        switch (op) {
            case '1':
                printf("\nEnter amount of Numbers : ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    Data1[i] = Data2[i] = Data3[i] = Data4[i] = (rand() % 1000) + 1;
                }
                break;
            case '2':
                Display(Data1, n);
                break;
            case '3':
                start = clock();
                QuickSort(Data1, n);
                end = clock();
                cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
                Display(Data1, n);
                printf("\nIn Quick Sort Interchange %ld", qsi);
                printf("\nTime taken by Quick Sort: %f seconds\n", cpu_time_used);
                break;
            case '4':
                start = clock();
                BubbleSort(Data2, n);
                end = clock();
                cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
                Display(Data2, n);
                printf("\nIn Bubble Sort Interchange %ld", bsi);
                printf("\nTime taken by Bubble Sort: %f seconds\n", cpu_time_used);
                break;
            case '5':
                start = clock();
                Insertion_Sort(Data3, n);
                end = clock();
                cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
                Display(Data3, n);
                printf("\nIn Insertion Sort Interchange %ld", isi);
                printf("\nTime taken by Insertion Sort: %f seconds\n", cpu_time_used);
                break;
            case '6':
                start = clock();
                Selection_Sort(Data4, n);
                end = clock();
                cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
                Display(Data4, n);
                printf("\nIn Selection Sort Interchange %ld", ssi);
                printf("\nTime taken by Selection Sort: %f seconds\n", cpu_time_used);
                break;
            case '0':
                exit(0);
                break;
        }
    }
}


