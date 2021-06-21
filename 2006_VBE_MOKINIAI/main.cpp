#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

struct Mokinys{
    string vardas, pavarde;
    int P[15];
    double vid;

};
int n;

Mokinys M[20];

void Skaitymas(double &v, int p);
double Vidurkis(int X[], int x);
void Pirmunai(int &k, double v);
void Rasymas(int k);

int main()
{
    int k,p;
    double v;
    Skaitymas(v,p);
    Pirmunai(k,v);
    Rasymas(k);
    return 0;
}

void Skaitymas(double &v, int p)
{
    ifstream in("Duom2.txt");

    in>>n>>p>>v;

    for(int i=0; i<n; i++)
    {
        in>>M[i].vardas >> M[i].pavarde;
        for(int j=0; j<p; j++)
        {
            in>>M[i].P[j];
        }
        M[i].vid = Vidurkis(M[i].P, p);
    }

    in.close();
}

double Vidurkis(int X[], int x)
{
    double suma=0, vidurkis;

    for(int i=0; i<x; i++)
        suma+=X[i];

    if(x>0)
        vidurkis =suma/x;
    else
        vidurkis=0;

    return vidurkis;
}

void Pirmunai(int &k, double v)
{
    k=0;
    for(int i=0; i<n; i++)
    {
        if(M[i].vid >= v)
            k++;
    }
}

void Rasymas(int k)
{
    ofstream out("Rez2.txt");

    for(int i=0; i<n; i++)
    {

        out<<M[i].vardas<<" "<<M[i].pavarde<<" ";
        out<<fixed<<setprecision(1)<<M[i].vid<<endl;
    }

    out<<k<<endl;
    out.close();
}
