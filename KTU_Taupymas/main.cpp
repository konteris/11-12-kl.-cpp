#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void Skaitymas(int &k, double &a, double &b, double &c, double S[], double L[], double M[]);

double Suma(int x, double X[]);

double Vidurkis(double sk, int k);

double Kiek_liko(double n, double m );

int Daugiau(int k, double D[], double vid);

void Isvedimas(double sum1, double sum2,double sum3,double v1,double v2,double v3,double k1,double k2,double k3, int d4 );

int main()
{
    int k;
    double a,b,c;
    double S[32],L[32],M[32];

    Skaitymas(k,a,b,c,S,L,M);

    double sum1 = Suma(k, S);
    double sum2 = Suma(k, L);
    double sum3 = Suma(k, M);

    double v1= Vidurkis(sum1, k);
    double v2= Vidurkis(sum2, k);
    double v3= Vidurkis(sum3, k);

    double k1 = Kiek_liko(a,sum1);
    double k2 = Kiek_liko(b,sum2);
    double k3 = Kiek_liko(c,sum3);

    int d1 = Daugiau(k, S, Vidurkis(sum1,k));
    int d2 = Daugiau(k, L, Vidurkis(sum2,k));
    int d3 = Daugiau(k, M, Vidurkis(sum3,k));
    int d4 = d1+d2+d3;

    Isvedimas(sum1, sum2,sum3, v1, v2, v3, k1, k2, k3,  d4 );
    return 0;
}

void Skaitymas(int &k, double &a, double &b, double &c, double S[], double L[], double M[])
{
    ifstream in ("Duomenys.txt");
    in>>k;
    in>>a>>b>>c;
    for(int x=0; x<k; x++)
    {
        in>>S[x]>>L[x]>>M[x];
    }
    in.close();
}

double Suma(int x, double X[])
{
    double sum=0;

    for(int i=0; i<x; i++)
    {
        sum+=X[i];
    }
    return sum;
}

double Vidurkis(double sk, int k)
{
    double y = sk / k;
    return y;
}

double Kiek_liko(double n, double m)
{
    double lik;
    lik = n-m;
    return lik;

}

int Daugiau(int o, double D[], double vid)
{
    int daug=0;
    for(int m=0; m<o; m++)
    {
        if(D[m]>vid)
            daug+=1;
    }
    return daug;
}

void Isvedimas(double sum1, double sum2,double sum3,double v1,double v2,double v3,double k1,double k2,double k3, int d4 )
{
    ofstream out ("Rezultatai.txt");

    out<<"Vaikinai isleido:"<<endl;
    out<<fixed<<setprecision(2)<<sum1<<" "<<sum2<<" "<<sum3<<" "<<endl;
    out<<"Dienos islaidu vidurkis:"<<endl;
    out<<v1<<" "<<v2<<" "<<v3<<endl;
    out<<"Vaikinams liko pinigu:"<<endl;
    out<<"Simui "<<k1<<"; Linui "<<k2<<"; Mantui "<<k3<<endl;
    out<<"Dienø skaicius, kai vaikinai isleido daugiau uz savo dienos vidurki: "<<d4<<endl;

    out.close();
}
