#include <iostream>
#include <fstream>

using namespace std;

struct Sportininkas
{
    string vardas;
    int nr, t1,t2,t=0;
};

int n,m;
Sportininkas S_v[30];
Sportininkas S_m[30];

void Skaitymas(int &m_kiek, int &v_kiek);
void Rikiavimas(Sportininkas X[], int x);
void Rasymas(string grupe, Sportininkas X[], int x);
int main()
{
    ofstream out("U2rez.txt");
    out.close();
    int m_kiek =0, v_kiek=0;
    Skaitymas(m_kiek, v_kiek);
    Rikiavimas(S_v,v_kiek);
    Rikiavimas(S_m,m_kiek);
    Rasymas("Merginos", S_m,m_kiek);
    Rasymas("Vaikinai", S_v,v_kiek);
    return 0;
}

void Skaitymas(int &m_kiek, int &v_kiek)
{
    ifstream in("U2.txt");
    in>>n;
    char X[21];
    for(int i=0; i<n; i++)
    {
        string vardas_x;
        int nr_x,val,mi,sec;
        in>>ws;
        in.get(X,21);
        vardas_x = X;
        in>>nr_x>>val>>mi>>sec;
        if(nr_x<200)
        {
            S_m[m_kiek].vardas=vardas_x;
            S_m[m_kiek].nr=nr_x;
            S_m[m_kiek].t1=val*3600+mi*60+sec;
            m_kiek++;
        }
        else
        {
            S_v[v_kiek].vardas=vardas_x;
            S_v[v_kiek].nr=nr_x;
            S_v[v_kiek].t1=val*3600+mi*60+sec;
            v_kiek++;
        }
        in>>ws;
    }

    in>>m;
    for(int i=0; i<m; i++)
    {
        int nrx,val,mi,sec, x1,x2,x3,x4;
        in>>nrx>>val>>mi>>sec;
        if(nrx<200)
        {
            in>>x1>>x2;
            for(int j=0; j<m_kiek; j++)
            {
                if(nrx == S_m[j].nr)
                {
                    S_m[j].t2=val*3600+mi*60+sec+(5-x1)*60+(5-x2)*60;
                    S_m[j].t = S_m[j].t2 - S_m[j].t1;

                }
            }
        }
        else
        {
            in>>x1>>x2>>x3>>x4;
            for(int j=0; j<v_kiek; j++)
            {
                if(nrx==S_v[j].nr)
                {
                    S_v[j].t2=val*3600+mi*60+sec+(5-x1)*60+(5-x2)*60+(5-x3)*60+(5-x4)*60;
                    S_v[j].t = S_v[j].t2 - S_v[j].t1;
                }
            }
        }
    }

    in.close();
}

void Rikiavimas(Sportininkas X[], int x)
{
    for(int i=0;i<x-1;i++)
        for(int j=i;j<x;j++)
            if(X[i].t > X[j].t or X[i].t == X[j].t and X[i].vardas < X[j].vardas)
                swap(X[i],X[j]);
}

void Rasymas(string grupe, Sportininkas X[], int x)
{
    ofstream out("U2rez.txt", ios::app);
    int val,minut;
    out<<grupe<<endl;
    for(int i=0;i<x;i++)
    {
        if(X[i].t > 0)
        {
            minut = X[i].t/60;
            val = minut/60;
            out<<X[i].nr<<" "<<X[i].vardas<<" "<<int(val)<<" "<< int(minut%60)<<" "<<int(X[i].t%60)<<endl;
        }

    }

    out.close();
}
