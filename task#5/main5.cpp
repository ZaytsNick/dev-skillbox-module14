#include <iostream>
using namespace std;
void pimply_initialization(bool array[][12])
{
    for (int i = 0; i < 12; ++i)
    {
        for (int j = 0; j < 12; ++j)
        {
            array[i][j] = true;
        }
    }
}
void status_pimply(bool array[][12])
{
    cout << "     ";
    for (int i = 0; i < 12; ++i)
    {
        cout << i + 1 << "   ";
    }
    cout << "\n"
         << endl;
    for (int i = 0; i < 12; ++i)
    {
        cout << (char)(i + 'A') << "    ";
        for (int j = 0; j < 12; ++j)
        {
            if (array[i][j])
                cout << "O   ";
            else
                cout << "X   ";
        }
        cout << "\n";
    }
}
void enter_push(bool array[][12])
{
    char g('0');
    int origin_pilar(-1), origin_line(-1), end_pilar(-1), end_line(-1);
    while ((origin_pilar < 0 || origin_pilar > 11) || (origin_line < 0 || origin_line > 11))
    {
        cout << "Enter the coordinate from which to start popping bubbles:";
        cin >> g >> origin_pilar;
        origin_line = g - 'A';
        origin_pilar -= 1;
    }
    while ((end_pilar < 0 || origin_pilar > 11) || (end_line < 0 || end_line > 11))
    {
        cout << "Enter the coordinate at which to end:";
        cin >> g >> end_pilar;
        end_line = g - 'A';
        end_pilar -= 1;
    }
     push(array, origin_pilar, origin_line, end_pilar, end_line);
}
void push(bool arr[][12], int origin_p, int origin_l, int end_p, int end_l)
{
    for (int i = 0; i < 12; ++i)
    {
        for (int j = 0; j < 12; ++j)
        {
            if ((i >= origin_p && i <= end_p) && (j >= origin_l && j <= end_l))
                arr[i][j] = false;
        }
    }
}
int main()
{
    bool pimply[12][12];
    pimply_initialization(pimply);
    status_pimply(pimply);
    enter_push(pimply);
    // status_pimply(pimply);
}
