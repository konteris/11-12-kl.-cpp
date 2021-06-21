#include <iostream>
#include <fstream>
/*
5 20 2500
5 14 5 500 700 400 200
7 25 8 800 450 600 250 400 600 700
6A 12 7 450 220 400 750 560 420
10 42 9 450 520 600 320 290 560 470 300
10A 15 5 490 250 360 540
*/
using namespace std;

struct Marsrutas
{
    string nr;
    int keleiviai, stoteles;
    int ats[50], Atstumas;

};
Marsrutas M[100];

void Skaitymas(int &n, int &k, int &m);
int Ilgis(int x, int X[]);
bool Tikrinimas(int k, int m, int kel, int ilg);
void Rasymas(int n, int k, int m,string grupe);
int main()
{
    int n,k,m;
    Skaitymas(n,k,m);
    Rasymas(n,k,m, "Pirmos");
    Rasymas(n,k,m, "Antros");
    return 0;
}

void Skaitymas(int &n, int &k, int &m)
{
    ifstream in("autobusai_data.txt");
    in>>n>>k>>m;
    for(int i=0; i<n; i++)
    {
        in>>M[i].nr>>M[i].keleiviai>>M[i].stoteles;
        for(int j=1; j<M[i].stoteles; j++)
        {
            in>>M[i].ats[j];
        }
        M[i].Atstumas = Ilgis(M[i].stoteles, M[i].ats);
    }
    in.close();
}

int Ilgis(int x, int X[])
{
    int sum=0;
    for(int i=1; i<x; i++)
        sum+=X[i];
    return sum;
}
bool Tikrinimas(int k, int m, int kel, int ilg)
{
    if(kel>= k && ilg>m)
        return true;
    else
        return false;
}

void Rasymas(int n, int k, int m, string grupe)
{
    ofstream out("autobusai_res.txt", ios::app);
    int x=0, y=0;
    out<<grupe<<" grupës marðrutai:"<<endl;
    for(int i=0; i<n; i++)
        if(grupe=="Pirmos")
        {
            if(Tikrinimas(k,m,M[i].keleiviai, M[i].Atstumas))
            {
                out<<M[i].nr<<" "<<M[i].keleiviai<<" "<<M[i].Atstumas<<endl;
            }
            else
                x++;
        }
        else
        {
            if(!Tikrinimas(k,m,M[i].keleiviai, M[i].Atstumas))
            {
                out<<M[i].nr<<" "<<M[i].keleiviai<<" "<<M[i].Atstumas<<endl;
            }
            else
                y++;
        }

    if(x>0)
        out<<"Pirmos grupës marðrutø nëra"<<endl;
    if(y>0)
        out<<"Antros grupës marðrutø nëra"<<endl;
    out.close();
}
