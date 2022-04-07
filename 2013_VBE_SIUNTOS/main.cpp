#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

struct Imone{
    string vardas;
    int x,y;
};

Imone Im[51];
int n,m;

void Skaitymas();
int Atstumas_prieki_atgal(int ox, int oy);
void Rasymas();

int main()
{
    Skaitymas();
    Rasymas();
    return 0;
}
void Skaitymas()
{
    ifstream in("U1.txt");
    in>>n>>m;
    char Pav[11];
    for(int i=0;i<n;i++)
    {
        in>>ws;
        in.get(Pav,11);
        Im[i].vardas = Pav;
        in>>Im[i].x>>Im[i].y;
    }
    in.close();
}
int Atstumas_prieki_atgal(int ox, int oy){
    return 2*(ox * ((ox>0) - (ox<0))) + 2*(oy * ((oy>0) - (oy<0)));
}
void Rasymas()
{
    ofstream out("U1rez.txt");
    int kiek_nuvaziavo=0, i;
    string pav="";
    for(i=0;i<n;i++)
    {
        if(kiek_nuvaziavo+Atstumas_prieki_atgal(Im[i].x, Im[i].y) > m)
            break;
        pav=Im[i].vardas;
        kiek_nuvaziavo+=Atstumas_prieki_atgal(Im[i].x, Im[i].y);
    }
    out<<i<<" "<<kiek_nuvaziavo<<" "<<pav<<endl;
    out.close();
}
