#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct Slidininkas{
    string zmogus;
    int s, sk;

};

void Skaitymas(int n, int &m);
void Rikiavimas(int m);
void Rasymas(int m);

Slidininkas S[30];
Slidininkas FS[30];


int main()
{
    int n,m;
    Skaitymas(n,m);
    Rikiavimas(m);
    Rasymas(m);
    return 0;
}

void Skaitymas(int n, int &m)
{
    int h,mi,sec, h2,mi2,sec2;
    ifstream in("U2.txt");
    char Z[21];
    char FZ[21];
    in>>n;

    for(int i=0; i<n; i++)
    {
        in>>ws;
        in.get(Z,21);
        S[i].zmogus = Z;

        in>>h>>mi>>sec;
        S[i].s = h*3600 + mi*60 +sec;
    }
    in>>m;
    for(int i=0; i<m; i++)
    {
        in>>ws;
        in.get(FZ, 21);
        FS[i].zmogus = FZ;

        in>>h2>>mi2>>sec2;
        FS[i].s = h2*3600 + mi2*60 + sec2;

        for(int j=0; j<n; j++)
        {
            if(FS[i].zmogus == S[j].zmogus)
            {
                FS[i].sk = FS[i].s - S[j].s;
            }
        }
    }
    in.close();
}

void Rikiavimas(int m)
{
    for(int i=0; i< m-1; i++)
        for(int j=i+1; j<m; j++)
            if(FS[i].sk>FS[j].sk || FS[i].sk == FS[j].sk && FS[i].zmogus>FS[j].zmogus)
                swap(FS[i],FS[j]);
}

void Rasymas(int m)
{
    ofstream out("U2rez.txt");
    for(int i=0; i<m; i++)
    {
        if(FS[i].sk<=3600)
            out<<setw(20)<<FS[i].zmogus<<FS[i].sk / 60<<" "<<FS[i].sk % 60<<endl;
    }
    out.close();
}
