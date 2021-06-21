#include <iostream>
#include <fstream>

using namespace std;
struct dalyvis
{
    string vardas;
    int taskai;
};
struct mokykla
{
    string pavadinimas;
    int k;
    dalyvis D[30];
};
struct finalas
{
    string vardas;
    int taskai;
    string pavadinimas;
};
mokykla M[50];
int n;//mokykl¸ kiekis
int f,p;//finalinink¸ sk
finalas Fpagrindinis[150],Fpapildomas[1500];

void skaityti();
void rikiuoti(int x,dalyvis X[]);
void atrinkti();
void rasyti();
bool nera(string vardas);
void atrinkti1(int t);
void rikiuoti1(int x,finalas X[]);
int main()
{
    skaityti();
    atrinkti();//ATRENKAMAS PAGRINDINIS S1RA6AS
    rikiuoti1(f,Fpagrindinis);
    int taskuriba=Fpagrindinis[f-1].taskai;//NUSTATOMA ZEMIAUSIA TASKU RIBA
    atrinkti1(taskuriba);//ATRENKAMAS PAPILDOMAS SARASAS
    rasyti();
    return 0;
}
void skaityti()
{
    ifstream in("U2.txt");
    in>>n;
    for(int i=0; i<n; i++)
    {
        in>>ws;
        getline(in,M[i].pavadinimas);
        in>>M[i].k;
        for(int j=0; j<M[i].k; j++)
        {
            char e[21];
            in>>ws;
            in.get(e,21);
            M[i].D[j].vardas=e;
            in>>M[i].D[j].taskai;


        }
    }
}

void atrinkti()
{
    f=0;
    dalyvis X[30];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<M[i].k; j++)//PAIDAROM DALYVIU DUOMENU KOPIJA, NES NENORIM PAKEISTI PRADINIO SARASO EILES TVARKOS
            X[j]=M[i].D[j];
        rikiuoti(M[i].k,X);
        for(int j=0; j<3; j++)
        {
            Fpagrindinis[f].vardas=X[j].vardas;
            Fpagrindinis[f].taskai=X[j].taskai;
            Fpagrindinis[f].pavadinimas=M[i].pavadinimas;
            f++;
        }
    }
}
void rikiuoti(int x,dalyvis X[])
{
    for(int i=0; i<x-1; i++)
        for(int j=i+1; j<x; j++)
            if(X[i].taskai<X[j].taskai||X[i].taskai==X[j].taskai&&X[i].vardas>X[j].vardas)
                swap(X[i],X[j]);
}
void rikiuoti1(int x,finalas X[])
{
    for(int i=0; i<x-1; i++)
        for(int j=i+1; j<x; j++)
            if(X[i].taskai<X[j].taskai||X[i].taskai==X[j].taskai&&X[i].vardas>X[j].vardas)
                swap(X[i],X[j]);
}

void atrinkti1(int t)
{
    p=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<M[i].k; j++)
        {
            if(M[i].D[j].taskai>=t&&nera(M[i].D[j].vardas))
            {
                Fpapildomas[p].vardas=M[i].D[j].vardas;
                Fpapildomas[p].taskai=M[i].D[j].taskai;
                Fpapildomas[p].pavadinimas=M[i].pavadinimas;
                p++;
            }
        }

    }
}
//JEI DALYVIS SURINKO TIEK PAT TASKU KAIP PASKUTINIS PAGRINDINIO SARASO NARYS, TIKRINAM AR JIS YRA PAGRINDINIAME SARASE
bool nera(string vardas)
{
    for(int i=0; i<f ; i++)
        if(Fpagrindinis[i].vardas==vardas)
            return false;
    return true;
}
void rasyti()
{
    ofstream out("U2rez.txt");
    out<<"PAGRINDINIS SĄRAŠAS\n";
    for(int i=0; i<f ; i++)
        out<<i+1<<". "<<Fpagrindinis[i].vardas<<" "<<Fpagrindinis[i].taskai<<" "<<Fpagrindinis[i].pavadinimas<<endl;
    out<<"PAPILDOMAS SĄRAŠAS\n";
    for(int i=0; i<p ; i++)
        out<<Fpapildomas[i].vardas<<" "<<Fpapildomas[i].taskai<<" "<<Fpapildomas[i].pavadinimas<<endl;
}
