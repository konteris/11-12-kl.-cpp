#include <iostream>
#include <array>

using namespace std;

template<int T>
void Print(array<int,T> x) { //bet nepatogu tuos 3 pasuot todel naudojam template; &-paiima vieta, o ne kopija
   for (int i = 0; i < x.size(); i++)
   {
       cout << x[i] << endl;
   }
}

int main()
{
    const int SIZE = 3;

    array<int, SIZE> data;
    
    data[0] = 2020;
    data[1] = 11;
    data[2] = 28;

    for (int i = 0; i < data.size(); i++) //.size() metodas 
    {
        cout << data[i] << endl;
    }

    for (int d : data) //iteruojam
    {
        cout << d << endl;
    }
    //Print<int>(data);
    return 0;
}
