#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct Tersalai
{
    string pavadinimas;
    double tersalu_kiekis;
};
Tersalai T[20];
int r, prmetai, m;
double PM[10] = {0}; //tersalu kiekis per metus
void Skaitymas();
double Suma(double X[], int x);
void Rikiavimas(Tersalai X[], int x);
int Didziausias(Tersalai X[], int x);
int Salinti(Tersalai X[], int kuri_salinti);
void Rasymas();

int main()
{
    Skaitymas();
    Rasymas();
    return 0;
};

void Skaitymas()
{
    ifstream in("tersalai.txt");
    in>>r>>prmetai>>m;
    char X[31];
    for(int i=0; i<r; i++)
    {
        in>>ws;
        in.get(X,31);
        T[i].pavadinimas = X;
        double A[m];
        for(int j=0; j<m; j++)
        {
            in>>A[j];
            PM[j]+=A[j];
        }

        T[i].tersalu_kiekis = Suma(A,m);
        //cout<<T[i].tersalu_kiekis<<endl;
    }
    in.close();
}
double Suma(double X[], int x)
{
    double sum=0;
    for(int i=0; i<x; i++)
        sum+=X[i];
    return sum;
}
void Rikiavimas(Tersalai X[], int x)
{
    for(int i=0;i<x-1;i++)
        for(int j=i;j<x;j++)
            if(X[i].tersalu_kiekis < X[j].tersalu_kiekis or X[i].tersalu_kiekis == X[j].tersalu_kiekis and X[i].pavadinimas > X[j].pavadinimas)
                swap(X[i],X[j]);
}

int Didziausias(Tersalai X[], int x)
{
    int d=0;
    for(int i=1;i<x;i++)
    {
        if(X[d].tersalu_kiekis<X[i].tersalu_kiekis)
            d=i;
    }
    return d;
}
int Salinti(Tersalai X[], int kuri_salinti)
{
    for(int i=kuri_salinti; i<r-1;i++)
        X[i]=X[i+1];
    r--;
}
void Rasymas()
{
    ofstream out("tersalairez.txt");
    out<<"Uþregistruota terðalø per metus"<<endl;
    for(int i=0;i<m;i++)
        out<<fixed<<setprecision(1)<<prmetai+i<<" "<<PM[i]<<endl;

    Rikiavimas(T,r);
    out<<"Surikiuotas sàraðas"<<endl;
    for(int i=0; i<r; i++)
        out<<T[i].pavadinimas<<fixed<<setprecision(1)<<T[i].tersalu_kiekis<<endl;

    int didz = Didziausias(T,r);
    Salinti(T,didz);
    out<<"Sàraðas paðalinus 1 elementà"<<endl;
    for(int i=0; i<r; i++)
        out<<T[i].pavadinimas<<fixed<<setprecision(1)<<T[i].tersalu_kiekis<<endl;

    out.close();
}
