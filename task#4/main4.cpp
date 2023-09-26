#include <iostream>
using namespace std;
template <typename T>
void write_array(T *array, int row, int column)
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            cout << array[i][j] << " ";
        }
        cout << "\n";
    }
}
template <typename S>
void cin_array(S *array, int row, int column)
{
    cout << "Enter array:" << endl;
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            cin >> array[i][j];
        }
        cout << "\n";
    }
}
// template <typename D>
void multiplication_array(float arrA[][4],  float arrB[][1], float arr_answer[][1])
{
    for (int i = 0; i < 4; ++i)
    {
        arr_answer[i][0]=0;
        for (int j = 0; j < 4; ++j)
        {
            arr_answer[i][0] += arrA[i][j]*arrB[i][0];
        }
    }
}
int main()
{
    int row_a, column_a, row_b, column_b; 
    float array_a[4][4], array_b[4][1], array_answer[4][1];
    
    row_a = size(array_a);
    column_a = size(array_a[0]);
    cin_array(array_a, row_a, column_a);
    row_b = size(array_b);
    column_b = size(array_b[0]);
    cin_array(array_b, row_b, column_b);

    multiplication_array(array_a, array_b, array_answer );
    write_array(array_answer, row_b, column_b);
}