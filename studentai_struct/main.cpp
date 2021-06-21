#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct studentas
{
    string vardas, kodas;
    int k;
    double vid;
};

studentas S[200];
studentas St[200];
int n;

void skaitymas();
void stipendija(int &a);
int didziausias(int a, studentas Y[]);
void rasymas(int a);

int main()
{
    int a;
    skaitymas();
    stipendija(a);
    rasymas(a);
    return 0;
}

void skaitymas()
{
    ifstream in("stud.txt");
    in>>n;
    char Z[21], Z1[8];

    for(int i=0; i<n; i++)
    {
        in>>ws;
        in.get(Z, 21);
        S[i].vardas = Z;

        in>>S[i].k;

        in.get(Z1, 8);
        S[i].kodas = Z1;

        in>>S[i].vid;

    }

    in.close();
}

void stipendija(int &a)
{
    a=0;

    for(int i=0; i<n; i++)
    {
        if(S[i].vid > 9.5)
        {
            St[a] = S[i];
            a++;
        }
    }
}

int didziausias(int a, studentas Y[])
{
    int d=0;

    for(int i=0; i<a; i++)
    {
        if(Y[i].vid > Y[d].vid)
            d=i;
    }
    return d;
}

void rasymas(int a)
{
    ofstream out("studrez.txt");
    for(int i=0; i<n; i++)
        out<<S[i].vardas<<" "<<S[i].k<<" "<<S[i].kodas<< " "<<fixed<<setprecision(1)<<S[i].vid<<endl;
    out<<"Padidinta stipendija gaus: "<<a<<" stud."<<endl;
    for(int i=0; i<a; i++)
        out<<St[i].vardas<<" "<<St[i].k<<" "<<St[i].kodas<< " "<<fixed<<setprecision(1)<<St[i].vid<<endl;

    int didz = didziausias(a, St);
    out<<"Didziausias pazymiu vidurkis:"<<endl;
    out<<St[didz].vardas<<" "<<St[didz].k<<" "<<St[didz].kodas<< " "<<fixed<<setprecision(1)<<St[didz].vid<<endl;
    out.close();
}
