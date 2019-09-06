/*
 ============================================================================
 Name        : Assignment6.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Assignment 6 - bubble,selection sort, binary search(recursive&non-rec).
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stud{
	char name[30];
	int roll;
	int marks;
}Stud;


void swap(int *a , int *b){
	int tmp;
	tmp = *b;
	*b = *a;
	*a = tmp;
}

void swapchar(char a[20], char b[20]){

	char tmp[20];
	strcpy(tmp,b);
	strcpy(b,a);
	strcpy(a,tmp);

}

void bubbleSort(Stud s[], int n){
	int i , j, c=0;
    printf("\n");
	for(j=0;j<n;j++)
		printf("%d ", s[j].roll);
	printf(" (Original)");
	for(i=0;i<n-1; i++){
		for(j = 0; j < n-i-1; j++){
			if(s[j].roll > s[j+1].roll){

				swap(&s[j].roll , &s[j+1].roll);
				swapchar(s[j].name , s[j+1].name);
				swap(&s[j].marks, &s[j+1].marks);
				c++;
			}
		}
		printf("\n");
		for(j=0;j<n;j++)
			printf("%d ", s[j].roll);
		printf(" (Pass %d)", i+1);
	}
	printf("\nNo. of swaps = %d\n", c);
}


void selSort(Stud s[], int n){
    int i, j, min,c=0;
    printf("\n");
	for(j=0;j<n;j++)
		printf("%d ", s[j].marks);
	printf(" (Original)");
    for (i = 0; i < n-1; i++){
        min = i;
        for (j = i+1; j < n; j++)
          if (s[j].marks > s[min].marks)
            min = j;

		  swap(&s[min].roll, &s[i].roll);
		  swapchar(s[min].name, s[i].name);
		  swap(&s[min].marks, &s[i].marks);
		  if(min!=i)
			  c++;
		  printf("\n");
		for(j=0;j<n;j++)
			printf("%d ", s[j].marks);
		printf(" (Pass %d)", i+1);
    }
	printf("\nNo. of swaps = %d\n", c);
}

int binarySearch(Stud s[], int l, int h, int x){
	int  mid;
	if(h>=l)
	{
		mid = (h+l)/2;
		if(s[mid].roll == x)
			return mid;
		if(s[mid].roll > x)
			return binarySearch(s, l, mid-1, x);
		if(s[mid].roll < x)
			return binarySearch(s, mid+1, h, x);
	}
	else
		return -1;
	return -1;
}

int binarySearch_nonrec(Stud s[],int n, int x){
	int l=0,h=n,mid;
	while(l<=h)
	{
		mid = (h+l)/2;
		if(s[mid].roll == x)
			return mid;
		if(s[mid].roll > x)
			h=mid-1;
		if(s[mid].roll < x)
			l=mid+1;
	}
	return -1;
}



void inp(Stud s[], int i){
	printf("Enter the Details: \n");
	printf("\tName: ");
	scanf("%s[^\n]",s[i].name);
	printf("\tRoll No.: ");
	scanf("%d",&s[i].roll);
	printf("\tMarks: ");
	scanf("%d",&s[i].marks);
}

void display(Stud s[], int n){
	int i;
	printf("----------------Record----------------\n");
	printf("Roll No.         \t Name \t Marks \n");
	printf("--------------------------------------\n");
	for(i=0;i<n;i++){
		printf("%d\t%21s\t %d\n",s[i].roll,s[i].name,s[i].marks);
	}
	printf("--------------------------------------\n");
}

void disp(Stud s[], int i){
	printf("-------------Found Record-------------\n");
	printf("Roll No. \t         Name \t Marks \n");
	printf("--------------------------------------\n");
	printf("%d\t%21s\t %d\n",s[i].roll,s[i].name,s[i].marks);
	printf("--------------------------------------\n");
}

int menu()
{
	int c;
	printf("\n1.Insert record\n2.Sort Record\n3.Search(recursive)\n4.Search(non-recursive)\n5.Display\n6.Exit");
	printf("\n\tYour Choice : ");
	scanf("%d",&c);
	return c;
}

int main() {
	Stud s[100];
	int f=1,n,i=0,x;
	while(f)
	{
		switch(menu())
		{
			case 1: inp(s, i++);
					break;

			case 2: printf("Sort by 1.Roll No.\t2.Marks");
					scanf("%d",&n);
					if(n==1){
						bubbleSort(s, i);
						display(s, i);
					}
					else if(n==2){
						selSort(s, i);
						display(s, i);
					}
					else
						printf("\n\tInvalid Choice!\n");
					break;

			case 3: printf("Enter the Roll No.");
					scanf("%d",&x);
					bubbleSort(s, i);
					int l = binarySearch(s, 0, i, x);
					if(l!=-1)
					{
						disp(s, l);
					}
					else
						printf("No such record!\n");
					break;

			case 4: printf("Enter the Roll No.");
					scanf("%d",&x);
					bubbleSort(s, i);
					int m = binarySearch_nonrec(s, i, x);
					if(m!=-1)
					{
						disp(s, m);
					}
					else
						printf("No such record!\n");
					break;

			case 5: display(s, i);
					break;

			default: f=0;

		}
	}
	return 0;
}


