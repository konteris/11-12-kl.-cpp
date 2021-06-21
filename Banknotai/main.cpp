#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void skaitymas(int P[], int I[], int Nom[]);
int suma(int X[], int x);
void rasymas(int P[], int I[], int Nom[]);
int main()
{
    int P[101], I[101], Nom[50];
    skaitymas(P,I,Nom);
    rasymas(P,I,Nom);
    return 0;
}

void skaitymas(int P[], int I[], int Nom[])
{
    int n,x;
    ifstream in("U1.txt");
    for(int i=0; i<5; i++)
        in>>Nom[i];

    for(int i=1; i<101; i++)
    {
        P[i]=0;
        I[i]=0;
    }
    in>>n;
    for(int i=0; i<n; i++)
    {
        in>>x;
        if(x>0)
            P[x]++;
        else
            I[abs(x)]++;
    }

    in.close();
}

int suma(int X[], int x)
{
    int sum=0;
    for(int i=0; i<x; i++)
        sum+= i*X[i];
    return sum;
}

void rasymas(int P[], int I[], int Nom[])
{
    ofstream out("U1rez.txt");
    out<<"Priimta:"<<endl;
    for(int j=0; j<5; j++)
    {
        out<<Nom[j]<<" "<<P[Nom[j]]<<endl;
    }
    int sumaP = suma(P,101);
    out<<"Ið viso: "<<sumaP<<"Eur"<<endl;

    //--------------------------------

    out<<"Iðduota:"<<endl;
    for(int j=0; j<5; j++)
    {
        out<<Nom[j]<<" "<<I[Nom[j]]<<endl;
    }
    int sumaI = suma(I,101);
    out<<"Ið viso: "<<sumaI * -1<<"Eur"<<endl;

    out.close();
}
