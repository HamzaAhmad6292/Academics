#include<iostream>
using namespace std;
class Faculty :public Teachers,Administrator
{
	int x;
public:
	virtual void print()
	{
		cout << "Faulty" << endl;
	}
};
class Teachers {
	int y;
	public:
	virtual void print()
	{
		cout << "Teachers" << endl;
	}
};
class Administrator {
	int z;
	
	public:
		 virtual void print()
	    {
		cout << "Adminitrator" << endl;
	    }

};
class TeacherAdministrator {

public:
	void print()
	{
		cout << "Teacher Administrator";
	}

};


int main()
{
	Faculty obj[3];
	
	Faculty* ptr = obj;

	ptr[0] = new Teachers;
	ptr[1] = new Administrator;
	ptr[2] = new TeacherAdministrator;

	for (int i = 0; i < 3; i++)
	{
		obj[i]->print();
	}

}