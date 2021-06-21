#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct knyga
{
    string autorius, pav;
    int t; // naudosiu suskaiciuoti kai yra tokiu paciu knygu
    double kaina;
};

struct filialas
{
    string pavadinimas;
    int k;
    knyga K[100];
    double sum;
};

filialas F[20];
filialas F1[20];
int n;

void skaitymas();
void rikiavimas(int x, knyga X[]);
void atrinkimas(int &a, knyga Y,knyga X[], int x);
int tokia_pat(int a, string ieskomas_autorius, string ieskoma_knyga, knyga Y[]);
int suma(knyga X[], int x);
double suma_viso(knyga X[],int x);
void rasymas();

int main()
{
    int a;
    skaitymas(); // nenuskaito trecio filialo
    rasymas();

    return 0;
}

void skaitymas()
{
    ifstream in("U2.txt");
    in>>n;
    char X[12], Y[14];

    for(int i=0; i<n; i++)
    {
        in>>ws;
        in.get(X,12);
        F[i].pavadinimas = X;
        in>>F[i].k;

        for(int j=0; j<F[i].k; j++)
        {
            in>>ws;
            in.get(Y,14);
            F[i].K[j].autorius = Y;
            in>>ws;
            in.get(Y,14);
            F[i].K[j].pav = Y;
            in>>F[i].K[j].kaina;
            F[i].K[j].t = 1;
        }
    }
    in.close();
}

void rikiavimas(int x,knyga X[])
{
    for(int i=0; i<x-1; i++)
        for(int j=i+1; j<x; j++)
            if(X[i].autorius > X[j].autorius || X[i].autorius == X[j].autorius && X[i].pav > X[j].pav)
                swap(X[i],X[j]);
}

int tokia_pat(int a, string ieskomas_autorius, string ieskoma_knyga, knyga Y[])
{
    for(int j=0; j<a; j++)
    {
        if(ieskomas_autorius == Y[j].autorius && ieskoma_knyga == Y[j].pav)
            return j;
    }


    return -1;
}

void atrinkimas(int &a, knyga Y[],knyga X[], int x)
{
    a=0;

    for(int i=0; i<x; i++)
    {
        int z = tokia_pat(a, X[i].autorius, X[i].pav, Y);

        if(z == -1)
        {
            Y[a]= X[i];
            a++;
            Y[a].t =1;
        }
        else
        {
            Y[z].t++; // jeigu knygos sutampa tai prie F1_knygos pridedu 1
        }

    }
}

int suma(knyga X[], int x)
{
    int k=0;

    for(int i=0; i<x; i++)
        if(X[i].t > 1)
            k+= X[i].t;
    return k;
}

double suma_viso(knyga X[],int x)
{
    double s=0;
    for(int i=0; i<x; i++)
        s+= X[i].t * X[i].kaina;
    return s;
}

void rasymas()
{
    ofstream out("U2rez.txt");

    for(int i=0; i<n; i++)
    {
        rikiavimas(F[i].k, F[i].K);
    }

    for(int i=0; i<n; i++)
    {
        out<<"Filialas: " << F[i].pavadinimas<<endl;

        for(int j=0; j< F[i].k; j++)
        {
            out<<F[i].K[j].autorius << F[i].K[j].pav << fixed<<setprecision(2)<<" "<<F[i].K[j].kaina<<endl;
        }
    }

    out<<"Vienodø knygø kiekis filialuose:"<<endl;
    for(int i = 0; i<n; i++)
        atrinkimas(F1[i].k, F1[i].K, F[i].K, F[i].k);
    for(int i=0; i<n; i++)
        out<< F[i].pavadinimas<< " "<<suma(F1[i].K, F1[i].k)<<endl;
    out<< "Filialø nesikartojanèiø knygø sàraðas:"<<endl;
    for(int i=0; i<n; i++)
    {
        rikiavimas(F1[i].k, F1[i].K);
        out<< F[i].pavadinimas<< ": "<<endl;
        for(int j=0; j<F1[i].k; j++)
        {
            out<<F1[i].K[j].autorius<< " "<<F1[i].K[j].pav<< fixed<<setprecision(2)<<" "<<F1[i].K[j].kaina<< " "<<F1[i].K[j].t<<endl;
        }
    }
    out<<"Filialø piniginë knygø vertë:"<<endl;
    double s=0;
    for(int i = 0; i<n; i++)
    {
        double s1 = suma_viso(F1[i].K, F1[i].k);
        out<< F[i].pavadinimas<< ": "<<s1<<" Eur."<<endl;
        s+=s1;
    }
    out<<"Centrinës bibliotekos piniginë knygø vertë: "<<s<<" Eur."<<endl;

    out.close();
}
