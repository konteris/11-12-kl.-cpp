#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void Skaityti(int &n, int T[], int K[]);

int Suma(int x, int X[]);

int Dvigubi(int n, int T[], int K[]);

void Rasyti(int n, int T[], int K[], double vidT, double vidK );

int main()
{
    int n;

    int T[50], K[50];

    Skaityti(n,  T, K);

    double vidT = double(Suma(n, T))/n;
    double vidK =double(Suma(n, K))/n;

    Rasyti(n,T,K,vidT,vidK);

    return 0;
}

void Skaityti(int &n, int T[], int K[])
{
    ifstream in ("statistika.txt");
    in>>n;
    for(int x=0; x<n; x++)
    {
        in>>T[x]>>K[x];
    }
    in.close();
}

int Suma(int x, int X[])
{
    int sum=0;

    for(int i=0; i<x; i++)
    {
        sum+=X[i];
    }
    return sum;
}

int Dvigubi(int n, int T[], int K[])
{
    int k=0;
    for(int x=0; x<n; x++)
    {
        if(T[x]>9 && K[x]>9)
            k++;
    }
    return k;
}

void Rasyti(int n, int T[], int K[], double vidT, double vidK )
{
    ofstream out("rezultatai.txt");

    out<<Suma(n, T)<<" "<<Suma(n, K)<<endl;
    out<<fixed<<setprecision(1)<<vidT<<" "<<vidK<<endl;
    out<<Dvigubi(n,T,K);

    out.close();
}
