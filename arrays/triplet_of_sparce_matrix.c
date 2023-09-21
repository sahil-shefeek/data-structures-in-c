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
}