#include<iostream>
#include<vector>
using namespace std;
struct HashItem {
	int key;
	int value;
	HashItem* next;
	
};
template<class v>
class HashMap
{
	vector<v> hashvector;
	int currentitems;
	int capacity;
public:
	HashMap()
	{

		HashItem* obj = new HashItem[10];
		capacity = 10;

		for (int i = 0; i < 10; i++)
		{
			hashvector.push_back(obj[i]);
		}



	}
	HashMap(int x)
	{
		HashItem* obj = new HashItem[x];
		capacity = x;
		for (int i = 0; i < x; i++)
		{
			hashvector.push_back(obj[i]);
		}
	}
	void insert(int x)
	{
		int temp = x % capacity;
		insert(temp, x);
	}
	void insert(int const key, int const value)
	{
		 HashItem*  obj = hashvector[key];
		while (obj != NULL)
		{
			obj = obj->next;
		}
		obj->key = key;
		obj->value = value;
		obj->next = NULL;


	}
	bool deletekey(v const key)
	{

		HashItem* obj = new HashItem;
		obj->next = hashvector[key];
		HashItem* temp;
		if (hashvector[key] == NULL)
		{
			return false;
		}

		while (obj != NULL)
		{
			temp = obj->next;
			delete obj;
			obj = 0;
			obj = temp;
		}
		return true;

	}
	v* get(int const key)
	{

		HashItem* obj = new HashItem;
		obj->next = hashvector[key];
		if (hashvector[key] == NULL)
		{
			return false;
		}

		while (obj != NULL)
		{
			obj = obj->next;

		}
		cout << "Value:" << obj->value << endl;
	}

};

int main()
{
	HashMap<HashItem> obj(10);
	obj.insert(1);
	obj.insert(6);
	obj.insert(7);

}