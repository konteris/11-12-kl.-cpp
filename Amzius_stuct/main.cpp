#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct Zmogus
{
    string vardas;
    int y,m,d,y1,m1,d1;
    long int sum, sum1;
    long int skirtumas;
};
int n;
const int men[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
Zmogus Z[100];

void Skaitymas();
void Dienos();
void Rasymas();
int main()
{
    Skaitymas();
    Dienos();
    Rasymas();
    return 0;
}

void Skaitymas()
{
    ifstream in("U2.txt");
    in>>n;
    char x[26];

    for(int i=0; i<n; i++)
    {
        in>>ws;
        in.get(x, 26);
        Z[i].vardas = x;
        in>>Z[i].y>>Z[i].m>>Z[i].d>>Z[i].y1>>Z[i].m1>>Z[i].d1;
        in>>ws;
    }
    in.close();
}

void Dienos()
{
    for(int i=0; i<n; i++)
    {
        Z[i].sum = Z[i].y*365 + Z[i].d;
        for(int j=1; j<Z[i].m; j++)
            Z[i].sum += men[j];

        Z[i].sum1 = Z[i].y1*365 + Z[i].d1;
        for(int j=1; j<Z[i].m1; j++)
            Z[i].sum1 += men[j];

        Z[i].skirtumas = Z[i].sum1 - Z[i].sum;
    }
}

void Rasymas()
{
    ofstream out("U2rez.txt");

    for(int i=0; i<n; i++)
    {
        out<< setw(25)<<Z[i].vardas<<Z[i].y<<" "<<Z[i].m<<" "<<Z[i].d<<" "<<Z[i].y1<<" "<<Z[i].m1<<" "<<Z[i].d1<<" "<<Z[i].skirtumas<<endl;
    }

    out.close();
}
