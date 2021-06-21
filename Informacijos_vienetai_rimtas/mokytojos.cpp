#include <iostream>
#include <fstream>

using namespace std;
struct zaidejai
{
    int KK[30],kk=0;

};
int KT[30];
string K[11]= {" ","b", "B","kB","MB","GB","TB","PB","EB","ZB","YB"};
void skaitymas(int &n,int &m, string V[]);
void keitimas(int n, string V[],int Vt[]);
int did(int x,int X[]);
int kiek(int x,int X[],int d);
int main()
{
    int n,m,Vt[31];
    string V[30];
    skaitymas(n,m,V);
    keitimas(n,V,Vt);
    zaidejai Z[6];
    for(int i=0; i<n; i+=m)
    {
        int k=0;
        int j=i;
        int X[6];
        while(k<m)
        {
            X[k]=Vt[j];
            j++;
            k++;
        }
       // for(int z=0; z<m; z++)
      //      cout<<X[z]<<" ";
       // cout<<endl;
        int d=did(m,X);//cout<<X[d]<<" "<<d<<endl;
        if(kiek(m,X,X[d])==1)
            for(int z=0; z<m; z++)
            {
                Z[d].KK[Z[d].kk]=X[z];

                Z[d].kk++;
                KT[d]+=X[z];
            }
        else
            for(int z=0; z<m; z++)
                if(X[z]==X[d])
                {
                    Z[z].KK[Z[z].kk]=X[z];
                    Z[z].kk++;
                    KT[z]+=X[z];
                };

    }
   // cout<<endl;
    ofstream out ("U2rez.txt");
   for(int z=0; z<m; z++)
    {  // cout<<Z[z].kk<<endl;

        for(int i=0; i<Z[z].kk; i++)
        {
           out<<K[Z[z].KK[i]]<<" ";
        }
        out<<KT[z]<<endl;
    }

    int dd=did(m,KT);
    for(int z=0; z<m; z++)
        if(KT[z]==KT[dd])out<<z+1<<" ";
    out<<endl;
    return 0;
}
void skaitymas(int &n,int &m, string V[])
{
    ifstream in ("U1.txt");
    in>>n>>m;
    for(int i=0; i<n; i++)
    {
        in>>V[i];
    }
    in.close();
}
void keitimas(int n, string V[],int Vt[])
{
    for(int i=0; i<n; i++)
        for(int j=1; j<11; j++)
            if(V[i]==K[j])
                Vt[i]=j;
}
int did(int x,int X[])
{
    int d=0;
    for(int i=0; i<x; i++)
        if(X[i]>X[d])
            d=i;
    return d;
}
int kiek(int x,int X[],int d)
{
    int k=0;
    for(int i=0; i<x; i++)
        if(X[i]==d)
            k++;
    return k;
}
