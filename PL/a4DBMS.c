/*
 ============================================================================
 Name        : a4DBMS.c
 Author      : Prathamesh Shiralkar
 Description : Assignment3 - Database Management
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int id,age;
	char name[50],mbno[11],email[50];
}Emp;

int menu()
{
	int res;
	printf("\n\n1: Add new employee\n2: Display\n3: Search by ID\n4: Search by name\n5: Delete\n6: Modify\n7: Exit\n\nEnter a choice : ");
	scanf("%d", &res);
	return res;
}

int search(Emp *emp, int n, int id)
{
	int i;
	for(i=0;i<n;i++)
		if(emp[i].id==id && id!=0)
			break;
	if(i==n)
		return -1;
	return i;
}

void disp(Emp emp, int i)
{
	printf("\n%-6d %4d      %-15s    %3d   %-10s    %s",i, emp.id, emp.name, emp.age, emp.mbno, emp.email);
}

void searchname(Emp *emp, int n, char name[50])
{
	printf("\n--------------------------------------------------------------------------\nSr.No. Emp ID    Name               Age   Mobile No.    Email\n--------------------------------------------------------------------------\n");
	int i,c=1;
	for(i=0;i<n;i++)
		if(!strcmp(name, emp[i].name) && emp[i].id!=0)
			disp(emp[i], c++);
	printf("\n--------------------------------------------------------------------------\n");
}

int main(void) {
	Emp emp[50];
	int c=0,f=1,id,n,i,j=1;
	char name[50];
	while(f)
	{
		switch(menu())
		{
		case 1:
			printf("Enter details of new employee :\n\tID : ");
			scanf("%d", &emp[c].id);
			if(!(search(emp, c, emp[c].id)))
			{
				printf("\tName :"); scanf("%s", emp[c].name);
				printf("\tAge : "); scanf("%d", &emp[c].age);
				printf("\tMobile No. : "); scanf("%s", emp[c].mbno);
				printf("\tEmail : "); scanf("%s", emp[c].email);
				c++;
			}
			break;
		case 2:
			printf("\n---------------------------------------------------------------------------\nSr.No. Emp ID    Name               Age   Mobile No.    Email\n---------------------------------------------------------------------------\n");
			for(i=0;i<c;i++)
				if(emp[i].id!=0)
					disp(emp[i], j++);
			printf("\n---------------------------------------------------------------------------\n");
			break;
		case 3:
			printf("Enter ID to search : ");
			scanf("%d", &id);
			n=search(emp, c, id);
			if(n>=0){
				printf("\n---------------------------------------------------------------------------\nSr.No. Emp ID    Name               Age   Mobile No.    Email\n---------------------------------------------------------------------------\n");
				disp(emp[n], 1);
				printf("\n---------------------------------------------------------------------------\n");
			}
			else
				printf("No results found!");
			break;
		case 4:
			printf("Enter Name to search : ");
			scanf("%s", name);
			searchname(emp, c, name);
			break;
		case 5:
			printf("Enter ID to delete : ");
			scanf("%d", &id);
			n=search(emp, c, id);
			if(n>=0)
				emp[n].id=0;
			else
				printf("Given ID not found!");
			break;
		case 6:
			printf("Enter ID to update : ");
			scanf("%d", &id);
			n=search(emp, c, id);
			if(n>=0){
				printf("Enter new details :");
				printf("\n\tAge : "); scanf("%d", &emp[n].age);
				printf("\n\tMobile No. : "); scanf("%s", emp[n].mbno);
				printf("\n\tEmail : "); scanf("%s", emp[n].email);
			}else
				printf("Given ID not found!");
			break;
		default:
			f=0;
		}
	}
	return EXIT_SUCCESS;
}
