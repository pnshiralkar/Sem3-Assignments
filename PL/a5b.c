/*
 ============================================================================
 Name        : a5b.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int menu()
{
	int res;
	printf("\n\n1: Add new employee\n2: Display\n3: Search by ID\n4: Delete\n5: Modify\n6: Exit\n\nEnter a choice : ");
	scanf("%d", &res);
	return res;
}

typedef struct{
	int id,age;
	char name[50],email[50];
	long mbno;
}Emp;

int search(int c, int p)
{
	Emp emp;
	FILE *fp = fopen("db.sql", "r");
	fscanf(fp, "%d %s %d %ld %s", &emp.id, emp.name, &emp.age, &emp.mbno, emp.email);
	int i=1;
	while(!feof(fp))
	{
		i++;
		if(emp.id==c){
			if(p){
			printf("\n---------------------------------------------------------------------------\nSr.No. Emp ID    Name               Age   Mobile No.    Email\n---------------------------------------------------------------------------\n");
			printf("\n%-6d %-6d    %-15s    %3d   %-10ld    %s",i, emp.id, emp.name, emp.age, emp.mbno, emp.email);
			printf("\n---------------------------------------------------------------------------\n");
			}
			fclose(fp);
			return i;
		}
		fscanf(fp, "%d %s %d %ld %s", &emp.id, emp.name, &emp.age, &emp.mbno, emp.email);
	}
	printf("No results found!");
	fclose(fp);
	return -1;
}

int main(void) {
	FILE *fp;
	Emp emp;

	int f=1,c,d;
	while(f)
	{
		switch(menu())
		{
		case 1:
			fp = fopen("db.sql", "a");
			printf("Enter details of new employee :\n\tID : ");
			scanf("%d", &emp.id);
			printf("\tName :"); scanf("%s", emp.name);
			printf("\tAge : "); scanf("%d", &emp.age);
			printf("\tMobile No. : "); scanf("%ld", &emp.mbno);
			printf("\tEmail : "); scanf("%s", emp.email);
			fprintf(fp, "%d %s %d %ld %s\n", emp.id, emp.name, emp.age, emp.mbno, emp.email);
			fclose(fp);
			break;
		case 2:
			fp = fopen("db.sql", "r");
			c=1;
			fscanf(fp, "%d %s %d %ld %s", &emp.id, emp.name, &emp.age, &emp.mbno, emp.email);
			printf("\n---------------------------------------------------------------------------\nSr.No. Emp ID    Name               Age   Mobile No.    Email\n---------------------------------------------------------------------------\n");
			while(!feof(fp))
			{
				printf("\n%-6d %-6d    %-15s    %3d   %-10ld    %s",c++, emp.id, emp.name, emp.age, emp.mbno, emp.email);
				fscanf(fp, "%d %s %d %ld %s", &emp.id, emp.name, &emp.age, &emp.mbno, emp.email);
			}
			printf("\n---------------------------------------------------------------------------\n");
			fclose(fp);
			break;
		case 3:
			printf("Enter ID to search : ");
			scanf("%d", &c);
			search(c, 1);
			break;
		case 4:
			printf("Enter ID to delete : ");
			scanf("%d", &c);
			d = search(c, 0);
			if(c!=-1)
			{
				fp = fopen("db.sql", "r");
				FILE *fw = fopen("db1.sql", "w");
				fscanf(fp, "%d %s %d %ld %s", &emp.id, emp.name, &emp.age, &emp.mbno, emp.email);
				while(!feof(fp))
				{
					if(emp.id != c)
						fprintf(fw, "%d %s %d %ld %s\n", emp.id, emp.name, emp.age, emp.mbno, emp.email);
					fscanf(fp, "%d %s %d %ld %s", &emp.id, emp.name, &emp.age, &emp.mbno, emp.email);
				}
				fclose(fp);
				fclose(fw);
				rename("db1.sql", "db.sql");
			}
			break;
		}

	}
//	int v1=5,v2=4;
//	fprintf(fp, "%d\n", v1);
//	fprintf(fp, "%d", v2);
//	fscanf(fp, "%d", &v1);
//	fscanf(fp, "%d", &v2);
//	printf("%d %d", v1, v2);

	return EXIT_SUCCESS;
}
