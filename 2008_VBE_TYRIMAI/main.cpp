#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void Skaitymas(int IN[], int OUT[]);

void Isvedimas(int IN[], int OUT[]);

int Daugiausiai(int IN[]);

int main()
{
    int IN[100], OUT[100];
    Skaitymas(IN, OUT);
    Isvedimas(IN, OUT);

    return 0;
}

void Skaitymas(int IN[], int OUT[])
{
    int n, m, k;
    for(int i=1; i<=100; i++)
    {
        IN[i]=0;
        OUT[i]=0;
    }

    ifstream in("U1.txt");
    in>>n;

    for(int i=0; i<n; i++)
    {
        in>>m>>k;
        if(k>0)
            IN[m]+=k;
        else
            OUT[m]+=k;
    }
    in.close();
}

int Daugiausiai(int IN[])
{
    int d=1;
    for(int i=1; i<=100; i++)
    {
        if(IN[i] > IN[d])
            d=i;
    }
    return d;
}

void Isvedimas(int IN[], int OUT[])
{
    ofstream out("U1rez.txt");

    for(int i=1; i<=100; i++)
    {
        if(IN[i]>0)
        {
            out<<setw(6)<<i;
        }

    }

    out<<endl;
    for(int i=1; i<=100; i++)
    {
        if(IN[i]>0)
        {
            out<<setw(6)<<IN[i];
        }

    }

    out<<endl;
    for(int i=1; i<=100; i++)
    {
        if(IN[i]>0)
        {
            out<<setw(6)<<OUT[i];
        }

    }
    out<<endl;

    int d=Daugiausiai(IN);
    out<<setw(6)<<d;
    out.close();
}
