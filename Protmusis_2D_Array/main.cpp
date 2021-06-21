#include <iostream>
#include <fstream>
/*
5 6
Þalieji 1 1 1 0 1 1
Mëlynieji 0 0 1 1 1 1
Raudonieji 1 1 1 1 0 1
Geltonieji 0 0 0 1 1 1
Baltieji 1 1 1 1 1 1
*/
using namespace std;

void Skaitymas(int &n, int &m, int T[50][50],string Pav[]);
void Atsakymai(int n, int m, int T[50][50], int X[], int Y[]);
void Geriausios(int n, int m,int TT[], int NT[],string Pav[],string Gpav[], int Gtt[],int Gnt[], int &a);
void Rasymas(int n, string Pav[], int TT[], int NT[],string Gpav[], int Gtt[],int Gnt[], int a);
int main()
{
    int n,m,a,T[50][50], TT[50], NT[50],X[50],Y[50],Gtt[50],Gnt[50];
    string Pav[50], Gpav[50];
    Skaitymas(n,m,T,Pav);
    Atsakymai(n,m,T,X,Y);
    for(int i=1; i<=n; i++)
    {
        TT[0]=X[0];
        TT[i]=X[i]-X[i-1];
        NT[0]=Y[0];
        NT[i]=Y[i]-Y[i-1];
    }
    Geriausios(n,m,TT,NT,Pav,Gpav,Gtt,Gnt,a);
    Rasymas(n,Pav,TT,NT,Gpav,Gtt,Gnt,a);
    return 0;
}
void Skaitymas(int &n, int &m, int T[50][50], string Pav[])
{
    ifstream in("protmusis_data.txt");
    in>>n>>m;
    for(int i=0; i<n; i++)
    {
        in>>Pav[i];
        for(int j=0; j<m; j++)
            in>>T[i][j];
    }

    in.close();
}

void Atsakymai(int n, int m, int T[50][50], int X[], int Y[])
{
    int tt=0, nt=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if((T[i][j])==1)
                tt++;
            else
                nt++;
            X[i]=tt;
            Y[i]=nt;
        }

    }
}
void Geriausios(int n, int m,int TT[], int NT[],string Pav[],string Gpav[], int Gtt[],int Gnt[], int &a)
{
    a=0;
    int p=m/2;
    for(int i=0; i<n; i++)
    {
        if(TT[i]>p)
        {
            Gpav[a]=Pav[i];
            Gtt[a]=TT[i];
            Gnt[a]=NT[i];
            a++;
        }
    }
}

void Rasymas(int n, string Pav[], int TT[], int NT[],string Gpav[], int Gtt[],int Gnt[], int a)
{
    ofstream out("protmusis_res.txt");
    out<<"VISOS KOMANDOS:"<<endl;
    for(int i=0; i<n; i++)
    {
        out<<Pav[i]<<" "<<TT[i]<<" "<<NT[i]<<endl;
    }
    out<<"GERIAUSIOS KOMANDOS:"<<endl;
    if(a>0)
    {
        for(int i=0; i<a; i++)
            out<<Gpav[i]<<" "<<Gtt[i]<<" "<<Gnt[i]<<endl;
    }
    else
        out<<"nëra"<<endl;
    out.close();
}
