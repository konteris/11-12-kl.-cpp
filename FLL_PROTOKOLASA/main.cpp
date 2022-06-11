#include <iostream>
#include<fstream>
using namespace std;

struct Regionas{
    int taskai, nr;
    string pav;
};

struct Protokolas{
    int k;
    struct Regionas R[20];
};

Protokolas P[20]; //visas komandas susidedu

Regionas R1[400]; //susidesiu pirmojo regiono komandas, o poto pildysiu

int n,r1_kiek;

void Skaitymas();
int Kur_iterpti(int x_taskai);
void Iterpimas(string p, int task, int num);
void Rasymas();

int main()
{
    Skaitymas();
    Rasymas();

    return 0;
}

void Skaitymas()
{
    ifstream in("protokolas_data.txt");
    in>>n;
    int m=1;
    for(int i=0; i<n;i++)
    {
        in>>P[i].k;
        for(int j=0;j<P[i].k;j++)
        {
            in>>P[i].R[j].pav>>P[i].R[j].taskai;
            P[i].R[j].nr=m;
        }
        if(i==0) //susidedu pirmo regiono komandas
        {
            for(int j=0;j<P[i].k;j++)
            {
                R1[j].pav = P[i].R[j].pav;
                R1[j].taskai = P[i].R[j].taskai;
                R1[j].nr = 1;
                r1_kiek = P[i].k;
            }
        }  
        m++; //kitas regionas
    }
}

int Kur_iterpti(int x_taskai)
{
    int vieta;
    for(int i=0;i<r1_kiek;i++)
    {
        if(x_taskai>R1[i].taskai)
        {
            vieta=i;
            break;
        }
        else
            vieta = r1_kiek;
    }
    return vieta;
}
void Iterpimas(string p, int task, int num)
{
    int t=Kur_iterpti(task);
    for(int i=r1_kiek; i > t;i--)
        R1[i]=R1[i-1];

    r1_kiek++;
    R1[t].taskai=task;
    R1[t].pav = p;
    R1[t].nr = num;
   // cout<<t<<endl;
}

void Rasymas()
{
    ofstream out("protokolas_res.txt");
    for(int i=1; i<n;i++)
    {
        for(int j=P[i].k-1; j>=0; j--)
        {
            Iterpimas(P[i].R[j].pav, P[i].R[j].taskai, P[i].R[j].nr);
        }
    }
    for(int i=0;i<r1_kiek;i++)
        out<<R1[i].pav<<" "<<R1[i].taskai<<" "<<R1[i].nr<<endl;

    out.close();
}