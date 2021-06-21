#include <iostream>
#include <fstream>

using namespace std;

struct Abonentas
{
    int tel;
    string zmogus, raj;
    int sas, skol; //sas-saskaita, skol - jeigu yra skola tai 1

};


Abonentas A[100];

int n;

void Skaitymas();
int tas_pats(string ieskomas_raj, Abonentas A1[], int a);
int Daugiausiai(int a, Abonentas A1[]);
void Atrinkimas(int &a, Abonentas A1[]);
void Skolininku_sar(int a, Abonentas A1[]);
void Rikiavimas(int a, Abonentas A1[]);
void Rasymas(int a, Abonentas A1[]);

int main()
{
    Abonentas A1[100];
    int a;
    Skaitymas();
    Atrinkimas(a,A1);
    Rikiavimas(a,A1);
    Skolininku_sar(a,A1);
    Rasymas(a,A1);
    return 0;
}

void Skaitymas()
{
    ifstream in("u3duom.txt");

    in>>n;
    char Z[18];
    char S[13];

    for(int i=0; i<n; i++)
        A[i].skol = 0;

    for(int i=0; i<n; i++)
    {

        in>>ws;
        in>>A[i].tel;

        in>>ws;
        in.get(Z, 18);
        A[i].zmogus = Z;

        in>>ws;
        in.get(S,13);
        A[i].raj = S;


        in>>A[i].sas;

        if(A[i].sas<0)
            A[i].skol=1;
    }
    in.close();
}

int tas_pats(string ieskomas_raj, Abonentas A1[], int a)
{
    for(int i=0; i<a; i++)
    {
        if(A1[i].raj == ieskomas_raj)
        {
            return i;
        }
    }
    return -1;
}

void Atrinkimas(int &a, Abonentas A1[])
{
    a=0;

    for(int i=0; i<n; i++)
    {
        int t = tas_pats(A[i].raj, A1, a);
        if(t==-1)
        {
            A1[a] = A[i];
            a++;
        }
        else
            A1[t].skol += A[i].skol;
    }
}

int Daugiausiai(int a, Abonentas A1[])
{
    int k=0;
    for(int i=0; i<a; i++)
    {
        if(A1[i].skol > A1[k].skol)
            k=i;
    }
    return k;
}

void Skolininku_sar(int a, Abonentas A1[])
{
    for(int i=0; i<n-1; i++)
    {
        int m=i;
        Abonentas A2;
        for(int j=i+1; j<n; j++)
            if(A[m].zmogus > A[j].zmogus)
                m=j;
        A2 = A[m];
        for(int x=m; x>i; x--)
            A[x] = A[x-1];
        A[i]=A2;
    }
}

void Rikiavimas(int a, Abonentas A1[])
{
    for(int i=0; i<a-1; i++)
    {
        for(int j=i+1; j<a; j++)
        {
            if(A1[i].raj > A1[j].raj)
                swap(A1[i], A1[j]);
        }
    }
}

void Rasymas(int a, Abonentas A1[])
{
    ofstream out("u3rez.txt");

    out<<"Kauno miesto rajonu sarasas:"<<endl;
    for(int i=0; i<a; i++)
        out<<A1[i].raj<<endl;
    //--------------------------------------------------------------
    int d = Daugiausiai(a, A1);
    string rajonas = A1[d].raj;
    out<<"Daugiausiai skolininku turintis miesto rajonas: "<<rajonas<<endl;
    //---------------------------------------------------------------------------
    out<<"Skolininku sarasas:"<<endl;
    for(int i=0; i<n; i++)
    {
        if(A[i].raj==rajonas && A[i].sas<0)
        {
            out<<A[i].tel<<" "<<A[i].zmogus<<" "<<A[i].sas<<endl;
        }
    }

    out.close();
}
