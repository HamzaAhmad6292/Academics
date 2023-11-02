#include<iostream>
#include<string>
using namespace std;
class StudentData
{
    int rollno;
    double cnic;
    string name;
    string Degree;
    string address;

public:

    void Set(int val1, double val2, string val3, string val4, string val5)
    {
        rollno = val1;
        cnic = val2;
        name = val3;
        Degree = val4;
        address = val5;
    }


    string GetName()
    {
        return name;
    }
    int GetRollno()
    {
        return rollno;
    }
    double GetCNIC()
    {
        return cnic;
    }
    string GetDegree()
    {
        return Degree;
    }
    string GetAddress()
    {
        return address;
    }






};
int main()
{
    StudentData obj;

    string name;
    cout << "Enter Your Name:";
    getline(cin, name);
    int rollno;
    cout << "Enter your Rollno";
    cin >> rollno;
    string Degree;
    cout << "Enter your Degree Program:";
    cin >> Degree;
    double  cnic;
    cout << "Enter your CNIC:";
    cin >> cnic;
    string Address;
    cout << "Enter your Address:";
    cin >> Address;
    cout << endl << endl;
    obj.Set(rollno, cnic, name, Degree, Address);


    cout << "The Name of Student:" << obj.GetName() << endl;
    cout << "The Roll_no of thr Student:" << obj.GetRollno() << endl;
    cout << "The Degree of the Student:" << obj.GetDegree() << endl;
    cout << "The CNIC of the Student:" << obj.GetCNIC() << endl;
    cout << "The Address of the Student:" << obj.GetAddress() << endl;


    system("pause");
    return 0;


}