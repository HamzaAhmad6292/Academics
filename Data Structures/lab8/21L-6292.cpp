#include<iostream>
using namespace std;
class node 
{
	friend class BST;
	int data;
	node* left;
	node* right;
};
class BST
{
	node* root;
	bool insert(node*& t, int val)
	{
		if (t == 0)
		{
			t = new node;
			t->data = val;
			t->right = NULL;
			t->left = NULL;
		
			return true;
		}
		else if (val < t->data)
		{
			insert(t->left,val);

		}
		else if (val > t->data)
		{
			insert(t->right, val);

		}
		if (val == t->data)
		{
			return false;
		}
	}
	void inorder(node* root) {
		if (root != nullptr) {
			inorder(root->left);
			cout << root->data << " ";
			inorder(root->right);
		}
	}
	int minimum(node* t, int k)
	{
		int count = 0;
		while (t && t->left != 0)
		{
			t = t->left;
			count++;
		}
		t = root;
		for (int i = 0; i <= count - k; i++) {
			t = t->left;

		}

		return  t->data;
		
	}
  int maximum(node* t, int k) {
		int count = 0;
		while (t && t->right != 0)
		{
			t = t->right;
			count++;
		}
		t = root;
		for (int i = 0; i <= count - k; i++) {
			if(count==0)
		{
		t=t->left;
		}
			t = t->right;

		}
		return  t->data;
	
	}
	int height(node* t)
	{
		int count = 0;
		while (t && t->left != 0)
		{
			t = t->left;
			count++;
		}
		return count;
	}
	int length(node* root, int count = 0) {
		if (root != nullptr) {
			
			inorder(root->left);
			count++;
			inorder(root->right);
			count++;
		}
		return count;
	}


public:
	BST()
	{
		root = NULL;
	}
	void insert(int val)
	{
	
		insert(root, val);
	}
	bool remove(int val)
	{
		node* curr = root, * parent = 0;
		while (curr != 0 && curr->data != val)
		{
			parent = curr;
			if (val < curr->data)
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
				curr->data = l->data;
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

	int maximum(int k) {
		return maximum(root, k);
	}
	void inorder()
	{
		inorder(root);
	}
	int minimum(int k) {
		return minimum(root, k);
	}
	int height()
	{
		return height(root);
	}
	int length()
	{
		return length(root);
	}
};
int main()
{
	BST obj;
	obj.insert(19);
	obj.insert(20);
	obj.insert(31);
	obj.insert(32);
	obj.insert(8);
	obj.insert(28);
	obj.insert(10);
	obj.insert(6); 
	obj.insert(1);
	
	obj.inorder();
	cout << endl;
	cout << "length of the Tree:" << obj.length() << endl;

	cout << "Height of the Tree:" << obj.height() << endl;

	int minimum = obj.minimum(3);
	int maximum = obj.maximum(3);
	
	cout << "3rd maximum number in the tree:" << maximum << endl;
	cout << "3rd minimum number in the Tree:" << minimum << endl;

	cout << "Minimum and maximum can be for any kth number";

}