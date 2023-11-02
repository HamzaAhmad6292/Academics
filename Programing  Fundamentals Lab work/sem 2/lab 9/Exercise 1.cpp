#include<iostream>
#include "Header.h"

using namespace std;


shape::shape() {
	length = 10;
	breadth = 15;
	height = 20;
}

int Square::getarea() {
	int area = length * length;
	cout << "Total Square : " << area << endl;
	return area;

}



int Rectangle::getarea() {
	int area = breadth * length;
	cout << "Total Rectangle : " << area << endl;
	
	
	return area;

}
int Triangle::getarea() 

{
	int area = (1 / 2) * (height * breadth);

	cout << "Total Rectangle:" << area<<"\n";
	return area;
}

Painting::Painting(int a) {
	cost = a;
}
void Painting::getcost(int area) {


	int totalcost = cost * area;

	cout << "Total cosst :$" << totalcost<<"/n";
}



	int main() 
	
	{
		shape obj;

		Painting obj1(20);

		Square obj2;

		obj1.getcost(obj2.getarea());
		Rectangle obj3;

		obj1.getcost(obj3.getarea());
		Triangle obj4;

		obj1.getcost(obj4.getarea());

		return 0;
	}




