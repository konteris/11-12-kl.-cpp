#include <iostream>
#include <fstream>

using namespace std;

void Skaitymas(int Varztai[], int Verzles[], int Verzles_1[]);
void Kiek(int X[], int Y[], int &x);
void Rasymas(int X[], int kiek, string x, string y, string z);
int main()
{
    ofstream out("rez.txt");
    out.close();
    int Varztai[21], Verzles[21], Verzles_1[21], k_varztu=0, k_verzliu=0;
    Skaitymas(Varztai,Verzles,Verzles_1);

    Kiek(Verzles,Varztai,k_varztu);
    Rasymas(Verzles, k_varztu," varztai:", "Varztu","i");

    Kiek(Varztai,Verzles_1,k_verzliu);
    Rasymas(Varztai, k_verzliu," verzles:", "Verzliu", "os");
    return  0;
}
void Skaitymas(int Varztai[], int Verzles[], int Verzles_1[])
{
    ifstream in("duom.txt");
    int n,m,x,y;
    in>>n;
    for(int i=0; i<21; i++)
        Varztai[i]=0;
    for(int i=0; i<n; i++)
    {
        in>>x;
        Varztai[x]++;
    }
    in>>m;
    for(int i=0; i<21; i++)
    {
        Verzles[i]=0;
        Verzles_1[i] = 0;
    }

    for(int i=0; i<m; i++)
    {
        in>>y;
        Verzles[y]++;
        Verzles_1[y]++;
    }
    in.close();
}
void Kiek(int X[], int Y[], int &x)
{
    for(int i=2; i<=20; i++)
    {
        X[i]-=Y[i];
        if(X[i]>0)
            x++;
    }
}

void Rasymas(int X[], int kiek,string x, string y, string z)
{
    ofstream out("rez.txt", ios::app);
    if(kiek>0)
    {
        out<<"Reikaling"<<z<<x<<endl;
        for(int i=0; i<21; i++)
        {
            if(X[i]>0)
            {
                out<<X[i]<<" "<<i<<endl;
            }
        }
    }

    else
        out<<y<<" nereikia"<<endl;

    out.close();
}
