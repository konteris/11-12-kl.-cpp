#include <iostream>

using namespace std;
// Pirma pamoka apie templates ir STL sablonu biblioteka.
template <typename T>
T suma(T x, T y)
{
    return x+y;
}

template <typename T, typename Tresult> //typename gali but ir skaiciai
Tresult Avg(T a, T b)
{
    return (a+b)/(Tresult)2;

}
// int suma(int x, int y)
// {
//     return x+y;
// }

int main()
{
    cout<<suma<float>(6.6,9.2)<<endl;
    cout<<Avg<int, float>(8,9);
    return 0;
}