#include <iostream>
#include <fstream>

using namespace std;

struct sportas
{
    string pratimas;
    int kiek, suma;
};
int n;

sportas S[100];

void Skaitymas();
void Rasymas(int a,sportas S1[]);
void Atrinkimas(int &a,sportas S1[]);
void Rikiavimas(int a,sportas S1[]);
int yra(string ieskomas_pratimas,sportas S1[],int a);

int main()
{
    int a;
    sportas S1[100];
    Skaitymas();
    Atrinkimas(a,S1);
    Rikiavimas(a,S1);
    Rasymas(a,S1);


    return 0;
}

void Skaitymas()
{
    ifstream in("U2.txt");
    in>>n;
    char X[21];

    for(int i=0; i<n; i++)
    {
        in>>ws;
        in.get(X, 21);
        S[i].pratimas= X;

        in>>S[i].kiek;

        S[i].suma+=S[i].kiek;
    }
}

void Atrinkimas(int &a,sportas S1[])
{
    a=0;

    for(int i=0; i<n; i++)
    {
        int k = yra(S[i].pratimas, S1, a);
        if(k==-1)
        {
            S1[a] = S[i];
            a++;
        }
        else
            S1[k].suma+= S[i].suma;
    }
}

int yra(string ieskomas_pratimas,sportas S1[],int a)
{
    for(int i=0; i<a; i++)
        if(S1[i].pratimas == ieskomas_pratimas )
            return i;
    return -1;

}

void Rikiavimas(int a, sportas S1[])
{
    for(int i=0; i<a-1; i++)
        for(int j=i+1; j<a; j++)
            if(S1[i].suma<S1[j].suma || S1[i].suma==S1[j].suma && S1[i].pratimas>S1[j].pratimas)
                swap(S1[i], S1[j]);
}

void Rasymas(int a, sportas S1[])
{
    ofstream out("U2rez.txt");

    for(int i=0; i<a; i++)
        out<<S1[i].pratimas<<" "<<S1[i].suma<<endl;

    out.close();
}
