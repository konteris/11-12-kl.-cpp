#include <iostream>
#include<fstream>
using namespace std;

struct Zaidejas{
    string vardas, komanda;
    int taskai, kiek=1;
};

Zaidejas Z[10];
Zaidejas Z1[10];

void Skaitymas();
int yra(string ieskoma_komanda, Zaidejas Z1[], int n);
void Atrinkimas(int &n, Zaidejas Z1[]);
void Rikiavimas(int n, Zaidejas Z1[]);
void Rasymas(int n, Zaidejas Z1[]);

int main()
{
    int n;
    Skaitymas();
    Atrinkimas(n, Z1);
    Rikiavimas(n,Z1);
    Rasymas(n,Z1);
    return 0;
}
void Skaitymas()
{
    ifstream in("U1.txt");
    char X[21], Y[17];
    for(int i=0; i<10;i++)
    {
        in>>ws;
        in.get(X,21);
        Z[i].vardas = X;
        in.get(Y,17);
        Z[i].komanda = Y;
        in>>Z[i].taskai;
    }
    in.close();
}

int yra(string ieskoma_komanda, Zaidejas Z1[], int n)
{
    for(int i=0; i<n;i++)
    {
        if(ieskoma_komanda == Z1[i].komanda)
            return i;
    }
    return -1;
}
void Atrinkimas(int &n, Zaidejas Z1[])
{
    n=0;
    for(int i=0;i<10;i++)
    {
        int t = yra(Z[i].komanda, Z1, n);
        if(t==-1)
        {
            Z1[n].komanda=Z[i].komanda;
            Z1[n].vardas=Z[i].vardas;
            Z1[n].taskai=Z[i].taskai;
            n++;
        }
        else
        {
            if(Z1[t].taskai < Z[i].taskai)
                Z1[t].taskai=Z[i].taskai;
            Z1[t].kiek++;
        }
    }
}

void Rikiavimas(int n, Zaidejas Z1[])
{
    for(int i=0;i<n-1;i++)
        for(int j=i;j<n;j++)
            if(Z1[i].kiek < Z1[j].kiek || Z1[i].kiek==Z1[j].kiek && Z1[i].komanda>Z1[j].komanda)
                swap(Z1[i],Z1[j]);
}

void Rasymas(int n, Zaidejas Z1[])
{
    ofstream out("U1rez.txt");

    out<<n<<endl;
    for(int i=0; i<n;i++)
    {
        out<<Z1[i].komanda<<" "<<Z1[i].kiek<<" "<<Z1[i].vardas<<endl;
    }

    out.close();
}