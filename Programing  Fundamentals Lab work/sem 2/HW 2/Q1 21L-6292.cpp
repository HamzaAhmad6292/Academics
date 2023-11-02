#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int size = 999;

	char* arr = new char[size];
	cout << "Enter character array:";
	cin >> arr;
	cout << "Inverted Array:";


	for (int i = size - 1; i >= 0; --i)
	{
		if (arr[i] > 1)
			cout << *(arr+i);
	}
	cout << endl;

	arr = nullptr;
	delete[]arr;

	system("pause");
	return 0;

}