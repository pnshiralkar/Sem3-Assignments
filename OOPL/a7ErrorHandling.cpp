/*
Assignment 7
Roll no.: 23254
Batch : H10

Write a program in C++ which includes the code for following operations :
i. A function to read two double type numbers from keyboard
ii. A function to calculate the division of these two numbers
iii. A try block to detect and throw an exception if the condition “divide-by-   
      zero”occurs
iv. Appropriate catch block to handle the exceptions thrown

*/

#include<iostream>
#include<iomanip>

using namespace std;

class DivideByZeroExc{};

double divide(double a, double b)
{
	DivideByZeroExc d;
	if(b!=0)
		return a/b;
	else
		throw d;
}

void input(double *a, double *b)
{
	cout << "Enter the two numbers : ";
	cin >> *a >> *b;
}

int main()
{
	double a,b;
	char c;
	while(1)
	{
		input(&a,&b);
		try{
			cout << fixed << "Division of " << setprecision(6) << a << " and " << setprecision(6) << b << " is : " << divide(a,b) << endl;
		}
		catch(DivideByZeroExc e){
			cout << "Divide by zero not possible!\n";
		}
		cout << "\nDo you want to repeat(y/n)? : ";
		cin >> c;
		if(!(c=='Y' || c=='y'))
		return 0;
	}
}
