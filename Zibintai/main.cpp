#include <iostream>
#include <fstream>

using namespace std;

void skaitymas(int &k, int  &n, int Z[]);
void zibintai(int k, int  n, int Z[], int NN[]);
int suma(int x, int X[]);
int daugiausiai(int x, int X[]);
int maziausiai(int x, int X[]);
void rasymas(int n, int Z[], int k);
int S[100];
int main()
{
    int k,n,Z[100], NN[100];
    skaitymas(k,n,Z);
    zibintai(k,n,Z,NN);
    rasymas(n,Z,k);
    return 0;
}

void skaitymas(int &k, int  &n, int Z[])
{
    ifstream in("duom.txt");
    in>>n>>k;
    for(int i=1; i<=n; i++)
    {
        in>>Z[i];
        S[0] = suma(n, Z);
    }
    in.close();
}
void zibintai(int k, int  n, int Z[], int NN[]) //NN- nauja naktis;
{
    for(int i=1; i<k; i++)
    {
        if((i+1)%2 == 0) //pirmam ir paskutiniam zibuntui galioja tik 3 taisykle
        {
            NN[1]=1;
            NN[n]=1;
        }
        else
        {
            NN[1]=0;
            NN[n]=0;
        }

        for(int j=2; j<=n-1; j++)
        {
            if(Z[j-1]==1 && Z[j+1]==1) // pirma salygos taisykle
            {
                NN[j]=0;
            }

            else //kitu atveju
            {
                if(Z[j-1]!=Z[j+1]) //2 salygos taisykle
                    NN[j]=1;
                else // jei ir ji negalioja
                {
                    if((i+1)%2==0) //tai tikrinu ar diena lygine ar ne
                        NN[j]=1;
                    else
                        NN[j]=0;
                }
            }
        }
        S[i] = suma(n, NN);

        for(int m=1; m<=n; m++)
            Z[m]=NN[m];
    }
}
int suma(int x, int X[])
{
    int s=0;
    for(int i=1; i<=x; i++)
    {
        s+= X[i];
    }
    return s;
}
int daugiausiai(int x, int X[])
{
    int d=0;
    for(int i=0; i<x; i++)
    {
        if(X[i] > X[d])
            d=i;
    }
    return d;
}

int maziausiai(int x, int X[])
{
    int m=0;
    for(int i=0; i<x; i++)
    {
        if(X[i] < X[m])
            m=i;
    }
    return m;
}

void rasymas(int n, int Z[], int k)
{
    ofstream out("rez.txt");
    for(int i=1; i<=n; i++)
    {
        out<<Z[i]<<" ";
    }
    out<<endl;
    int daug = daugiausiai(k, S);
    int maz = maziausiai(k,S);
    out<<"Naktis, kai ðvietë daugiausiai: "<<daug+1<<endl;
    out<<"Naktis, kai ðvietë maþiausiai: "<<maz+1<<endl;
    out.close();
}
