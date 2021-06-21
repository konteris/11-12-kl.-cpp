#include <iostream>
#include <fstream>

using namespace std;

void Skaitymas(int D[]);
int Didiausias(int x, int X[]);
void Rasymas(int D[], int P[], int a, int m1, int d1, int m2, int d2);
int main()
{
    int m1, d1, m2, d2, P[93], D[93], a=0;
    Skaitymas(D);
    Rasymas(D,P,a,m1,d1,m2,d2);
    return 0;
}

void Skaitymas(int D[])
{
    ifstream in("U1.txt");
    int n;
    in>>n;
    int nr, m1, d1, m2, d2, x,y;
    for(int i = 1; i < 93; i++)
        D[i] = 0;
    for(int i = 0; i < n; i++)
    {
        in>>nr>>m1>>d1>>m2>>d2;
        if(m1 == 6)
            x = 0;
        else if(m1 == 7)
            x = 30;
        else
            x = 61;

        if(m2 == 6)
            y = 0;
        else if(m2 == 7)
            y = 30;
        else
            y = 61;
        for(int j = x+d1; j <= y+d2; j++)
            D[j]++;
    }
    in.close();
}
int Didiausias(int x, int X[])
{
    int d = 1;
    for(int i = 1; i <= x; i++)
    {
        if(X[i] > X[d])
            d = i;
    }
    return X[d];
}
void Rasymas(int D[], int P[], int a, int m1, int d1, int m2, int d2)
{
    ofstream out("U1rez.txt");
    int x, didz = Didiausias(92,D);
    for(int i = 1; i <= 92; i++)
    {
        if(D[i] == didz)
        {
            P[a] = i;
            a++;
        }
    }
   for(int i = 1; i <= a; i++)
    {
        if(P[0]+i == P[i])
            x = P[i];
    }
    if(a < 2)
        x = P[0];

    if(P[0] < 31)
    {
        m1 = 6;
        d1 = P[0];
    }
    else if(P[0] >= 31 && P[0] < 62)
    {
        m1 = 7;
        d1 = P[0]-30;
    }
    else
    {
        m1 = 8;
        d1 = P[0]-61;
    }
    if(x < 31)
    {
        m2 = 6;
        d2 = x;
    }
    else if(x >= 31 && x < 62)
    {
        m2 = 7;
        d2 = x-30;
    }
    else
    {
        m2 = 8;
        d2 = x-61;
    }
    out<<didz<<endl;
    out<<m1<<" "<<d1<<endl;
    out<<m2<<" "<<d2<<endl;
    out.close();
}
