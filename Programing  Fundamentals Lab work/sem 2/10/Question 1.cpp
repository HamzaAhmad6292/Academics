#include<iostream>
#include<string>
using namespace std;
class Ship{
	string name;
	string year;
public:
	Ship()
	{

	}
	Ship(string a, string b)
	{
		name = a;
		year = b;

	}
	void set(string a, string b)
	{
		name = a;
		year = b;
	}
	string getname()
	{
		return name;
	}
	string getyear()
	{
		return year;
	}

	virtual void print()
	{
		cout << "Name:" << name << endl;
		cout << "Year:" << year << endl;
	}


};

class CruiseShip: public Ship{

	int passengers;
public:
	CruiseShip()
	{

	}
	CruiseShip(int x)
	{
		passengers = x;
	}
	void set(int x)
	{
		passengers = x;
	}
	int  get()
	{
		return passengers;

	}

	void print()
	{

		string x = getname();
		cout << "Name:" << x << endl;
		cout << "Number of passengers:" << passengers << endl;
	}
};
class CargoShip: public Ship
{
	int capacity;
public:
	CargoShip()
	{

	}
	CargoShip(int x)
	{
		capacity = x;
	}

	void set(int x)
	{
		capacity = x;
	}
	int get()
	{
		return capacity;
	}
	void print()
	{
		string name = getname();
		cout << "Name:" << name << endl;
		cout << "Capacity:" << capacity << endl;
	}
};

int main()
{
	Ship obj1;
	cout<<obj1.getname;
	string name;
	string year;
	int Capacity;
	int passengers;
	cout << "Enter name of Ship:";
	cin >> name;
	cout << "Enter year:";
	cin >> year;
	cout << "Enter number of passengers:";
	cin >> passengers;
	cout << "Enter Capacity:";
	cin >> Capacity;

	Ship* obj[3];
	obj[0] = new Ship(name,year);
	obj[1] = new CruiseShip(passengers);
	obj[2] = new CargoShip(Capacity);
	for (int i = 0; i < 3; i++)
	{
		obj[i]->print();
	}

	system("pause");
	return 0;

}