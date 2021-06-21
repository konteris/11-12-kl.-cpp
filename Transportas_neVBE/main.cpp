#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct Bus
{
    int nr;
    string rusis;
    int m, visas, k,M[50];
    //int visas;

};
int n;
Bus B[100];

void Skaitymas(Bus B1[]);
void Atrinkimas(int &a,Bus B1[]);
int Ilgiausias();
void Trumpiausias(int &t, int &t1);
int yra(string ieskoma_rusis, int a, Bus B1[]);
void Rasymas(int a, Bus B1[],int t, int t1);

int main()
{
    int a;
    int t=0;
    int t1=1;
    Bus B1[100];
    Skaitymas(B1);
    Atrinkimas(a,B1);
    Trumpiausias(t,t1);

    Rasymas(a,B1,t,t1);

    return 0;
}

void Skaitymas(Bus B1[])
{
    ifstream in("Duom2.txt");
    in>>n;

    char R[15];

    for(int i=0; i<n; i++)
    {
        in>>ws;
        in>>B[i].nr;
        in>>ws;

        in.get(R, 15);
        B[i].rusis = R;

        in>>B[i].m;

        for(int j=1; j<B[i].m; j++)
        {
            in>>B[i].M[j];
            B[i].visas += B[i].M[j];
        }
    }
    in.close();
}

void Atrinkimas(int &a, Bus B1[])
{

    a=0;
     //kiek marsrutu yra
    for(int i=0; i<n; i++)
    {
        int b = yra(B[i].rusis, a, B1);
        B[i].k=1;

        if(b==-1)
        {
            B1[a] = B[i]; //tiesiog sukuriu nauja masyva
            a++;
        }
        else
        {
            B1[b].visas += B[i].visas; // naujam masyve pridedo to paties marsruto ilgi
            B1[b].k++; // jeigu taip atsitinka, tai +1
        }

    }
}

int Ilgiausias()
{
    int kelint=0;

    for(int i=0; i<n; i++)
        if(B[i].visas > B[kelint].visas)
            kelint = i;
    return kelint;
}

void Trumpiausias(int &t, int &t1)
{
    t=0;
    t1=1;

    for(int i=0; i<n; i++)
        {
            for(int j=1; j<B[i].m; j++)
            {
                if((B[i].M[j]) < (B[t].M[t1]))
                {
                   t=i;
                   t1=j;
                }
            }
        }

}
int yra(string ieskoma_rusis, int a, Bus B1[])
{
    for(int i=0; i<a; i++)
    {
        if(B1[i].rusis == ieskoma_rusis)
        {
            return i;
        }
    }
    return -1;
}

void Rasymas(int a, Bus B1[],int t, int t1)
{
    ofstream out ("Rez2.txt");
    int x1,x2,x3 =0;
    string  autobus = "autobusas";
    string mikro = "mikroautobusas";
    string trolei = "troleibusas";

    for(int i=0; i<a; i++)
    {
        out<<setw(14)<<B1[i].rusis<<" "<<B1[i].k<<" "<<B1[i].visas<<endl;
        if(B1[i].rusis == autobus)
            x1++;
        else if(B1[i].rusis == mikro)
            x2++;
        else if(B1[i].rusis == trolei)
            x3++;
    }

    if(x1<=0)
        out<<autobus<<"      nera"<<endl;
    else if(x2<=0)
        out<<mikro<<"   nera"<<endl;
    else if(x3<=0)
        out<<trolei<<"    nera"<<endl;

    int ilg = Ilgiausias();
    out<<B[ilg].rusis<<" "<<B[ilg].nr<<" "<<B[ilg].visas<<endl;

    out<<B[t].rusis<<" "<<B[t].nr<<" "<<B[t].M[t1] ;
    out.close();
}
