#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct zvejys{
    string vardas;
    int k, karosai = 0, karpiai = 0, kuojos = 0;
    int viso = 0;

};
int n;
zvejys Z[100];

void Skaitymas();
int daugiausiai();
void Rasymas();

int main()
{
    Skaitymas();
    Rasymas();
    return 0;
}

void Skaitymas()
{
    ifstream in("U2.txt");
    in>>n;
    char V[11];
    int a,b,c,k;

    for(int i = 0; i <n ; i++)
    {
        in>>ws;
        in.get(V, 11);
        Z[i].vardas = V;

        in>>k;
        for(int j = 0; j < k; j++)
        {
            in>>a>>b>>c;
            Z[i].karosai += a;
            Z[i].karpiai += b;
            Z[i].kuojos += c;

            Z[i].viso += a+b+c;
        }
    }
    in.close();
}

int daugiausiai()
{
    int kelintas=0;

    for(int i=1; i<n; i++)
        if((Z[i].viso) > Z[kelintas].viso)
            kelintas = i;

    return kelintas;
}

void Rasymas()
{
    ofstream out("U2rez.txt");
    for(int i=0; i<n; i++)
    {
        out<<setw(10)<<left<<Z[i].vardas<<setw(5)<<Z[i].karosai<<setw(5)<<Z[i].karpiai<<setw(5)<<Z[i].kuojos<<endl;
    }

    int d = daugiausiai();

    out<<setw(10)<<left<<Z[d].vardas<<setw(5)<<Z[d].viso<<endl;

    out.close();
}
