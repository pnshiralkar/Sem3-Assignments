/*
Mock Practical

Batch : H10
Roll No.: 23254
Date of Performance : 10/10/2019

Problem statement:
WAP to design a lass 'Complex' with data members for real and imaginary part.
Provide default and parameterized contructors. Write a program to perform arithmetic operaions of two complex numbers using operator overloading.
	i. Addition and subtraction using friend functions.

*/

#include<iostream>

using namespace std;


// Define a class for Complex numbers
class Complex{
	public:
	float real,img; // Declare real and imaginary parts.
	
	// Default constructor.
	Complex()
	{
		real=0;
		img=0;
	}
	
	// Parameterized constructor.
	Complex(float real, float img)
	{
		this->real = real;
		this->img = img;
	}
	
	friend Complex operator +(Complex, Complex); // Friend function to perform addition and overload operator (+).
	friend Complex operator -(Complex, Complex); // Friend function to perform subtraction and overload operator (-).
	friend ostream& operator <<(ostream& , Complex); // Friend function to display the complex number and overload operator (<<).
};

// Friend function to perform addition and overload operator (+).
Complex operator +(Complex c1, Complex c2)
{
	float real = c1.real + c2.real;
	float img = c1.img + c2.img;
	return Complex(real, img);
}

// Friend function to perform subtraction and overload operator (-).
Complex operator -(Complex c1, Complex c2)
{
	float real = c1.real - c2.real;
	float img = c1.img - c2.img;
	return Complex(real, img);
}

// Friend function to display the complex number and overload operator (<<).
ostream& operator <<(ostream& out, Complex c)
{
	float img;
	char sign;
	if(c.img>=0)
	{
		img = c.img;
		sign = '+';
	}
	else
	{
		img = -c.img;
		sign = '-';
	}
	out << c.real << " " << sign << " " << "i" << img;
	return out;
}


// Function to display menu and return response of user.
int menu()
{
	int res;
	cout << "\n\nComplex Numbers\n\n1. Enter the complex numbers\n2. Addition\n3. Subtraction\n4. Exit\n   Your choice : ";
	cin >> res;
	return res;
}


// Main function.
int main()
{
	Complex c1,c2; // Instantiate two objects (complex numbers) of the class Complex.
	float real, img; // Declare real and imaginary parts to input from user.
	
	while(1)
	{
		switch(menu())
		{
			case 1: // Take the numbers from user.
				cout << "Enter Complex number #1 : \n\t Real part : ";
				cin >> real;
				cout << "\t Imaginary part : ";
				cin >> img;
				c1 = Complex(real, img);
				cout << "Enter Complex number #2 : \n\t Real part : ";
				cin >> real;
				cout << "\t Imaginary part : ";
				cin >> img;
				c2 = Complex(real, img);
				cout << "\nComplex numbers (" << c1 << ") and (" << c2 << ") entered successfully.";
				break;
			case 2: // Perform adition.
				cout << "\n\nAddition of C1 and C2 is : " << c1 + c2 << endl;
				break;
			case 3: // Perform subtraction.
				cout << "\n\nSubraction of C1 and C2 is : " << c1 - c2 << endl;
				break;
			case 4: // Exit
				return 0;
			default: // Default action for any other response.
				cout << "Invalid choice entered!";
		}
	}
	
	return 0;
}
