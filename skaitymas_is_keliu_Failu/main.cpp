#include <iostream>
#include <fstream>

using namespace std;

struct zaidejas
{
    int nr,t;
    string komanda;
};
zaidejas Z1[30];
zaidejas Z2[30];
zaidejas Z3[30];
zaidejas Z4[30];
zaidejas ZZ[120]; //zalgirio visi
zaidejas ZR[120]; //ryto visi
zaidejas ZZ1[12]; //zalgirio nebesikartoja
zaidejas ZR1[12]; //ryto nebesikartoja
int n1,n2,n3,n4;

void skaitymas(char failas[], int &n, zaidejas Z[]);
int tas_pats(int x, int ieskomas_nr, zaidejas X[]);
void atrinkimas(int n, int &ar,int &az, zaidejas Z[]);
int tas_pats1(int a, int ieskomas_nr, zaidejas Z[]);
void atrinkimas1(int &a, int&b, int r, int z);
int suma(int x, zaidejas Z[]);
int rezultatyviausias(int x, zaidejas Z[]);
void rasyti(int n,zaidejas Z[]);
void rasyti_1(int a, int b);
int main()
{
    int ar=0,az=0,a,b;
    skaitymas("duomenys1.txt",n1,Z1);
    skaitymas("duomenys2.txt",n2,Z2);
    skaitymas("duomenys3.txt",n3,Z3);
    skaitymas("duomenys4.txt",n4,Z4);
    atrinkimas(n1,ar,az,Z1);
    atrinkimas(n2,ar,az,Z2);
    atrinkimas(n3,ar,az,Z3);
    atrinkimas(n4,ar,az,Z4);
    atrinkimas1(a,b,ar,az); //pilnai atrinkt
    rasyti(n1,Z1);
    rasyti(n2,Z2);
    rasyti(n3,Z3);
    rasyti(n4,Z4);
    rasyti_1(a,b);
    return 0;
}

void skaitymas(char failas[], int &n, zaidejas Z[])
{
    ifstream in(failas);
    in>>n;
    for(int i=0; i<n; i++)
        in>>Z[i].nr>>Z[i].komanda>>Z[i].t;

    in.close();
}

int tas_pats(int x, int ieskomas_nr, zaidejas X[])
{
    for(int i=0; i<x; i++)
    {
        if(X[i].nr == ieskomas_nr)
            return i;
    }
    return -1;
}

void atrinkimas(int n, int &ar,int &az, zaidejas Z[])
{
    for(int i=0; i<n; i++)
    {
        int x = tas_pats(n,Z[i].nr, ZZ);
        if(Z[i].komanda == "Rytas")
        {
            if(x ==-1)
            {
                ZR[ar] = Z[i];
                ar++;
            }
            else

                ZR[x].t += Z[i].t;
        }
        else
        {
            if(x ==-1)
            {
                ZZ[az] = Z[i];
                az++;
            }
            else
                ZZ[x].t += Z[i].t;

        }

    }
}
// dabar atrinksiu jau ZR ir ZZ masyvuose

int tas_pats1(int a, int ieskomas_nr, zaidejas Z[])
{
    for(int i=0; i<a; i++)
    {
        if(Z[i].nr == ieskomas_nr)
            return i;
    }
    return -1;
}

void atrinkimas1(int &a, int&b, int r, int z)
{
    a=0;
    b=0;
    for(int i=0; i<r; i++)
    {
        int x = tas_pats1(a, ZR[i].nr, ZR1);

        if(x == -1)
        {
            ZR1[a] = ZR[i];
            a++;
        }
        else
        {
            ZR1[x].t += ZR[i].t;
        }
    }

    for(int i=0; i<z; i++)
    {
        int x = tas_pats1(b, ZZ[i].nr, ZZ1);

        if(x == -1)
        {
            ZZ1[b] = ZZ[i];
            b++;
        }
        else
        {
            ZZ1[x].t += ZZ[i].t;
        }
    }
}

int suma(int x, zaidejas Z[])
{
    int s=0;
    for(int i=0; i<x; i++)
    {
        s+=Z[i].t;
    }
    return s;
}

int rezultatyviausias(int x, zaidejas Z[])
{
    int k=0;
    for(int i=0; i<x; i++)
    {
        if(Z[i].t > Z[k].t)
            k=i;
    }
    return k;
}

void rasyti(int n,zaidejas Z[])
{
    ofstream out("rezultatai.txt",ios::app);
    out<<n<<endl;
    for(int i=0; i<n; i++)
        out<<Z[i].nr<<" "<<Z[i].komanda<<" "<<Z[i].t<<endl;

    out.close();
}

void rasyti_1(int a, int b)
{
    ofstream out("rezultatai.txt",ios::app);

    int sr  = suma(a, ZR1);
    int sz  = suma(b, ZZ1);
    int rez_R = rezultatyviausias(a, ZR1);
    int rez_Z = rezultatyviausias(b, ZZ1);

    out<<b<<endl;
    for(int i=0; i<b; i++)
        out<<ZZ1[i].nr<<" "<<ZZ1[i].komanda<<" "<<ZZ1[i].t<<endl;
    out<<"viso: "<<sz<<" tðk."<<endl;
    out<<"rezultatyviausias Nr. "<<ZZ1[rez_Z].nr<< " "<<ZZ1[rez_Z].t<<" tðk."<<endl;


    out<<a<<endl;
    for(int i=0; i<a; i++)
        out<<ZR1[i].nr<<" "<<ZR1[i].komanda<<" "<<ZR1[i].t<<endl;
    out<<"viso: "<<sr<<" tðk."<<endl;
    out<<"rezultatyviausias Nr. "<<ZR1[rez_R].nr<< " "<<ZR1[rez_R].t<<" tðk."<<endl;
    out.close();
}
