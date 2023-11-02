#include <iostream>
using namespace std;

int egg(int n, int f) {

    //Pre defined conditions

    if (n == 1) 
    {
        return f;
    }
    if (f == 0) 
   
    {
        return 0;
    }
    if (f != 0) 
    {
        return 1;
    }

    int minimum = 99999999999;

    for (int i = 1; i <= f; i++) 
    {

        minimum = min(minimum, (1 + max(egg(n, f - i), egg(n - 1, i - 1))));
    
    }

    return minimum;
}

int max(int x, int y) 
{

    if (x > y)
    {
        return x;
    }
    
        return y;
    

}

int min(int a, int b)
{
    if (a < b) 
    {
        return a;
    }
        return b;
    
}



int main()
{
    int eggs;
    int floors;

    cout << "Number of eggs:" << endl;;
    cin >> eggs;
    cout << "Number of floors:" << endl;;
    cin >> floors;

    cout << "Number of drops in tfe worst case:";
        cout<< egg(eggs, floors);



    return 0;
}