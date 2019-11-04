//Assignment 10
//Roll no 23234
//Date of performance:
//Date of submission:
/*
Problem Statement: Implement sequential file and perform following operations: 
i.Display 
ii.Add records 
iii.Search record 
iv.Delete record 
*/ 
#include <iostream> 
#include <fstream> 
#include <cstring> 
#include <iomanip> 
#include<cstdlib> 
#define max 50 
using namespace std; 
class Student 
{ 
    char name[max]; 
    int rollNo; 
    int year; 
    
    char address[50]; 
    friend class FileOperations; 
    public:	Student() 
    		{ 
   				strcpy(name,""); 
   				rollNo=year=0; 
   				strcpy(address,""); 
    		} 
    		Student(char name[max],int rollNo,int year,char address[max]) 
    		{ 
    			strcpy(this->address,address); 
    			strcpy(this->name,name); 
    			
    			this->rollNo=rollNo; 
    			this->year=year; 
    		} 
    		int getRollNo() 
    		{ 
    			return rollNo; 
    		} 
    		void displayStudentData() 
    		{ 
    			cout<<endl<<setw(7)<<rollNo<<setw(16)<<name<<setw(8)<<year<<setw(15)<<address; 
    		} 
}; 
class FileOperations 
{ 
	fstream file; 
	public:FileOperations(char *name) 
		   { 
			 //strcpy(this->name,name); 
			 this->file.open(name,ios::in|ios::out|ios::ate|ios::binary); 
		   } 
		   void insertRecord(int rollNo,char name[max],int year,char address[max]) 
		   { 
			   Student s=Student(name,rollNo,year,address); 
			   file.seekp(0,ios::end); 
			   file.write((char*)&s,sizeof(Student)); 
			   file.clear(); 
		   } 
		   void displayAllRecords() 
		   { 
			   Student s; 
			   file.seekg(0,ios::beg); 
			   while(file.read((char *)&s,sizeof(Student))) 
			   { 
				   s.displayStudentData(); 
			   } 
			   file.clear(); 
		   } 
		   void displayRecord(int rollNo) 
		   { 
			   Student s; 
			   file.seekg(0,ios::beg); 
			   void *p; 
			   while(file.read((char *)&s,sizeof(Student))) 
			   { 
				   if(s.rollNo==rollNo) 
				   { 
					   s.displayStudentData(); 
					   break; 
				   } 
			   } 
			   if(p==NULL) 
				   throw "Element not present"; 
			   file.clear(); 
		   } 
		   void deleteRecord(int rollNo) 
		   { 
			   ofstream newFile("new.txt",ios::binary); 
			   file.seekg(0,ios::beg); 
			   bool flag=false; 
			   Student s; 
			   while(file.read((char *)&s,sizeof(s))) 
			   { 
				   if(s.rollNo==rollNo) 
				   { 
					   flag=true; 
					   continue; 
				   } 
				   newFile.write((char *)&s,sizeof(s)); 
			   } 
			   if(!flag) 
			   { 
				   cout<<"Element Not Present"; 
			   } 
			   file.close(); 
			   newFile.close(); 
			   remove("student.txt"); 
			   rename("new.txt","student.txt"); 
			   file.open("student.txt",ios::in|ios::ate|ios::out|ios::binary); 
		   } 
		   ~FileOperations() 
		   { 
			   file.close(); 
			   cout<<"Closing file.."; 
		   } 
  
}; 
int  main() 
{ 
	ofstream newFile("student.txt",ios::app|ios::binary); 
	newFile.close(); 
	FileOperations file((char *)"student.txt"); 
    	int rollNo,year,choice=0; 
    	char name[max],address[max]; 
	cout<<"\t\t\t\t::STUDENT DATABASE::\n";
    while(choice!=5) 
    {  
	cout<<"\n\t\tMENU\n"; 
	cout<<"1) Add New Record\n"; 
	cout<<"2) Display All Records\n"; 
	cout<<"3) Display by RollNo\n"; 
	cout<<"4) Deleting a Record\n"; 
	cout<<"5) Exit\n"; 
	cout<<"Choose your choice : "; 
	cin>>choice; 
	switch(choice) 
	{ 
	    case 1 : //New Record 
	    		cout<<endl<<"Enter RollNo:"; 
	    		cin>>rollNo; 
	    		cin.ignore(); 
	    		cout<<endl<<"Enter Name:"; 
	    		cin.getline(name, max); 
	    		cout<<"Enter Year :"; 
	    		cin>>year; 
	    		
	    		cin.ignore(); 
	    		cout<<"Enter address :"; 
	    		cin.getline(address, max); 
	    		file.insertRecord(rollNo,name,year,address); 
	    		break; 
	    case 2 : //display
			cout<<"RollNo\t\tName\t\tYear\tAddress";
	    		file.displayAllRecords(); 
	    		break; 
	    case 3 : //search
	    		cout<<"Enter Roll Number"; 
	    		cin>>rollNo; 
	    		try 
	    		{ 
	    			file.displayRecord(rollNo); 
	    		} 
	    		catch(const char *str) 
	    		{ 
	    			cout<<str; 
	    		} 
	    		break; 
	    case 4: //delete
	    		cout<<"Enter rollNo"; 
	    		cin>>rollNo; 
	    		file.deleteRecord(rollNo); 
	    		break; 
	   case 5 :break; 
        } 
  
    } 
}

