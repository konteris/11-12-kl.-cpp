#include <iostream>
#include <fstream>

using namespace std;
const int d=92;
int n, Dienos[d]; //Dienos - vasaros dienu sarasas, sumuosiu indekse

void Skaitymas();
int kelinta_diena(int x, int y);
int Daugiausiai(int X[], int x);
void Atsakymai(int xy, int &menesis, int &diena);
void Rasymas(int x, int y);

int main()
{
    Skaitymas();
    int x = Daugiausiai(Dienos,d); //pirmo intervalo kai zydi daugiausiai skirtingu geliu vieta vasaros dienu sarase
    int y; //antro(pabaigos) intervalo kai zydi daugiausiai skirtingu geliu vieta vasaros dienu sarase
    for(int i=x;i<=d;i++)
    {
        if(Dienos[x]==Dienos[i])
            y=i;
        else
            break;
    }
    Rasymas(x,y);
    return 0;
}

void Skaitymas()
{
    ifstream in("U1.txt");
    in>>n;
    for(int i=1;i<=d;i++)
    {
        Dienos[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        int nr, pr_men, pr_d, pab_men, pab_d, x_pr,y_pab;
        in>>nr>> pr_men>> pr_d>>pab_men>> pab_d;
        x_pr = kelinta_diena(pr_men, pr_d);
        y_pab = kelinta_diena(pab_men, pab_d);
        for(int j=x_pr; j<=y_pab;j++)
            Dienos[j]++;
    }
    in.close();
}

int kelinta_diena(int x, int y)
{
    int k;
    if(x==6)
        k=y;
    else if(x==7)
        k=30+y;
    else
        k=61+y;
}
int Daugiausiai(int X[], int x)
{
    int d=1;
    for(int i=1;i<=x;i++)
    {
        if(X[d]<X[i])
            d=i;
    }
    return d;
}

void Atsakymai(int xy, int &menesis, int &diena)
{
    if(xy<31)
    {
        menesis = 6;
        diena=xy;
    }
    else if(xy<62)
    {
        menesis = 7;
        diena = xy-30;
    }
    else{
        menesis=8;
        diena=xy-61;
    }
}

void Rasymas(int x, int y)
{
    ofstream out("U1rez.txt");
    int men1, d1, men2,d2;
    Atsakymai(x, men1, d1);
    Atsakymai(y,men2,d2);

    out<<Dienos[x]<<endl;
    out<<men1<<" "<<d1<<endl;
    out<<men2<<" "<<d2<<endl;

    out.close();
}
