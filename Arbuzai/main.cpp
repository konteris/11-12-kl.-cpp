#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void Skaitymas(int &n1, int &n2,double &a1, double &k1,double &k2, double A[], double A1[]);

double Suma(int k, double S[]);

void Pinigai(int &n1, int &n2, double &k1,double &k2, double A[], double A1[], double &viso);

int main()
{
    ofstream out("rez.txt");
    int n1, n2;
    double a1,k1,k2,viso,A[100],A1[100];
    Skaitymas(n1,n2,a1,k1,k2,A,A1);



    out<<"I kategorijos arbûzø yra "<<n1<<": ";
    for(int x=0; x<n1; x++)
    {
        out<<fixed<<setprecision(3)<<setw(7)<<A[x]<<" ";
    }
    out<<endl;
    out<<"I kategorijos arbûzai sveria: "<<setw(7)<<Suma(n1, A)<<"kg."<<endl;
//-----------------------------------------------------------------------------------------
    out<<"II kategorijos arbûzø yra "<<n2<<": ";
    for(int x=0; x<n2; x++)
    {
        out<<fixed<<setprecision(3)<<setw(7)<<A1[x]<<" ";
    }
    out<<endl;
    out<<"II kategorijos arbûzai sveria: "<<setw(7)<<Suma(n2, A1)<<"kg."<<endl;
//----------------------------------------------------------------------------------------
    Pinigai(n1,n2,k1,k2,A,A1,viso);
    out<<"Uþ arbûzus gauta "<<fixed<<setprecision(2)<<setw(7)<<viso<<"eur."<<endl;
    return 0;
}

void Skaitymas(int &n1, int &n2,double &a1, double &k1,double &k2, double A[], double A1[])
{
    int n;
    double a;
    n1 = 0, n2 = 0;

    ifstream in("duom.txt");
    in>>n>>a1>>k1>>k2;
    for(int x=0; x<n; x++)
    {
        in>>a;
        if(a<=a1)
        {
            A[n1]=a;
            n1++;
        }
        else
        {
            A1[n2]=a;
            n2++;
        }
    }
}

double Suma(int k, double S[])
{
    double sum=0;
    for(int x=0; x<k; x++)
        sum+=S[x];

    return sum;
}

void Pinigai(int &n1, int &n2, double &k1,double &k2, double A[], double A1[], double &viso)
{
    double v1, v2;
    for(int x=0; x<n1; x++)
        v1 += k1*A[x];

    for(int x=0; x<n2; x++)
        v2 += k2*A1[x];

    viso= v1+v2;
}
