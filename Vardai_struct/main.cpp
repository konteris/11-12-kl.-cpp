#include <iostream>
#include <fstream>

using namespace std;

struct zmogus{
    string pavarde, vardas;
    int kiek=1;
};

int n;

zmogus Z[100];

void Skaitymas();

void Atrinkimas(int &a, zmogus Z1[]);

void Rikiavimas(int a, zmogus Z1[]);

int yra(string ieskoma_pavarde, int a, zmogus Z1[]);

void Rasymas(int a, zmogus Z1[]);

int main()
{
    int a;
    zmogus Z1[100];

    Skaitymas();
    Atrinkimas(a,Z1);
    Rikiavimas(a, Z1);
    Rasymas(a, Z1);

    return 0;
}

void Skaitymas()
{
    ifstream in("vardai.txt");
    in>>n;
    char X[21];

    for(int i=0; i<n; i++)
    {
        in>>ws;
        in.get(X,21);
        Z[i].pavarde = X;

        in>>ws;
        in.get(X,21);
        Z[i].vardas = X;
    }
    in.close();
}

void Atrinkimas(int &a, zmogus Z1[])
{
   a=0;
   for(int i=0; i<n; i++)
   {
      int m=yra(Z[i].vardas, a,  Z1);
      if(m == -1)
      {
          Z1[a]=Z[i];
          a++;
      }
      else
      {
          Z1[m].kiek++;
      }
   }
}

int yra(string ieskomas_vardas, int a, zmogus Z1[])
{
     int k=0;
     for(int i=0; i<a; i++)
     {
         if(Z1[i].vardas == ieskomas_vardas)
         {
           return i;
         }
     }
    return -1;
}

void Rikiavimas(int a, zmogus Z1[])
{
    for(int i=0; i<a-1;i++)
        for(int j=i+1; j<a; j++)
            if(Z1[i].kiek > Z1[j].kiek || Z1[i].kiek ==Z1[j].kiek && Z1[i].vardas > Z1[j].vardas)
            swap(Z1[i], Z1[j]);
}

void Rasymas(int a, zmogus Z1[])
{
    ofstream out("vardairez.txt");

    for(int i=0; i<a; i++)
        out<<Z1[i].vardas<< " "<<Z1[i].kiek<<endl;

    out.close();
}
