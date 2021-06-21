#include <iostream>
#include <fstream>

using namespace std;

struct Avis
{
    string vardas, DNR;
    int k=0; //koficientas
};

Avis A[21];

int n;//aviu skaicius

void Skaitymas(int &m, int &eil);
int koef_radimas(int m, string a, string b);
void Rikiavimas();
void Isvedimas();
int main()
{
    int m, eil;// m - dnr ilgis, eil- tiriama avis
    Skaitymas(m,eil);

    for(int i=0; i<n; i++)
    {
        A[i].k = koef_radimas(m,A[i].DNR, A[eil-1].DNR); //priskiriu koficienta kiekvienai aviai
    }

    Rikiavimas();
    Isvedimas();
    return 0;
}

void Skaitymas(int &m, int &eil)
{

    ifstream in("U2.txt");
    in>>n>>m>>eil;

    char V[11];

    for(int i=0; i<n; i++)
    {
        in>>ws;
        in.get(V,11);
        A[i].vardas = V;

        in>>ws;
        in>>A[i].DNR;
    }
    in.close();
}

int koef_radimas(int m, string a, string b)
{
    int koef = 0;
    for(int i=0; i<m; i++)
    {
        if(a[i] == b[i])
            koef++;
    }
    return koef;
}

void Rikiavimas()
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(A[i].k < A[j].k || A[i].k==A[j].k && A[i].vardas < A[j].vardas)
                swap(A[i], A[j]);
        }
    }
}

void Isvedimas()
{
    ofstream out("U2rez.txt");
    out << A[0].vardas<<endl;
    for(int i=1; i<n; i++)
        out<< A[i].vardas<<" "<< A[i].k<<endl;
    out.close();
}
