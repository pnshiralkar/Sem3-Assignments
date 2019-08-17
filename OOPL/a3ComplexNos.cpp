/*
WAP to design a class ‘Complex ‘with data members for real and imaginary part. 
Provide  default  and  parameterized  constructors.  
Write  a  program  to  perform arithmetic operations of two complex numbers using operator overloading. 
	i.Addition and subtraction using friend functions. 
	ii.Multiplication and division using member functions
*/

#include <iostream>
#include <cmath>

using namespace std;

class Complex{
	float r,i;
	public:
	Complex()
	{
		r=0.0f;
		i=0.0f;
	}
	Complex(float r,float i)
	{
		this->r = r;
		this->i = i;
	}
	
	// Conjugate
	Complex operator ~()
	{
		return Complex(r,-i);
	}
	
	// Display
	friend ostream & operator << (ostream &out, Complex c)
	{
		out << "(" << c.r << ((c.i>=0)?('+'):('-')) << "i" << abs(c.i) << ")";
		return out;
	}
	
	// Addition & Substraction
	friend Complex operator +(Complex, Complex);
	friend Complex operator -(Complex, Complex);
	
	// Multiplication
	Complex operator *(Complex c)
	{
		return Complex((r*c.r - i*c.i), (r*c.i + i*c.r));
	}
	
	// Division
	Complex operator /(Complex c)
	{
		return Complex((r*c.r + i*c.i)/(c.i*c.i + c.r*c.r), (i*c.r + r*c.i)/(c.i*c.i + c.r*c.r));
	}
};

Complex operator +(Complex c1, Complex c2)
{
	return Complex(c1.r+c2.r, c1.i+c2.i);
}

Complex operator -(Complex c1, Complex c2)
{
	return Complex(c1.r-c2.r, c1.i-c2.i);
}

int menu()
{
	int i;
	cout << "\n\n\t1.Enter Numbers\n\t2.Display\n\t3.Addition\n\t4.Substraction\n\t5.Multiplicaton\n\t6.Division\n\t7.Exit\nEnter your choice : ";
	cin >> i;
	cout << endl << endl;
	return i; 
}

main()
{
	Complex c(-1,-2), ca(0,5), cb(3,7);
	Complex c1, c2;
	cout << "\n\n******Complex Numbers******";
	float a,b;
	int f=1;
	while(f)
	{
		switch(menu())
		{
			case 1:
				cout << "Enter First Complex number : ";
				cin >> a >> b;
				c1 = Complex(a,b);
				cout << "Enter Second Complex number : ";
				cin >> a >> b;
				c2 = Complex(a,b);
				break;
			case 2:
				cout << "C1 = " << c1 << endl << "C2 = " << c2 << endl;
				break;
			case 3:
				cout << "C1 + C2 = " << c1+c2 << endl;
				break;
			case 4:
				cout << "C1 - C2 = " << c1-c2 << endl;
				cout << "C2 - C1 = " << c2-c1 << endl;
				break;
			case 5:
				cout << "C1 * C2 = " << c1*c2 << endl;
				break;
			case 6:
				cout << "C1 / C2 = " << c1/c2 << endl;
				cout << "C2 / C1 = " << c2/c1 << endl;
				break;
			default:
				f=0;
		}
	}
	return 0;
}
