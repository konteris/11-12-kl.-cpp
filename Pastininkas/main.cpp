#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct prenumeratorius
{
    int L[10];
};
prenumeratorius P[100];
int n, M[100];

void skaitymas(int &is_viso, int SK[]);
void rikiavimas(int SK[], int A[]);
int daugiausiai(int x, int X[]);
void rasymas(int is_viso, int SK[], int A[], double vid,int skr, int SK1[]);
int main()
{
    int is_viso,SK[51], skr=0, A[51],SK1[51];
    double vid;
    skaitymas(is_viso,SK);
    for(int i=1; i<51; i++)
    {
        SK1[i]=SK[i];
        A[i]=i;
    }
    rikiavimas(SK,A);
    rasymas(is_viso,SK,A,vid,skr,SK1);
    return 0;
}

void skaitymas(int &is_viso, int SK[])
{
    ifstream in("U1.duom");
    in>>n;
    is_viso=0;

    for(int i=1; i<51; i++)
        SK[i]=0;

    for(int i=0; i<n; i++)
    {
        in>>M[i];
        for(int j=0; j<M[i]; j++)
        {
            in>>P[i].L[j];
            SK[P[i].L[j]]+=1;
        }
        is_viso += M[i];
    }
    in.close();
}

int daugiausiai(int x, int X[])
{
    int d=0;
    for(int i=0; i<x; i++)
    {
        if(X[i]> X[d])
            d=i;
    }
    return X[d];
}

void rikiavimas(int SK[], int A[])
{
    for(int i=1; i<51-1; i++)
    {
        int m=i, X[51], Y[51];
        for(int j=i+1; j<51; j++)
            if(SK[m]>SK[j])
                m=j;

        X[i]=SK[m];
        Y[i]=A[m];
        for(int x=m; x>i; x--)
        {
            SK[x] = SK[x-1];
            A[x] = A[x-1];
        }

        SK[i]=X[i];
        A[i]=Y[i];
    }
}

void rasymas(int is_viso, int SK[], int A[], double vid, int skr, int SK1[])
{
    ofstream out("U1.rez");
    out<<is_viso<<endl;
    for(int i=1; i<51; i++)
    {
        if(SK[i] > 0)
        {
            skr++;
        }
    }
    out<<skr<<endl;
    int daug = daugiausiai(n, M);
    for(int i=0; i<n; i++)
    {
        if(M[i] == daug)
            out<<setw(3)<<i+1;
    }
    out<<endl;
    vid = (double(is_viso)/(n));
    out<<fixed<<setprecision(1)<<vid<<endl;

    for(int i=1; i<51; i++)
        if(SK[i]>0)
            out<<setw(3)<<A[i];

    out.close();
}
