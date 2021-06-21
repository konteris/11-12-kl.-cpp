#include <iostream>
#include <fstream>
#include <limits.h>
#include <iomanip>
#include <cmath>

using namespace std;

double Rezultatas(int a, int b, int c, int d);

string klaida(int c, int d);

int main()
{
    ifstream in ("Argumentai.txt");
    ofstream out("Rezultatai.txt");
    int n, k=0;
    in>>n;
    double didz=INT_MIN;
    for(int i=1; i<=n; i++)
    {
        int a,b,c,d;
        in>>a>>b>>c>>d;
        if (c==0||d<0)
            out<<klaida(c,d)<<endl;
        else
        {
            double r=Rezultatas(a,b,c,d);
            out<<fixed<<setprecision(2)<<r<<endl;
            if(r>didz)
                didz=r;
            k++;

        }
    }
    if(k==0)
        didz=0;

    out<<didz<<endl;
    in.close();
    out.close();
    return 0;
}

double Rezultatas(int a, int b, int c, int d)
{
    return double (a+b)/(c*(-c))+ (sqrt(d));
}

string klaida(int c, int d)
{
    if(c==0)
    {
        return "KLAIDA! c negali būti lygus nuliui!";
    }
    if(d<0)
    {
        return "KLAIDA! d negali būti neigiamas!";
    }
}


