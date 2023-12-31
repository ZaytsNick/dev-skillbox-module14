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
void push(bool arr[][12], int origin_p, int origin_l, int end_p, int end_l)
{
    for (int i = origin_l; i <= end_l; ++i)
    {
        for (int j = origin_p; j <= end_p; ++j)
        {
            if (arr[i][j])
            {
                arr[i][j] = false;
                cout << "Pop!";
            }
        }
    }
    cout <<"\n"<< endl;
}
bool checking_the_bump(bool arr[][12])
{
    for (int i = 0; i < 12; ++i)
    {
        for (int j = 0; j < 12; ++j)
        {
            if (arr[i][j])
                return true;
        }
    }
    return false;
}
void enter_push(bool arr[][12])
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
    while ((end_pilar < 0 || end_pilar > 11) || (end_line < 0 || end_line > 11))
    {
        cout << "Enter the coordinate at which to end:";
        cin >> g >> end_pilar;
        end_line = g - 'A';
        end_pilar -= 1;
    }
    push(arr, origin_pilar, origin_line, end_pilar, end_line);
}

int main()
{
    bool pimply[12][12];
    pimply_initialization(pimply);

    while (checking_the_bump(pimply))
    {
        status_pimply(pimply);
        enter_push(pimply);
    }
    cout << "The bubble wrap is over";
}
