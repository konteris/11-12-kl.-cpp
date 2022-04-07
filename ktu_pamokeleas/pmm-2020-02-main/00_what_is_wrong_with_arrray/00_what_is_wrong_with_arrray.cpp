// 00_what_is_wrong_with_arrray.cpp
//

#include <iostream>

using namespace std;

void Print(int* data, int size) {
    for (int i = 0; i < size; i++)
    {
        cout << data[i] << endl;
    }
}

int main()
{
    const int SIZE = 3;

    int data[SIZE];

    data[0] = 2020;
    data[1] = 11;
    data[2] = 28;

    for (int i = 0; i < SIZE; i++)
    {
        cout << data[i] << endl;
    }

    Print(data, SIZE);
}

//kokie trūkumai?