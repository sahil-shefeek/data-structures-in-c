#include <stdio.h>

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

int main(){
	int arr[100],size, choice, element, pos, index, flag = 0;
		printf("Enter array size:\n");
		scanf("%d", &size);
		printf("Enter array elements :\n");
		for (int i =0 ; i< size ; i++)
			scanf("%d", &arr[i]);
		print_arr(arr, size);
		do
		{
			printf("Select operation :\n");
			printf("1. Insertion\n2. Deletion\n3. Exit\n");
			scanf("%d", &choice);
			switch (choice)
			{
				case 1:
					printf("Enter the element to insert :");
					scanf("%d", &element);
					printf("Enter the position to insert to :");
					scanf("%d", &pos);
					index = pos - 1;
					for (int i = size; i > index; i--)
						{
							arr[i] = arr [i-1];
						}
					arr [index] = element;
					size++;
					print_arr(arr, size);
					break;
			
				case 2:
					printf("Enter the element to delete :");
					scanf("%d", &element);
					for (int i = 0 ; i<size ; i++ )
					{
						if (arr[i] == element)
						{
							index = i;
							flag = 1;
						}
					}
					if (flag)
					{
						for (int i = index; i< size; i++)
							arr[i] = arr[i+1];
						size--;
						print_arr(arr, size);
					}
					else
						printf("ERR: Deletion failed.\n Element not found in array.\n");
					break;
					
				case 3:
					break;
					
				default:
					printf("Invalid choice!\nTry again...\n");
					break;
			}
		} while (choice != 3);
		
		return 0;
		
}
