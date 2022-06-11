#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Zmogus
{
    string vardas, kodas,menesis;
    int  metai, men_skaicius, diena;

};
int n;
Zmogus Z[99];
Zmogus Z_m[99];
Zmogus Z_v[99];

int amzius[7]= {0,18,18,19,19,20,20};

void Skaitymas(int &m, int &v);
void duom_isskyrimas(string kodasx, int &year, int &month, int &day);
string menuo(int menesiukai);
void Duomenys(int v, int m);
void Rikiavimas(int x, Zmogus X[]);
void Rasymas(int v, int m);

int main()
{
    int m=0, v=0;
    Skaitymas(m,v);
    Duomenys(n,m);
    Rikiavimas(m,Z_m);
    Rikiavimas(v,Z_v);
    Rasymas(v,m);
    return 0;
}
void Skaitymas(int &m, int &v)
{
    ifstream in("gimine_data.txt");
    in>>n;
    for(int i=0; i<n; i++)
    {
        string x, y;
        in>>x>>y;
        int yy = y[0]-'0';
        if(yy%2==0)
        {
            Z_m[m].vardas = x;
            Z_m[m].kodas = y;
            m++;
        }
        else
        {
            Z_v[v].vardas = x;
            Z_v[v].kodas = y;
            v++;
        }
    }
    in.close();
}
void duom_isskyrimas(string kodasx, int &year, int &month, int &day)
{
    if(kodasx.length()==11)
    {
        string y,m="",d="";
        int pirmas = kodasx[0]-'0';
        y = to_string(amzius[pirmas])+ kodasx[1]+ kodasx[2];
        year = stoi(y);

        if(kodasx[3]=='0')
            m+=kodasx[4];
        else
        {
            m+=kodasx[3];
            m+=kodasx[4];
        }
        month = stoi(m);

        if(kodasx[5]=='0')
            d+=kodasx[6];
        else
        {
            d+=kodasx[5];
            d+=kodasx[6];
        }
        day = stoi(d);
    }
}

string menuo(int menesiukai)
{
    string pavadinimai[13]= {"","sausio", "vasario", "kovo", "balandzio", "geguzes", "birzelio", "liepos", "rugpjucio", "rugsejo", "spalio", "lapkricio", "gruodzio"};
    return pavadinimai[menesiukai];
}

void Duomenys(int v, int m)
{

    for(int i=0; i<m; i++)
    {
        duom_isskyrimas(Z_m[i].kodas, Z_m[i].metai, Z_m[i].men_skaicius, Z_m[i].diena);
        Z_m[i].menesis = menuo(Z_m[i].men_skaicius);
    }


    for(int i=0; i<v; i++)
    {
        duom_isskyrimas(Z_v[i].kodas, Z_v[i].metai, Z_v[i].men_skaicius, Z_v[i].diena);
        Z_v[i].menesis = menuo(Z_v[i].men_skaicius);
    }


}

void Rikiavimas(int x, Zmogus X[])
{
    for(int i=0; i<x-1; i++)
    {
        for(int j=i; j<x; j++)
        {
            if(X[i].metai>X[j].metai or (X[i].metai==X[j].metai and X[i].men_skaicius >X[j].men_skaicius) or (X[i].metai==X[j].metai and X[i].men_skaicius ==X[j].men_skaicius and X[i].diena > X[j].diena))
            {
                swap(X[i], X[j]);
            }
        }
    }
}

void Rasymas(int v, int m)
{
    ofstream out("gimine_res.txt");
    cout<<"MOTERYS"<<endl;
    if(m==0)
        cout<<"NERASTA"<<endl;
    else
    {
        for(int i=0; i<m; i++)
            cout<<Z_m[i].vardas<<" "<<Z_m[i].metai<<" "<<Z_m[i].menesis<<" "<<Z_m[i].diena<<endl;
    }
    //---------------------------------
    cout<<"VYRAI"<<endl;
    if(v==0)
        cout<<"NERASTA"<<endl;
    else
    {
        for(int i=0; i<v; i++)
            cout<<Z_v[i].vardas<<" "<<Z_v[i].metai<<" "<<Z_v[i].menesis<<" "<<Z_v[i].diena<<endl;
    }


    out.close();
}