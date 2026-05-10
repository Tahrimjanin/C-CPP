#include <stdio.h>
#define MAX 30

void input(int A[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &A[i][j]);
}

void print(int A[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++, printf("\n"))
        for (int j = 0; j < c; j++)
            printf("%d ", A[i][j]);
}

void addMat(int A[MAX][MAX], int B[MAX][MAX], int R[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            R[i][j] = A[i][j] + B[i][j];
}

void subMat(int A[MAX][MAX], int B[MAX][MAX], int R[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            R[i][j] = A[i][j] - B[i][j];
}

void mulMat(int A[MAX][MAX], int B[MAX][MAX], int R[MAX][MAX], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++) {
            R[i][j] = 0;
            for (int k = 0; k < c1; k++)
                R[i][j] += A[i][k] * B[k][j];
        }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], R[MAX][MAX];
    int r1, c1, r2, c2, ch;

    while (1) {
        printf("\n1. Input matrices\n");
        printf("2. Print matrices\n");
        printf("3. Add matrices\n");
        printf("4. Subtract matrices\n");
        printf("5. Multiply matrices\n");
        printf("0. Exit\nEnter option: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter rows and columns for matrix A: ");
                scanf("%d %d", &r1, &c1);
                printf("Enter elements for matrix A:\n");
                input(A, r1, c1);

                printf("Enter rows and columns for matrix B: ");
                scanf("%d %d", &r2, &c2);
                printf("Enter elements for matrix B:\n");
                input(B, r2, c2);
                break;

            case 2:
                printf("Matrix A:\n");
                print(A, r1, c1);
                printf("Matrix B:\n");
                print(B, r2, c2);
                break;

            case 3:
                if (r1 == r2 && c1 == c2) {
                    addMat(A, B, R, r1, c1);
                    printf("Result matrix after addition:\n");
                    print(R, r1, c1);
                } else {
                    printf("Matrix addition not possible. Dimensions must be same.\n");
                }
                break;

            case 4:
                if (r1 == r2 && c1 == c2) {
                    subMat(A, B, R, r1, c1);
                    printf("Result matrix after subtraction:\n");
                    print(R, r1, c1);
                } else {
                    printf("Matrix subtraction not possible. Dimensions must be same.\n");
                }
                break;

            case 5:
                if (c1 == r2) {
                    mulMat(A, B, R, r1, c1, c2);
                    printf("Result matrix after multiplication:\n");
                    print(R, r1, c2);
                } else {
                    printf("Matrix multiplication not possible. Columns of A must match rows of B.\n");
                }
                break;

            case 0:
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}