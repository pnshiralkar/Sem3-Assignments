#include<iostream>
#include<fstream>
#define l 1000007
using namespace std;

int main()
{
	char fname[l],line[l];
	
	ofstream fout;
	cout<<"\nWRITE INTO FILE: -\nEnter file name : ";
	cin>>fname;
	fout.open(fname);
	cout<<"\nEnter data to write into file :\n";
	if(fout)
	{
		cin.ignore();
		cin.getline(line, l);
		fout<<line<<endl;
	}
	else
		cout<<"\nFile Creation Failed..!!\n";
	fout.close();
	
	ifstream fin;
	cout<<"\nREAD THE FILE: -\n";
	fin.open(fname);
	while(!fin.eof())
	{
		fin.getline(line, l);
		cout<<line<<endl;
	}
	fin.close();
	
	return 0;
}
