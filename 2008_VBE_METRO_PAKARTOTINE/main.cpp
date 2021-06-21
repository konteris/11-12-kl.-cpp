#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void Skaitymas(int X[], int Y[], int NR[]);

void Stotys(int NR[]);

void Keleiviai(int X[], int Y[], int NR[]);

int Daugiausiai(int X[], int Y[]);

void Isvedimas(int X[],int NR[], int Y[]);

int main()
{

    int X[101], Y[101],NR[101];

    Skaitymas(X,Y,NR);
    Stotys(NR);
    Keleiviai(X,Y,NR);
    Isvedimas(X,NR,Y);

    return 0;
}
void Skaitymas(int X[], int Y[], int NR[])
{

    int n,d,x,y,m;

    for(int i=1; i<=100; i++)
        X[i]=0;
    for(int i=1; i<=100; i++)
        Y[i]=0;
    for(int i=1; i<=100; i++)
        NR[i]=0;

    ifstream in("U1.txt");
    in>>m;

    for(int i=1; i<=m; i++)
    {
        in>>n>>d>>x>>y;
        X[n]+=x;
        Y[n]+=y;
        NR[n]++;
    }

    in.close();
}
void Stotys(int NR[])
{
    ofstream out("U1rez.txt");
    for(int i=1; i<=100; i++)
    {
        if(NR[i]>0)
        {
            out<<setw(6)<<i;
        }
    }
    out.close();
}

void Keleiviai(int X[], int Y[], int NR[])
{
    ofstream out("U1rez.txt", ios::app); //toliau rasau
    out<<endl;
    for(int i=1; i<=100; i++)
    {
        if(NR[i]>0)
            out<<setw(6)<<X[i]+Y[i];
    }
    out.close();
}

int Daugiausiai(int X[], int Y[])
{
    int d=1;

    for(int i=1; i<=100; i++)
    {
        if((X[i]+Y[i]) > (X[d]+Y[d]))
            d=i;
    }

    return d;
}

void Isvedimas(int X[],int NR[], int Y[])
{
    ofstream out("U1rez.txt", ios::app);
    out<<endl;
    int d = Daugiausiai(X,Y);
    out<<setw(6)<<d<<endl;


    int sum=0;
    for(int i=1; i<=100; i++)
    {
        if(NR[i]>0)
            sum+=X[i];
    }
    out<<setw(6)<<sum<<endl;

    out.close();
}

