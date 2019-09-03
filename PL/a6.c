/*
 ============================================================================
 Name        : Assignment6.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stud{
	int roll_no;
	int marks;
	char name[20];
}s[100];


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

void BubbleSort(int n){
	int i , j;
	for(i=0;i<n-1; i++){
		for(j = 0; j < n-i-1; j++){
			if(s[j].roll_no > s[j+1].roll_no){

				swap(&s[j].roll_no , &s[j+1].roll_no);
				swapchar(s[j].name , s[j].name);
				swap(&s[j].marks, &s[j].marks);
			}
		}
	}
}


void SelectionSort(int n){
    int i, j, min;

    for (i = 0; i < n-1; i++){
        min = i;
        for (j = i+1; j < n; j++)
          if (s[j].marks > s[min].marks)
            min = j;

          swap(&s[min].roll_no, &s[i].roll_no);
          swapchar(s[min].name, s[i].name);
          swap(&s[min].marks, &s[i].marks);
    }
}

int BinarySearch(int l, int h, int x){
	int  mid;
	if(h>=l)
	{
		mid = (h+l)/2;
		if(mid == x)
			return mid;
		if(mid > x)
			return BinarySearch(l, mid-1, x);
		if(mid<x)
			return BinarySearch(mid+1, h, x);
	}
	else
		return -1;
	return -1;
}



void add(int i){
	printf("Enter the Details: \n");
	printf("\tName: ");
	scanf("%s[^\n]",s[i].name);
	printf("\tRoll No.: ");
	scanf("%d",&s[i].roll_no);
	printf("\tMarks: ");
	scanf("%d",&s[i].marks);
}

void display(int n){
	int i;
	printf("-----RECORD-----\n");
	printf("ROLL_NO \t NAME \t MARKS \n");
	printf("------------------------------\n");
	for(i=0;i<n;i++){
		printf("%d\t%s\t%d\n",s[i].roll_no,s[i].name,s[i].marks);
	}
	printf("------------------------------\n");
}

void disp(int i){
	printf("-----SEARCHED RECORD-----\n");
	printf("ROLL_NO \t NAME \t MARKS \n");
	printf("------------------------------\n");
	printf("%d\t%s\t%d\n",s[i].roll_no,s[i].name,s[i].marks);
	printf("------------------------------\n");
}



int main() {
	int c,f=1,n,i=0,x,rl;
	while(f==1)
	{
		printf("\n1.ADD\n2.SORT\n3.SEARCH\n4.DISPLAY");
		printf("\n\tEnter Choice: ");
		scanf("%d",&c);
		switch(c)
		{
			case 1: add(i++);
					break;

			case 2: printf("SORT for 1.ROLL_NO\t2.MARKS");
					scanf("%d",&n);
					if(n==1){
						BubbleSort(i);
						display(i);
					}
					else if(n==2){
						SelectionSort(i);
						display(i);
					}
					else
						printf("\n\tEnter Correct Choice\n");
					break;

			case 3: printf("Enter the ROLL_NO");
					scanf("%d",&rl);
					int l = BinarySearch(0, i, x);
					if(l!=-1)
					{
						disp(l);
					}
					else
						printf("NO RESULTS FOUND!!\n");
					break;

			case 4: display(i);
					break;

			case 5: f=0;

		}
	}
	return 0;
}

