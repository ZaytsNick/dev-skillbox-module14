#include <iostream>
#include <math.h>
using namespace std;
void conclusion_battlefield(char field[][3])
{
    cout << "  1 2 3" << endl;
    for (int i = 0; i < 3; ++i)
    {
        cout << (char)(i + 'A') << " ";
        for (int j = 0; j < 3; ++j)
        {
            cout << field[i][j] << " ";
        }
        cout << "\n";
    }
}
bool examination(char field[][3], char gamer_name, int i, int j)
{
    
    for (int k = 1; k < 3; ++k)
    {
        int condition1(1), condition2(1), condition3(1),condition4(1);
        if (field[i][(j + k) % 3] == gamer_name)
        {
            condition1++;
            if (condition1 == 3)
                return true;
        }
        if (field[(i + k) % 3][j] == gamer_name)
        {
            condition2++;
            if (condition2 == 3)
                return true;
        }
        if ((((j + k) % 3 + (i + k) % 3) % 2 == 0) && field[(i + k) % 3][(j + k) % 3] == gamer_name)
        {
            condition3++;
            if (condition3 == 3)
                return true;
        }
        if (((abs((j - k)) % 3 + abs(i - k) % 3) % 2 == 0) && field[abs(i - k) % 3][abs(j - k) % 3] == gamer_name)
        {
            condition4++;
            if (condition4 == 3)
                return true;
        }
    }
    return false;
}
bool Enter_symbol(char field[][3], char gamer_name)
{
    char g('D');
    int pilar(0), line;
    while (true)
    {
        cout << "Player " << gamer_name << "\nEnter coordinates separated by spaces (example: A 1):";
        cin >> g >> pilar;
        line = g - 'A';
        pilar -= 1;
        if (((pilar >= 0 && pilar <= 2) && (g >= 'A' && g <= 'C')) && field[line][pilar] == ' ')
        {
            field[line][pilar] = gamer_name;
            break;
        }
    }
    if (examination(field, gamer_name, line, pilar))
    {

        conclusion_battlefield(field);
        cout << "Player " << gamer_name << " winner!!!";
        return true;
    }
    else
        return false;
}

int main()
{
    bool presenceOfWinner(false);
    char gamer_name;
    char battlefield[3][3]{{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    for (int i = 0; i < 9; ++i)
    {
        conclusion_battlefield(battlefield);
        if (i % 2 == 0)
            gamer_name = 'X';
        else
            gamer_name = 'O';
        presenceOfWinner = Enter_symbol(battlefield, gamer_name);
        if (presenceOfWinner)
            break;
    }
    if (!presenceOfWinner)
    {
        conclusion_battlefield(battlefield);
        cout << "DRAW";
    }
}