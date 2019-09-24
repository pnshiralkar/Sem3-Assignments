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

#define debug(n) printf("debug%d", n)

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
		for(i=0;i<p-1;i++){
			if(!ni){
				printf("Invalid position!\n");
				return;
			}
			ni = ni->nxt;
		}
		new->nxt = ni->nxt;
		if(!(new->nxt))
			ll->end=new;
		ni->nxt = new;
	}
}

void insertLast(LinkedList *ll,int n)
{
	Node *ni=ll->start,*new=(Node*)malloc(sizeof(Node));

	new->val = n;
	if(ni==NULL)
	{
		new->nxt = NULL;
		ll->start=new;
		ll->end = new;
	}
	else
	{
		for(;ni->nxt;ni = ni->nxt);
		new->nxt = ni->nxt;
		if(!(new->nxt))
			ll->end=new;
		ni->nxt = new;
	}
}

void delLL(LinkedList *ll, int v)
{
	Node *c,*p;
	int i;
	if(!(ll->start))
	{
		printf("LinkedList is empty!\n");
		return;
	}
	for(i=0,c=ll->start;;i++,c=c->nxt)
	{
		if(!(c->nxt)){
			printf("Value not found in the LinkedList!!\n");
			return;
		}
		if(c->val==v)
		{

			if(c==ll->start){
				ll->start = c->nxt;
				free(c);
			}
			else{
				free(p->nxt);
				p->nxt = p->nxt->nxt;
			}
			return;
		}
		p=c;
	}
}

void dispLL(LinkedList ll)
{
	printf("LinkedList is : ");
	Node *c=ll.start;
	while(c!=NULL)
	{
		printf("%d ", c->val);
		c=c->nxt;
	}
	printf("\n");
}

void revLL(LinkedList *ll)
{
	Node *a=ll->start,*b,*c;
	if(a){
		b=a->nxt;
		a->nxt=NULL;
	}
	while(b->nxt)
	{
		c=b->nxt;
		b->nxt=a;
		a=b;
		b=c;
	}
	b->nxt=a;
	ll->start = b;
}

int menu()
{
	int r;
	printf("\n\n***LinkedList in C***\n\n1. Create LinkedList\n2. Insert\n3. Insert at position\n4. Delete a node\n5. Display\n6. Display reverse\n7. Revert LinkedList\n8. Exit\n\tYour choice : ");
	scanf("%d", &r);
	return r;
}

int main(void) {
	LinkedList ll;
	int inited=0,v,p;
//	init(&ll);
//	insert(&ll,22,0);
//	insert(&ll,6,100);
//	insert(&ll,66,9);
//	insert(&ll,29,1);
//	dispLL(ll);
//	delLL(&ll, 1);
//	dispLL(ll);
//	revLL(&ll);
//	dispLL(ll);
//	revLL(&ll);
//	dispLL(ll);
	while(1)
	{
		switch(menu())
		{
		case 1:
			init(&ll);
			inited=1;
			printf("LinkedList created successfully!");
			break;
		case 2:
			if(!inited){printf("Create a LinkedList first!"); break;}
			printf("Enter value to insert : ");
			scanf("%d", &v);
			insertLast(&ll, v);
			break;
		case 3:
			if(!inited){printf("Create a LinkedList first!"); break;}
			printf("Enter value to insert : ");
			scanf("%d", &v);
			printf("Enter position at which you want to insert : ");
			scanf("%d", &p);
			insert(&ll, v, p);
			break;
		case 4:
			if(!inited){printf("Create a LinkedList first!"); break;}
			printf("Enter value to delete : ");
			scanf("%d", &v);
			delLL(&ll, v);
			break;
		case 5:
			if(!inited){printf("Create a LinkedList first!"); break;}
			dispLL(ll);
			break;
		case 6:
			if(!inited){printf("Create a LinkedList first!"); break;}
			revLL(&ll);
			dispLL(ll);
			revLL(&ll);
			break;
		case 7:
			if(!inited){printf("Create a LinkedList first!"); break;}
			revLL(&ll);
			printf("LinkedList reverted successfully!");
			break;
		default:
			return 0;
		}
	}


	return EXIT_SUCCESS;
}
