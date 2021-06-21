#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void skaitymas(int &n, int masyvas[], int D[]);

int isbraukimas(int elem, int &del);

void isvedimas(int masyvas[], int D[], int S[], int n);

int main()
{
    int n, del;
    int masyvas[50];
    int D[50];
    int S[50];

    skaitymas(n,masyvas,D);

    for(int x=0; x<n; x++)
    {
        S[x] = isbraukimas(masyvas[x], D[x]);
    }

    isvedimas(masyvas, D, S, n);

    return 0;
}

void skaitymas(int &n, int masyvas[], int D[])
{
    ifstream in("U1.txt");
    in>>n;
    for(int x=0; x<n; x++)
    {
        in>>masyvas[x] >>D[x];
    }
    in.close();
}

int isbraukimas(int elem, int &del)
{
    int m = 0, kl=1;
    while(elem>0)
    {
        int liek;
        liek = elem%10;
        if(liek!=del)
        {
            m+=liek*kl;
            kl*=10;

        }
        elem/=10;
    }
    return m;
}

void isvedimas(int masyvas[], int D[], int S[], int n)
{
    ofstream out("U1rez.txt");
    for(int x=0; x<n; x++)
    {
        out<<masyvas[x]<<" "<<D[x]<<" "<<S[x]<<endl;
    }
    out.close();
}