/*OUTPUT:

	::STUDENT DATABASE::

		MENU
1) Add New Record
2) Display All Records
3) Display by RollNo
4) Deleting a Record
5) Exit
Choose your choice : 1

Enter RollNo:1

Enter Name:Tim
Enter Year :4
Enter address :abcde

		MENU
1) Add New Record
2) Display All Records
3) Display by RollNo
4) Deleting a Record
5) Exit
Choose your choice : 2
RollNo		Name		Year	Address
      1             Tim       4          abcde
		MENU
1) Add New Record
2) Display All Records
3) Display by RollNo
4) Deleting a Record
5) Exit
Choose your choice : 1

Enter RollNo:2

Enter Name:Sam
Enter Year :3
Enter address :Fghijk

		MENU
1) Add New Record
2) Display All Records
3) Display by RollNo
4) Deleting a Record
5) Exit
Choose your choice : 2
RollNo		Name		Year	Address
      1             Tim       4          abcde
      2             Sam       3         Fghijk
		MENU
1) Add New Record
2) Display All Records
3) Display by RollNo
4) Deleting a Record
5) Exit
Choose your choice : 1

Enter RollNo:10

Enter Name:Jim
Enter Year :1
Enter address :rtyui

		MENU
1) Add New Record
2) Display All Records
3) Display by RollNo
4) Deleting a Record
5) Exit
Choose your choice : 2
RollNo		Name		Year	Address
      1             Tim       4          abcde
      2             Sam       3         Fghijk
     10             Jim       1          rtyui
		MENU
1) Add New Record
2) Display All Records
3) Display by RollNo
4) Deleting a Record
5) Exit
Choose your choice : 1

Enter RollNo:7 

Enter Name:Pete  
Enter Year :3
Enter address :wxyz

		MENU
1) Add New Record
2) Display All Records
3) Display by RollNo
4) Deleting a Record
5) Exit
Choose your choice : 2
RollNo		Name		Year	Address
      1             Tim       4          abcde
      2             Sam       3         Fghijk
     10             Jim       1          rtyui
      7            Pete       3           wxyz
		MENU
1) Add New Record
2) Display All Records
3) Display by RollNo
4) Deleting a Record
5) Exit
Choose your choice : 3
Enter Roll Number2

      2             Sam       3         Fghijk
		MENU
1) Add New Record
2) Display All Records
3) Display by RollNo
4) Deleting a Record
5) Exit
Choose your choice : 4
Enter rollNo1

		MENU
1) Add New Record
2) Display All Records
3) Display by RollNo
4) Deleting a Record
5) Exit
Choose your choice : 2
RollNo		Name		Year	Address
      2             Sam       3         Fghijk
     10             Jim       1          rtyui
      7            Pete       3           wxyz
		MENU
1) Add New Record
2) Display All Records
3) Display by RollNo
4) Deleting a Record
5) Exit
Choose your choice : 5
Closing file..*/
