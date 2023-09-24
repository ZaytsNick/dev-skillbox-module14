#include <iostream>
using namespace std;
template <typename T>
void cout_array(T array[][4])
{
    cout<<"Array:"<<endl;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            cout << array[i][j] << " ";
        }
        cout << "\n";
    }
}
template <typename S>
void cin_array(S array[][4])
{
    cout<<"Enter array#1"<<endl;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            cin >> array[i][j];
        }
        cout << "\n";
    }
}
bool cin_array2(int arr1[][4], int arr2[][4])
{
    for (int i = 0; i < 4; ++i)
    {
    cout<<"Enter array#2"<<endl;
        for (int j = 0; j < 4; ++j)
        {
            cin >> arr2[i][j];
            if (arr1[i][j] != arr2[i][j])
                return false;
        }
        cout << "\n";
    }
    return true;
}

void diag_array(int arr1[][4])
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (i != j)
                arr1[i][j] = 0;
        }
        cout << "\n";
    }
}
int main()
{
    int array1[4][4], array2[4][4];
    cin_array(array1);
    if (cin_array2(array1,array2))
    {
        diag_array(array1);
        cout_array(array1);
        cout_array(array2);
    }
    else
    cout<<"Error: array are not equal to each other!";
}