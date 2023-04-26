#include <stdio.h>

void matrixMultiply(int A[][100], int B[][100], int C[][100], int row1, int col1, int row2, int col2, int row3, int col3)
{
    if (row3 == row1 && col3 == col2)
    {
        
        C[row3][col3] = 0;
        for (int i = 0; i < col1; i++)
        {
            C[row3][col3] += A[row3][i] * B[i][col3];
        }
    }
    else
    {
       
        C[row3][col3] = 0;
        for (int i = 0; i < col1; i++)
        {
            C[row3][col3] += A[row3][i] * B[i][col3];
        }

        if (col3 < col2)
        {
            matrixMultiply(A, B, C, row1, col1, row2, col2, row3, col3 + 1);
        }
        else if (row3 < row1)
        {
            matrixMultiply(A, B, C, row1, col1, row2, col2, row3 + 1, 0);
        }
    }
}

int main()
{
    int row1, col1, row2, col2;
    int A[100][100], B[100][100], C[100][100];

    printf("Enter the number of rows and columns of matrix A: ");
    scanf("%d %d", &row1, &col1);
    printf("Enter the number of rows and columns of matrix B: ");
    scanf("%d %d", &row2, &col2);

    if (col1 != row2)
    {
        printf("Matrix multiplication not possible! Column of A must be equal to row of B.\n");
        return 0;
    }

    printf("Enter the elements of matrix A:\n");
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter the elements of matrix B:\n");
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            C[i][j] = 0;
        }
    }

    matrixMultiply(A, B, C, row1, col1, row2, col2, 0, 0);

    printf("Matrix A:\n");
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    printf("Matrix B:\":\n");
for (int i = 0; i < row2; i++)
{
for (int j = 0; j < col2; j++)
{
printf("%d ", B[i][j]);
}
printf("\n");
}
printf("Matrix C (Result of matrix multiplication A * B):\n");
for (int i = 0; i < row1; i++)
{
    for (int j = 0; j < col2; j++)
    {
        printf("%d ", C[i][j]);
    }
    printf("\n");
}

return 0;
}
