#include <stdio.h>

void scan_arr(int *arr, int size)
{	
	printf("Enter array elements :\n");
	for (int i =0; i < size ; i++)
		scanf("%d",&arr[i]);
}

void print_arr(int *arr, int size)
{	
	printf("Index: ");
	for (int i =0; i < size ; i++)
		printf("[%d]\t",i);
	printf("\n");
	printf("Element: ");
	for (int i =0; i < size ; i++)
		printf("%d\t", arr[i]);
	printf("\n");
}

int main()
{
	int arr[100], low , high , mid, flag =0;
	int key, size, index;
	printf("Enter sorted array size:");
	scanf("%d", &size);
	scan_arr(arr, size);
	print_arr(arr, size);
	search:
		printf("Enter element to search :");
		scanf("%d", &key);
		low = 0;
		high = size-1;
		while( low <= high )
		{
			mid = (low+high)/2;
			if ( key == arr[mid] )
			{
				index = mid;
				flag = 1;
				break;
			}
			else if (arr[mid] > key)
			{
				high = mid-1;
			}
			else if (arr[mid] < key)
				low = mid + 1;
		}
		
		if (flag)
			printf("Element found at index : %d\n", index);
		else
		{
			printf("Requested element (%d) is not found in the given array.\n", key);
			goto search;
		}
	return 0;
	
	
}
