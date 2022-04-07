#include <iostream>
#include <fstream>

using namespace std;

struct Stotele{
    string pavadinimas;
    int k;
    int stoteliu_numeriai[51]; //manau nebus daugiau nei 50 skirtingu stoteliu
};
int n;
Stotele S[100];

void Skaitymas(int Numeriai[]);
int Ilgiausias_marsrutas(int X[]);
void Rasymas(int Numeriai[]);
int main()
{
    int Numeriai[51];
    Skaitymas(Numeriai);
    Rasymas(Numeriai);    
    return 0;
}
void Skaitymas(int Numeriai[])
{
    ifstream in("U2.txt");
    in>>n;
    for(int j=1;j<=50;j++)
        Numeriai[j]=0; // sitas Numeriai masyvą ir naudoju sumuoti indekse. Dabar kiekvienas jo elementas =0
    
    char X[21];
    for(int i=0;i<n;i++)
    {
        in>>ws;
        in.get(X,21);
        S[i].pavadinimas = X;
        in>>S[i].k;
        for(int j=0;j<S[i].k ; j++)
            {
                int nr; // papildomas kintamasis kuri nusiskaitysiu
                in>>nr;
                S[i].stoteliu_numeriai[j]=nr; // cia isirasau visus tuos marsrutu numerius. Veliau panaudoju rasyme, kai jau susirandu ilgiausia marsruta(tam turiu Numeriai masyva)
                Numeriai[nr]++; //sicia ir sumuoju, tarkim nr=4(marsruto numeris cia) tai Numeriai[4] atsiranda +1 marsrutas
            }
    }
    in.close();
}
int Ilgiausias_marsrutas(int X[])
{
    int ilg=1;
    for(int i=1;i<=50;i++)
        {
            if(X[ilg] < X[i])
                ilg=i;
        }
    return ilg;
}

void Rasymas(int Numeriai[])
{
    ofstream out("U2rez.txt");
    int marsruto_nr = Ilgiausias_marsrutas(Numeriai);
    out<<marsruto_nr<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<S[i].k ; j++)
            {
                if(S[i].stoteliu_numeriai[j] == marsruto_nr)
                    out<<S[i].pavadinimas<<endl;
            }
    }
    out.close();
}