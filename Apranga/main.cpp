#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

void duomenys(int &a, int &b, int &c, int &d, int &e);
void rezultatai(int &a, int &b, int &c, int &d, int &e, int &m);
void isvedimas(int &a, int &b, int &c, int &d, int &e, int &m);

int main()
{
    int a,b,c,d, e;
    int m;
    duomenys(a,b,c,d,e);
    rezultatai(a,b,c,d,e,m);
    isvedimas(a,b,c,d,e,m);


    return 0;
}
void duomenys(int &a, int &b, int &c, int &d, int &e)
{
    ifstream in ("Komponentai.txt");
    in>>a>>b>>c>>d>>e;
    in.close();

}

void rezultatai(int &a, int &b, int &c, int &d, int &e, int &m)
{
    m = min(min(min(a, b), min(c,d)),e );
    a-=m;
    b-=m;
    c-=m;
    d-=m;
    e-=m;
}

void isvedimas(int &a, int &b, int &c, int &d, int &e, int &m)
{
    ofstream out("Rezultatai.txt");
    out<<m<<endl;
    out<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e;

    out.close();
}

