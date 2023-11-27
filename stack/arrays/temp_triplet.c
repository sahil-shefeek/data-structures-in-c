#include <stdio.h>

int main()
{
	int i, j, nz = 0, row, column;
	int a[20][20], triplet[20][3];
	printf("Enter the number of rows:");
	scanf("%d", &row);
	printf("Enter the number of columns:");
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
	return 0;
}
