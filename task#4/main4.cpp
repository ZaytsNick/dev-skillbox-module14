#include <iostream>
using namespace std;
template <typename T>
void write_array(T *array )
{
    for (int i = 0; i < array.length; ++i)
    {
        for (int j = 0; j < array[0].length; ++j)
        {
            cout << array[i][j] << " ";
        }
        cout << "\n";
    }
}
//template <typename S>
// void cin_array(S *array)
// {
//     cout << "Enter array:" << endl;
//     for (int i = 0; i < array.length; ++i)
//     {
//         for (int j = 0; j < array[0].length; ++j)
//         {
//             cin >> array[i][j];
//         }
//         cout << "\n";
//     }
// }
template <typename D>
void multiplication_array(D* arrA, D* arrB, D* arr_answer)
{
    for (int i = 0; i < arrA.length; ++i)
    {
        for (int j = 0; j < arrA[0].length; ++j)
        {
            arr_answer[i][0] += arrA[i][j];
        }
        arr_answer[i][0] *= arrB[i][0];
    }
}
int main()
{
    // int rows = a.length; //строки
    // int columns = a[0].length; //столб   ,array_a.length(),array_a[0].length()
    float array_a[4][4], array_b[4][1], array_answer[4][1];
    //cin_array(array_a);
    //cin_array(array_b);
    //multiplication_array(array_a, array_b, array_answer);
    write_array(&array_a);
}