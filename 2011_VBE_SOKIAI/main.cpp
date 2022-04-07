#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct Pora{
    string vardas;
    int tech[10], art[10];
    int viso_balu;
};

Pora P[100];
int n,k;

void Skaitymas();
void Rikiavimas(int X[], int x);
int Vienas_rinkinys(int X[], int x);
void Rikiavimas1();
void Rasymas();

int main()
{
    Skaitymas();
    for(int i=0;i<n;i++)
    {
        int t = Vienas_rinkinys(P[i].tech, k);
        int a = Vienas_rinkinys(P[i].art, k);
        P[i].viso_balu = a+t;
    }
    Rikiavimas1();

    ofstream out("U2rez.txt");
    for(int i=0;i<n;i++)
    {
        out<<left<<setw(20)<<P[i].vardas<<" "<<P[i].viso_balu<<endl;
    }
    out.close();

    return 0;
}
void Skaitymas()
{
    ifstream in("U2.txt");
    in>>n>>k;
    char X[21];
    for(int i=0;i<n;i++)
    {
        in>>ws;
        in.get(X,21);
        P[i].vardas = X;
        for(int j=0;j<k;j++)
        {
            in>>P[i].tech[j];
        }
        for(int ll=0;ll<k;ll++)
        {
            in>>P[i].art[ll];
        }
    }
    in.close();
}

void Rikiavimas(int X[], int x)
{
    for(int i=0; i<x-1;i++)
        for(int j=i+1;j<x;j++)
            if(X[i]>X[j])
                swap(X[i], X[j]);
}

int Vienas_rinkinys(int X[], int x)
{
   int balsai=0;
   Rikiavimas(X,k);
    for(int i=1;i<k-1;i++)
    {
        balsai+=X[i];
    }
    return balsai;
}

void Rikiavimas1()
{
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(P[i].viso_balu < P[j].viso_balu)
                swap(P[i],P[j]);
}