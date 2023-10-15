#include <stdio.h>

void print_sparce(int (*mat)[10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            printf("%d\t", mat[i][j]);
        printf("\n");
    }
}

void parse_triplet(int (*mat)[10], int *count, int *rows, int *cols, int (*mat_3)[3])
{

    for (int i = 0; i < *rows; i++)
    {
        for (int j = 0; j < *cols; j++)
            scanf("%d", &mat[i][j]);
    }
    printf("You have entered :\n");
    print_sparce(mat, *rows, *cols);

    printf("Generating triplet representation...\n");
    for (int i = 0; i < (*rows); i++)
    {
        for (int j = 0; j < (*cols); j++)
            if (mat[i][j] != 0)
            {
                (*count)++;
                mat_3[*count][0] = i;
                mat_3[*count][1] = j;
                mat_3[*count][2] = mat[i][j];
            }
    }
    mat_3[0][0] = *rows;
    mat_3[0][1] = *cols;
    mat_3[0][2] = *count;
}

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
    int mat_a[10][10], mat_b[10][10];
    int triplet_a[100][3], triplet_b[100][3];
    int row_a, col_a, count_a = 0, row_b, col_b, count_b = 0;
    printf("Input the first matrix :\n");
    printf("Enter the number of rows :\n");
    scanf("%d", &row_a);
    printf("Enter the number of columns :\n");
    scanf("%d", &col_a);

    printf("Input the second matrix :\n");
    printf("Enter the number of rows :\n");
    scanf("%d", &row_b);
    printf("Enter the number of columns :\n");
    scanf("%d", &col_b);

    if (!(row_a == row_b && col_a == col_b))
    {
        printf("Matrix addition not possible.\n");
        return 0;
    }

    printf("Enter first sparce matrix elements :\n");
    parse_triplet(mat_a, &count_a, &row_a, &col_a, triplet_a);

    print_triplet(triplet_a, count_a);

    printf("Enter second sparce matrix elements :\n");
    parse_triplet(mat_b, &count_b, &row_b, &col_b, triplet_b);

    print_triplet(triplet_b, count_b);

    int res[200][3];

    int i = 1, j = 1, k = 0;
    while (i <= count_a && j <= count_b)
    {
        if (triplet_a[i][0] == triplet_b[j][0] && triplet_a[i][1] == triplet_b[j][1])
        {
            k++;
            res[k][0] = triplet_a[i][0];
            res[k][1] = triplet_a[i][1];
            res[k][2] = triplet_a[i][2] + triplet_b[j][2];
            i++, j++;
        }
        else if (triplet_a[i][0] == triplet_b[j][0])
        {
            if (triplet_a[i][1] < triplet_b[j][1])
            {
                k++;
                sparce_add(res, triplet_a, k, i);
                i++;
            }
            else
            {
                k++;
                sparce_add(res, triplet_b, k, j);
                j++;
            }
        }
        else if (triplet_a[i][0] < triplet_b[j][0])
        {
            k++;
            sparce_add(res, triplet_a, k, i);
            i++;
        }
        else
        {
            k++;
            sparce_add(res, triplet_b, k, j);
            j++;
        }
    }

    while (i <= count_a)
    {
        k++;
        sparce_add(res, triplet_a, k, i);
        i++;
    }

    while (j <= count_b)
    {
        k++;
        sparce_add(res, triplet_b, k, j);
        j++;
    }

    res[0][0] = row_a;
    res[0][1] = col_a;
    res[0][2] = k;

    printf("The sum is :\n");
    print_triplet(res, k);
    return 0;
}