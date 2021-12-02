#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
#include <cmath>
using namespace std;

struct Turistas
{
    string Vardas;
    int Eur, cent, Bitai, Bitai_cent;

};

void Skaitymas(int &n, Turistas T[], double &rate_eur, double &rate_cent, double &kursas);
int suma(int x, int y);
void Gido_pinigai(Turistas T[], int n, double kursas, int &gido_sv, int &gido_cent, int &gido_sveiki, int &gido_centai, float &bitu_sum);
void Rasymas(Turistas T[], int gido_sv, int gido_cent,int  gido_sveiki, int gido_centai, int n, float bitu_sum);

int main()
{
    Turistas T[30];
    int n, gido_sv, gido_cent,gido_sveiki,gido_centai;
    double kursas,rate_eur, rate_cent;
    float bitu_sum;
    Skaitymas(n,T,rate_eur,rate_cent,kursas);
    Gido_pinigai(T,n,kursas,gido_sv, gido_cent,gido_sveiki, gido_centai, bitu_sum);
    Rasymas(T,gido_sv, gido_cent, gido_sveiki, gido_centai,n, bitu_sum);
    return 0;
}

void Skaitymas(int &n, Turistas T[], double &rate_eur, double &rate_cent, double &kursas)
{
    ifstream in("Duom.txt");

    in>>n;
    char X[16];

    for(int i=0; i<n; i++)
    {
        in>>ws;
        in.get(X,16);
        T[i].Vardas = X;
        in>>T[i].Eur>>T[i].cent;
    }
    in>>rate_eur>>rate_cent;
    kursas = rate_eur + rate_cent/100;
    double y;
    for(int i=0; i<n; i++)
    {
        float x = kursas * (T[i].Eur * 100 +  T[i].cent);
        T[i].Bitai = x/100;
        y = fmod(x, 100.0);
        T[i].Bitai_cent = y;
    }
    in.close();
}

int suma(int x, int y)
{
    int sum=0;
    sum += x*100 + y;
    return sum;
}
void Gido_pinigai(Turistas T[], int n, double kursas, int &gido_sv, int &gido_cent, int &gido_sveiki, int &gido_centai, float &bitu_sum)
{
    float sum=0;

    for(int i = 0; i < n; i++)
        sum += suma(T[i].Eur, T[i].cent);
    gido_sv=sum/100;
    gido_cent = fmod(sum, 100.0);

    bitu_sum = sum *kursas;
    gido_sveiki = bitu_sum/100;
    gido_centai = fmod(bitu_sum,100.0);
}

void Rasymas(Turistas T[], int gido_sv, int gido_cent,int  gido_sveiki, int gido_centai, int n, float bitu_sum)
{
    ofstream out("Rez.txt");

    float sum=0;
    for(int i=0; i<n; i++)
    {
        sum += suma(T[i].Bitai, T[i].Bitai_cent);
    }

    out<<"Gidas surinko: "<<gido_sv<<" "<<gido_cent<<endl;
    out<<"Gidas gavo: "<<gido_sveiki<<" "<<gido_centai<<endl;
    for(int i=0; i<n; i++)
    {
        out<<left<<setw(15)<<T[i].Vardas<<" "<<T[i].Eur<< " "<<T[i].cent<< " "<<T[i].Bitai<<" "<<T[i].Bitai_cent<<endl;
    }
    if(int(sum) > int(bitu_sum))
        out<<"Daugiau"<<endl;
    else if(int(sum) < int(bitu_sum))
        out<<"Maziau"<<endl;
    else
        out<<"Tiek pat"<<endl;
    out.close();
}
