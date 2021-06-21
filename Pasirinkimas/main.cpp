#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

void Skaitymas(int &n, int &m, string Pav[], int Mok[],int Max[]);
int Kiek(int x, int y);
void Atrinkimas(int m, int n, string Pav[], int Mok[], int Maz[], string A[], int A1[], int &a);
void Rasymas(int n, int Maz[],string Pav[],string A[], int A1[], int a);
int main()
{
    int n,m, a,Mok[100], Max[100], Maz[100], A1[100];
    string Pav[100],A[100];
    Skaitymas(n,m,Pav,Mok,Max);
    for(int i=0; i<n;i++)
    {
        Maz[i]=Kiek(Mok[i],Max[i]);
    }
    Atrinkimas(m,n,Pav,Mok,Maz,A,A1,a);
    Rasymas(n,Maz,Pav,A,A1,a);
    return 0;
}

void Skaitymas(int &n, int &m, string Pav[], int Mok[],int Max[])
{
    ifstream in("pasirinkimas_data.txt");
    in>>n>>m;
    for(int i=0; i<n; i++)
    {
        in>>Pav[i]>>Mok[i]>>Max[i];
    }
    in.close();
}
int Kiek(int x, int y)
{
    int maz;
    if(x%y!=0)
        maz= (x/y)+1;
    else
        maz=x/y;
    return maz;
}

void Atrinkimas(int m, int n, string Pav[], int Mok[], int Maz[], string A[], int A1[], int &a)
{
    a=0;
    int x=m/2;
    if(m&2!=0)
        x+=1;
    for(int i=0; i<n; i++)
    {
        if(Mok[i]<x)
        {
            A[a]=Pav[i];
            A1[a]=Maz[i];
            a++;
        }
    }
}

void Rasymas(int n, int Maz[],string Pav[],string A[], int A1[], int a)
{
    ofstream out("pasirinkimas_res.txt");
    out<<"VISI DALYKAI:"<<endl;
    for(int i=0; i<n;i++)
    {
        out<<Pav[i]<< " "<<Maz[i]<<endl;
    }
    out<<"ATRINKTI DALYKAI:"<<endl;
    if(a>0)
    {
        for(int j=0; j<a; j++)
            out<<A[j]<<" "<<A1[j]<<endl;
    }
    else
    {
    out<<"nëra"<<endl;
    }
    out.close();
}
