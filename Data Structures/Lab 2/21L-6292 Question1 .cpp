#include<iostream>
using namespace std;
class shape
{
	friend class Rectangle;

private:
	int length;
	int width;
public:
	shape(int x,int y)
	{
		length = x;
		width = y;
	}
	shape()
	{

	}
	void set(int x,int y)
	{
		length = x;
			width = y;
	}
	int getL()
	{
		
		return length;
	}
	int getW()
	{
		return width;
	}
	~shape()
	{

	}

};
class Rectangle
{

public:

	int Area(shape &obj)
	{
		int area = obj.length * obj.width;
		return area;
	}
	int Perimeter(shape &obj)
	{
		int per = 2 * obj.length + 2 * obj.width;
		return per;
	}


};
int main()
{
	int length;
	int width;

	cout << "Enter length:";
	cin >> length;
	cout << "Enter Width:";
	cin >> width;
	shape obj;
	obj.set(length, width);
	
	Rectangle obj1;
	int area = obj1.Area(obj);
	int per = obj1.Perimeter(obj);

	cout << "Area:" << area  << endl;
	cout << "Perimeter:" << per << endl;

	system("pause");
	return 0;

	


}