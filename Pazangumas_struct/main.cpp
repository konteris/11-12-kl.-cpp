#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

struct Studentas
{
    string vardas, pavarde;
    int p, P[20]; // p -kiek kartu;  P - pazymiai
    double vid;
};

Studentas S[100];

int n;

void Skaitymas();
void Rikiavimas();
double GrazintiStudentoVidurki(int X[], int x);
void Rasymas();

int main()
{
    Skaitymas();
    Rikiavimas();
    Rasymas();
    return 0;
}

void Skaitymas()
{
    ifstream in("duom.txt");
    in>>n;

    for(int i = 0; i < n; i++)
    {
        in>> S[i].vardas >> S[i].pavarde >>S[i].p;

        for(int j = 0; j < S[i].p; j++)
            in>>S[i].P[j];
        S[i].vid =  GrazintiStudentoVidurki(S[i].P, S[i].p);
    }
    in.close();
}

double GrazintiStudentoVidurki(int X[], int x)
{
    double suma=0, vidurkis;

    for(int j = 0; j < x; j++)
    {
        suma += X[j];
    }
    if(x>0)
        vidurkis =suma/x;
    else
        vidurkis=0;

    return vidurkis;
}

void Rikiavimas()
{
    for(int i=0; i<n-1; i++)
    {
        int m=i; //papildomas kintamasis
        Studentas st;
        for(int j=i+1; j<n; j++)
            if(S[m].vid > S[j].vid)
                m=j;
        st = S[m];
        for(int x=m; x>i; x--)
            S[x] = S[x-1];
        S[i]=st;
    }
}

void Rasymas()
{
    ofstream out("rez.txt");

    for(int i = 0; i < n; i++)
    {
        out.width(10);
        out<<left<<S[i].vardas;
        out.width(15);
        out<<left<<S[i].pavarde<<" "<<fixed<<setprecision(2)<<S[i].vid<<endl;
    }


    out.close();
}
