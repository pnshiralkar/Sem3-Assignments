#include<iostream>

using namespace std;

class Report{
	int day;
	float ht,lt,rain,snow;
	
	public:
	Report()
	{
		day=99;
		ht=999;
		lt=-999;
		rain=0;
		snow=0;
	}
	
	void disp()
	{
		//cout << day << "    " << ht << "       " <<  lt << "      " << rain << "   " << snow << endl;
		printf("%2d    %3.2f        %3.2f        %2.2f   %2.2f\n", day, ht, lt, rain, snow);
	}
	
	void update(int uday, int uht, int ult, int ur, int us)
	{
		day = uday;
		ht = uht;
		lt = ult;
		rain = ur;
		snow = us;
		
	}
	
	int getd(){return day;}
	float getht(){return ht;}
	float getlt(){return lt;}
	float getr(){return rain;}
	float gets(){return snow;}
};

void disp(Report* report)
{
	cout << "Day " << " High Temp " << "     Low Temp " << "      Rain  " << " Snow " << endl;
	for(int i=0;i<30;i++)
		report[i].disp();
}

void dispAvg(Report* report)
{
	int d,den=0;
	float ht=0,lt=0,r=0,s=0;
	for(int i=0;i<30;i++)
	{
		if(report[i].getd() != 99)
		{
			den++;
			ht += report[i].getht();
			lt += report[i].getlt();
			r += report[i].getr();
			s += report[i].gets();
		}
	}
	printf("Avg:  %3.2f        %-3.2f        %2.2f   %2.2f\n", ht/den, lt/den, r/den, s/den);
}

int main()
{
	Report report[30];
	disp(report);
	
	
	while(1)
	{
		int d,ht,lt,r,s;
		cout << "Enter a day to update : ";
		cin >> d;
		cout << "\nEnter values of High temp, Low temp, Rain and Snow : ";
		cin >> ht >> lt >> r >> s;
		report[d-1].update(d,ht,lt,r,s);
		disp(report);
		dispAvg(report);
		cout << "\nDo you want to update other day?(y/n) : ";
		char res;
		cin >> res;
		if(res!='y' && res!='Y')
			break;
	}
	
	cout << "\nThank You\n";
	
	return 0;
}
