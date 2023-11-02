#include<iostream>
using namespace std;
void merge(string array[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
    string *leftArray = new string[subArrayOne],
        * rightArray = new string[subArrayTwo];
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne
        = 0,
        indexOfSubArrayTwo
        = 0;
    int indexOfMergedArray
        = left; 
    while (indexOfSubArrayOne < subArrayOne
        && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
void mergeSort(string array[], int const begin, int const end)
{
    if (begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
int min(int x, int y)
{
	if (x <= y)
	{
		return x;
	}
	else
		return y;
}
int main()
{
    int m;
    int n;

    cout << "Enter no of teachers:";
    cin >> m;
    cout << "Enter number of Students:";
    cin >> n;
    string* teachers = new string[m];
    string** students = new string*[n];
    for (int i = 0; i < n; i++)
    {
        students[i] = new string [3];
    }

    cout << "Enter Teachers:" << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> teachers[i];
    }
    cout << "Enter Students     Format Teachers Name - Students Name - Age :" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> students[i][j];
        }
    }
   
    
    mergeSort(teachers, 0, m-1);

    cout << endl;
    cout << "Sorted Teachers:" << endl;
    for (int i = 0; i < m; i++)
    {
        cout << teachers[i] << endl;
    }
    cout << endl;
    cout << endl;
    cout << "Teachers With Their Students" << endl;
    
    for (int i = 0; i < m; i++)
    {
        cout << teachers[i];
        for (int x = 0; x < n; x++)
        {
            if (teachers[i] == students[x][0])
            {
                cout << endl << students[x][1] << endl << students[x][2];
            }
        }
        cout << endl;
    }




	system("pause");
	return 0;


}