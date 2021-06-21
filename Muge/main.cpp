#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void skaitymas(int Masyvas[], int &n);

int suma(int Masyvas[], int &n);

int kiekis(int Masyvas[], int &n);

double vidurkis(int sk, int &n);

int main()
{
    int Masyvas[50];

    int n;

    skaitymas(Masyvas,n);

    ofstream out("mugerez.txt");

    out<<suma(Masyvas, n)<<endl;
    out<<kiekis(Masyvas,n)<<endl;
    out<<fixed<<setprecision(1)<<vidurkis(suma(Masyvas,n),n);

    out.close();
    return 0;
}

void skaitymas(int Masyvas[], int &n)
{
    ifstream in ("muge.txt");
    in>>n;
    for(int x=0; x<n; x++)
    {
        in>>Masyvas[x];
    }
    in.close();
}

int suma(int Masyvas[], int &n)
{
    int sum=0;

    for(int x=0; x<n; x++)
    {
        sum+=Masyvas[x];
    }
    return sum;
}

int kiekis(int Masyvas[], int &n)
{
    int k = 0;
    for(int x=0; x<n; x++)
    {
        if(Masyvas[x]>50)
            k++;
    }
    return k;
}


double vidurkis(int sk, int &n)
{
    double y = double(sk) / n;
    return y;
}
