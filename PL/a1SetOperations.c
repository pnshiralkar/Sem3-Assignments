/*
 ===============================================================================
 Name        : Assignment1 - Set Operations
 Author      : Prathamesh Shiralkar
 Description : Input sets A & B and output operations like Union, Intersection,
 	 	 	   Difference and Symmetric Difference.
 ===============================================================================
 */

#include <stdio.h>

void disp(int *a,int n)
{
	printf("{ ");
	int i;
	for(i=0;i<n;i++)
		printf("%d ", a[i]);
	printf("}");
}

int menu()
{
	int res;
	printf("\n\n1: Enter Sets\n2: Union\n3: Intersection\n4: Difference(A - B)\n5: Difference(B - A)\n6: Symmetric Difference\n7: Exit\n\nEnter a choice : ");
	scanf("%d", &res);
	return res;
}


void  funion(int *a, int n1, int *b, int n2, int *r, int *n)
{
	int i=0,j,k;
	//copy first set
	for(;i<n1;i++){
		r[i]=a[i];
	}
	//copy elements of set B which are not in set A
	for(j=0;j<n2;j++)
	{
		for(k=0;k<n1;k++)
			if(b[j]==a[k])
				break;
		if(k==n1)
		{
			r[i]=b[j];
			i++;
		}
	}
	*n=i;
}

void  inter(int *a, int n1, int *b, int n2, int *r, int *n)
{
	int i=0,j,k;
	//copy elements of sets which are present in both A and B
	for(j=0;j<n2;j++)
	{
		for(k=0;k<n1;k++)
			if(a[k]==b[j])
				break;
		if(k!=n1)
		{
			r[i]=b[j];
			i++;
		}
	}
	*n=i;
}

void  diff(int *a, int n1, int *b, int n2, int *r, int *n)
{
	int i=0,j,k;
	//copy elements of set A which are not present in set B
	for(j=0;j<n1;j++)
	{
		for(k=0;k<n2;k++)
			if(a[j]==b[k])
				break;
		if(k==n2)
		{
			r[i]=a[j];
			i++;
		}
	}
	*n=i;
}

int main(void)
{
	int n1=0,n2=0,i,f=1,a[10],b[10], b1[10], t1[20], t2[20], nt1, nt2, n, r[20];
	while(f)
	{
		switch(menu())
		{
		case 1:
			printf("Enter number of elements in set A : ");
			scanf("%d", &n1);
			printf("Enter set A : ");
			//add element only if it does not exist already
			for(i=0;i<n1;i++)
			{
				int t,it;
				scanf("%d", &t);
				for(it=0;it<i;it++)
					if(t==a[it])
						break;
				if(it==i){
					a[i]=t;
				}
				else{
					n1--;
					i--;
				}
			}
			printf("Enter number of elements in set B : ");
			scanf("%d", &n2);
			//add element only if it does not exist already
			printf("Enter set B : ");
			for(i=0;i<n2;i++)
			{
				int t,it;
				scanf("%d", &t);
				for(it=0;it<i;it++)
					if(t==b[it])
						break;
				if(it==i){
					b[i]=t;
				}
				else{
					n2--;
					i--;
				}
			}
			break;
		case 2:
			//union
			funion(a,n1,b,n2,r,&n);
			printf("\nA = "); disp(a, n1);
			printf("\nB = "); disp(b, n2);
			printf("\nA U B = "); disp(r, n);
			break;
		case 3:
			//intersection
			inter(a,n1,b,n2,r,&n);
			printf("\nA = "); disp(a, n1);
			printf("\nB = "); disp(b, n2);
			printf("\nA ^ B = "); disp(r, n);
			break;
		case 4:
			//A-B
			diff(a,n1,b,n2,r,&n);
			printf("\nA = "); disp(a, n1);
			printf("\nB = "); disp(b, n2);
			printf("\nA - B = "); disp(r, n);
			break;
		case 5:
			//B-A
			diff(b,n2,a,n1,r,&n);
			printf("\nA = "); disp(a, n1);
			printf("\nB = "); disp(b, n2);
			printf("\nB - A = "); disp(r, n);
			break;
		case 6:
			//(A - B) U (B - A)
			diff(a,n1,b,n2,t1,&nt1);
			diff(b,n2,a,n1,t2,&nt2);
			funion(t1,nt1,t2,nt2,r,&n);
			printf("\nA = "); disp(a, n1);
			printf("\nB = "); disp(b, n2);
			printf("\nSymmetric Difference = "); disp(r, n);
			break;
		default:
			//exit
			f=0;
		}
	}
	return 0;
}
