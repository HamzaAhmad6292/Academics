#include<iostream>
#include<fstream>
#include <string>
#include<ctype.h>
using namespace std;
class Singly;
class Node {
	friend class Singly;

	string data;
	Node* next;


};

class Singly {
	Node* head;

public:

	Singly()
	{
		head = 0;
	}

	void insertSorted(string  x)
	{
		Node* temp = new Node();
		temp->data = x;
		temp->next = 0;

		if (head == 0)
		{
			head = temp;
			return;

		}
		Node* curr = head;
		Node* prev = curr;
		while (curr != NULL)
		{
			prev = curr;
			curr = curr->next;



		}

		prev->next = temp;
		return;

	}

	void display()
	{
		Node* curr = head;
		while (curr != 0)
		{

			cout << curr->data << "-";

			curr = curr->next;

		}
	}
};


class node
{
	friend class BST;
	node* left;
	node* right;
	string keyword;
	Singly urls;
};
class BST
{
	node* root;





	void search(string keyword, node* t)
	{
		while (t != 0)
		{
			if (t->keyword == keyword)
			{
				t->urls.display();
				return;
			}
			else if (keyword < t->keyword)
				t = t->left;
			else if (keyword > t->keyword)
				t = t->right;
		}


	}


public:
	BST()
	{
		root = 0;

	}

	void search(string keyword)
	{
		search(keyword, root);

		cout << endl;
		return;
	}

	bool remove(string val)
	{
		node* curr = root, * parent = 0;
		while (curr != 0 && curr->keyword != val)
		{
			parent = curr;
			if (val < curr->keyword)
				curr = curr->left;
			else
				curr = curr->right;
		}
		if (curr == 0)
			return false;
		else
		{
			if (curr->left != 0 && curr->right != 0)
			{
				node* l = curr->left, * pl = curr;
				while (l->right != 0)
				{
					pl = l;
					l = l->right;
				}
				curr->keyword = l->keyword;
				curr = l;
				parent = pl;
			}
			node* child;
			if (curr->left != 0)
			{
				child = curr->left;
			}
			else
			{
				child = curr->right;
			}
			if (curr == root)
			{
				root = child;
			}
			else
			{
				if (curr == parent->left)
					parent->left = child;
				else
					parent->right = child;
			}
			delete curr;
			curr = 0;
			return true;
		}
	}


	void insert(string keyword, string url)
	{
		node* temp = insert(root, keyword, url);

	}
	node* insert(node*& t, string keyword, string url) {
		if (t == NULL)
		{

			t = newNode(keyword, url);
			return t;
		}
		if (keyword == t->keyword)
		{
			t->urls.insertSorted(url);
			return t;
		}

		if (keyword < t->keyword)
			t->left = insert(t->left, keyword, url);
		else
			t->right = insert(t->right, keyword, url);

		return t;
	}
	node* newNode(string item, string url) {
		node* temp = new node;
		temp->keyword = item;
		temp->left = temp->right = NULL;
		temp->urls.insertSorted(url);

		return temp;

	}




	void Inputfile(node*& t, string filename)
	{

		ifstream filein(filename);

		string str;
		string url;
		string key;
		if (filein.is_open())
		{
			while (!filein.fail())
			{
				filein >> str;

				if (!filein.fail())
				{
					for (int i = 0; !str.empty(); i++)
					{
						if (isdigit(str[i]))
							url = str;
						else
							key = str;
					}
					if (str.length() > 17)
						url = str;
					else
						key = str;
					insert(key, url);

				}
			}

		}
		else
		{
			cout << "file could not open\n";
		}
		filein.close();
	}
	void inputfile(string filename)
	{
		Inputfile(root, filename);
	}

};



int main()
{
	BST obj;
	obj.insert("hamza", "url1");
	obj.insert("ali", "url2");                            // some hardcoded data for all functions ;
	obj.insert("hadi", "url3");
	obj.insert("hamza", "url4");
	obj.insert("hamza", "url5");

	obj.search("hamza");
	//obj.inputfile("Data.txt");                  functions for reading the data from the file ;

	system("pause");
	return 0;



}