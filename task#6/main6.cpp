#include <iostream>
using namespace std;
void write_array(int array[][5])
{
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            cout << array[i][j] << " ";
        }
        cout << "\n";
    }
}
int main()
{
    int digits[5][5], number(0);
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            digits[i][((i % 2) * 4)?(4-j):j] = number;
            number++;
        }
    }
    write_array(digits);
}