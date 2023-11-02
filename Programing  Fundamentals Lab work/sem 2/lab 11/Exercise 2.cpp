#include<iostream>
using namespace std;
template<class T,class X>
X GetMax(X x,T y)
{
	if (x >= y)
	{
		return x;
	}
	else
		return y;
}
template<class T1,class X1>
X1 GetMin(X1 x, T1 y)
{
	if (x <= y)
	{
		return x;
	}
	else return y;

}


template<class T2,class X2,class Y2>
T2 GetMax(T2 x, X2 y, Y2 z)
{
	if ((x >= y) && (x >= z))
	{
		return x;
	}
	else if ((y >= x) && (y >= z))
	{
		return y;
	}
	else
		return z;
}


template<class T3, class X3, class Y3>
T3 GetMin(T3 x, X3 y, Y3 z)
{
	if ((x <= y) && (x <= z))
	{
		return x;
	}
	else if ((y <= x) && (y <= z))
	{
		return y;
	}
	else
		return z;
}


int main()
{
	char i ='Z';
	int j = 6, k;
	long l = 10, m = 5, n,x,y;
	k = GetMax (i, m);
	n = GetMin (j, l);
	x = GetMax(i, j, l);
	y = GetMin(i, m, j);
	cout<<k<< endl;
	cout<< n<< endl;
	cout << x << endl;
	cout << y << endl;

	return 0;
}

