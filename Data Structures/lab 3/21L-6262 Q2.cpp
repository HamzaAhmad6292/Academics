#include<iostream>
using namespace std;
class linkA;
class node
{
	friend class linkA;
	friend class linkB;
	friend class linkC;

	int data;
	node* next;
public:
	int get(node* X)
	{
		int x = X->data;
		return x;

	}
	node* getA(node* X)
	{
		X = X->next;
		return X;
	}


};
class linkA
{
	node* head;
public:
	linkA()
	{
		head = NULL;
	}
	void InsetSort(int x)
	{
		node* temp = new node();
		temp->data = x;
		if (head == NULL)
		{
			temp->data = x;
			temp->next = NULL;
			head = temp;
			return;
		}
		node* curr = head;
		node* prev = nullptr;

		while (curr != NULL)
		{
			if (x <= curr->data)
			{
				break;
			}

			prev = curr;
			curr = curr->next;

			if (curr == NULL)
			{
				prev->next = temp;
				temp->next = NULL;
				return;
			}
		}
		if (prev == NULL)
		{
			temp->next = curr;
			head = temp;
			return;

		}
		else
		{
			temp->next = curr;
			prev->next = temp;
			return;

		}

	}

	node* get()
	{
		node* curr = head;
		return curr;
	}
	void Display()
	{
		node* curr = head;
		while (curr != NULL)
		{
			cout << curr->data << " ";
			curr = curr->next;
		}
	}


};



linkA Union(linkA  A, linkA  B)
{
	node* X = A.get();
	node* Y = B.get();
	linkA C;
	while (X != NULL)
	{
		int x = X->get(X);
		C.InsetSort(x);
		X = X->getA(X);
	}
	while (Y != NULL)
	{
		int x = Y->get(Y);
		C.InsetSort(x);
		Y = Y->getA(Y);
	}
	return C;
}

linkA Inter(linkA A, linkA B)
{

	node* X = A.get();
	node* Y;
	linkA C;


	while (X != NULL)
	{
		Y = B.get();
		while (Y != NULL)
		{
			int x = X->get(X);
			int y = Y->get(Y);

			if (x == y)
			{
				C.InsetSort(x);
				Y = Y->getA(Y);
				break;


			}

			Y = Y->getA(Y);
			if (Y == NULL)
			{
				break;
			}
		}
		X = X->getA(X);
		if (X == NULL)
		{
			return C;
		}

	}
	return C;
}

int main()
{
	linkA A;
	linkA B;
	int a;
	cout << "Enter LinkA" << endl;
	for (int x = 0; x < 5; x++)
	{
		cin >> a;
		A.InsetSort(a);


	}
	cout << "Enter linkB" << endl;
	for (int i = 0; i < 10; i++)
	{
		cin >> a;
		B.InsetSort(a);
	}
	linkA C = Union(A, B);
	cout << "Sorted linkA:";
	A.Display();
	cout << endl << "Sorted linkB:";
	B.Display();
	cout << endl << endl;

	cout << "Union:";

	C.Display();
	cout << endl;


	C = Inter(A, B);
	cout << "Intersection:";


	C.Display();

	system("pause");
	return 0;

}