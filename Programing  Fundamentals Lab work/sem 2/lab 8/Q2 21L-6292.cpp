
#include <iostream>


using namespace std;

class Teacher 

{


    int EmployeeID;
    char* Name;
public:
    Teacher(int ID, char* n) {
        EmployeeID = ID;

        Name = new char[30];
        Name = n;
    }
    ~Teacher() {
        Name = NULL;
        delete Name;

    }
    void Display() {
        cout << "Teacher Name:";


        cout << Name << endl;

        cout << "Teacher ID:";


        cout << EmployeeID << endl;
    }

};

class Student
{

    char* rollnumber;
    char* name;
    Teacher* TeacherList;
public:
    Student(char* ron, char* n, Teacher* t)
    {

        rollnumber = new char[30];


        rollnumber = ron;

        name = new char[30];
        name = n;
        TeacherList = t;


    }
    ~Student() {

        rollnumber = nullptr;

        delete[] rollnumber;

        name = nullptr;

        delete[] name;

    }
    void Display() {
        cout << "Student_Roll No:";
        cout << rollnumber << endl;
        cout << "Student_Name:";
        cout << name << endl;
        cout << "Teacher_List:";
        cout << TeacherList;

    }
};

int main() {
    char x[50];
    char roll[30];
    int id;
   



    cout << "Enter Student Roll No:" << endl;

    cin.get(roll, 30);


    cout << "Enter Student Name:" << endl;

    cin.get(x, 30);

    
    cout << "Enter Teacher Name:" << endl;

    cin.get(x, 30);
 
    cout << "Enter Teachers ID:" << endl;

    cin >> id;


    Teacher obj(id, x);

    obj.Display();

   



    return 0;
  
}