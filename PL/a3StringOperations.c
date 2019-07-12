/*
 ============================================================================
 Name        : a3StringOperations.c
 Author      : Prathamesh Shiralkar
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int menu()
{
	int res;
	printf("\n\n1: Enter string\n2: Length\n3: Palindrome\n4: Compare\n5: Copy\n6: Reverse\n7: Substring\n8: Exit\n\nEnter a choice : ");
	scanf("%d", &res);
	return res;
}

int len(char *s)
{
	int i;
	for(i=0;s[i]!=(char)0;i++);
	return i;
}

int pal(char *s, int l)
{
	int i;
	for(i=0;i<=l/2;i++)
		if(s[i]!=s[l-i-1])
			break;
	if(i>(l/2))
		return 1;
	return 0;
}

int cmp(char *s, int l, char *s1)
{
	int l1 = len(s1);
	int i;
	if(l==l1)
	{
		for(i=0;i<l;i++)
			if(s[i]!=s1[i])
				break;
		if(i==l)
			return 1;
	}
	return 0;
}

void cp(char *s,int l,char *s1)
{
	char t[50];
	int l1 = len(s1),i;
	for(i=0;i<l;i++)
		t[i]=s[i];
	for(;i<l1+l;i++)
		t[i]=s1[i-l];
	t[i]=(char)0;
	printf("Resultant string is : %s", t);
}

void rev(char *s,int l,char *s1)
{
	int i;
	for(i=0;i<l;i++)
		s1[l-i-1]=s[i];
	s1[l]=(char)0;
}

int sub(char *s,int l,char *s1)
{
	int i,l1 = len(s1),c=0;
	for(i=0;i<l-l1+1;i++)
		if(cmp((s+i),l1,s1))
			c++;
	return c;
}

int main(void) {
	char s[50],s1[50];
	int f=1,l=-1;
	while(f)
	{
		switch(menu())
		{
		case 1:
			printf("Enter string : ");
			scanf("%s", s);
			l=len(s);
			break;
		case 2:
			printf("%d", l);
			break;
		case 3:
			if(pal(s,l))
				printf("\nGiven string is a palindrome.\n");
			else
				printf("\nGiven string is not a palindrome.\n");
			break;
		case 4:
			printf("Enter string to compare : ");
			scanf("%s", s1);
			if(cmp(s,l,s1))
				printf("\nGiven strings are same.\n");
			else
				printf("\nGiven strings are not same.\n");
			break;
		case 5:
			printf("Enter string to copy : ");
			scanf("%s", s1);
			cp(s,l,s1);
			break;
		case 6:
			rev(s,l,s1);
			printf("\n%s", s1);
			break;
		case 7:
			printf("Enter substring to check : ");
			scanf("%s", s1);
			int t=sub(s,l,s1);
			if(t)
				printf("Substring exists in the given string %d times.", t);
			else
				printf("Substring does not exist in the given string.");
			break;
		default:
			f=0;
		}
	}
	return EXIT_SUCCESS;
}
