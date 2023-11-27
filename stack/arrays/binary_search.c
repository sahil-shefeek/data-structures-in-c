#include <stdio.h>

int main()
{
	int arr[100], low, high, mid, flag = 0;
	int key, size, index;
	printf("Enter sorted array size:");
	scanf("%d", &size);
	printf("Enter array elements :\n");
	for (int i = 0; i < size; i++)
		scanf("%d", &arr[i]);
	printf("Index: ");
	for (int i = 0; i < size; i++)
		printf("[%d]\t", i);
	printf("\n");
	printf("Element: ");
	for (int i = 0; i < size; i++)
		printf("%d\t", arr[i]);
	printf("\n");
	printf("Enter element to search :");
	scanf("%d", &key);
	low = 0;
	high = size - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key == arr[mid])
		{
			index = mid;
			flag = 1;
			break;
		}
		else if (arr[mid] > key)
		{
			high = mid - 1;
		}
		else if (arr[mid] < key)
			low = mid + 1;
	}

	if (flag == 1)
		printf("Element found at index : %d\n", index);
	else
		printf("Requested element (%d) is not found in the given array.\n", key);
	return 0;
}
