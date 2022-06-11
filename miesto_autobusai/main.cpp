#include <iostream>
#include <fstream>

using namespace std;

struct Marsrutas
{
    string nr;
    int keleiviai, ilgis;
};
int n,k,m;
Marsrutas M[20];
Marsrutas M1[20]; //pirmos grupes marsrutai
Marsrutas M2[20]; //antros grupes marsrutai
void Skaitymas();
int Ilgis(int X[],int x);
bool Tikrinimas(int x, int y);
void Rasymas(Marsrutas X[], int x, string grupe);

int main()
{
    ofstream out("autobusai_res.txt");
    out.close();
    int a1=0, a2=0; //a1 pirmos grupes marsrutu kiekis; a2 antros grupes marsruttu kiekis
    Skaitymas();
    for(int i=0; i<n; i++)
    {
        if(Tikrinimas(M[i].keleiviai, M[i].ilgis))
        {
            M1[a1] = M[i];
            a1++;

        }
        else
        {
            M2[a2] = M[i];
            a2++;
        }
    }
    Rasymas(M1,a1,"Pirmos");
    Rasymas(M2,a2,"Antros");
    return 0;
}

void Skaitymas()
{
    ifstream in("autobusai_data.txt");
    in>>n>>k>>m;
    for(int i=0; i<n; i++)
    {
        int stotys; //stoteliu skaicius
        in>>ws;
        in>>M[i].nr>>M[i].keleiviai>>stotys;
        int A[stotys-1];
        for(int j=0;j<stotys-1;j++)
        {
            in>>A[j];
        }
        M[i].ilgis = Ilgis(A,stotys);
    }
    in.close();
}

int Ilgis(int X[],int x)
{
    int sum=0;
    for(int i=0;i<x-1;i++)
        sum+=X[i];
    return sum;
}

bool Tikrinimas(int x, int y)
{
    if(x>=k and y>m)
        return true;
    return false;
}

void Rasymas(Marsrutas X[], int x, string grupe)
{
    ofstream out("autobusai_res.txt", ios::app);

    if(x==0)
        out<<grupe<<" grupës marğrutø nëra"<<endl;
    else{
        out<<grupe<<" grupës marğrutai:"<<endl;
        for(int i=0;i<x;i++)
            out<<X[i].nr<<" "<<X[i].keleiviai<<" "<<X[i].ilgis<<endl;
    }
    out.close();
}
