#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev, *next;
} Node;

Node *head = NULL, *tail = NULL, *mov = NULL;

void readll(int num)
{
    for(int i = 0; i < num; i++)
    {
		Node *new = (Node*) malloc(sizeof(Node));
		printf("Enter element to insert: ");
		scanf("%d", &new->data);
		new->prev = NULL;
		new->next = NULL;
		if(head == NULL)
		    head = new;
		else
		{
		    tail->next = new;
		    new->prev = tail;
		}
			tail = new;
    }
}

void print()
{	
	if (head == NULL)
		printf("List is empty!\n");
	else
	{
	    Node *ptr = head;
		while(ptr != NULL)
	    {
    	    printf("%d\t", ptr->data);
    	    ptr = ptr->next;
   		 }  
   		 printf("\n");
	}
}

int main()
{
    int key, num;
    printf("Enter the number of elements in the list:\n");
    scanf("%d", &num);
	readll(num);
    printf("Before operation:\n");
    print();
    printf("Enter element to be moved:\n");
    scanf("%d", &key);
    if(head->data == key)
        printf("Element at front of DLL!\n");
    else
    {
        Node *ptr = head;
        while(ptr->next != NULL)
        {
            if(ptr->next->data == key)
            {
                mov = ptr->next;
            	ptr->next = mov->next;
            	if(mov->next != NULL)
                	mov->next->prev = ptr;    
            	if (mov == tail)
            		tail = tail->prev;
            	break;
            }
            ptr = ptr->next;
       }
       if (mov == NULL)
			printf("Element not found!\n");
       else
		{
            mov->next = head;
            head = mov;
            printf("List after modification:\n");
            print();
        }
    }
	return 0;
}



