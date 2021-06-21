#include <iostream>
#include <fstream>

using namespace std;

void Skaitymas(int L[], int J[]);

void Mainai_Isvedimas(int L[], int J[], int lm, int jm);

int main()
{
    int L[101], J[101], lm=0, jm=0;

    Skaitymas(L,J);
    Mainai_Isvedimas(L,J,lm,jm);

    return 0;
}

void Skaitymas(int L[], int J[])
{
    ifstream in("U1duom.txt");
    int n,m, ln, j;

    for(int i=1; i<=100; i++)
    {
        L[i]=0;
        J[i]=0;
    }
    in>>n>>m;

    for(int i=0; i<n; i++)
    {
        in>>ln;
        L[ln]++;
    }

    for(int i=0; i<m; i++)
    {
        in>>j;
        J[j]++;
    }
    in.close();
}

void Mainai_Isvedimas(int L[], int J[], int lm, int jm)
{
    ofstream out("U1rez.txt");
    for(int i=1; i<=100; i++) //linos siulomi zaislai
    {
        if(L[i]>1 && J[i]==0)
        {
            out<<i<<" ";
            lm++;
        }
    }
    if(lm==0)
        out<<0;
    out<<endl;

    for(int i=1; i<=100; i++) //jurgio siulomi zaislai
    {
        if(J[i]>1 && L[i]==0)
        {
            out<<i<<" ";
            jm++;
        }
    }

    if(jm==0)
        out<<0;
    out<<endl;
    for(int i=1; i<=100; i++)
    {
        if(L[i]>0 || J[i]>0)
            out<<i<<" ";
    }
    out.close();
}
