#include<iostream>
using namespace std;
class node
{
	friend class stack;
	node* next;
	int data;
};
class stack
{
	node* top;


public:
	stack()
	{
		top = 0;
	}
	void push(int x)
	{

		node* temp = new node;
		temp->data = x;
		if (top == 0)
		{
			top = temp;
			temp->next = 0;
			return;
		}
		temp->next = top;
		top = temp;
		
		 

	}
	void sort()
	{
		
		node*curr =top;
		recursion(curr);
	

	}
	void recursion(node* curr)
	{
		node* temp = new node;
		if (curr->next == NULL)
		{
			return;
		}
	   if (curr->data >= curr->next->data)
		{
			temp->data = curr->data;
			curr->data = curr->next->data;
			curr->next->data = temp->data;
			recursion(curr);
		}
		else
			curr = curr->next;

		if (curr == 0)
		{
			return;
		}
		recursion( curr);
	}
	
	void display()
	{
		node* curr = top;
		while (curr != NULL)
		{
			cout << curr->data << endl;
			curr = curr->next;
		}
	}
	void reverse()
	{
		stack obj1;
		node* curr = top;
		rereverse(obj1, curr);

	}
	void rereverse(stack obj1,node* curr)
	{
		obj1.push(curr->data);
		curr = curr->next;
		if (curr == NULL)
		{
			top = obj1.top;
			return;
		}
		rereverse(obj1,curr);
	}

};
int main()
{
	stack obj;
	int n;
	cout << "Enter N:";
	cin >>n ;
	cout << "Input Stack"<<endl;
	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		obj.push(x);
	}
	//obj.sort();
	//obj.sort();
	//cout << "Sorted Stack:" << endl;
	//obj.display();
	//cout << "Inversed Array:" << endl;                
	//node* temp = NULL;
	obj.reverse();
	obj.display();
	system("pause");
	return 0;
}