//Design , develop and execute a program in C to simulate the working of queue of integers using an array. Provide the following  operations a.Insert b.Delete c.Display
#include <stdio.h>
#include<conio.h>
#define MAX_SIZE 100
int queue[MAX_SIZE];
int front = -1, rear = -1;
void insert()
{
	int element;
	if (rear == MAX_SIZE - 1)
	{
		printf("Error: Queue is full\n");
		return;
	}
	printf("Enter element to insert: ");
	scanf("%d", &element);
	if (front == -1)
		front = 0;
		rear++;
		queue[rear] = element;
	printf("Element inserted successfully\n");
}
void delete()
{
	if(front == -1 || front > rear)
	{
		printf("Error: Queue is empty\n");
		return;
	}
	front++;
	printf("Element deleted successfully\n");
}
void display()
{
	int i;
	if (front == -1 || front > rear)
	{
		printf("Error: Queue is empty\n");
		return;
	}
	printf("Queue elements: ");
	for(i=front;i<=rear;i++)
		printf("%d ", queue[i]);

	printf("\n");
}
void main()
{
	int choice;
	clrscr();
	while (1)
	{
		printf("Queue Operations\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Display\n");
		printf("4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
			case 1:
				insert();
				break;
			case 2:
				delete();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("Exiting the program...\n");
				exit(0);
			default:
				printf("Invalid choice\n");
				break;
		}
	}
    getch();
}
