#include <iostream>
#include <fstream>

using namespace std;

void skaitymas(int &N1, int &N2, int &N, int Z[]);
void pakuotes(int &p1, int &p2, int N1, int N2, int N, int Z[], int &pirkejai, int &k);
void rasymas(int p1, int p2, int pirkejai, int k);

int main()
{
    int p1,p2,N1,N2,N,Z[100], pirkejai,k;
    skaitymas(N1,N2,N,Z);
    pakuotes(p1,p2,N1,N2,N,Z,pirkejai, k);
    rasymas(p1,p2,pirkejai,k);
    return 0;
}

void skaitymas(int &N1, int &N2, int &N, int Z[])
{
    ifstream in("Z1.txt");
    in>>N1>>N2;
    in>>N;
    for(int i=0; i< N; i++)
    {
        in>>Z[i];
    }
    in.close();
}

void pakuotes(int &p1, int &p2, int N1, int N2, int N, int Z[], int &pirkejai, int &k)
{
    int x, y;
    p1=0, p2 = 0, pirkejai=0, k=0;
    for(int i=0; i< N; i++)
    {
        if(N2>=Z[i]/2)
            x = Z[i]/2;
        else
            x=N2;

        Z[i]-=x*2; //pardaves po 2kg, ziurim kas lieka po 1kg

        if(N1>=Z[i])
            y=Z[i];
        else
            y=N1;

        if(x*2+y > 0)//jei kazka parduoda
        {
            pirkejai++;
            k = x*2+y;
        }
        else
            break;
        p2 += x; //pridedu
        p1+= y;

        N1-=y; //sumazinu
        N2-=x;
    }

}
void rasymas(int p1, int p2, int pirkejai, int k)
{
    ofstream out("Z1rez.txt");
    out<<p1<<" "<<p2<<endl;
    out<<pirkejai<<endl;
    out<<k<<endl;
    out.close();
}
