/*
 ============================================================================
 Name        : a8_sparse.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Assignment 8 - Sparse Matrix
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define R 50
#define C 50

typedef struct s
{
	int row,column,value;
}Sparse;

int menu()
{
	int choice;
	printf("Sparse Matrix Operations\n1. Accept matrix and convert into sparse matrix\n2. Addition of sparse matrix\n3. Simple transpose of sparse matrix\n4. Fast transpose of sparse matrix\n5. Convert sparse matrix into simple matrix\n6. Exit\n\nEnter your choice:- ");
	scanf("%d",&choice);
	return choice;
}


void accept(int mat[R][C],int *r,int *c,int *count, Sparse s[R])
{
	int i,j;
	*count =1;
	printf("Enter number of rows in the matrix:- ");
	scanf("%d",r);
	printf("Enter number of columns in the matrix:- ");
	scanf("%d",c);
	for(i=0;i<*r;i++)
	{
		for(j=0;j<*c;j++)
		{
			printf("Enter element [%d][%d]:- ",i,j);
			scanf("%d",&mat[i][j]);
			if(mat[i][j]!=0)
				(*count)++;
		}
	}
	convert(mat,*r,*c,*count,s);
}

void convert(int mat[R][C],int r,int c,int count, Sparse s[R])
{
	int i,j,k;
	s[0].row=r;
	s[0].column=c;
	s[0].value=count-1;
	k=1;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(mat[i][j]!=0)
			{
				s[k].row=i;
				s[k].column=j;
				s[k].value=mat[i][j];
				k++;
			}
		}
	}
}

void display(Sparse s[R],int count)
{
	int i,j;
	printf("--------------------------------------------\n");
	printf("Index\tRow\tColumn\tValue\n");
	printf("--------------------------------------------\n");
	for(i=0;i<count;i++)
		printf("%d\t%d\t%d\t%d\n",i,s[i].row,s[i].column,s[i].value);
	printf("--------------------------------------------\n");
}

void add(Sparse s1[R],Sparse s2[R],Sparse s3[R],int count)
{
	int i=1,j=1,k=1;
	while(i<=s1[0].value && j<=s2[0].value)
	{
		if(s1[i].row==s2[j].row && s1[i].column == s2[j].column)
		{
			s3[k].row=s1[i].row;
			s3[k].column=s1[i].column;
			s3[k].value=s1[i].value + s2[j].value;
			i++,j++,k++;
		}
		if(s1[i].row==s2[j].row && s1[i].column < s2[j].column)
		{
			s3[k].row=s1[i].row;
			s3[k].column=s1[i].column;
			s3[k].value=s1[i].value;
			i++,k++;
		}
		if(s1[i].row==s2[j].row && s1[i].column > s2[j].column)
		{
			s3[k]=s2[j];
			j++,k++;
		}
		if(s1[i].row < s2[j].row)
		{
			s3[k]=s1[i];
			i++,k++;
		}
		if(s1[i].row > s2[j].row)
		{
			s3[k]=s2[j];
			j++,k++;
		}
		while(i<=s1[0].value)
		{
			s3[k]=s1[i];
			i++,k++;
		}
		while(j<=s2[0].value)
		{
			s3[k]=s2[j];
			j++,k++;
		}
		s3[0].row=s1[0].row;
		s3[0].column=s1[0].column;
		s3[0].value=k;
	}
}


int main(void)
{
	int mat1[R][C],mat2[R][C];
	int r1,c1,r2,c2;
	int count;
	Sparse s1[R],s2[R],s3[R];

	while(1)
	{
		switch(menu())
		{
			case 1:
				printf("Enter matrix 1: \n");
				accept(mat1,&r1,&c1,&count,s1);
				display(s1,count);
				printf("Enter matrix 2: \n");
				accept(mat2,&r2,&c2,&count,s2);
				display(s2,count);
				break;
			case 2:
				printf("\nMatrix 1 is: \n");
				display(s1,count);
				printf("\nMatrix 2 is: \n");
				display(s2,count);
				add(s1,s2,s3,count);
				printf("\nAddition of matrices is: ");
				display(s3,count);
				break;
			default:
				return EXIT_SUCCESS;
		}
	}
	return EXIT_SUCCESS;
}

