#include <stdio.h>

int triplet[20][3];

void get_triplet(int row, int column)
{
    int a[20][20], i, j, q = 0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
            scanf("%d", &a[i][j]);
    }
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            if (a[i][j] != 0)
            {
                q++;
                triplet[q][0] = i;
                triplet[q][1] = j;
                triplet[q][2] = a[i][j];
            }
        }
    }
    triplet[0][0] = row;
    triplet[0][1] = column;
    triplet[0][2] = q;
}

int main()
{
    int i, j, k, q, nz = 0, row, column;
    int triplet1[20][3], triplet2[20][3], sum[20][3];
    printf("Matrix 1:\n");
    printf("Enter the number of rows: ");
    scanf("%d", &row);
    printf("Enter the number of columns: ");
    scanf("%d", &column);
    printf("Enter the elements row wise:\n");
    get_triplet(row, column);
    printf("Triplet of Matrix 1:\n");
    for (i = 0; i <= triplet[0][2]; i++)
    {
        for (j = 0; j < 3; j++)
        {
            triplet1[i][j] = triplet[i][j];
            printf("%d\t", triplet1[i][j]);
        }
        printf("\n");
    }
    printf("Matrix 2:\n");
    printf("Enter the number of rows: ");
    scanf("%d", &row);
    printf("Enter the number of columns: ");
    scanf("%d", &column);
    printf("Enter the elements row wise:\n");
    get_triplet(row, column);
    printf("Triplet of Matrix 2:\n");
    for (i = 0; i <= triplet[0][2]; i++)
    {
        for (j = 0; j < 3; j++)
        {
            triplet2[i][j] = triplet[i][j];
            printf("%d\t", triplet2[i][j]);
        }
        printf("\n");
    }

    k = triplet1[0][2], q = triplet2[0][2];
    if (triplet1[0][0] == triplet2[0][0] && triplet1[0][1] == triplet2[0][1])
    {
        i = 1, j = 1;
        while (i <= k && j <= q)
        {
            if (triplet1[i][0] == triplet2[j][0] && triplet1[i][1] == triplet2[j][1])
            {
                nz++;
                sum[nz][0] = triplet1[i][0];
                sum[nz][1] = triplet1[i][1];
                sum[nz][2] = triplet1[i][2] + triplet2[j][2];
                i++, j++;
            }
            else if (triplet1[i][0] == triplet2[j][0])
            {
                if (triplet1[i][1] < triplet2[j][1])
                {
                    nz++;
                    sum[nz][0] = triplet1[i][0];
                    sum[nz][1] = triplet1[i][1];
                    sum[nz][2] = triplet1[i][2];
                    i++;
                }
                else
                {
                    nz++;
                    sum[nz][0] = triplet2[j][0];
                    sum[nz][1] = triplet2[j][1];
                    sum[nz][2] = triplet2[j][2];
                    j++;
                }
            }
            else if (triplet1[i][0] < triplet2[j][0])
            {
                nz++;
                sum[nz][0] = triplet1[i][0];
                sum[nz][1] = triplet1[i][1];
                sum[nz][2] = triplet1[i][2];
                i++;
            }
            else
            {
                nz++;
                sum[nz][0] = triplet2[j][0];
                sum[nz][1] = triplet2[j][1];
                sum[nz][2] = triplet2[j][2];
                j++;
            }
        }
        while (i <= k)
        {
            nz++;
            sum[nz][0] = triplet1[i][0];
            sum[nz][1] = triplet1[i][1];
            sum[nz][2] = triplet1[i][2];
            i++;
        }
        while (j <= q)
        {
            nz++;
            sum[nz][0] = triplet2[j][0];
            sum[nz][1] = triplet2[j][1];
            sum[nz][2] = triplet2[j][2];
            j++;
        }
        sum[0][0] = triplet1[0][0];
        sum[0][1] = triplet1[0][1];
        sum[0][2] = nz;
        printf("Sum of Matrix 1 and Matrix 2:\n");
        for (i = 0; i <= nz; i++)
        {
            for (j = 0; j < 3; j++)
                printf("%d\t", sum[i][j]);
            printf("\n");
        }
    }
    else
        printf("Addition not possible!\n");
    return 0;
}