#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct Zmogus
{
    string vardas;
    int taskai=0; // cia kaupsiu zvejo taskus ir zuvies mase
};

struct Zuvis
{
    int kiek;
    string Pav[30];
    int M[30];

};

int n,k;
Zmogus Z[30]; //zvejys ir jo surinkti taskai
Zmogus Z1[30]; // zuvis ir kiek tasku uz ja skiriama, bei cia kaupsiu mases
Zuvis  Z2[30];  // informacija apie zuvis

void skaitymas();
void taskai();
void rikiavivmas(Zmogus X[], int p);
void rasymas();


int main()
{
    skaitymas();
    taskai();
    rikiavivmas(Z,n);
    rikiavivmas(Z1,k);
    rasymas();
    return 0;
}

void skaitymas()
{
    ifstream in ("U2.txt");
    char X[21];
    char Y[21];
    char P[21];
    in>>n;
    for(int i=0; i<n; i++)
    {
        in>>ws;
        in.get(X, 21);
        Z[i].vardas = X;

        in>>Z2[i].kiek;
        for(int j=0; j<Z2[i].kiek; j++)
        {
            in>>ws;
            in.get(Y,21);
            Z2[i].Pav[j] = Y;
            in>>Z2[i].M[j];

            if(Z2[i].M[j] >= 200)
            {
                Z[i].taskai += 30;
            }
            else
                Z[i].taskai +=10;
        }
    }
    in>>k;
    for(int i=0; i<k; i++)
    {
        in>>ws;
        in.get(P, 21);
        Z1[i].vardas = P;

        in>>Z1[i].taskai;
    }

    in.close();
}

void taskai()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<Z2[i].kiek; j++)
        {
            for(int x=0; x<k; x++)
            {
                if(Z2[i].Pav[j] == Z1[x].vardas)
                    Z[i].taskai += Z1[x].taskai;
            }
        }
    }

    for(int i=0; i<k; i++)
    {
        Z1[i].taskai =0;
        for(int j=0; j<n; j++)
        {
            for(int x=0; x<Z2[j].kiek; x++)
                if(Z1[i].vardas == Z2[j].Pav[x])
                    Z1[i].taskai += Z2[j].M[x];
        }
    }
}


void rikiavivmas(Zmogus X[], int p)
{
    for(int i=0; i<p-1; i++)
    {
        for(int j=i+1; j<p; j++)
        {
            if(X[i].taskai < X[j].taskai || X[i].taskai==X[j].taskai && X[i].vardas>X[j].vardas)
                swap(X[i], X[j]);
        }
    }
}

void rasymas()
{
    ofstream out("U2rez.txt");

    out<<"Dalyviai"<<endl;

    for(int i=0; i<n; i++)
        out<<setw(20)<<Z[i].vardas<<" "<<Z[i].taskai<<endl;

    out<<"Laimikis"<<endl;
    for(int i=0; i<k; i++)
        out<<setw(20)<<Z1[i].vardas<<" "<<Z1[i].taskai<<endl;

    out.close();
}
