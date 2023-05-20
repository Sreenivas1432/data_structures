//Write a C Program to simulate the working of a singly linked list providing the following operations a) Display & Insert  b) Delete from beginning/end c) Delete a given element
#include<stdio.h> 
#include<stdlib.h>  
struct node 
{ 
	int data; 
	struct node *next; 
}; 
struct node *head; 
void beginsert(); 
void begin_delete(); 
void last_delete(); 
void random_delete();  
void display(); 
void search(); 
void main() 
{ 
	int choice =0; 
	clrscr(); 
	while(choice != 9) 
	{ 
		printf("\n\n*********Main Menu *******\n"); 
		printf("\nChoose one option from the following list ...\n"); 
		printf("\n=======================================================\n"); 
		printf("\n1.Insert in begining \n2.Delete from Beginning\n3.Delete from last\n4.Delete node after specified location\n5.Search for an element\n6.Show\n7.Exit\n"); 
		printf("\nEnter your choice?\n"); 
		scanf("%d",&choice);
		switch(choice) 
		{ 
			case 1:
				beginsert(); 
				break; 
			case 2: 
				begin_delete(); 
				break; 
			case 3: 
				last_delete(); 
				break; 
			case 4: 
				random_delete(); 
				break; 
			case 5: 
				search(); 
				break; 
			case 6: 
				display(); 
				break; 
			case 7: 
				exit(0); 
				break; 
			default: 
				printf("Please enter valid choice.."); 
		} 
	} 
getch(); 
} 
void beginsert()
{
	struct node *ptr; 
	int item; 
	ptr = (struct node *) malloc(sizeof(struct node *));
	if(ptr == NULL) 
	{ 
		printf("\nOVERFLOW"); 
	} 
	else
	{ 
		printf("\nEnter value\n");
		scanf("%d",&item); 
		ptr->data = item;
		ptr -> next = head; 
		head = ptr; 
		printf("\nNode inserted"); 
	} 
}
void begin_delete()
{ 
	struct node *ptr;  
	if(head== NULL) 
	{
		printf("\nList is empty\n"); 
	}
	else
	{ 
		ptr= head; head= ptr->next; 
		free(ptr);
		printf("\nNode deleted from the begining...\n"); 
	} 
}
void last_delete()
{
	struct node *ptr, *ptr1; 
	if(head== NULL) 
	{
		printf("\nlist is empty"); 
	} 
	else if(head->next == NULL) 
	{ 
		head = NULL; 
		free(head); 
		printf("\nOnly node of the list deleted...\n"); 
	}
	else
	{ 
		ptr = head; 
		while(ptr->next!= NULL) 
		{ 
			ptr1 = ptr; ptr = ptr ->next; 
		}  
		ptr1->next = NULL; 
		free(ptr);
		printf("\nDeleted Node from the last...\n"); 
	} 
}
void random_delete() 
{ 
	struct node *ptr,*ptr1; 
	int loc,i; 
	printf("\n Enter the location of the node after which you want to perform deletion \n");
	scanf("%d",&loc);
	ptr=head;
	for(i=0;i<loc;i++) 
	{
		ptr1 = ptr;
		ptr =ptr->next; 
		if(ptr== NULL) 
		{ 
			printf("\nCan't delete"); 
			return; 
		} 
	} 
	ptr1->next = ptr ->next; 
	free(ptr);  
	printf("\nDeleted node %d ",loc+1); 
}
void search() 
{
	struct node *ptr;
	int item,i=0, flag; 
	ptr = head; 
	if(ptr == NULL) 
	{ 
		printf("\nEmpty List\n"); 
	} 
	else 
	{ 
		printf("\nEnter item which you want to search?\n"); 
		scanf("%d",&item); 
		while (ptr!=NULL) 
		{ 
			if(ptr->data == item) 
			{ 
				printf("Item found at location %d ",i+1); 
				flag=0; 
			} 
			else 
			{ 
				flag=1; 
			} 
			i++; 
			ptr = ptr ->next; 
		} 
		if(flag == 1) 
		{ 
			printf("Item not found\n"); 
		} 
	} 
}
void display() 
{ 
	struct node *ptr;
	ptr = head; 
	if(ptr == NULL)
	{
		printf("Nothing to print");
	}
	else 
	{ 
		printf("\nprinting values.....\n"); 
		while (ptr!=NULL) 
		{ 
			printf("\n%d",ptr->data); 
			ptr = ptr ->next; 
		} 
	} 
} 
