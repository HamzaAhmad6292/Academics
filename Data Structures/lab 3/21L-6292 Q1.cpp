#include<iostream>
using namespace std;
struct linkedlist
{
	struct node
	{
		int data;
		node* next;
	};

	node* head;
	node* tail;
public:
	linkedlist()
	{
		head = nullptr;
		tail = nullptr;
	}
	void InsertAtStart(int const x)
	{
		node* temp = new node;
		temp->data = x;
		temp->next = head;
		head = temp;
	}
	void InsetAtEnd(int x)
	{
		node* curr = head;
		node* prev = nullptr;
		node* temp = new node();
		temp->data = x;
		while (curr != NULL)
		{

			prev = curr;
			curr = curr->next;
		}
		if (prev == NULL)
		{
			head = temp;
		}
		else
		{
			prev->next = temp;
		}
	}
	void Display()
	{
		node* curr = head;
		while (curr != NULL)
		{
			cout << curr->data << " ";
			curr = curr->next;
			if (curr == NULL)
			{
				return;
			}
		}
	}
	void DeleteFromStart()
	{
		if (head == NULL)
		{
			return;
		}
		else
		{
			node*curr=head;
		     head=head->next;
				delete curr;
				curr=0;
				
		}
	}
	void DeleteFromEnd()
	{
		if (head == 0)
		{
		}
		else
		{
			node* curr = head;
			node* last = 0;
			node* Slast = 0;
			while (curr != NULL)
			{
				Slast = last;
				last = curr;
				curr = curr->next;
			}
			if (Slast == 0)
			{
				head = NULL;
				delete last;
				last = 0;
				return;
			}
			else
			{
				Slast->next = NULL;
				delete last;
				last = 0;
				return;
			}
		}
		
	}
	~linkedlist()
	{
		node* curr;
		while (head != NULL)
		{
			curr = head;
			head = head->next;
			delete curr;
			curr = head;
		}
	}

};
int main()
{
	linkedlist l1;
	l1.InsertAtStart(2);
	l1.InsertAtStart(6);
	l1.InsertAtStart(7);
	l1.InsetAtEnd(3);
	l1.InsetAtEnd(8);
	l1.InsetAtEnd(1);
	l1.DeleteFromStart();
	l1.DeleteFromEnd();
	l1.Display();


	system("pause");
	return 0;
}