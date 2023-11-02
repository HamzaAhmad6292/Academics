#include<iostream>
using namespace std;
class Point
{
	int x, y;
public:
	void set()
	{

	}
	Point(int a=3,int b=2)
	{
		x = a;
		y = b;
		cout << "Point()Called" << endl;
	}

	void print()
	{
		cout << "(" << x << "," << y << ")" << endl;
	}

	~Point()
	{
		cout << "Destructor called" << endl;
	}
};
class Circle
{
	Point obj;
	float radius;
public:
	Circle(int a, int b, float c)
	{
		obj=Point(a,b);
		radius = c;

		cout << "circle()called" << endl;

	}
	void print()
	{
		cout << "Radius:" << radius << endl;
		cout << "Centre";
		obj.print();
	}
	
};
class Quadliteral
{
	Point w, x, y, z;
public:
	Quadliteral(int a = 1, int b=2, int a1=3, int b1=4, int a2=5, int b2=6, int a3=7, int b3=8)
	{
		w=Point(a, b);
		x=Point(a1, b1);
		y=Point(a2, b2);
		z=Point(a3, b3);
	}

	void print()
	{
		w.print();
		x.print();
		y.print();
		z.print();
	}
};
int main()
{
	Circle c(3, 4, 2.5);
	cout << endl;
	c.print();
	cout << endl;
	Quadliteral a;
	cout << endl;
	a.print();
	cout << endl;
	Quadliteral b(1, 0, 0, 1, 1, 1, 0, 0);
	cout << endl;
	b.print();

	return 0;
}