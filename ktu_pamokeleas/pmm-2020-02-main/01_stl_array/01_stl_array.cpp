// 01_stl_array.cpp
//

#include <iostream>
#include <array> //nepamirštam

using namespace std;


//void Print(array<int, 3> data) {
//    for (int i = 0; i < data.size(); i++)
//    {
//        cout << data[i] << endl;
//    }
//}
//kas keista? kaip spręsti?
//o kas dar?

int main()
{
    const int SIZE = 3;

    array<int, SIZE> data;

    data[0] = 2020;
    data[1] = 11;
    data[2] = 28;

    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << endl;
    }

    for (int d : data) //iteratorius, 3 paskaitos tema
    {
        cout << d << endl;
    }

    //Print(data);
}