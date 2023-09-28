#include <iostream>
using namespace std;
void cin_heights(bool array[][5][10])
{
    cout << "\nInput matrix of heights:" << endl;
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            int height(-1);
            while (height < 0 || height > 10)
            {
                cout << "Enter the height of the block whose coordinates: " << i + 1 << "x" << (char)(j + 'A') << " : ";
                cin >> height;
            }
            for (int k = 0; k < 10; ++k)
            {
                if (k < height)
                    array[i][j][k] = true;
                else
                    array[i][j][k] = false;
            }
        }
    }
}
void input_slice(bool arr[][5][10])
{
    int slice(-2);
    while (slice != -1)
    {
        slice=-2;
        while (slice < 0 || slice > 9)
        {
            cout << "input slice: ";
            cin >> slice;
        }
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                cout << arr[i][j][slice] << " ";
            }
            cout << "\n";
        }
    }
}
int main()
{
    bool landscape[5][5][10];
    cin_heights(landscape);
    input_slice(landscape);
}