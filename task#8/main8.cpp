#include <iostream>
#include <math.h>
using namespace std;
void status_field(bool field[][10])
{
    cout << "     ";
    for (int i = 0; i < 10; ++i)
    {
        cout << i + 1 << " ";
    }
    cout << "\n"
         << endl;
    for (int i = 0; i < 10; ++i)
    {
        cout << (char)(i + 'A') << "    ";
        for (int j = 0; j < 10; ++j)
        {
            if (field[i][j])
                cout << "# ";
            else
                cout << "~ ";
        }
        cout << "\n";
    }
}
bool installation_warship(bool arr[][10], int origin_p, int origin_l, int end_p, int end_l)
{
    for (int i = origin_l; i <= end_l; ++i)
    {
        for (int j = origin_p; j <= end_p; ++j)
        {
            if (arr[i][j])
                return false;
        }
    }
    for (int i = origin_l; i <= end_l; ++i)
    {
        for (int j = origin_p; j <= end_p; ++j)
        {
            arr[i][j] = 1;
        }
    }
    return true;
}
void enter_warship(bool arr[][10])
{
    for (int number_warhip = 0; number_warhip < 10;)
    {
        char g('0');
        int origin_pilar(-1), origin_line(-1), end_pilar(-2), end_line(-2);
        while ((origin_line != end_line || origin_pilar != end_pilar))
        {
            status_field(arr);
            while ((origin_pilar < 0 || origin_pilar > 9) || (origin_line < 0 || origin_line > 9))
            {
                cout << "Enter the coordinate from which warship:";
                cin >> g >> origin_pilar;
                origin_line = g - 'A';
                origin_pilar -= 1;
            }
            if (number_warhip > 3)
            {
                while ((end_pilar < 0 || end_pilar > 9) || (end_line < 0 || end_line > 9))
                {
                    cout << "Enter the coordinate at which to end:";
                    cin >> g >> end_pilar;
                    end_line = g - 'A';
                    end_pilar -= 1;
                    if (number_warhip < 7 && ((abs(origin_line - end_line) == 1 - abs(origin_pilar - end_pilar) == 1) == 1))
                    {
                        if (origin_line > end_line || origin_pilar > end_pilar)
                        {
                            swap(origin_line, end_line);
                            swap(origin_pilar, end_pilar);
                        }
                    }
                    else if ((number_warhip > 6 && number_warhip < 9) && (abs((abs(origin_line - end_line) == 2) - (abs(origin_pilar - end_pilar) == 2)) == 1))
                    {
                        if (origin_line > end_line || origin_pilar > end_pilar)
                        {
                            swap(origin_line, end_line);
                            swap(origin_pilar, end_pilar);
                        }
                    }
                    else if (number_warhip == 9 && (abs((abs(origin_line - end_line) == 3) - (abs(origin_pilar - end_pilar) == 3))) == 1)
                    {
                        if (origin_line > end_line || origin_pilar > end_pilar)
                        {
                            swap(origin_line, end_line);
                            swap(origin_pilar, end_pilar);
                        }
                    }
                    else
                    {
                        end_line = -2;
                        end_pilar = -2;
                    }
                }
            }
            else
            {
                end_line = origin_line;
                end_pilar = origin_pilar;
            }
            if (installation_warship(arr, origin_pilar, origin_line, end_pilar, end_line))
            {

                ++number_warhip;
                if (number_warhip == 10)
                {
                    break;
                }
                origin_line = -1;
                origin_pilar = -1;
                end_line = -2;
                end_pilar = -2;
            }
            else
            {
                origin_line = -1;
                origin_pilar = -1;
                end_line = -2;
                end_pilar = -2;
            }
        }
    }
}
void cin_array(bool array[][10])
{
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            array[i][j] = 0;
        }
    }
}
bool examination(bool field[][10])
{
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            if (field[i][j] == 1)
                return true;
        }
    }
    return false;
}
bool attack(bool field[][10])
{
    bool move(true);
    while (move)
    {
        char g('0');
        int pilar(-1), line(-1);
        while ((pilar < 0 || pilar > 9) || (line < 0 || line > 9))
        {
            cout << "Enter attack coordinates warship:";
            cin >> g >> pilar;
            line = g - 'A';
            pilar -= 1;
        }
        if (field[line][pilar])
        {
            field[line][pilar] = false;
        }
        else
        {
            move = false;
        }

        if (!examination(field))
        {

            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}
int main()
{
    bool field_1[10][10], field_2[10][10];
    cin_array(field_1);
    cin_array(field_2);
    enter_warship(field_1);
    enter_warship(field_2);
    while (true)
    {
        cout << "Player #1\nYour warships:" << endl;
        status_field(field_1);
        if (attack(field_2))
            cout << "Player #1 wins!";

        cout << "Player #2\nYour warships:" << endl;
        status_field(field_2);

        if (attack(field_1))
            cout << "Player #1 wins!";
    }
}