void MatrixMultiplication(int matrixA[][50], int rA, int cA, int matrixB[][50], int rB, int cB, int matrixC[][50], int i) {
    int j, k, sum;
    if (cA != rB) {
        printf("Order of Input Matrices is Invalid");
        return;
    }
    if (i >= rA)
        return;
    for (j = 0; j < cB; ++j) {
        sum = 0;
        for (k = 0; k < rA; ++k) {
            sum += matrixA[i][k] * matrixB[k][j];
        }
        matrixC[i][j] = sum;
    }
    MatrixMultiplication(matrixA, rA, cA, matrixB, rB, cB, matrixC, i + 1);
}
int main() {
    int i, j;
    int rA, cA, rB, cB;
    int matrixA[50][50], matrixB[50][50], matrixC[50][50];
    // Enter Matrix A
    printf("Enter Number of Rows in MatrixA: ");
    scanf("%d", &rA);
    printf("Enter Number of columns in MatrixA: ");
    scanf("%d", &cA);
    printf("Enter MatrixA: \n");
    for (i = 0; i < rA; ++i) {
        for (j = 0; j < cA; ++j) {
            scanf("%d", &matrixA[i][j]);
        }
    }
    // Enter Matrix B
    printf("Enter Number of Rows in MatrixB: ");
    scanf("%d", &rB);
    printf("Enter Number of columns in MatrixB: ");
    scanf("%d", &cB);
    printf("Enter MatrixB: \n");
    for (i = 0; i < rB; ++i) {
        for (j = 0; j < cB; ++j) {
            scanf("%d", &matrixB[i][j]);
        }
    }
    // the function multiply matrixA and matrixB and stores
    // the result in matrixC
    // the order of matrixC is rA X cB
    MatrixMultiplication(matrixA, rA, cA, matrixB, rB, cB, matrixC, 0);
    // Printing MatrixC
    printf("\nThe Matrix Multiplication of MatrixA and MatrixB: \n");
    for (i = 0; i < rA; ++i) {
        for (j = 0; j < cB; ++j) {
            printf("%d ", matrixC[i][j]);
        }
        printf("\n");
    }
}
