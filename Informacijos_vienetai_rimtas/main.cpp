#include <iostream>
#include <fstream>

using namespace std;

void Skaitymas(int &n, int &m,int &k,string Y[][6], string X[][6]);
void Konvertavimas(int m, int k, string Y[][6], string X[][6]);
int Didz(int m,int k, string xy[][6]);
void Rasymas();

int main()
{
    int n,m,k;
    string Y[6][6], X[6][6];
    Skaitymas(n,m,k,Y,X);
    Konvertavimas(m,k,Y,X);
    //cout<<Y[1][2]<<endl; //[i][j] i-korteles numeris , j-zaidejas
    int d = Didz(m,k,X);
    for(int i=1; i<=k; i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(Y[i][d]!=Y[i][j]) //jei jis laimi

        }
    }

    return 0;
}

void Skaitymas(int &n, int &m,int &k, string Y[][6], string X[][6])
{
    ifstream in("U2.txt");
    in>>n>>m;
    k=n/m;
    for(int i=1; i<=k; i++)
    {
        for(int j=1;j<=m;j++)
            in>>Y[i][j];
    }
    in.close();
}

void Konvertavimas(int m, int k, string Y[][6], string X[][6])
{
    string YB="10", ZB="9", EB= "8", PB="7", TB="6", GB="5", MB="4",kB="3", B="2", b="1";
    for(int i=1; i<=k; i++)
    {
        for(int j=1;j<=m;j++)
        {
            X[i][j]=Y[i][j];
        }
    }
    for(int i=1; i<=k; i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(Y[i][j]=="YB")
                X[i][j]=YB;
            if(Y[i][j]=="ZB")
                X[i][j]=ZB;
            if(Y[i][j]=="EB")
                X[i][j]=EB;
            if(Y[i][j]=="PB")
                X[i][j]=PB;
            if(Y[i][j]=="TB")
                X[i][j]=TB;
            if(Y[i][j]=="GB")
                X[i][j]=GB;
            if(Y[i][j]=="MB")
                X[i][j]=MB;
            if(Y[i][j]=="kB")
                X[i][j]=kB;
            if(Y[i][j]=="B")
                X[i][j]=B;
            if(Y[i][j]=="b")
                X[i][j]=b;
        }
    }
}

int Didz(int m,int k, string xy[][6])
{
    int d=0;
    for(int i=1; i<=k; i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(xy[i][j]>xy[i][d])
                d=i;
        }
    }
    return d;
}

/*
################################
#          |1  |2  | 3| -(j)   #
#   1(i)   |ZB |GB |TB|        #
#   -------|---|---|--|        #
#   2(i+1) |B  |b  |MB|        #
#          ------------        #
################################
*/
