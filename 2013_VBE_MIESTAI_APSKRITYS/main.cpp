#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct Vietove
{
    string m, apskr;
    int g;
    int maz;
} ;

int k;

Vietove V[103];

void skaitymas();
void atrinkimas(Vietove V1[], int &a);
int yra(string ieskoma_apskritis, Vietove V1[], int a);
void maziausiai(Vietove V1[], int a);
void rikiavimas(Vietove V1[], int a);
void rasymas(Vietove V1[], int a);

int main()
{
    int a;
    Vietove V1[103];
    skaitymas();
    atrinkimas(V1, a);
    maziausiai(V1,a);
    rikiavimas(V1,a);
    rasymas(V1,a);
    return 0;
}

void skaitymas()
{
    ifstream in("U2.txt");
    in>>k;

    char M[21], A[14];

    for(int i=0; i<k; i++)
    {
        in>>ws;
        in.get(M, 21);
        V[i].m = M;

        in>>ws;

        in.get(A,14);
        V[i].apskr = A;

        in>>V[i].g;
    }

    in.close();
}

int yra(string ieskoma_apskritis, Vietove V1[], int a)
{
    for(int i=0; i<a; i++)
    {
        if(V1[i].apskr == ieskoma_apskritis)
        {
            return i;
        }
    }
    return -1;
}

void atrinkimas(Vietove V1[], int &a)
{
    a=0;

    for(int i=0; i<k; i++)
    {
        int x = yra(V[i].apskr, V1, a);

        if(x == -1)
        {
            V1[a] = V[i];
            a++;
        }
        else
        {
            V1[x].g += V[i].g;
        }
    }
}

void maziausiai(Vietove V1[], int a)
{
    int x=0;

    for(int i=0; i<a; i++)
    {
        x=0;
        V1[i].maz =0;
        for(int j=0; j<k; j++)
        {
            if(V1[i].apskr == V[j].apskr)
            {
                if(V[j].g < V[x].g)
                {
                    x=j;
                }
            }
        }
        V1[i].maz = V[x].g;
    }
}

void rikiavimas(Vietove V1[], int a)
{
    for(int i=0; i< a-1; i++)
    {
        for(int j=i+1; j<a; j++)
        {
            if(V1[i].maz > V1[j].maz || V1[i].maz==V1[j].maz && V1[i].apskr > V1[j].apskr)
                swap(V1[i], V1[j]);
        }
    }
}

void rasymas(Vietove V1[], int a)
{
    //ofstream out("U2rez.txt");

    cout<<a<<endl;

    for(int i=0; i<a; i++)
        cout<<setw(13)<<V1[i].apskr<<V1[i].maz<<" "<<V1[i].g<<endl;

    //out.close();
}
