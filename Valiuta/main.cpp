#include <iostream>
#include <fstream>

using namespace std;

void Skaitymas(int &n, int GM[], int GS[], int &n1, int EM[], int ES[]);

int Suma_Studento(int n, int SM[], int SS[]);

void keitimas(int s, int XM[], int x, int XK[]);

int main()
{
    int n, n1, sumg=0, sume=0;
    int GM[50], GS[50], EM[50], ES[50], XK1[50],XK2[50] ;
    Skaitymas(n,GM,GS,n1,EM,ES);
    ofstream out("U1rez.txt");
    int sumG=Suma_Studento(n,GM,GS);
    int sumE=Suma_Studento(n1,EM,ES);

    keitimas(sumG, EM, n1, XK1);
    for(int x=0; x<n1; x++)
    {
        out<<EM[x]<<" "<<XK1[x]<<endl;
        sumg+=XK1[x];
    }

    out<<sumg<<endl;

    keitimas(sumE,GM,n,XK2);
    for(int y=0; y<n; y++)
    {
        out<<GM[y]<<" "<<XK2[y]<<endl;
        sume+=XK2[y];
    }

    out<<sume<<endl;

    out.close();
    return 0;
}

void Skaitymas(int &n, int GM[], int GS[], int &n1, int EM[], int ES[])
{
    ifstream in("U1.txt");
    in>>n;
    for(int x=0; x<n; x++)
        in>>GM[x];
    for(int x=0; x<n; x++)
        in>>GS[x];

    in>>n1;
    for(int x=0; x<n1; x++)
        in>>EM[x];
    for(int x=0; x<n1; x++)
        in>>ES[x];
    in.close();
}

int Suma_Studento(int n, int SM[], int SS[])
{
    int suma =0;
    for(int x=0; x<n; x++)
    {
         int s=SM[x]*SS[x];
         suma += s;
    }
    return suma;
}

void keitimas(int s, int XM[], int x, int XK[])
{
    for(int i=0; i<x; i++)
    {
        XK[i]=s/XM[i];
        s = s%XM[i];
    }
}
