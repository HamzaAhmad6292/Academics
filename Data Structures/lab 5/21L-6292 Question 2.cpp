#include<iostream>
using namespace std;
class Queue;
class node
{
	friend class Queue;
	int data;
	node* next;
};
class Queue
{
	node* front;
	node* rear;
public:

	Queue()
	{
		front = 0;
		rear = 0;
	}
	bool isempty()
	{
		if (front == 0)
			return 1;
		else
			return 0;
		
	}
	int size()
	{
		node* curr = front;
		int count = 0;
		while (curr != rear)
		{

			count++;
			curr = curr->next;
		}
		return count;
	}
	void enqueue(const int& e)
	{
		node* temp = new node();

		temp->data = e;
		temp->next = front;
		
		
		front = temp;
		return ;
	}
	void dequeue()
	{
		if (front == 0)
		{
			return;
		}
		else
		{
			node* curr = new node();
			curr = front->next;
			delete front;
			front = 0;
			front = curr;
			return;
		}
	}
	
	bool efront(Queue& obj, int x)
	{
		if (obj.isempty() == 1)
		{
			obj.enqueue(x);
			return 0;
		}
		else
		{
			obj.enqueue(x);
			return 1;
		}
	}
};
int main()
{

	Queue obj;
	if (obj.isempty() == 1)
	{
		cout << "Queue is Empty";
	}
	obj.enqueue(1);
	obj.enqueue(2);
	obj.enqueue(3);
	obj.enqueue(4);
	if (obj.efront(obj, 5) == 0)
	{
		cout << "Some Error" << endl;
	}


	int size = obj.size();
	cout << "Size:" << size << endl;


	obj.dequeue();
	 size = obj.size();
	cout << "Size after deletion:" << size << endl;





	system("pause");
	return 0;




}