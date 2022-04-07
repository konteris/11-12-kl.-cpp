// 02_stl_vector.cpp
//

#include <iostream>
#include <vector> //nepamirštam

using namespace std;

void Print(const vector<int>& data) {
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << endl;
    }
}

int main()
{
    vector<int> data; //"vector" kitose kalbose - list, arraylist

    data.push_back(2020); //"push_back" kitose kalbose - add
    data.push_back(11);
    data.push_back(27);

    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << endl;
    }

    data[2] = 28; //jei esam tikri kad toks elementas jau yra

    for (int d : data) //iteratorius, 3 paskaitos tema
    {
        cout << d << endl;
    }

    Print(data);
}