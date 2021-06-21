#include <iostream>
#include <fstream>

using namespace std;

void Skaitymas(int &d1, int &d2, int &d3, int &n, string Pav[], int T[], int K[]);
int Suma(int x, int y);
void Trys_draugai(int d, int n, string Pav[], int T[], int K[], string XPav[], int XT[], int XK[], int &a);
int Trukme(int x, int X[]);
bool Tikrinimas(int d1, int d2, int d3, int n, int x);
void Rasymas(string x, string gal, string X[], int XT[], int XK[], int xvid,int xa);
int main()
{
    ofstream out("keliones_res.txt");
    out.close();
    int d1,d2,d3,n,T[50], K[50], T1[50],K1[50],T2[50],K2[50],T3[50],K3[50],a1,a2,a3, TV[50], KV[50], av=0;
    string Pav[50], Pav1[50], Pav2[50], Pav3[50], PavVisi[50];
    Skaitymas(d1,d2,d3,n,Pav,T,K);
    Trys_draugai(d1,n,Pav,T,K,Pav1,T1,K1,a1);
    Trys_draugai(d2,n,Pav,T,K,Pav2,T2,K2,a2);
    Trys_draugai(d3,n,Pav,T,K,Pav3,T3,K3,a3);
    int vid1, vid2,vid3,vid_visi;
    if(a1>0)
        vid1 = Trukme(a1,T1);
    if(a2>0)
        vid2 = Trukme(a2,T2);
    if(a3>0)
        vid3 = Trukme(a3,T3);

    for(int i=0; i<n; i++)
    {
        if(Tikrinimas(d1,d2,d3,n,K[i]))
        {
            PavVisi[av]=Pav[i];
            TV[av]=T[i];
            KV[av]=K[i];
            av++;
        }
    }
    if(av>0)
         vid_visi= Trukme(av, TV);
    Rasymas("Pirmam", "ui", Pav1,T1,K1,vid1,a1);
    Rasymas("Antram", "ui", Pav2,T2,K2,vid2,a2);
    Rasymas("Treciam", "ui", Pav3,T3,K3,vid3,a3);
    Rasymas("Visiems", "ams", PavVisi,TV,KV,vid_visi,av);
   // int x= sizeof(T)/sizeof(T[0]);
    //cout<<x;
    return 0;
}
void Skaitymas(int &d1, int &d2, int &d3, int &n, string Pav[], int T[], int K[])
{
    ifstream in("keliones_data.txt");
    in>>d1>>d2>>d3;
    in>>n;
    int x1,y1;
    for(int i=0; i<n; i++)
    {
        in>>Pav[i]>>T[i]>>x1>>y1;
        K[i]=Suma(x1,y1);
    }
    in.close();
}
int Suma(int x, int y)
{
    int sum;
    return sum=x+y;
}

void Trys_draugai(int d, int n, string Pav[], int T[], int K[], string XPav[], int XT[], int XK[], int &a)
{
    a=0;
    for(int i=0; i<n; i++)
    {
        if(K[i]<=d)
        {
            XPav[a]=Pav[i];
            XT[a]=T[i];
            XK[a]=K[i];
            a++;
        }
    }
}

int Trukme(int x, int X[])
{
    int sum=0;
    for(int i=0; i<x; i++)
        sum+=X[i];
    return sum/x;
}

bool Tikrinimas(int d1, int d2, int d3, int n, int x)
{
    if(x<= d1 && x<= d2 && x<= d3)
        return true;
    else
        return false;
}

void Rasymas(string x, string gal, string X[], int XT[], int XK[], int xvid,int xa)
{
    ofstream out("keliones_res.txt", ios::app);
    if(xa>0)
    {
        out<<x<<" draug"<<gal<<" tinkamos keliones:"<<endl;
        for(int i=0; i<xa; i++)
        {
            out<<X[i]<<" "<<XT[i]<<" "<<XK[i]<<endl;
        }
        out<<"Vidutine keliones trukme dienomis yra: "<<xvid<<endl;
    }
    else
        out<<x<<" draug"<<gal<<" tinkamu kelioniu nera"<<endl;
    out.close();
}
