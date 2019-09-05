/*
 Inheritance 
Design a base class with name, date of birth, blood group and another base class consisting of the data members such as height and weight. 
Design one more base class consisting of the insurance policy number and contact address. 
The derived class contains the data members’ telephone numbers and driving license number.
Write a menu driven program to carry out the following things:
i. Build a master table
ii.  Display Record
iii.  Insert  a record
iv.  Delete record
v.  Edit  record
vi.  Search  for a record

*/

#include<iostream>
#include<iomanip>
#include<string.h>

using namespace std;

class base{
	public:
	char name[50], dob[12], bgrp[5];
};

class base1: public base{
	public:
	float height, weight;
};

class base2 : public base1{
	public:
	long insPolNo;
	char addr[100];
};

class der : base2{
	long tel;
	char dl[20];
	public:
	void disp(int i)
	{
		cout << setw(5) << i << fixed << showpoint << setw(25) << name << setw(15) << dob << setw(10) << bgrp << setw(9) << setprecision(2) << height << setw(9) << setprecision(2) << weight << setw(18) << insPolNo << setw(35) << addr << setw(16) << tel << setw(20) << dl << endl;
	}
	void inp()
	{
		cout << "Enter the details for record :\n\tName : ";
		cin >> name;
		cout << "\tDateOfBirth : ";
		cin >> dob;
		cout << "\tBlood Group : ";
		cin >> bgrp;
		cout << "\tHeight : ";
		cin >> height;
		cout << "\tWeight : ";
		cin >> weight;
		cout << "\tInsurance Policy No. : ";
		cin >> insPolNo;
		cout << "\tAddress : ";
		cin >> addr;
		cout << "\tTel No. : ";
		cin >> tel;
		cout << "\tDriving License No. : ";
		cin >> dl;
	}
	int compName(char name[])
	{
		return (!strcmp(this->name, name));
	}
};

int menu()
{
	int i;
	cout << "\n\n******Inheritance******\n\n\t1.Display master table\n\t2.Display record\n\t3.Insert record\n\t4.Delete record\n\t5.Edit record\n\t6.Search record\n\t7.Exit\nEnter your choice : ";
	cin >> i;
	cout << endl << endl;
	return i; 
}

int search(der d[], int n, char msg[])
{
	char name[50];
	cout << "Enter Name to " << msg << " : ";
	cin >> name;
	for(int i=0;i<n;i++)
		if(d[i].compName(name))
			return i;
	cout << "No such record!";
	return -1;
}

int main()
{
	der d[100];
	int f=1,n=0,t;
	while(f)
	{
		switch(menu())
		{
		case 1:
			cout << "\nSr.No.             Name               DOB       BloodGrp  Height   Weight  InsurancePolicyNo.    Address                           TelephoneNo.   DrivingLicense\n";
			for(int i=0;i<n;i++)
				d[i].disp(i+1);
			break;
		case 2:
			t=search(d,n,"display");
			if(t!=-1){
				cout << "\nSr.No.             Name               DOB       BloodGrp  Height   Weight  InsurancePolicyNo.    Address                           TelephoneNo.   DrivingLicense\n";
				d[t].disp(1);
			}
			break;
		case 3:
			d[n++].inp();
			break;
		case 4:
			t=search(d,n,"delete");
			if(t!=-1){
				for(int i=t;i<n-1;i++)
					d[i]=d[i+1];
				cout << "Record deleted successfully.";
			}
			break;
		case 5:
			t=search(d,n,"delete");
			if(t!=-1){
				d[t].update();
			}
		}
	}
	return 0;
}

//Pratham 16/16/4848 O+ 112.00 165.00 1365464864 eir,ori,forj 9075577238 646464365mhgb54
