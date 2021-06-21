#include <iostream>
#include <fstream>
#include <limits.h>

using namespace std;

int Plotas(int a, int b);
int Perimetras(int a, int b);

int main()
{
    ifstream in ("duom.txt");
    ofstream out("rez.txt");
    int k, a, b, s=0, s1=0, didz=INT_MIN, maz=INT_MAX;
    in>>k;
    out<<"Plotai ir perimetrai: "<<endl;
    for(int i=1; i<=k; i++)
    {
        in>>a>>b;
        int Plo = Plotas(a,b);
        s+=Plo;
        int P = Perimetras(a,b);
        s1+=P;
        if(Plo>didz){
            didz=Plo;
        }
        if(Plo<maz){
            maz=Plo;
        }
        out<<"Plotas "<<Plotas(a,b)<<" Perimetras "<<Perimetras(a,b)<<endl;
    }

    out<<"Bendras plotas "<<s<<endl;
    out<<"Bendras perimetras "<<s1<<endl;
    out<<"Max plotas "<<didz<<endl;
    out<<"Min plotas "<<maz<<endl;

    in.close();
    out.close();
    return 0;
}

int Plotas(int a, int b)
{
    return a*b;
}

int Perimetras(int a, int b)
{
    return 2*a+2*b;
}
