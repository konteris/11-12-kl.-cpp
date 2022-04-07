#include <iostream>
#include <fstream>

using namespace std;

struct Apygarda
{
    string pavadinimas;
    int k, N, N_dalyvavo; //k - kandidatu skaicius; N - rinkeju skc sarasuose;
    string Vardai[10];
    int Balsai[10];
};

int n;
Apygarda A[20];

void Skaitymas();
void Rikiavimas(int X[], string Y[], int x);
bool Ar_pirmam_rate(int N1, int N_dalyvavo1, int daugiausiai_balsu);
void Rasymas(string pav, string vardas, string vardas1, int N1, int N_dalyvavo1, int balsai);

int main()
{
    Skaitymas();
    for(int i=0; i<n; i++)
    {
        Rikiavimas(A[i].Balsai, A[i].Vardai, A[i].k);
    }
    ofstream out("U1rez.txt");
    out.close();
    for(int i=0; i<n; i++)
    {
        Rasymas(A[i].pavadinimas, A[i].Vardai[0], A[i].Vardai[1], A[i].N, A[i].N_dalyvavo, A[i].Balsai[0]);
    }
    return 0;
}

void Skaitymas()
{
    ifstream in("U1.txt");
    in>>n;
    for(int i=0; i<n; i++)
    {
        in>>A[i].pavadinimas;
        in>>A[i].k>>A[i].N>>A[i].N_dalyvavo;

        char X[11];
        for(int j=0; j<A[i].k; j++)
        {
            in>>ws;
            in.get(X,11);
            A[i].Vardai[j] = X;
            in>>A[i].Balsai[j];
        }
    }
    in.close();
}

void Rikiavimas(int X[], string Y[], int x)
{
    for(int i=0; i<x-1; i++)
    {
        for(int j=i; j<x; j++)
        {
            if(X[i]<X[j])
            {
                swap(X[i],X[j]);
                swap(Y[i],Y[j]);
            }
        }
    }
}

bool Ar_pirmam_rate(int N1, int N_dalyvavo1, int daugiausiai_balsu)
{
    if(N_dalyvavo1 >= N1*0.4 and daugiausiai_balsu > N_dalyvavo1 / 2)
    {
        return true;
    }
    else if(N_dalyvavo1 >= N1*0.4 and daugiausiai_balsu <= N_dalyvavo1 / 2)
        return false;

    else if(N_dalyvavo1 < N1*0.4 and daugiausiai_balsu >=N1*0.2)
        return true;
    else
        return false;
}

void Rasymas(string pav, string vardas, string vardas1, int N1, int N_dalyvavo1, int balsai)
{
    ofstream out("U1rez.txt", ios::app);

    if(Ar_pirmam_rate(N1, N_dalyvavo1, balsai))
    {
        out<<pav<<endl;
        out<<"Laimetojas: "<<vardas<<endl;
    }
    else
    {
        out<<pav<<endl;
        out<<"Pakartotinis balsavimas:"<<endl;
        if(vardas[0]<vardas1[0])
        {
            out<<vardas<<endl;
            out<<vardas1<<endl;
        }
        else
        {
            out<<vardas1<<endl;
            out<<vardas<<endl;
        }
    }
    out.close();
}