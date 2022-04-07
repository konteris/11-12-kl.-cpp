#include <iostream>
#include<fstream>

using namespace std;

struct Savivaldybe{
    string savivaldybes_pav, apskritis;
    int mokyklu_skc;
};
struct Apskritis{
    string pavadinimas;
    int savivaldybiu_skc=1, x=1, mokyklos[100];
    int didz_mok_skc;
};
int k,n;
Savivaldybe S[60];

void Skaitymas();
int yra(string ieskoma_apskritis, Apskritis A[], int a1);
void Atrinkimas(int &a1, Apskritis A[]);
int Didziausias(int Y[], int y);
void Rikiavimas(int a1, Apskritis A[]);
void Rasymas(int a1, Apskritis A[]);

int main()
{
    Apskritis A[10];
    int a1;
    Skaitymas();
    Atrinkimas(a1,A);
    Rasymas(a1,A);
    return 0;
}
void Skaitymas()
{
    ifstream in("U2.txt");
    in>>k;
    char X[21], Y[14];
    for(int i=0;i<k;i++)
    {
        in>>ws;
        in.get(X,21);
        S[i].savivaldybes_pav = X;
        in.get(Y,14);
        S[i].apskritis = Y;
        in>>S[i].mokyklu_skc;
    }
    in.close();
}

int yra(string ieskoma_apskritis, Apskritis A[], int a1)
{
    for(int i=0;i<a1;i++)
    {
        if(A[i].pavadinimas==ieskoma_apskritis)
            return i;
    }
    return -1;
}

void Atrinkimas(int &a1, Apskritis A[])
{
    a1=0;
    for(int i=0;i<k;i++)
    {
        int m = yra(S[i].apskritis, A, a1);
        if(m==-1)
        {
            A[a1].pavadinimas = S[i].apskritis;
            A[a1].mokyklos[0]=S[i].mokyklu_skc;
            a1++;
        }
        else
        {
            A[m].mokyklos[A[m].x]=S[i].mokyklu_skc;
            A[m].savivaldybiu_skc++;
            A[m].x++;
        }
    }
}
int Didziausias(int Y[], int y)
{
    int d=0;
    for(int i=0;i<y;i++)
    {
        if(Y[d] < Y[i])
            d=i;
    }
    return Y[d];
}
void Rikiavimas(int a1, Apskritis A[])
{
    for(int i=0;i<a1 -1;i++)
        for(int j=i+1;j<a1;j++)
            if(A[i].didz_mok_skc < A[j].didz_mok_skc or A[i].didz_mok_skc==A[j].didz_mok_skc and A[i].pavadinimas > A[j].pavadinimas)
                swap(A[i], A[j]);
}
void Rasymas(int a1, Apskritis A[])
{
    ofstream out("U2rez.txt");
    for(int i=0;i<a1;i++)
    {
        A[i].didz_mok_skc = Didziausias(A[i].mokyklos, A[i].x);
    }
    Rikiavimas(a1,A);
    out<<a1<<endl;
    for(int i=0;i<a1;i++)
    {
        out<<A[i].pavadinimas<<A[i].savivaldybiu_skc<<" "<<A[i].didz_mok_skc<<endl;
    }
    out.close();
}