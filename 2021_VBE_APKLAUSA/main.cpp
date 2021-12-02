#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Mokinys //pradiniam duomenims struktura
{
    string Vardas, pam;
    int vid,k;
};
struct Pamoka
{
    string dalykas; // nebesikartojancios pamokos
    int kiek=1; // kiek mokiniu pasirinke
    string V[50]; // Mokiniu vardai
};
void Skaitymas(Mokinys M[], int &n);
int vid(int X[], int x);
void virsdevyn(Mokinys M[], int n, Mokinys Dev[], int &a);
int yra(string ieskoma_pamoka, Pamoka P[],int b);
void atrinkimas(int &b, Pamoka P[], Mokinys Dev[], int a);
void Rikiavimas(Pamoka P[], int b);
void Rasymas(Pamoka P[], Mokinys Dev[], int a, int b);

int main()
{
    Mokinys M[50];
    Mokinys Dev[50];
    Pamoka P[50];
    int n,a,b;
    Skaitymas(M,n);
    virsdevyn(M,n,Dev,a);
    atrinkimas(b,P,Dev,a);
    Rikiavimas(P,b);
    Rasymas(P,Dev,a,b);

    return 0;
}

void Skaitymas(Mokinys M[], int &n)
{
    ifstream in("U2.txt");
    int P[20], p_skc;
    in>>n;
    for(int i=0; i<n; i++)
    {
        in>>M[i].Vardas>>M[i].pam>>p_skc;
        for(int j=0; j<p_skc; j++)
        {
            in>>P[j];
            M[i].vid = vid(P,p_skc);
        }
    }

    in.close();
}
int vid(int X[], int x)
{
    int s=0;
    for(int i=0; i<x; i++)
    {
        s+=X[i];
    }
    return s/x;
}

void virsdevyn(Mokinys M[], int n, Mokinys Dev[], int &a) //randu mokinius kuriu vidurkis >9 ir susidedu juos i Dev
{
    a=0;
    for(int i=0; i<n; i++)
    {
        if(M[i].vid >=9)
        {
            Dev[a].Vardas = M[i].Vardas;
            Dev[a].pam = M[i].pam;
            Dev[a].vid = M[i].vid;
            a++;
        }
    }
}

int yra(string ieskoma_pamoka, Pamoka P[],int b)
{
    for(int i=0; i<b; i++)
    {
        if(P[i].dalykas == ieskoma_pamoka)
            return i;

    }
    return -1;
}

void atrinkimas(int &b, Pamoka P[], Mokinys Dev[], int a)
{
    b=0; // structuros Pamoka elementu skaicius
    for(int i=0; i<a; i++)
    {
        int m=yra(Dev[i].pam,P,b); // indeksas kai tapati pamoka
        if(m==-1) // jei pamokos nesutampa
        {
            P[b].dalykas= Dev[i].pam; //  I P[] irasau ta pamoka
            // P[b].V[0]= Dev[i].Vardas;
            b++; // padidinu

        }
        else // jei pamoka ta pati
        {
            P[m].kiek++; // mokiniu kiekis +=1;
        }
    }
}

void Rikiavimas(Pamoka P[], int b)
{
    for(int i=0; i<b-1; i++)
    {
        for(int j=i+1; j<b; j++)
            if(P[i].kiek < P[j].kiek or P[i].kiek == P[j].kiek and P[i].dalykas > P[j].dalykas)
                swap(P[i], P[j]);
    }
}

void Rasymas(Pamoka P[], Mokinys Dev[], int a, int b)
{
    //ofstream out("U2rez.txt");

    for(int i=0; i<b; i++)
    {
        //cout<<P[i].dalykas<<endl;
        cout<<P[1].V[1]<<endl;
    }

    //out.close();
}
