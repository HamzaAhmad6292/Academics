#include<iostream>
using namespace std;
class MyBigInt
{
	int* bigint;
	int length;
public:
	MyBigInt(int size=5)
	{
		bigint = nullptr;
		length=size;
		bigint = new int[length];
	     
	}
	MyBigInt(const MyBigInt& obj)
	{
		length = obj.length;
		bigint = new int[length];
		for (int i = 0; i < length; i++)
		{
			bigint[i] = obj.bigint[i];
		}
		cout << "copy construcor called" << endl;
	}
	void assign(const MyBigInt& obj)
	{
		length = obj.length;
		bigint = new int[length];
		for (int i = 0; i < length; i++)
		{
			bigint[i] = obj.bigint[i];
		}
		cout << "Function  called" << endl;

	}
	int CompareTo(const MyBigInt& obj)
	{
		bool flag = false;
		int x = obj.length;
		length = obj.length;
		if (x == length)
		{
			for (int i = 0; i < length; i++)
			{
				if (obj.bigint[i] == bigint[i])
				{
					bool flag = true;
				}
			}
		}
		if (flag == true)
		{
			return 0;
		}
		else
		{
			if (x > length)
			{
				return 2;
			}
			if (x < length)
			{
				return 1;
			}
		}

			

	}
	void display()
	{
		if (bigint == nullptr)
		{
			cout << "No Value assigned" << endl;

		}
		else
		{
			for (int i = 0; i < length; i++)
			{
				cout << bigint[i];
			}
		}
	}
	~MyBigInt()
	{
		delete[]bigint;
		bigint = nullptr;

    }


};
int main()
{
	MyBigInt obj1(5);
	MyBigInt obj2(obj1);
	obj2.assign(obj1);

	int x = obj1.CompareTo(obj2);
	obj2.display();


	return 0;



}