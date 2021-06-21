#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;

void skaitymas(int &n, int masyvas[]);

bool lyginis(int y);

int suma(int sk);

int didziausias(int S[], int p);

int atbulai(int elem);

void isvedimas(int masyvas[],int L[], int S[], int A[], int k, int n);

int main()
{
    int didz;
    int n,y;
    int m=0;
    int k=0;
    int masyvas[20]; // visi skaiciai
    int L[20]; //visi lyginiai
    int S[20]; // sumos
    int A[20]; //atbulai

    skaitymas(n, masyvas);

    for(int x=0; x<n; x++)
    {
        if(lyginis(masyvas[x]))
        {
            L[k]=masyvas[x];
            k++;
        }
    }

    for(int x=0; x<n; x++)
    {
        m++;
        S[x]=suma(masyvas[x]);
    }

    for(int x=0; x<n; x++)
    {
        A[x]=atbulai(masyvas[x]);
        //cout<<A[x]<<endl;
    }
    isvedimas(masyvas,L,  S,  A,  k, n);

    return 0;
}


void skaitymas(int &n, int masyvas[])
{
    ifstream in("duom.txt");
    in>>n;
    for(int x=0; x<=n; x++)
    {
        in>>masyvas[x];
    }

    in.close();
}


bool lyginis(int y)
{
    while(y>0)
    {
        if((y%10%2)==1)
            return false;
        y/=10;
    }
    return true;

}


int suma(int sk)
{
    int s=0;
    while(sk>0)
    {
        s+=sk%10;
        sk/=10;
    }
    return s;
}


int didziausias(int S[], int x)
{
    int didz = 0;

    for (int i = 1; i < x; i++)
        if (S[i] > S[didz])
            didz = i;

    return didz;
}

int atbulai(int elem)
{
    int atv = 0;
    while(elem>0)
    {
        atv = atv*10+ elem%10;
        elem/=10;
    }
    return atv;
}

void isvedimas(int masyvas[],int L[], int S[], int A[], int k, int n)
{
    ofstream out("rez.txt");
    out<<"Perskaityti skaiciai:"<<endl;
    for(int x=0; x<n; x++)
    {
        out<<setw(6)<<masyvas[x];
    }

    out<<endl;

    out<<"Visi skaitmenys lyginiai:"<<endl;
    for(int x=0; x<k; x++)
    {
        out<<setw(6)<<L[x]<<" ";
    }

    out<<endl;

    int di=didziausias(S,n);
    out<<"Didziausia skaitmenų suma lygi"<<setw(6)<<S[di]<<endl;
    for(int i=0; i<n; i++)
        if(S[i]==S[di]) out<<setw(6)<<masyvas[i];

    out<<endl;

    out<<"Atbulai:"<<endl;
    for(int x=0; x<n; x++)
    {
        out<<A[x]<<endl;
    }

    out.close();
}
