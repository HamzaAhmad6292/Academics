#include<iostream>
using namespace std;
template <class a>
void function(a& x, a& y)
{
	a temp = x;
	x = y;
	y = temp;
}
int main()
{
	int x, y;
	cout << "Enter first number:";
	cin >> x;
	cout << "ENter second number:";
	cin >> y;
	function(x, y);

	cout << "first value:" << x << endl;;
	cout << "Secomd valuw:" << y << endl;;

	system("pause");
	return 0;




}