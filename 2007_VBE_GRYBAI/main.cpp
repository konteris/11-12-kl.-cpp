#include <iostream>
#include <fstream>

using namespace std;

void Skaitymas(int n, int d, int b, int r, int l, int B[], int R[], int L[]);

int daugiausiai(int B[], int R[], int L[]);

void Isvedimas(int B[], int R[], int L[]);

int main()
{
    int n, d,b,r,l;
    int B[32], R[32], L[32];

    Skaitymas(n,d,b,r,l,B,R,L);
    Isvedimas(B,R,L);
    return 0;
}

void Skaitymas(int n, int d, int b, int r, int l, int B[], int R[], int L[])
{

    for(int i=1; i<=31; i++)
        B[i]=0;
    for(int i=1; i<=31; i++)
        R[i]=0;
    for(int i=1; i<=31; i++)
        L[i]=0;

    ifstream in("U1.txt");
    in>>n;
    for(int i=0; i<n; i++)
    {
        in>>d>>b>>r>>l; //nuskaitau i-taja diena, ir grybu skaiciu ta diena;

        //visas atskiru grybu skaicius:
        B[d]+=b;
        R[d]+=r;
        L[d]+=l;

    }
    in.close();
}

int daugiausiai(int B[], int R[], int L[])
{
    int d=1;
    for(int i=1; i<=31; i++)
    {
        if(B[i]+R[i]+L[i] > B[d]+R[d]+L[d])
        {
            d=i;
        }
    }
    return d;
}

void Isvedimas(int B[], int R[], int L[])
{
    ofstream out("U1rez.txt");

    for(int i=1; i<=31; i++)
    {
        if(B[i]!=0 || R[i]!=0 || L[i]!=0 )
            out<<i<<" "<<B[i]<<" "<<R[i]<<" "<<L[i]<<endl;
    }
    int d;
    d = daugiausiai(B,R,L);
    out<<d<<" "<<B[d]+R[d]+L[d]<<endl;

    out.close();
}
