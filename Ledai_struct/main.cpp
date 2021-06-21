#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct ledai
{
    string pavadinimas;
    int kiekis;
    double kaina;
    double suma;
};

int n;
ledai L[50];

void Skaitymas();
void Rasymas(int a,ledai L1[]);
void Atrinkimas(int &a,ledai L1[]);
void Rikiavimas(int a,ledai L1[]);
int yra(string ieskomas_pavadinimas,ledai L1[],int a);


int main()
{
    int a;
    ledai L1[100];
    Skaitymas();
    Atrinkimas(a,L1);
    Rikiavimas(a,L1);
    Rasymas(a,L1);

}

void Skaitymas()
{
    ifstream in("ledai.txt");

    in>>n;
    char A[21];

    for(int i=0; i<n; i++)
    {
        in>>ws;
        in.get(A, 21);
        L[i].pavadinimas = A;
        in>>L[i].kiekis>>L[i].kaina;

        L[i].suma = L[i].kiekis * L[i].kaina;
    }
    in.close();
}

void Atrinkimas(int &a, ledai L1[])
{
    a=0;
    for(int i = 0; i<n; i++)
    {
        int k = yra(L[i].pavadinimas,L1,a);//surandu kurioje vietoje naujame masyve yra i-tasis pavadinimas
        if(k==-1)//jei tokio pavadinimo nera
        {
            L1[a]=L[i];//irasau nauja saldainiu rusi ir visus duomenis apie ja
            a++;//padidinu vienetu turimø naujo masyvo irasu kieki
        }
        else
            L1[k].suma+=L[i].suma;//i k-taja vieta prie bendros sumos pridedu
    }
}

int yra(string ieskomas_pavadinimas,ledai L1[],int a)
{

    for(int i=0; i<a; i++)
        if(L1[i].pavadinimas==ieskomas_pavadinimas)
            return i;//jei toks pavadinimas yra naujam masyve nurodau kurioje pozicijoje
    return -1;   //jei toks pavadinimas dar neáraðytas
}

void Rikiavimas(int a,ledai L1[])
{
    for(int i=0; i<a-1; i++)
        for(int j=i+1; j<a; j++)
            if(L1[i].suma<L1[j].suma || L1[i].suma==L1[j].suma && L1[i].pavadinimas>L1[j].pavadinimas)
                swap(L1[i],L1[j]);

}

void Rasymas(int a,ledai L1[])
{
    ofstream out("ledairez.txt");
    for(int i=0; i<a; i++)
    {
        out<<L1[i].pavadinimas<<" "<<fixed<<setprecision(2)<<L1[i].suma<<endl;
    }
    out.close();
}
