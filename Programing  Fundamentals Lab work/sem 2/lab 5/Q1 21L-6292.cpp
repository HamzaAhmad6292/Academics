#include<iostream>
using namespace std;
class Date
{
	int day;
	int month;
	int year;
public:
	Date()
	{
		day = 1;
		month = 1;
		year = 1926;
		cout << "Default Constructor Called" << endl;
	}
	Date(int n1, int n2, int n3)
	{
		n1 = day;
		n2 = month;
		n3=year;

		cout << "Over loaded function called" << endl;
	}

	void Print()
	{
		cout << day << "/" << month << "/" << year  << endl;

	}
	void print(int day, int month, int year)
	{
		cout << day << "/" << month << "/" << year << endl;
	}
	void input()
	{
		cout << "Enter day:";
			cin >> day;
		cout << "Enter month:";
		cin >> month;
		cout << "Enter year:";
		cin >> year;
	}

	void setday(int x)
	{
		day = x;
	}
	void setmonth(int y)
	{
		month = y;
	}
	void setyear(int z)
	{
		year = z;
	}
	int getday()
	{
		return day;
	}
	int getmonth()
	{
		return month;
	}
	int getyear()
	{
		return year;
	}


};

int main()
{

	int day;
	int month;
	int year;


	int x = 25;
	int y = 12;
	int z = 2020;


	Date date1;
	Date date2(30, 7, 2003);
	date1.Print();
	Date independenceDay;
	independenceDay.print(14,8,1947);
	date1.input();
	date1.Print();
	Date xmaxday;
	xmaxday.Print();

	xmaxday.setday(x);
	xmaxday.setmonth(y);
	xmaxday.setyear(z);

	xmaxday.getday();
	xmaxday.getmonth();
	xmaxday.getyear();

	xmaxday.Print();



	system("pause");
	return 0;
}
