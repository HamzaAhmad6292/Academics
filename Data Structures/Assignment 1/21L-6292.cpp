#include<iostream>
using namespace std;


class DoublyLinkedList;

class Node
{
	int data;
	friend DoublyLinkedList;
	Node* next, * prev;
};


class DoublyLinkedList
{
	Node* head;
public:
	DoublyLinkedList()
	{
		head = 0;


	}
	void InsertAtStart(int x)
	{

		Node* curr = new Node;
		curr->prev = nullptr;
		curr->next = head;
		curr->data = x;

		if (head != nullptr)//if the head is not empty
			head->prev = curr;

		head = curr;
		return;
	}
	bool DeleteFromEnd()
	{
		Node* temp = head;
		Node* curr = nullptr;
		if (head == nullptr)
		{
			cout << "The linked list is Already empty\n";
			return 0;
		}
		else
		{
			while (temp != nullptr)
			{
				curr = temp;
				temp = temp->next;
			}
			if (curr == nullptr)
			{
				delete temp;
				return 1;
			}
			if (curr->prev == nullptr)
				return 0;

			curr->prev->next = nullptr;
			delete curr;
			curr = nullptr;
			return 1;

		}
		return 1;
	}

	bool DelAtSpecific(int x)
	{
		if (head == nullptr)
		{
			return 0;
		}
		else {
			Node* temp = head;

			while ((temp != NULL) && (temp->data != x))
			{
				temp = temp->next;
			}
			if (temp == head)
			{
				DeleteFromStart();
				return 1;
			}
			if (temp->next == NULL)
			{
				DeleteFromEnd();
				return 1;
			}

			temp->prev->next = temp->next;

			delete temp;
			temp = 0;
			return 0;
		}
	}
	bool DeleteFromStart()
	{
		Node* temp = head;

		head = head->next;
		head->prev = 0;

		delete temp;
		temp = 0;
		return 1;
	}
	bool InsertAtEnd(int x)
	{
		Node* curr = new Node;
		curr->data = x;

		if (head == nullptr)
		{
			InsertAtStart(x);
			return 1;
		}
		Node* temp;
		temp = head;

		while (temp->next != 0)
		{
			temp = temp->next;
		}
		temp->next = curr;
		curr->prev = temp;
		curr->next = NULL;
		return 1;
	}
	bool SortedInsert(int x)
	{
		Node* temp = new Node;
		temp->data = x;
		Node* curr = head;
		while (curr != 0 && curr->data < temp->data)
		{
			curr->prev = curr;
			curr = curr->next;
		}
		if (curr->prev != 0)
		{
			curr->prev->next = temp;
		}
		else
		{
			InsertAtStart(temp->data);
		}
		temp->next = curr;

		return 1;

	}
	Node* search(int x)
	{
		Node* curr = head;
		Node* temp = new Node;
		temp->data = x;
		int index = 1;
		while (curr != nullptr)
		{
			if (curr->data == temp->data)
			{
				cout << "value is present at index: " << index << "\n";
				return curr;
			}
			else
			{
				index++;
				curr = curr->next;
			}
		}
		cout << "value not found\n";
		delete temp;
		temp = 0;
		return 0;
	}
	void Display()
	{
		Node* curr = nullptr;
		curr = head;
		cout << "Linked List:";
		while (curr != nullptr)
		{
			cout << curr->data << "-";
			curr = curr->next;
		}
		cout << endl;
	}
	~DoublyLinkedList()
	{
		Node* curr;
		while (head != NULL)
		{
			curr = head;

			head = curr->next;

			delete curr;

		}
		curr = nullptr;
		delete head;
		if (head == 0)
		{
			cout << "Linked List deleted\n";


		}
	}
};

int main()


{
	DoublyLinkedList obj;
	obj.InsertAtStart(5);

	obj.InsertAtStart(4);
	obj.InsertAtStart(2);

	obj.Display();
	obj.DeleteFromStart();
	obj.DelAtSpecific(4);

	obj.DeleteFromEnd();



	obj.SortedInsert(2);

	obj.Display();

	obj.search(5);

	return 0;
}