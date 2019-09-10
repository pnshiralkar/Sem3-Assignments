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

int menu()
{
	int res;
	printf("\n\n1: Enter matrix\n2: Display\n3: Addition\n4: Simple transpose\n5: Fast transpose\n6: Exit\n\nEnter a choice : ");
	scanf("%d", &res);
	return res;
}

typedef struct{
	int i,j,val;
}SparseMat;

int inp(SparseMat s[])
{
	int i,j,r,c,tmp,count=0;
	printf("Enter No. of rows and columns for matrix : ");
	scanf("%d %d", &r, &c);
	printf("Enter the elements of matrix : ");
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
		{
			scanf("%d", &tmp);
			if(tmp != 0)
			{
				s[count].i = i;
				s[count].j = j;
				s[count++].val = tmp;
			}
		}
	return count;
}

void swapint(int *a , int *b){
	int tmp;
	tmp = *b;
	*b = *a;
	*a = tmp;
}

void swap(SparseMat *a , SparseMat *b){
	SparseMat tmp;
	tmp = *b;
	*b = *a;
	*a = tmp;
}


void BubbleSort(SparseMat a[] , int n)
{
	int i , j;
	for(i=0;i<n-1; i++)
	{
		for(j = 0; j < n-i-1; j++)
		{
			if(a[j].i > a[j+1].i)
				swap(&a[j] , &a[j+1]);
		}
	}
}

void out(SparseMat m[], int n)
{
	int i;
	printf("Row Col Value\n");
	for(i=0;i<n;i++)
		printf("%3d %3d %5d\n", m[i].i, m[i].j, m[i].val);
}

void add(SparseMat m1[], int n1, SparseMat m2[], int n2, SparseMat res[], int *nres)
{
	int i=0,j=0,c=0,f=0;
	while(i<n1 || j<n2)
	{
		f=0;
		if(m1[i].i == m2[j].i)
		{
			if(m1[i].j == m2[j].j)
			{
				res[c].i = m1[i].i;
				res[c].j = m1[i].j;
				res[c++].val = m1[i++].val+m2[j++].val;
				f=1;
			}
			else if(m1[i].j < m2[j].j)
			{
				res[c].i = m1[i].i;
				res[c].j = m1[i].j;
				res[c++].val = m1[i++].val;
			}
			else
			{
				res[c].i = m2[j].i;
				res[c].j = m2[j].j;
				res[c++].val = m2[j++].val;
			}
		}
		else
		{
			res[c].i = m1[i].i;
			res[c].j = m1[i].j;
			res[c++].val = m1[i++].val;
		}
	}
	*nres = c;
}

int main(void) {
	int f=1,n1=0,n2=0,nres,i;
	SparseMat m1[100],m2[100],mres[100];

	while(f)
	{
		switch(menu())
		{
		case 1:
			n1 = inp(m1);
			break;
		case 2:
			out(m1, n1);
			break;
		case 3:
			/////Incomplete//////////////
			printf("Enter matrix to add : \n");
			n2 = inp(m2);
			add(m1,n1,m2,n2,mres,&nres);
			out(mres, nres);
			break;
		case 4:
			for(i=0;i<n1;i++)
				swapint(&m1[i].i, &m1[i].j);
			out(m1, n1);
		}
	}
	return EXIT_SUCCESS;
}
