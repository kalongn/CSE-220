#include "../include/global.h"

int min(int numOne, int numTwo) {
    return numOne < numTwo ? numOne : numTwo;
}

int SparseMatrix(int **M, int **S, int *D) {
    int indexOfSparseMatrix = 0;
    int rowLength = *D, colLength = *(D + 1);
    int maximumSpace = rowLength > colLength ? rowLength : colLength;
    for (int i = 0; i < rowLength; i++) {
        for (int j = 0; j < colLength; j++) {
            if (*(*(M + i) + j) != 0) {
                if (indexOfSparseMatrix == maximumSpace) {
                    return -1;
                }
                *(*(S + 0) + indexOfSparseMatrix) = i;
                *(*(S + 1) + indexOfSparseMatrix) = j;
                *(*(S + 2) + indexOfSparseMatrix) = *(*(M + i) + j);
                indexOfSparseMatrix = indexOfSparseMatrix + 1;
            }
        }
    }
    return indexOfSparseMatrix;
}
int Addition(int **M, int **N, int **A, int *D) {
    int rowLengthM = *D, colLengthM = *(D + 1);
    int rowLengthN = *(D + 2), colLengthN = *(D + 3);
    int rowLengthA = *(D + 4), colLengthA = *(D + 5);

    int iMax = min(min(rowLengthA, rowLengthM), rowLengthN), jMax = min(min(colLengthA, colLengthM), colLengthN);
    for (int i = 0; i < iMax; i++) {
        for (int j = 0; j < jMax; j++) {
            *(*(A + i) + j) = *(*(M + i) + j) + *(*(N + i) + j);
        }
    }
    if (rowLengthN == rowLengthM && colLengthN == colLengthM) {
        if (rowLengthA == rowLengthM && colLengthA == colLengthM) {
            return 1;
        }
        if (rowLengthA >= rowLengthM && colLengthA >= colLengthM) {
            return 2;
        }
        return -3;
    }
    int largerRowLength = rowLengthM > rowLengthN ? rowLengthM : rowLengthN;
    int largerColLength = colLengthM > colLengthN ? colLengthM : colLengthN;
    if (rowLengthA >= largerRowLength && colLengthA >= largerColLength) {
        return -1;
    }
    return -2;
}

int Multiplication(int **M, int **N, int **A, int *D) {
    int rowLengthM = *D, colLengthM = *(D + 1);
    int rowLengthN = *(D + 2), colLengthN = *(D + 3);
    int rowLengthA = *(D + 4), colLengthA = *(D + 5);

    int iMax = min(rowLengthM, rowLengthA), jMax = min(colLengthN, colLengthA), zMax = min(colLengthM, rowLengthN);
    for (int i = 0; i < iMax; i++) {
        for (int j = 0; j < jMax; j++) {
            for (int z = 0; z < zMax; z++) {
                *(*(A + i) + j) += (*(*(M + i) + z) * *(*(N + z) + j));
            }
        }
    }

    if (colLengthM == rowLengthN) {
        if (rowLengthM == rowLengthA && colLengthN == colLengthA) {
            return 1;
        } else if (rowLengthA >= rowLengthM && colLengthA >= colLengthM) {
            return 2;
        } else {
            return -3;
        }
    }
    if (rowLengthA >= rowLengthM && colLengthA >= colLengthN) {
        return -1;
    }
    return -2;
}
int Transpose(int **A, int **AT, int *D) {
    int rowLengthA = *D, colLengthA = *(D + 1);
    int rowLengthAT = *(D + 2), colLengthAT = *(D + 3);

    int iMax = min(rowLengthA, colLengthAT), jMax = min(colLengthA, rowLengthAT);
    for (int i = 0; i < iMax; i++) {
        for (int j = 0; j < jMax; j++) {
            *(*(AT + j) + i) = *(*(A + i) + j);
        }
    }

    if (rowLengthA == colLengthAT && colLengthA == rowLengthAT) {
        return 1;
    }
    for (int i = iMax; i < rowLengthAT; i++) {
        for (int j = jMax; j < colLengthAT; j++) {
            *(*(AT + i) + j) = 0;
        }
    }
    if (colLengthAT >= rowLengthA && rowLengthAT >= colLengthA) {
        return 2;
    }
    return -1;
}

// Helper functions for Testing
int **initializeMatrix(int n, int m, int *values) {
    int **ret = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        ret[i] = (int *)malloc(m * sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ret[i][j] = values[i * m + j];
        }
    }
    return ret;
}

void freeMatrix(int n, int **M) {
    for (int i = 0; i < n; i++) {
        free(M[i]);
    }
    free(M);
}

void printMatrix(int n, int m, int **M, char *name) {
    printf("%s:\n", name);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", M[i][j]);
            if (j == m - 1) {
                printf("\n");
            }
        }
    }
}

int main(void) {
    int **M = initializeMatrix(1, 3, (int[]) { 1, 2, 3 });
    int **A_act = initializeMatrix(2, 4, (int[]) { 0, 0, 0, 0, 0, 0, 0, 0 });
    int **A_exp = initializeMatrix(2, 4, (int[]) { 1, 0, 0, 0, 2, 0, 0, 0 });
    int D[4] = { 1,3,2,4 };
    int ret_act = Transpose(M, A_act, D);
    int ret_exp = -1;
    printf("Transpose:\n");
    printf("Expected: %d\n", ret_exp);
    printf("Actual: %d\n", ret_act);
    return 0;
}

