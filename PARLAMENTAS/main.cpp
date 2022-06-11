#include <iostream>
#include<fstream>

using namespace std;

struct Partija{
    int k, Nariai[20];
};
Partija P[30];
const int tt=20;
int N, a=0,Parlamentas[20];

int Daznis[tt] = {0};
int Numeriai[tt];

void Skaitymas();
void Rikiavimas(int X[], int x);
void Rikiavimas1(int X[], int Y[], int xy);

void Rasymas();

int main()
{
    Skaitymas();
    for(int i=0; i<N; i++)
    {
        Rikiavimas(P[i].Nariai, P[i].k);
    }
    
    for(int i=0;i<tt;i++)
        Numeriai[i]=i;

    Rikiavimas1(Daznis,Numeriai,tt);
    for(int i=1;i<=tt;i++)
    {
        if(Daznis[i]==N)
        {
            Parlamentas[a]=Numeriai[i];
            a++;
        }
        // else
        // { 
        // }    
    }
    ofstream out("parlamentas_res.txt");
    out<<"Pradiniai surikiuoti duomenys:"<<endl;
    for(int i=0; i<N; i++)
    {
        for(int j=0;j<P[i].k;j++)
            out<<P[i].Nariai[j]<<" ";
        out<<endl;
    }
    out<<"Parlamenta sudaro:"<<endl; 
    for(int i=0; i<a; i++)  
        out<<Parlamentas[i]<<endl;
    return 0;
}
void Skaitymas()
{
    ifstream in("parlamentas_data.txt");
    in>>N;
    for(int i=0; i<N; i++)
    {
        in>>P[i].k;
        for(int j=0;j<P[i].k;j++)
        {
            in>>P[i].Nariai[j];
            Daznis[P[i].Nariai[j]]++;
        }
    }
    in.close();
}

void Rikiavimas(int X[], int x)
{
    for(int i=0;i<x-1;i++)
        for(int j=i;j<x;j++)
            if(X[i] > X[j])
                swap(X[i],X[j]);
}
void Rikiavimas1(int X[], int Y[], int xy)
{
    for(int i=1;i<=xy-1;i++)
        for(int j=i;j<=xy;j++)
            if(X[i]<X[j])
            {
                swap(X[i],X[j]);
                swap(Y[i],Y[j]);
            }
}