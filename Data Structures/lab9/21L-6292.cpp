#include <iostream>
#include <fstream>

#include <cassert>
#include <string>

using namespace std;

template <typename k, typename v>
class minHeap {
	struct HeapItem {
		k key;
		v value;
	};
	HeapItem* arr;
	int capacity;
	int totalItems;
	void shiftUp(int index)
	{
		if (index < 1)
			return;

		int parent = (index - 1) / 2;

		if (this->arr[index].key < this->arr[parent].key)
		{
			swap(this->arr[index], this->arr[parent]);
			shiftUp(parent);
		}
	}

	void doubleCapacity()
	{
		if (this->arr == nullptr)
		{
			this->arr = new HeapItem[1];
			this->capacity = 1;
			return;
		}
		int newCapacity = capacity * 2;
		HeapItem* newArr = new HeapItem[newCapacity];
		for (int i = 0; i < this->totalItems; i++)
		{
			newArr[i] = this->arr[i];
		}
		if (this->arr != nullptr)
			delete[] this->arr;
		this->capacity = newCapacity;
		swap(arr, newArr);
	}
public:
	minHeap()
	{
		this->arr = nullptr;
		this->capacity = 0;
		this->totalItems = 0;
	}
	minHeap(int _capacity)
	{
		assert(_capacity >= 1);
		this->arr = new HeapItem[_capacity];
		this->capacity = _capacity;
		this->totalItems = 0;
	}
	void insert(k const key, v const value)
	{
		if (totalItems == capacity)
			doubleCapacity();
		arr[totalItems].key = key;
		arr[totalItems].value = value;
		shiftUp(totalItems);
		totalItems++;
	}
	void getMin(v& value)
	{
		assert(totalItems != 0);
		value = arr[0].value;
	}
	bool isEmpty() const {
		return (totalItems == 0);
	}

	void deleteMin() {
		assert(totalItems != 0);
		swap(arr[0], arr[totalItems - 1]);
		totalItems=totalItems-1;
		shiftDown(0);
	}



	void deleteAll()
	{
		if (this->arr != nullptr)
		{
			delete[]arr;


			arr = NULL;
			this->capacity = 0;
			this->totalItems = 0;

		}
	}
	~minHeap()
	{
		deleteAll();
	}
};

class Student {
	int rollNumber;
	string name;
	float cgpa;

public:
	Student(int rollNumber, string name, float cgpa) {
		this->rollNumber = rollNumber, this->name = name, this->cgpa = cgpa;
	}
	Student() {
		rollNumber = -1, name = "", cgpa = -1;
	}

	void setn(string n) {
		this->name = n;
	}
	void setr(int roll) {
		this->rollNumber = roll;
	}

	friend ostream& operator<<(ostream& out, const Student& s)
	{
		out << s.rollNumber << "  ";
			cout<< s.name <<  "  " << s.cgpa << endl;
		return out;
	

};

void BuildStudentHeap(const string& fileName, minHeap<int, Student>& stdHeap) {
	fstream fin(fileName, ios::in);
	if (!fin) { 
		
		cout << "invalid file "; 
		
		
		return; 
	}


	

	string temp;
	int t;

	int rollNumber;
	string name;

	float cgpa;

	fin >> t;
	getline(fin, temp);
	Student* s = new Student[t];
	for (int i = 0; i < t; i++)
	{
		fin >> rollNumber >> name >> cgpa;

		s[i].setr(rollNumber); s[i].setn(name); s[i].setr(cgpa);

		stdHeap.insert(rollNumber, s[i]);
	}

	fin.close();
}




int main()
{
	minHeap<int, Student> stdHeap;

	BuildStudentHeap("students.txt", stdHeap);

	while (!stdHeap.isEmpty())
	{
		Student st;

		stdHeap.getMin(st);


		cout << st << endl << endl;
		
		stdHeap.deleteMin();
	}
	system("pause");
	return 0;
}