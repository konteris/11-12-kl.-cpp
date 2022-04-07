// 04_our_array_with_template.cpp
//

#include <iostream>

using namespace std;

template<typename T, size_t S>
class Array
{
private:
    T myData[S];

public:
    constexpr size_t Size() const { return S; }

    T& operator[](size_t index) { return myData[index]; }
    const T& operator[](size_t index) const { return myData[index]; }

    T* Data() { return myData;  }
    const T* Data() const { return myData; }
};

template<typename T, size_t S>
void Print(const Array<T, S>& data) {
    for (size_t i = 0; i < data.Size(); i++)
    {
        cout << data[i] << endl;
    }
}

int main()
{
    Array<int, 3> data;

    data[0] = 2020;
    data[1] = 11;
    data[2] = 28;

    for (size_t i = 0; i < data.Size(); i++)
    {
        cout << data[i] << endl;
    }

    Print(data);
}