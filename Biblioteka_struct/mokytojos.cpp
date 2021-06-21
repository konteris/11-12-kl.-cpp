#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;
struct knygos
{

    string aut, pav;
    double kain;
    int kiek;
};
struct filial
{

    string raj;
    int k;
    knygos K[100];
};
filial S[100],A[100];

int n;
void skaityti();
void rasyti();
void rikiuoti(knygos X[],int x);
int suma (knygos X[],int x);
void atrinkti(knygos X[],int x, knygos Y[], int &y);
int yra(string a,string p,knygos Y[],int y);
double suma1 (knygos X[],int x);

int main()
{

    skaityti();
    rasyti();
}
void skaityti()
{

    ifstream in ("U2.txt");
   // ifstream in ("3.in");
    char e[15];
    in >> n;
    for(int i = 0; i<n; i++)
    {
        in>>ws;
        in.get(e,12);
        S[i].raj=e;
        in >>S[i].k;
        int m = S[i].k;
        for(int j = 0; j<m; j++)
        {
            in >> ws;
            in.get(e,14);
            S[i].K[j].aut = e;
            in>>ws;
            in.get(e,14);
            S[i].K[j].pav = e;
            in >> S[i].K[j].kain;
            S[i].K[j].kiek = 1;
        }
    }
}
void rasyti()
{
    //ofstream cout ("U2rez.txt");
    //ofstream cout ("3.ch");

    for(int i = 0; i<n; i++)
    {
        cout << "Filialas: " <<S[i].raj <<endl;
        int m = S[i].k;
        for(int j = 0; j<m; j++)
        {
            cout << S[i].K[j].aut << S[i].K[j].pav << fixed << setprecision(2)<<S[i].K[j].kain << endl;
        }
    }
    cout << "Vienodø knygø kiekis filialuose: " <<endl;
    for(int i = 0; i<n; i++)
        atrinkti(S[i].K,S[i].k,A[i].K,A[i].k);
    for(int i = 0; i<n; i++)
        cout << S[i].raj << " " << suma(A[i].K,A[i].k) << endl;
    cout << "Filialø nesikartojanèiø knygø sàraðas: " <<endl;
    for(int i = 0; i<n; i++)
    {
        rikiuoti(A[i].K,A[i].k);
        cout <<S[i].raj <<": "<<endl;
        int m = A[i].k;
        for(int j = 0; j<m; j++)
        {
            cout << A[i].K[j].aut<<" " << A[i].K[j].pav << fixed << setprecision(2)<<A[i].K[j].kain << " " << A[i].K[j].kiek<< endl;
        }
    }
    cout<<"Filialø piniginë knygø vertë:"<<endl;
    double sv=0;
    for(int i = 0; i<n; i++)
     {
         double ss=suma1(A[i].K,A[i].k);
         cout << S[i].raj << " " << ss<<" Eur." << endl;
         sv+=ss;
     }
     cout<<"Centrinës bibliotekos piniginë knygø vertë: "<<sv<<" Eur." << endl;
  // cout.close();
}
void atrinkti(knygos X[],int x, knygos Y[], int &y)
{
    y=0;
    for(int i = 0; i<x; i++)
    {
        int z=yra(X[i].aut,X[i].pav,Y,y);
        if(z==-1)
        {
            Y[y]=X[i];
            y++;
            Y[y].kiek=1;
        }
        else
        {

            Y[z].kiek++;
        }
    }

}
int yra(string a,string p,knygos Y[],int y)
{


    for(int i = 0; i<y; i++)
    {
        if(a==Y[i].aut&&p==Y[i].pav)
            return i;
    }
    return -1;
}


void rikiuoti(knygos X[],int x)
{

    for(int i = 0; i<x-1; i++)
        for(int j = i+1; j<x; j++)
        {

            if(X[i].aut > X[j].aut||X[i].aut == X[j].aut&&X[i].pav > X[j].pav)
                swap(X[i],X[j]);
        }
}

int suma (knygos X[],int x)
{
    int k=0;
    for(int i=0; i<x; i++)
        if(X[i].kiek>1)
            k+=X[i].kiek;
    return k;
}
double suma1 (knygos X[],int x)
{
    double k=0;
    for(int i=0; i<x; i++)
                    k+=X[i].kiek*X[i].kain;
    return k;
}
