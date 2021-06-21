#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void Skaitymas(int &n, double &p1, double &p2, double M[]);

double Vidurkis(int y, double X[]);

void Tinkami(double M[], double MA[], int &a, double &p1, double &p2, int n);

void Isvedimas(double M[], int n, int a, double MA[]);

int main()
{
    int n, a;
    double p1,p2;
    double M[100], MA[100];

    Skaitymas(n,p1,p2,M);
    Tinkami(M,MA,a,p1,p2,n);

    Isvedimas(M,n,a,MA);
    return 0;
}

void Skaitymas(int &n, double &p1, double &p2, double M[])
{
    ifstream in("Duomenys.txt");

    in>>n>>p1>>p2;
    for(int x=0; x<n; x++)
        in>>M[x];

    in.close();
}

double Vidurkis(int y, double X[])
{
    double vid=0;
    for(int x=0; x<y; x++)
        vid+=X[x];

    return vid/y;
}

void Tinkami(double M[], double MA[], int &a, double &p1, double &p2, int n)
{
    a=0;
    for(int x=0; x<n; x++)
    {
        if(M[x]>=p1 && M[x]<=p2)
        {
            MA[a]=M[x];
            a++;
        }
    }
}

void Isvedimas(double M[], int n, int a, double MA[])
{
    ofstream out("Rezultatai.txt");

    out<<"Visø moliûgø vidutinis svoris: "<<fixed<<setprecision(3)<<Vidurkis(n,M)<<" kg"<<endl;
    if(a==0)
        out<<"Á supirkimo punktà atrinktø moliûgø nëra."<<endl;
    else
    {
        out<<"Á supirkimà atrinkta: "<<a<<endl;
        out<<"Atrinktø moliûgø svoriø sàraðas:"<<endl;
        for(int x=0; x<a; x++)
            out<<MA[x]<<" ";
        out<<endl;

        out<<"Vidutinis vieno atrinkto moliûgo svoris: "<<Vidurkis(a,MA)<<" kg"<<endl;
    }

    out.close();
}





