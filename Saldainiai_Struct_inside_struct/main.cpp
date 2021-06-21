#include <iostream>
#include <fstream>

using namespace std;

struct saldainiai
{
    int m;
    string pav[11]; // pavadinimai
    int p[11]; // kuri saldaini megsta visi mokiniai
};

struct mokinys
{
    saldainiai S;
};
mokinys M[30];

string x[11];
int y[11];

void skaitymas(int &n);
int tas_pats(string ieskomas_saldainis, int a);
void atrinkimas(int &a, int n);
void rasymas(int n, int a);

int main()
{
    int n,a;
    skaitymas(n);
    atrinkimas(a,n);
    rasymas(n,a);
    return 0;
}

void skaitymas(int &n)
{
    ifstream in("U2.txt");
    char Z[21];

    in>>n;

    for(int i=0; i<n; i++)
    {
        in>>M[i].S.m;
        for(int j=0; j<M[i].S.m; j++)
        {

            in>>ws;
            in.get(Z,21);

            M[i].S.pav[j] = Z;
            M[i].S.p[j] = 1;
        }
    }
    in.close();
}

int tas_pats(string ieskomas_saldainis, int a)
{
    for(int i=0; i<a; i++)
    {
        if(x[i] == ieskomas_saldainis)
            return i;
    }
    return -1;

}

void atrinkimas(int &a, int n)
{
    a=0;
    for(int i=0; i<=30; i++)
        y[i]=1;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<M[i].S.m; j++)
        {
            int t = tas_pats(M[i].S.pav[j], a);
            if(t == -1)
            {
                x[a] = M[i].S.pav[j];
                a++;
            }
            else
            {
                y[t] += M[i].S.p[j]; //jeigu pavadinimai vienodi tai tam saldainiui pridedu +1;
            }
        }
    }
}

void rasymas(int n, int a)
{
    ofstream out("rez.txt");
    int k=0;
    out<<"1. Saldainiu rusiu yra: "<<a<<endl;
    out<<"2. Visi mokiniai megsta:"<<endl;
    for(int i=0; i<a; i++)
    {
        if(y[i] == n)
        {
            out<<x[i]<<endl;
            k++;
        }
    }

    if(k==0)
        out<<"Nera";
    out.close();
}
