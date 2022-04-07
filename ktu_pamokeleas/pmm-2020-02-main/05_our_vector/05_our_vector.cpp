// 05_our_vector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

template<typename T>
class Vector
{
private:
    T* myData = new T[2]; //namų darbe - nullptr;
    size_t mySize = 0;
    size_t myCapacity = 0;

    void EnsureCapacity(size_t newCapacity) {
        //TODO NAMŲ DARBAS (2) - realizuoti. Laikome, kad tik didinam.
        //2.1. Sukurti naują masyvą, dvigubai didesnės talpos
        //2.2. Perkelti senus elementus į naują masyvą
        //2.3. Išvalom seną masyvą
        //2.4. Priskiriam naujas reikšmes 
    }

public:
    Vector() {
        EnsureCapacity(2);
    }

    constexpr size_t Size() const { return mySize; }

    T& operator[](size_t index) { return myData[index]; }
    const T& operator[](size_t index) const { return myData[index]; }

    T* Data() { return myData; }
    const T* Data() const { return myData; }

    void PushBack(const T& value) {
        //TODO NAMŲ DARBAS (1) - reikia patikrinti, ar užtenka talpos
        myData[mySize++] = value;
    }
};

template<typename T>
void Print(const Vector<T>& data) {
    for (size_t i = 0; i < data.Size(); i++)
    {
        cout << data[i] << endl;
    }
}

int main()
{
    Vector<int> data;

    data.PushBack(2020);
    data.PushBack(11);
    data.PushBack(27);

    for (size_t i = 0; i < data.Size(); i++)
    {
        cout << data[i] << endl;
    }

    data[2] = 28;

    Print(data);
}
