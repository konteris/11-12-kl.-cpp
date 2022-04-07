#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct Begikas{
    string vardas;
    int laikas;
};
struct Grupes{
    int begiku_skc;
    Begikas B[50];
};

Grupes G[25];
Begikas B1[25];
int k;

void Skaitymas();
void Atrinkimas(int &a);
void Rikiavimas();
void Rikiavimas1(int a);
void Rasymas(int a);

int main()
{
    int a;
    Skaitymas();
    Rikiavimas();
    Atrinkimas(a);
    Rikiavimas1(a);
    Rasymas(a);
    return 0;
}
void Skaitymas()
{
    ifstream in("U2.txt");
    in>>k;
    char X[21];
    for(int i=0;i<k;i++)
    {
        in>>ws;
        in>>G[i].begiku_skc;
        for(int j=0;j<G[i].begiku_skc; j++)
        {
            in>>ws;
            in.get(X,21);
            G[i].B[j].vardas = X;
            int min, sec;
            in>>min>>sec;
            G[i].B[j].laikas = min*60 + sec;
        }
    }
    in.close();
}

void Rikiavimas()
{
    for(int i=0;i<k;i++) //labai sudetinga su tuo rikiavimas
    {
        for(int j=0; j<G[i].begiku_skc - 1; j++)
        {
            for(int k=j+1; k<G[i].begiku_skc;k++)
            {
                if(G[i].B[j].laikas > G[i].B[k].laikas)
                    swap(G[i].B[j], G[i].B[k]);
            }
        }
    }
}

void Atrinkimas(int &a)
{
    a=0;
    for(int i=0;i<k;i++)
    {
        //if(G[i].begiku_skc%2 == 0 )
        for(int j=0; j < G[i].begiku_skc/2 ; j++)
        {
            B1[a].laikas = G[i].B[j].laikas;
            B1[a].vardas = G[i].B[j].vardas;
            a++;
        }
    }

}
void Rikiavimas1(int a)
{
    for(int i=0;i<a-1;i++)
        for(int j=i+1;j<a;j++)
            if(B1[i].laikas>B1[j].laikas)
                swap(B1[i], B1[j]);
}

void Rasymas(int a)
{
    ofstream out("U2rez.txt");

    for(int i=0;i<a;i++)
        out<<B1[i].vardas<<B1[i].laikas/60<<" "<<B1[i].laikas%60<<endl;

    out.close();
}