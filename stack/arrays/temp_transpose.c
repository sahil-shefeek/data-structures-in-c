#include <stdio.h>
int main()
{
	int i, j, k = 0, nz = 0, row, column;
	int a[20][20], triplet[20][3], transpose[20][3];
	printf("Enter the number of rows: ");
	scanf("%d", &row);
	printf("Enter the number of columns: ");
	scanf("%d", &column);
	printf("Enter the elements row wise:\n");
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
				nz++;
				triplet[nz][0] = i;
				triplet[nz][1] = j;
				triplet[nz][2] = a[i][j];
			}
		}
	}
	triplet[0][0] = row;
	triplet[0][1] = column;
	triplet[0][2] = nz;
	printf("Triplet representation:\n");
	for (i = 0; i <= nz; i++)
	{
		for (j = 0; j < 3; j++)
			printf("%d ", triplet[i][j]);
		printf("\n");
	}

	for (i = 0; i < triplet[0][1]; i++)
	{
		for (j = 1; j <= triplet[0][2]; j++)
		{
			if (triplet[j][1] == i)
			{
				k++;
				transpose[k][0] = triplet[j][1];
				transpose[k][1] = triplet[j][0];
				transpose[k][2] = triplet[j][2];
			}
		}
	}
	transpose[0][0] = triplet[0][1];
	transpose[0][1] = triplet[0][0];
	transpose[0][2] = triplet[0][2];
	printf("Transpose of the given triplet representation:\n");
	for (i = 0; i <= k; i++)
	{
		for (j = 0; j < 3; j++)
			printf("%d ", transpose[i][j]);
		printf("\n");
	}
	return 0;
}