#include <iostream>
#include <fstream>

using namespace std;

struct zmogus
{
    string pavarde, vardas;
    string lytis;
    int y, m, d;
    int t;
};

zmogus Z[1000]; //pradinis
zmogus Z1[1000]; //papildomas, kur kaupiu t
zmogus ZB[1000]; // berniuku
zmogus ZM[1000]; // mergaiciu
int n;

void skaitymas(int &b, int &me, int M[]);
int tas_pats(string ieskomas_vardas, zmogus X[]);
void atrinkimas();
void rikiavimas();
void atskyrimas(int &v, int &m);
int daugiausiai(zmogus Y[]);
void rasymas(int b, int me, int M[], int v, int m);

int main()
{
    int b=0,me=0, v, m, M[13];
    skaitymas(b,me, M);
    atrinkimas();
    rikiavimas();
    atskyrimas(v,m);
    rasymas(b,me,M,v,m);
    return 0;
}

void skaitymas(int &b, int &me, int M[])
{
    ifstream in("Duom.txt");
    in>>n;

    for(int i=0; i<13; i++)
        M[i] = 0;

    for(int i=0; i<n; i++)
    {
        in>>Z[i].pavarde>>Z[i].vardas>>Z[i].lytis>>Z[i].y>>Z[i].m>>Z[i].d;
        M[Z[i].m]++;
        Z[i].t = 0;
        if(Z[i].lytis == "v")
            b++;
        else
            me++;
    }
    in.close();
}

int tas_pats(string ieskomas_vardas, zmogus X[])
{
    for(int i=0; i<n; i++)
    {
        if(X[i].vardas == ieskomas_vardas)
            return i;
    }
    return -1;
}

void atrinkimas()
{
    for(int i=0; i<n; i++)
    {
        Z1[i] = Z[i];
    }

    for(int i=0; i<n; i++)
    {
        int t = tas_pats(Z[i].vardas, Z1);

        if(t != -1)
            Z1[t].t++;
    }
}

void rikiavimas()
{
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(Z1[i].vardas > Z1[j].vardas)
                swap(Z1[i], Z1[j]);
}

void atskyrimas(int &v, int &m)
{
    v=0;
    for(int i=0; i<n; i++)
    {
        if(Z1[i].lytis == "v")
        {
            ZB[v]=Z1[i];
            v++;
        }
    }

    m=0;
    for(int i=0; i<n; i++)
    {
        if(Z1[i].lytis == "m")
        {
            ZM[m]=Z1[i];
            m++;
        }
    }
}

int daugiausiai(zmogus Y[])
{
    int d=0;

    for(int i=0; i<n; i++)
    {
        if(Y[i].t > Y[d].t)
            d=i;
    }
    return Y[d].t;
}

void rasymas(int b, int me, int M[], int v, int m)
{
    ofstream out("Rez.txt");

    out<<"Berniukai: "<<b<<endl;
    int d1 = daugiausiai(ZB);
    for(int i=0; i<v; i++)
    {
        if(ZB[i].t == d1)
            out<<ZB[i].vardas<<endl;
    }
    if(v == 0)
        out<<"Vardo nera"<<endl;

    //----------------------------------------

    out<<"Mergaites: "<<me<<endl;
    int d2 = daugiausiai(ZM);
    for(int i=0; i<m; i++)
    {
        if(ZM[i].t == d2)
            out<<ZM[i].vardas<<endl;
    }
    if(m == 0)
        out<<"Vardo nera"<<endl;

    for(int i=1; i<13; i++)
        out<<i<<" "<<M[i]<<endl;

    out.close();
}
