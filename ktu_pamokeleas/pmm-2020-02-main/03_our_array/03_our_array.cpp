// 03_our_array.cpp 
//

#include <iostream>
#include <algorithm>

using namespace std;

class Array3Int
{
private:
    int myData[3];

public:
    int Size() const { return 3;  }

    int operator[](int index) { return myData[index]; }
};

int main()
{
    Array3Int data;

    //data[0] = 2020; //kodėl?
    //data[1] = 11;
    //data[2] = 28;

    for (int i = 0; i < data.Size(); i++)
    {
        cout << data[i] << endl;
    }

    //int test[data.Size()]; //ką daryt?
}

//template
//size_t vietoj int
//Size() metodas grąžina konstantą