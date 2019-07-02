/*
 ========================================================================
 Name        : Assignment2 - Matrix Operations
 Author      : Prathamesh Shiralkar
 Description : Perform following operations on Matrix using 2D arrays -
 	 	 	   1) Addition				2) Multiplication
 	 	 	   3) Transpose				4) Saddle point
 ========================================================================
 */

#include <stdio.h>

int menu()
{
	int res;
	printf("\n\n1: Enter Matrices\n2: Print Matrices\n3: Addition\n4: Multiplication\n5: Transpose\n6: Saddle Point\n7: Exit\n\nEnter a choice : ");
	scanf("%d", &res);
	return res;
}

void getmat(int a[5][5], int r, int c)
{
	int i,j;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			scanf("%d", &a[i][j]);
}

void printmat(int a[5][5], int r, int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		printf(" ");
		for(j=0;j<c;j++)
			printf("%3d ", a[i][j]);
		printf("\n");
	}
}

void add(int a[5][5], int b[5][5], int r, int c, int res[5][5])
{
	int i,j;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			res[i][j] = a[i][j] + b[i][j];
}

void mul(int a[5][5], int ra, int ca, int b[5][5], int rb, int cb, int res[5][5])
{
	int i,j,k;
	for(i=0;i<ra;i++)
		for(j=0;j<cb;j++)
		{
			int s=0;
			for(k=0;k<rb;k++)
				s+=a[i][k]*b[k][j];
			res[i][j] = s;
		}
}

void trans(int a[5][5], int r, int c)
{
	int i,j;
	for(i=0;i<c;i++)
	{
		printf(" ");
		for(j=0;j<r;j++)
			printf("%3d ", a[j][i]);
		printf("\n");
	}
}

void saddle(int a[5][5], int r, int c)
{
	int i,j,k,count=0;
	for(i=0;i<r;i++)
	{
		int min=a[i][0],minc;
		for(j=0;j<c;j++)
		{
			if(min>a[i][j])
			{
				min=a[i][j];
				minc=j;
			}
		}
		int max=a[0][minc],maxr;
		for(j=0;j<r;j++)
		{
			if(max<a[j][minc])
			{
				max=a[j][minc];
				maxr=j;
			}
		}
		if(maxr==i){
			printf("(%d, %d) ", i+1,minc+1);
			count++;
		}
	}
	if(!count)
		printf("No saddle points for this matrix!");
}

int main(void) {
	printf("Assignment2 - Matrix Operations\n\n");
	int a[5][5], b[5][5],ra=0,ca=0,rb=0,cb=0,f=1,res[5][5],rr=0,rc=0;
	while(f)
	{
		switch(menu())
		{
			case 1:
				printf("Enter No. of rows and columns of matrix A : ");
				scanf("%d %d", &ra, &ca);
				printf("Enter elements of matrix A - ");
				getmat(a, ra, ca);
				printmat(a, ra, ca);
				printf("Enter No. of rows and columns of matrix B : ");
				scanf("%d %d", &rb, &cb);
				printf("Enter elements of matrix B - ");
				getmat(b, rb, cb);
				printmat(b, rb, cb);
				break;

			case 2:
				printf("Matrix A - \n");
				printmat(a, ra, ca);
				printf("Matrix B - \n");
				printmat(b, rb, cb);
				break;

			case 3:
				if(ra==rb && ca==cb)
				{
					add(a,b,ra,ca,res);
					printf("A + B = \n");
					printmat(res, ra, ca);
				}else{
					printf("Size of both matrices should be same to perform addition!\n");
				}
				break;

			case 4:
				if(ca==rb)
				{
					mul(a,ra,ca,b,rb,cb,res);
					printf("A * B = \n");
					printmat(res, ra, cb);
				}else{
					printf("Invalid size to perform multiplication!\n");
				}
				break;

			case 5:
				printf("Transpose of A = \n");
				trans(a, ra, ca);
				printf("Transpose of B = \n");
				trans(b, rb, cb);
				break;
			case 6:
				printf("Saddle points of A = \n");
				saddle(a, ra, ca);
				printf("\nSaddle points of B = \n");
				saddle(b, rb, cb);
				break;
			default:
				f=0;
		}
	}
	return 0;
}
