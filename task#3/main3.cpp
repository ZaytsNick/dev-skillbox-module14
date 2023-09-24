#include <iostream>
using namespace std;
template <typename T>
void write_array(T array[][4])
{
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
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            cin >> array[i][j];
        }
        cout << "\n";
    }
}
void diag_array(int arr[][4],int diag[][16])
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if(i==j)
            diag
        }
        cout << "\n";
    }
}
int main()
{
    int array1[4][4], array2[4][4],diag[16][16];
}