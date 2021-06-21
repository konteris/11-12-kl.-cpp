#include <iostream>
#include <fstream>

using namespace std;

int penktadienis(int x, int X[]);

int main()
{
    int n, d, m, MD[1000], P[20];
    ifstream in("U1.txt");
    in>>n;
    for(int i=0; i<n; i++)
    {
        in>>d>>m;
        for(int j=0; j<m; j++)
            in>>MD[j];
        P[i]= penktadienis(m,MD);
    }
    ofstream out("U1rez.txt");
    for(int i=0; i<n; i++)
        out<<P[i]<<endl;

    in.close();
    out.close();
    return 0;
}
int penktadienis(int x, int X[])
{
    int p=0, i=0;
    for(int j=0; j<x; j++)
    {
        for(int k=1; k<=X[j]; k++)
        {
            if(k==13 && i==5)
                p++;
            i++;
            if(i==8)
                i=1;
        }
    }
    return p;
}
