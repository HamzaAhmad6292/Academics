#include <iostream>
using namespace std;

class Roman
{
    string roman;
    int num;
public:


    int convert(string rstr)

    {
        int n = int(rstr.length());
        if (0 == n) {
            return 0;
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            switch (rstr[i]) {
            case 'I':
                result += 1;
                break;
            case 'V':
                result += 5;
                break;
            case 'X':
                result += 10;
                break;
            case 'L':
                result += 50;
                break;
            case 'C':
                result += 100;
                break;
            case 'D':
                result += 500;
                break;
            case 'M':
                result += 1000;
                break;
            }
        }

        for (int i = 1; i < n; i++) {
            if ((rstr[i] == 'V' || rstr[i] == 'X') && rstr[i - 1] == 'I') {
                result -= 1 + 1;
            }

            if ((rstr[i] == 'L' || rstr[i] == 'C') && rstr[i - 1] == 'X') {
                result -= 10 + 10;
            }

            if ((rstr[i] == 'D' || rstr[i] == 'M') && rstr[i - 1] == 'C') {
                result -= 100 + 100;
            }
        }
        return result;
    }



    string itr(int n)
    {

        string str_romans[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
        int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };

        string result = "";

        for (int i = 0; i < 13; ++i)
        {
            while (n - values[i] >= 0)
            {
                result += str_romans[i];
                n -= values[i];
            }
        }

        return result;
    }


    void input()
    {
        cout << "Enter any Roman Number:";
        cin >> roman;
    }

    Roman operator +(const Roman a1)
    {
        Roman temp;
        int x;
        int y;
        x = convert(a1.roman);
        y = convert(roman);
        temp.num = x + y;
        temp.roman = itr(temp.num);

        return temp;
    }
    Roman operator -(const Roman a2)
    {
        Roman temp;
        int x;
        int y;
        x = convert(a2.roman);
        y = convert(roman);

        if (x >= y)
        {
            temp.num = x - y;
        }
        else
        {
            temp.num = y - x;
        }
        if (temp.num < 0)
        {
            temp.num * -1;
        }
        temp.roman = itr(temp.num);

        return temp;
    }
    Roman operator *(const Roman a3)
    {
        Roman temp;
        int x;
        int y;
        x = convert(a3.roman);
        y = convert(roman);
        temp.num = x * y;
        temp.roman = itr(temp.num);

        return temp;
    }

    Roman operator /(const Roman a4)
    {
        Roman temp;
        int x;
        int y;
        x = convert(a4.roman);
        y = convert(roman);
        if (x >= y)
        {
            temp.num = x / y;
        }
        else
            temp.num = y / x;
        temp.roman = itr(temp.num);

        return temp;
    }
    int  operator >(const Roman a5)
    {

        int x = convert(roman);
        int y = convert(a5.roman);
        if (x > y)
        {
            return 1;
        }
        else return 0;
    }
    int  operator <(const Roman a6)
    {

        int x = convert(roman);
        int y = convert(a6.roman);
        if (x < y)
        {
            return 1;
        }
        else return 0;
    }
    int  operator ==(const Roman a7)
    {

        int x = convert(roman);
        int y = convert(a7.roman);
        if (x == y)
        {
            return 1;
        }
        else return 0;
    }
    int  operator !=(const Roman a8)
    {

        int x = convert(roman);
        int y = convert(a8.roman);
        if (x != y)
        {
            return 1;
        }
        else return 0;
    }
    Roman operator++(int)
    {
        Roman temp;
        int x = convert(roman);
        x++;
        temp.roman = itr(x);

        return temp;
    }
    Roman operator--(int)
    {
        Roman temp;
        int x = convert(roman);
        x--;

        temp.roman = itr(x);
        return temp;

    }
    void output()
    {
        cout << roman;
    }

};
int main()
{
    Roman a, obj1, obj2;
    obj1.input();
    obj2.input();
    a = obj1 + obj2;
    cout << "Sum:";
    a.output();
    cout << endl;

    Roman b;
    b = obj1 - obj2;
    cout << "Difference:";
    b.output();
    cout << endl;

    Roman c;
    c = obj1 * obj2;
    cout << "Multiplaction:";
    c.output();
    cout << endl;

    Roman d;
    d = obj1 / obj2;
    cout << "Division:";
    d.output();
    cout << endl;

    cout << "Increment of ";
    obj1.output();
    cout << ":";
    obj1++;
    obj1++.output();
    cout << endl;

    cout << "Decrement of ";
    obj1.output();
    cout << ":";
    obj1--;
    obj1--.output();
    cout << endl;
    if (obj1 > obj2)
    {
        obj1.output();
        cout << " is greater than ";
        obj2.output();
    }
    cout << endl;

    if (obj1 < obj2)
    {
        obj1.output();
        cout << " is smaller than ";
        obj2.output();
    }
    cout << endl;

    if (obj1 == obj2)
    {
        obj1.output();
        cout << " is equal to  ";
        obj2.output();
    }
    cout << endl;

    if (obj1 != obj2)
    {
        obj1.output();
        cout << " is not equal to ";
        obj2.output();
    }
    system("pause");
    return 0;

}