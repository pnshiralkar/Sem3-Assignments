/*
 ============================================================================
 Name        : a9LL.c
 Author      : 23254
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct Nodep;

typedef struct Nodep{
	int val;
	struct Nodep *nxt;
} Node;

typedef struct{
	Node *start,*end;
} LinkedList;

void init(LinkedList *ll)
{
	ll->start = NULL;
	ll->end = NULL;
}

void insert(LinkedList *ll,int n, int p)
{
	int i=0;
	Node *ni=ll->start,*new=(Node*)malloc(sizeof(Node));

	new->val = n;

	if(ni==NULL && p>0){
			printf("Invalid position!");
			return;
		}
	if(p==0)
	{
		if(ni==NULL)
		{
			new->nxt = NULL;
			ll->start=new;
			ll->end = new;
		}
		else
		{
			new->nxt = ni;
			ll->start=new;
		}
	}
	else
	{
		for(;i<p-1;i++){
			if(ni==NULL)
				printf("Invalid position!");
			ni = ni->nxt;
		}
		new->nxt = ni->nxt;
		if(new->nxt==NULL)
			ll->end=new;
//		if(new->nxt==NULL)
//			printf("%d is last", n);
		ni->nxt = new;
	}
}

void delLL(LinkedList *ll, int p)
{
	Node *c;
	int i;
	if(p==0)
	{
		c=ll->start;
		ll->start = c->nxt;
		free(c);
	}
	else
	{
		for(i=0,c=ll->start;i<p-1;i++,c=c->nxt)
			if(c->nxt==NULL)
				printf("Invalid value!");
		free(c->nxt);
		c->nxt = c->nxt->nxt;
	}
}

void dispLL(LinkedList ll)
{
	Node *c=ll.start;
	while(c!=NULL)
	{
		printf("%d ", c->val);
		c=c->nxt;
	}
	printf("\n");
}

int main(void) {
	LinkedList ll;
	init(&ll);
	insert(&ll,22,0);
	insert(&ll,6,1);
	dispLL(ll);
	delLL(&ll, 1);
	dispLL(ll);

	return EXIT_SUCCESS;
}

