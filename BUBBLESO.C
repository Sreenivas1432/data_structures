//Write a C Program to implement the following sorting algorithms  using user defined functions a) Bubble Sort(Ascending order b) selection sort(Descending order)

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void display(int a[], int n);
void bubble_sort(int a[], int n);
void selection_sort(int a[], int n);
//------------------Main Function-------------------

void main()
{ 
	int n,choice,i; 
	int arr[20]; 
	clrscr(); 
	printf("Enter no. of elements you want to sort :"); 
	scanf("%d",&n); 
	for(i=0;i<n;i++) 
	{ 
		printf("Enter %d Element: ",i+1); 
		scanf("%d",&arr[i]); 
	} 
	printf("Please select any option Given Below for Sorting :\n"); 
	while(1) 
	{ 
		printf("\nl. Bubble Sort\n2. Selection Sort\n3. Display Array \n4. Exit the Program\n"); 
		printf("Enter your Choice: "); 
		scanf("%d",&choice); 
		switch(choice) 
		{ 
			case 1: 
				bubble_sort(arr,n); 
				break; 
			case 2: 
				selection_sort(arr,n); 
				break; 
			case 3: 
				display(arr,n); 
				break; 
			case 4: 
				exit(0);
			default: 
				printf("\nPlease Select only 1-4 option --------\n");
		} 
	} 
getch();
} 
//-----------End of main function--------------- //-----------Display Function------------------- 
void display(int arr[], int n) 
{ 
	int i; 
	for(i=0;i<n;i++)
	{ 
		printf("%d\t",arr[i]); 
	} 
} 
//---------------------Bubble Sort Function-------------- 
void bubble_sort(int arr[], int n) 
{ 
	int i,j,temp; 
	for(i=0;i<n;i++) 
	{ 
		for(j=0;j<n-i-1;j++) 
		{ 
			if(arr[j]>arr[j+1]) 
			{ 
				temp=arr[j]; arr[j]= arr[j+1]; 
				arr[j+1]=temp; 
			} 
		} 
	} 
	printf("After Bubble sort Elements are: "); 
	display(arr,n); 
} 
//--------------Selection Sort Function------- 
void selection_sort(int arr[], int n) 
{ 
	int i,j,temp; 
	for(i=0;i<n-1;i++) 
	{ 
		for(j=i+1;j<n;j++) 
		{ 
			if(arr[i]<arr[j]) 
			{ 
				temp=arr[i]; 
				arr[i]=arr[j]; 
				arr[j]=temp; 
			} 
		} 
	} 
	printf("After Selection sort Elements are: "); 
	display(arr,n); 
} 
