#include <stdio.h>

#define MAX 10 // Maximum matrix size

void rotateMatrix(int n, int matrix[MAX][MAX]) {
    int i, j, temp;

    // Step 1: Transpose the matrix
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // Step 2: Reverse each row
    int k;
    for (i = 0; i < n; i++) {
        for (j = 0, k = n - 1; j < k; j++, k--) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[i][k];
            matrix[i][k] = temp;
        }
    }
}

void printMatrix(int n, int matrix[MAX][MAX]) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

int main() {
    int n, i, j;
    printf("Enter size of matrix: ");
    scanf("%d", &n);

    int matrix[MAX][MAX];

    // Input matrix
    printf("Enter matrix elements:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    rotateMatrix(n, matrix);

    printf("Rotated matrix:\n");
    printMatrix(n, matrix);

    return 0;
}

