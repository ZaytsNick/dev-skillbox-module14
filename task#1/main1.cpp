#include <iostream>
using namespace std;
template <typename S>
int sum[6][2](S a[][2], S b[][2])
{
    int summ[6][2]
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            summ[i][j]=a[i][j]+b[i][j];
        }
    }
}

template <typename T>
void write_array(T array[][2])
{
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            cout << array[i][j] << " ";
        }
        cout << "\n";
    }
}
int main()
{

    // int devices [6][2]={{4,4},{3,3},{3,3},{3,3},{3,3},{3,3}};
    bool fork[6][2]{{1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}};
    bool spoon[6][2]{{1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}};
    bool knife[6][2]{{1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}};
    bool small_spoon[6][2]{{1, 1}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}};

    int dishes[6][2] = {
        {3, 3},
        {2, 2},
        {2, 2},
        {2, 2},
        {2, 2},
        {2, 2},
    };
    int chairs[6][2] = {
        {1, 1},
        {1, 1},
        {1, 1},
        {1, 1},
        {1, 1},
        {1, 1},
    };

    // Пришедшая на пятое место первого ряда дама привела с собой ребёнка, и поэтому на данное место был приставлен ещё один стул.
    chairs[4][0]++;
    // С третьего места во втором ряду в неизвестном направлении была украдена ложка.
    spoon[2][1] = false;
    // Одна из VIP-персон (любая) поделилась своей ложкой с тем, кто остался без ложки, и стала есть суп десертной.
    small_spoon[0][1] = false;
    small_spoon[2][1] = true;
    // За ненадобностью официант забрал у VIP-гостя одну десертную тарелку, ведь есть десерт ложкой, которая уже побывала уже в супе, неприлично.
    dishes[0][1]--;
     int devices[6][2]=sum((sum((int)fork,(int)spoon)),(sum((int)nife,(int)small_spoon)));
    cout << "No more accidents\nCutlery for visitors:\n";
    write_array(devices);
    cout << "\nPlates of cutlery for visitors:\n";
    write_array(dishes);
    cout << "\nChairs for visitors:\n";
    write_array(chairs);
}