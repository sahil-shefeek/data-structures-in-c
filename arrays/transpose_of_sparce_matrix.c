#include <stdio.h>
int main()
{
    int mat[100][100], mat_3[100][3];
    int trans_3[100][3];
    int rows, cols, count = 0;
    printf("Enter the number of rows :\n");
    scanf("%d", &rows);
    printf("Enter the number of columns :\n");
    scanf("%d", &cols);
    printf("Enter the sparce matrix elements :\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            scanf("%d", &mat[i][j]);
    }

    printf("Generating triplet representation...\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            if (mat[i][j] != 0)
            {
                count++;
                mat_3[count][0] = i;
                mat_3[count][1] = j;
                mat_3[count][2] = mat[i][j];
            }
    }
    mat_3[0][0] = rows;
    mat_3[0][1] = cols;
    mat_3[0][2] = count;

    for (int i = 0; i <= count; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%d \t", mat_3[i][j]);
        printf("\n");
    }

    printf("Generating triplet representation...\n");
    for (int i = 0; i <= count; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%d \t", mat_3[i][j]);
        printf("\n");
    }

    printf("Generating transpose of triplet representation...\n");
    trans_3[0][0] = mat_3[0][1];
    trans_3[0][1] = mat_3[0][0];
    trans_3[0][2] = mat_3[0][2];
    for (int i = 0, k = 0; i <= cols; i++)
    {
        for (int j = 1; j <= count; j++)
        {
            if (mat_3[j][1] == i)
            {
                k++;
                trans_3[k][0] = mat_3[j][1];
                trans_3[k][1] = mat_3[j][0];
                trans_3[k][2] = mat_3[j][2];
            }
        }
    }

    for (int i = 0; i <= count; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%d \t", trans_3[i][j]);
        printf("\n");
    }
}