#include <iostream>
#include <fstream>

using namespace std;

struct Mokinys{
    string Vardas, pam;
    //int p_skc;
   // int P[20];
    int vid,k;
};

void Skaitymas(Mokinys M[], int &n);
int vid(int X[], int x);
void Rasymas();

int main()
{
    Mokinys M[50];
    int n;
    Skaitymas(M,n);
    for(int i=0; i<n; i++)
    {
        cout<<M[i].Vardas<<" "<<M[i].pam<<" "<<M[i].vid<<endl;
    }
    return 0;
}

void Skaitymas(Mokinys M[], int &n)
{
    ifstream in("U2.txt");
    int P[20], p_skc;
    in>>n;
    for(int i=0; i<n; i++)
    {
        in>>M[i].Vardas>>M[i].pam>>p_skc;
        for(int j=0; j<p_skc; j++)
        {
            in>>P[j];
            M[i].vid = vid(P,p_skc);
        }
    }

    in.close();
}
int vid(int X[], int x)
{
    int s=0;
    for(int i=0;i<x;i++)
    {
        s+=X[i];
    }
    return s/x;
}
