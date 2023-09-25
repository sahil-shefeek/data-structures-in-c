#include <stdio.h>

void print_triplet(int (*triplet)[3], int count)
{
    for (int i = 0; i < count + 1; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%d\t", triplet[i][j]);
        printf("\n");
    }
}

void sparce_add(int (*res)[3], int (*mat)[3], int res_k, int mat_k)
{
    res[res_k][0] = mat[mat_k][0];
    res[res_k][1] = mat[mat_k][1];
    res[res_k][2] = mat[mat_k][2];
}

int main()
{
    int mat_a[100][3], mat_b[100][3];
    int row_a, col_a, count_a, row_b, col_b, count_b;
    printf("Input the first matrix :\n");
    printf("Enter the number of rows :\n");
    scanf("%d", &row_a);
    printf("Enter the number of cols :\n");
    scanf("%d", &col_a);
    printf("Enter the number of non-zero elements :\n");
    scanf("%d", &count_a);
    printf("Enter matrix elements :\n");

    for (int i = 1; i <= count_a; i++)
    {
        for (int j = 0; j < 3; j++)
            scanf("%d", &mat_a[i][j]);
    }

    mat_a[0][0] = row_a;
    mat_a[0][1] = col_a;
    mat_a[0][2] = count_a;

    printf("You have entered :\n");
    print_triplet(mat_a, count_a);

    printf("Input the second matrix :\n");
    printf("Enter the number of rows :\n");
    scanf("%d", &row_b);
    printf("Enter the number of cols :\n");
    scanf("%d", &col_b);

    if (!(row_a == row_b && col_a == col_b))
    {
        printf("Matrix addition not possible.\n");
        return 0;
    }

    printf("Enter the number of non-zero elements :\n");
    scanf("%d", &count_b);
    printf("Enter matrix elements :\n");

    for (int i = 1; i <= count_b; i++)
    {
        for (int j = 0; j < 3; j++)
            scanf("%d", &mat_b[i][j]);
    }

    mat_b[0][0] = row_b;
    mat_b[0][1] = col_b;
    mat_b[0][2] = count_b;

    printf("You have entered :\n");
    print_triplet(mat_b, count_b);

    int res[200][3];

    int i = 1, j = 1, k = 0;
    while (i <= count_a && j <= count_b)
    {
        if (mat_a[i][0] == mat_b[j][0] && mat_a[i][1] == mat_b[j][1])
        {
            k++;
            res[k][0] = mat_a[i][0];
            res[k][1] = mat_a[i][1];
            res[k][2] = mat_a[i][2] + mat_b[j][2];
            i++, j++;
        }
        else if (mat_a[i][0] == mat_b[j][0])
        {
            if (mat_a[i][1] < mat_b[j][1])
            {
                k++;
                sparce_add(res, mat_a, k, i);
                i++;
            }
            else
            {
                k++;
                sparce_add(res, mat_b, k, j);
                j++;
            }
        }
        else if (mat_a[i][0] < mat_b[j][0])
        {
            k++;
            sparce_add(res, mat_a, k, i);
            i++;
        }
        else
        {
            k++;
            sparce_add(res, mat_b, k, j);
            j++;
        }
    }

    while (i <= count_a)
    {
        k++;
        sparce_add(res, mat_a, k, i);
        i++;
    }

    while (j <= count_b)
    {
        k++;
        sparce_add(res, mat_b, k, j);
        j++;
    }

    res[0][0] = row_a;
    res[0][1] = col_a;
    res[0][2] = k;

    printf("The sum is :\n");
    print_triplet(res, k + 1);
    return 0;
}