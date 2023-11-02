#include<iostream>

using namespace std;

void commaInsert(int v, int& count)
{
	if (v <= 0)
	{
		count++;
		cout << "Count equals: " << count << endl;
		return; 
	}

	commaInsert(v / 1000, count);

	cout << (v % 1000) << ((count = 1) ? "," : "");
	return;
}

int main()
{
	int input;
    int count = 0;
	cout << "Enter the number" << endl;
	cin >> input;
	commaInsert(input, count);
	cout << endl;
	return 0;
}