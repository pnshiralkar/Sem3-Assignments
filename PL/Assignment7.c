/*
============================================================================
 Name        : a7_quickSort.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Assignment 7 - Quick Sort
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50

typedef struct Data
{
	long unsigned int mob;
	char name[25];
	float sal;
}Data;


void inp(Data s[],int *f)
{
	if(*f<SIZE)
	{
		printf("Enter the mob:- ");
		scanf("%lu",&s[*f].mob);
		printf("Enter the name:- ");
		while(getchar()!='\n'); 	
		gets(s[*f].name);
		printf("Enter the sal:- ");
		scanf("%f",&s[*f].sal);
		*f=*f+1;
		printf("\nRecord added successfully!\n\n");
	}
	else
	{
		printf("\nCannot add more records!\n");
	}
}

void disp(Data s[],int f)
{
	int i;
	if(f==0)
		printf("\nPlease enter valid data\n");
	else
	{
		printf("\n-------------------------------------------------------\n");
		printf("Sr.no\tMob.No.  Name\t  Salary");
		printf("\n-------------------------------------------------------\n");
		for(i=0;i<f;i++)
			printf("%3d %7lu %10s %9.2f\n",i+1,s[i].mob,s[i].name,s[i].sal);
		printf("-------------------------------------------------------\n\n");
	}
}

void quickSort(Data s[],int l,int h)
{
	static int f;
	Data pivot_el,temp;
	int low=l+1,high=h;
	int i;
	pivot_el=s[l]; 	
	
	while(low<=high)
	{
		while(strcmp(s[low].name,pivot_el.name)>0)
			low++;
		while(strcmp(s[high].name,pivot_el.name)<0)
			high--;
			
		if(low<high)
		{
			temp=s[low];
			s[low]=s[high];
			s[high]=temp;
			low++;
			high--;
		}
	}
	s[l]=s[high];
	s[high]=pivot_el;
	
	high--;
	f++;
	printf("Pass :- %d\n",f);	
	for(i=0;i<f;i++)
	{
		printf("%s  ",s[i].name);
	}
	printf("\n");
	
	if(l<high)
		quickSort(s,l,high);
		
	if(low<h)
		quickSort(s,low,h);
}

int main(void)
{
	Data s[SIZE];
	int choice,f=0,i;
	int rno;

	while(1)
	{
		printf("DBMS");
		printf("\n1. Accept records");
		printf("\n2. Display records");
		printf("\n3. Sort records in descending order of names(quick with recursion)");
		printf("\n4. Exit");
		printf("\n\nEnter your choice:- ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				inp(s,&f);
				break;
			case 2:
				disp(s,f);
				break;
			case 3:
				printf("\n-------------------------------------------------------");
				printf("\nQUICK SORT FOR DESCENDING ORDER OF NAMES\n\n");
				quickSort(s,0,f);
				disp(s,f);
				break;
			case 4:
				return EXIT_SUCCESS;
			default:
				printf("Error in choice, try again\n\n");
		}
	}
	return EXIT_SUCCESS;
}


	
	
			

