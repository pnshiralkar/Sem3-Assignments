/*
Assignment 6
Roll No.: 23254
Batch : H10

Inheritance using Virtual function 
Create a base class shape with two double type values and member functions to input the data and compute_area() for calculating area of figure. 
Derive two classes’ triangle and rectangle.
Make compute_area() as a virtual function and redefine this function in the derived class to suit their requirements.
Write a program that accepts dimensions of triangle/rectangle and display calculated area.
*/

#include<iostream>

using namespace std;

class shape{
	public:
	double a,b;
	void inp(double a, double b)
	{
		this->a = a;
		this->b = b;
	}
	virtual double compute_area()=0;
};

class triangle : public shape{
	double compute_area()
	{
		return (a*b)/2.000f;
	}
};

class rectangle : public shape{
	double compute_area()
	{
		return (a*b);
	}
};

int menu()
{
	int r;
	cout << "1. Triangle\n2. Rectange\n3. Exit\nYour choice : ";
	cin >> r;
	return r;
}

int main()
{
	int f=1;
	double a,b;
	shape *s;
	rectangle r;
	triangle t;
	while(f)
	{
		switch(menu())
		{
		case 1:
			s = &t;
			cout << "Enter Height and base of triangle : ";
			cin >> a >> b;
			s->inp(a,b);
			cout << "Area of the triangle is : " << s->compute_area() << endl;
			break;
		case 2:
			s = &r;
			cout << "Enter length and breadth of rectangle : ";
			cin >> a >> b;
			s->inp(a,b);
			cout << "Area of the rectangle is : " << s->compute_area() << endl;
			break;
		default:
			f=0;
		}
	}
	return 0;
}
