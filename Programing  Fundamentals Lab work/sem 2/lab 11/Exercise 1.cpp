#include<iostream>
using namespace std;
template<class T>
void performOperation(T a, T b,char c)
{
	T x;
	if (c == '*')
	{
		x = a * b;
	}
	else if (c == '+')
	{
		x = a + b;
	}
	else if (c == '-')
	{
		x = a - b;
	}
	else if  (c == '/')
	{
		x = a / b;
	}

	cout << "Answer:" << x;
}

int main()
{
	
	float a, b; // this can be float, int or double too
	char op;

	cout<<" Enter first operand:";
	cin>> a;
	cout << " Enter second operand ";
	cin>> b;
	cout<<" Enter operation";
	cin>> op; // op can be +, -, * or /
	if (op == '*' || op == '+' || op == '-' || op == '/')
	{
		performOperation(a, b, op);
	}
	else
	{
		cout<< "Wrong operation ";
	}
}