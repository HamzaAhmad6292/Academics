#include <iostream>
using namespace std;

class BasicShape {
protected:
	double area;
public:
	double getArea() {
		return area;
	}
	virtual void calcArea()=0 {
	}
	virtual ~BasicShape() {}
};

class Circle :  public BasicShape {
	long int centerX;
	long int centerY;
	double radius;
public:
	Circle(long int x = 0, long int y = 0, double r = 0) {
		centerX = x;
		centerY = y;
		radius = r;
		this->calcArea();
	}
	void calcArea() {
		BasicShape::area = 3.14159 * radius * radius;
	}
	long int getCenterX() {
		return centerX;
	}
	long int getCenterY() {
		return centerY;
	}
};

class Rectangle :public BasicShape {
	long int length;
	long int width;
public:
	Rectangle(long int l = 0, long int w = 0) {
		length = l;
		width = w;
		this->calcArea();
	}
	void calcArea() {
		area = length * width;
	}
	long int getWidth() {
		return width;
	}
	long int getLength() {
		return length;
	}
};

void main() {
	long int cX, cY, l, w;
	double ra;
	cout << "Enter Circle's X Coordinate:";
	cin >> cX;
	cout << "Enter Circle's Y Coordinate:";
	cin >> cY;
	cout << "Enter Circle's Radius:";
	cin >> ra;
	cout << "Enter Rectangle's length:";
	cin >> l;
	cout << "Enter Rectangle's width:";
	cin >> w;
	Circle c(cX, cY, ra);
	Rectangle r(l, w);
	cout << "Circle's area is " << c.getArea() << endl;
	cout << "Rectangle's area is " << r.getArea() << endl;
	system("PAUSE");
}
