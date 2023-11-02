#include<iostream>
using namespace std;
class bday
{
	int day;
	int month;
	int year;
public:
	class invalid_Day
	{

	};
	class invalid_Month
	{
		string s;
	public:
		invalid_Month(string r)
		{
			s = r;
		}
		string get()
		{
			return s;
		}
		
	};
	class invalid_Year
	{

	};

	bday(int x, int y, int z)
	{
		day = x;
		month=y;
		year = z;
	}
	void check()
	{
		string s;
		if (month == 1)
		{
			s = "January";
		}
		else if (month == 2)
		{
			s = "Febuary";
		}
		else if (month == 3)
		{
			s = "March";
		}
		else if (month == 4)
		{
			s = "April";
		}
		else if (month == 5)
		{
			s = "May";
		}
		else if (month == 6)
		{
			s = "June";
		}
		else if (month == 7)
		{
			s = "July";

		}
		else if (month == 8)
		{
			s = "August";
		}
		else if (month == 9)
		{
			s = "September";
		}
		else if (month == 10)
		{
			s = "October";
		}
		else if (month == 11)
		{
			s = "Nevember";
		}
		else if (month == 12)
		{
			s = "December";
		}
		else 
		{
			throw invalid_Month();
		}


		if ((month == 1)&&(day!=31))
		{
			s = "January";
		}
		if ((month == 2)&& (day != 28))
		{
			s = "Febuary";
		}
		if ((month == 3)&& (day != 30))
		{
			s = "March";
		}
		if ((month == 4)&& (day != 31))
		{
			s = "April";
		}
		if ((month == 5)&& (day != 30))
		{
			s = "May";
		}
		if ((month == 6)&& (day != 31))
		{
			s = "June";
		}
		if ((month == 7)&& (day != 30))
		{
			s = "July";
		}
		if ((month == 8)&& (day != 31))
		{
			s = "August";
		}
		if ((month == 9)&&(day != 31))
		{
			s = "September";
		}
		if ((month == 10)&&(day != 30))
		{
			s = "October";
		}
		if ((month == 11)&& (day != 31))
		{
			s = "November";
		}
		if ((month == 12)&&(day != 31))
		{
			s = "December";
		}
	
	}

};

int main()
{
	int day;
	int month;
	int year;
	cout << "Enter your birthday:";
		cin >> day;
		cin >> month;
		cin >> year;
		bday obj(day, month, year);
		try
		{
			obj.check();
		}
		catch (dbay::invalid_month())
		{

		}
}