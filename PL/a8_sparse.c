/*
------------------------------------------------------------
Roll No.          : 23254
Batch             : H10
Problem Statement : Implement Sparse Matrix and perform the
					following operations on it:
					1) Addition
					2) Simple Transpose
					3) Fast Transpose
------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define l 20

typedef struct {
	int row;
	int col;
	int val;
}spMat;

void getMat(spMat m[l])
{
	int i,j,t,temp,cnt=1;
	printf("Enter elements one by one.\n");
	for(i=0;i<m[0].row;i++)
		for(j=0;j<m[0].col;j++)
		{	scanf("%d",&temp);
			if(temp!=0)
			{
				m[cnt].row = i;
				m[cnt].col = j;
				m[cnt].val = temp;
				cnt++;
			}
		}
	m[0].val = cnt-1;
}

void showMat(spMat m[l])
{
	int t;
	printf("\n\tRow\tCol\tValue\n");
	for(t=0;t<=m[0].val;t++)
	{
		printf("\t%d\t%d\t%d\n",m[t].row,m[t].col,m[t].val);
	}
}

void addMat(spMat m1[l],spMat m2[l],spMat m[l])
{
	int i=1, j=1, k=1;
	while(i<=m1[0].val && j<=m2[0].val)
	{
		if(m1[i].row == m2[j].row && m1[i].col == m2[j].col)
		{
			m[k].row = m1[i].row;
			m[k].col = m1[i].col;
			m[k].val = m1[i].val + m2[j].val;
			i++;
			j++;
			k++;
		}
		else if(m1[i].row == m2[j].row && m1[i].col < m2[j].col)
		{
			m[k] = m1[i];
			i++;
			k++;
		}
		else if(m1[i].row == m2[j].row && m1[i].col > m2[j].col)
		{
			m[k] = m2[j];
			j++;
			k++;
		}
		else if(m1[i].row < m2[j].row)
		{
			m[k] = m1[i];
			i++;
			k++;
		}
		else
		{
			m[k] = m2[j];
			j++;
			k++;
		}
	}
	while(i<=m1[0].val)
	{
		m[k] = m1[i];
		i++;
		k++;
	}
	while(j<=m2[0].val)
	{
		m[k] = m2[j];
		j++;
		k++;
	}
	m[0].row = m1[0].row;
	m[0].col = m1[0].col;
	m[0].val = k-1;
}

void trans(spMat a[l], spMat b[l])
{
	int i,j,cb;
	b[0].row = a[0].col;
	b[0].col = a[0].row;
	b[0].val = a[0].val;
	if(a[0].val > 0)
	{
		cb = 1;
		for(i=0; i<a[0].col; i++)
			for(j=1; j<=a[0].val; j++)
				if(a[j].col == i)
				{
					b[cb].row = a[j].col;
					b[cb].col = a[j].row;
					b[cb].val = a[j].val;
					cb++;
				}
	}
}

void fasttrans(spMat a[l], spMat b[l])
{
	int row_terms[l], start_pos[l];
	int i, j, num_cols = a[0].col, num_terms = a[0].val;
	b[0].row = num_cols;
	b[0].col = a[0].row;
	b[0].val = num_terms;

	if(num_terms > 0)
	{
		for(i=0; i<num_cols; i++)
			row_terms[i] = 0;
		for(i=1; i<=num_terms; i++)
			row_terms[a[i].col]++;
        start_pos[0] = 1;
        for(i=1; i<num_cols; i++)
            start_pos[i] = start_pos[i-1] + row_terms[i-1];
		for(i=1; i<=num_terms; i++)
		{
			j = start_pos[a[i].col]++;
			b[j].row = a[i].col;
			b[j].col = a[i].row;
			b[j].val = a[i].val;
		}
	}
}

void MatDisplay(spMat m[l])
{
    int i, j, t=1, a;

    printf("\t");
    for(i=0; i<m[0].row; i++)
    {
        for(j=0; j<m[0].col; j++)
        {
            if(i==m[t].row && j==m[t].col)
            {
                a=m[t].val;
                t++;
            }
            else
                a=0;
            printf(" %d  ", a);
        }
        printf("\n\t");
    }
}

int main()
{
	int ch,t=0;
	spMat m1[l],m2[l],m3[l];

	do
	{
		printf("\n Menu :\n1. Input Matrix.\n2. Display Matrix.\n3. Add Matrices.\n4. Simple Transpose.\n5. Fast Transpose.\n6. Exit.\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	printf("\nSparse Matrix 1:\n");
					printf("Enter no. of rows : ");
					scanf("%d", &m1[0].row);
					printf("Enter no. of columns : ");
					scanf("%d", &m1[0].col);
					getMat(m1);
					t=1;
					break;

			case 2:	if(t)
					{	printf("\nSHOW MATRIX:\nEntered Sparse Matrix is :-\n");
						showMat(m1);
						printf("\nIn Matrix Form :\n");
						MatDisplay(m1);
					}
					else
						printf("\nEnter Matrix First..!!\n");
					break;

			case 3:	if(!t)
					{
						printf("\nSparse Matrix 1:\n");
						printf("Enter no. of rows : ");
						scanf("%d", &m1[0].row);
						printf("Enter no. of columns : ");
						scanf("%d", &m1[0].col);
						getMat(m1);
						t=1;
					}
					printf("\nEnter another Matrix to ADD :");
					printf("\nSparse Matrix 2:\n");
					printf("Enter no. of rows : ");
					scanf("%d", &m2[0].row);
					printf("Enter no. of columns : ");
					scanf("%d", &m2[0].col);
					getMat(&m2);

					printf("\nADDITION:\n");
					if(m1[0].row==m2[0].row && m1[0].col==m2[0].col)
					{	addMat(m1,m2,m3);
						printf("\nSparse Matrix 1:");
						showMat(m1);
						printf("\nSparse Matrix 2:");
						showMat(m2);
						printf("\nSum :");
						showMat(m3);

						printf("\nSparse Matrix 1:\n");
						MatDisplay(m1);
						printf("\nSparse Matrix 2:\n");
						MatDisplay(m2);
						printf("\nSum :\n");
						MatDisplay(m3);
					}
					else
						printf("\nCannot Add Matrices\n");
					break;

			case 4:	if(t)
					{	printf("\nSIMPLE TRANSPOSE:\n");
						trans(m1,m3);
						printf("\nSparse Matrix 1:");
						showMat(m1);
						printf("\nTranspose of Sparse Matrix 1 :");
						showMat(m3);
					}
					else
						printf("\nEnter Matrix First..!!\n");
					break;

			case 5:	if(t)
					{	printf("\nFAST TRANSPOSE:\n");
						fasttrans(m1,m3);
						printf("\nSparse Matrix 1:");
						showMat(m1);
						printf("\nTranspose of Sparse Matrix 1 :");
						showMat(m3);
					}
					else
						printf("\nEnter Matrix First..!!\n");
					break;

			default: return 0;
		}
	}while(ch!=6);

    return 0;
}

