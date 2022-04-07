#include <iostream>
#include <fstream>

using namespace std;

struct Patiekalas{
    string pavadinimas;
    int produktai[10];
    int kaina;
};
Patiekalas P[12];

void Skaitymas(int &n, int &p, int kainos[]);
int patiekalo_kaina(int X[], int Y[], int n);
int suma(int x);
void Rasymas(int n, int p, int kainos[]);

int main()
{
    int n, p, kainos[10];
    Skaitymas(n,p,kainos);
    Rasymas(n,p, kainos);
    return 0;
}

void Skaitymas(int &n, int &p, int kainos[])
{
    ifstream in("U2.txt");

    in>>n>>p;
    for(int i=0;i<n;i++)
        in>>kainos[i];
    char X[16];

    for(int i=0;i<p;i++)
    {
        in>>ws;
        in.get(X,16);
        P[i].pavadinimas = X;
        for(int j=0;j<n;j++)
            in>>P[i].produktai[j];
    }
    in.close();
}

int patiekalo_kaina(int X[], int Y[], int n)
{
    int kaina_p=0;
    for(int i=0;i<n;i++)
    {
        kaina_p += X[i]*Y[i];
    }
    return kaina_p;
}
int suma(int x)
{
    int sum=0;
    for(int i=0;i<x;i++)
        sum+=P[i].kaina;
    return sum;
}
void Rasymas(int n, int p, int kainos[])
{
    ofstream out("U2rez.txt");

    for(int i=0;i<p;i++)
    {
        P[i].kaina = patiekalo_kaina(P[i].produktai, kainos, n);
        out<<P[i].pavadinimas<<P[i].kaina<<endl;
    }
    int vieno_kaina = suma(p);
    out<<vieno_kaina/100<<" "<<vieno_kaina%100<<endl;
    out.close();
}