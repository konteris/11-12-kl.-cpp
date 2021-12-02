#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct Duomenys
{
    int k;
    int Komandos[30];
};

void Skaitymas(int &x0,int &y0,int &x1,int &y1,int &n, Duomenys D[]);
void Komandos_vykdymas(int x0, int y0, int x1, int y1, int n, Duomenys D[], int S[]);

int main()
{
    int x0,y0,x1,y1,n, S[30];
    Duomenys D[10];
    Skaitymas(x0,y0,x1,y1,n,D);
    Komandos_vykdymas(x0,y0,x1,y1,n,D,S);

    return 0;
}

void Skaitymas(int &x0,int &y0,int &x1,int &y1,int &n, Duomenys D[])
{
    ifstream in("U2.txt");
    in >> x0 >> y0;
    in >> x1 >> y1;
    in>>n;

    for(int i = 0 ; i < n ; i++)
    {
        in>>D[i].k;
        for(int j=0; j<D[i].k; j++)
        {
            in>>D[i].Komandos[j];
        }
    }
    in.close();
}

void Komandos_vykdymas(int x0, int y0, int x1, int y1, int n, Duomenys D[], int S[])
{
    ofstream out("U2rez.txt");
    for(int i = 0; i < n; i++)
    {
        int x = x0, y = y0, z=0;
        for(int j=0; j<D[i].k; j++)
        {
            if(D[i].Komandos[j]==1)
                y++;
            else if(D[i].Komandos[j]==2)
                x++;
            else if(D[i].Komandos[j]==3)
                y--;
            else if(D[i].Komandos[j]==4)
                x--;
            S[z]=D[i].Komandos[j];
            z++;
            if(x == x1 and y == y1)
                break;
        }
        if(x == x1 and y == y1)
        {
            out<<fixed<<left<<setw(20)<<"pasiektas tikslas ";
            for(int j = 0; j < z; j++)
            {
                out<<S[j]<<" ";
            }
            out<<z<<endl;
        }
        else
        {
            out<<fixed<<left<<setw(20)<<"sekos pabaiga ";
            for(int j = 0; j < z; j++)
            {
                out<<S[j]<<" ";
            }
            out<<z<<endl;
        }
    }
    out.close();
}
