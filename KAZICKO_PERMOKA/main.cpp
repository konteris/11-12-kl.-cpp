#include <iostream>
#include<fstream>

using namespace std;

struct Klientas{
    string pavarde;
    int y,m,d, deklaruoti, fiksuoti, skirtumas;
};
Klientas K[100];
int n, metai, men, diena;

void Skaitymas();
int Keliamieji_metai(int metai_x, int men_x, int dien_x);
void Datu_skirtumo_skaiciavimas();
int main()
{
    Skaitymas();
    Datu_skirtumo_skaiciavimas();
    for(int i=0;i<n;i++)
        cout<<K[i].pavarde<<" "<<K[i].skirtumas<<endl;
    return 0;
}
void Skaitymas()
{
    ifstream in("permoka.txt");
    in>>n>>metai>>men>>diena;

    for(int i=0;i<n;i++)
    {
        in>>K[i].pavarde>>K[i].y>>K[i].m>>K[i].d>>K[i].deklaruoti>>K[i].fiksuoti;
    }
}

int Keliamieji_metai(int metai_x, int men_x, int dien_x)
{
    if(men_x<=2)
        metai_x--;

    return metai_x /4 - (metai_x/100)+ (metai_x/400);
}

void Datu_skirtumo_skaiciavimas()
{
    int menesiai[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    for(int i=0;i<n;i++)
    { 
        int d1 = K[i].y * 365 + K[i].d;
        for(int j=0; j< K[i].m;j++)
            d1+=menesiai[j];
        d1+=Keliamieji_metai(K[i].y, K[i].m, K[i].d);

        int d2 = metai * 365 + diena;
        for(int j=0; j< men;j++)
            d2+=menesiai[j];
        d2+=Keliamieji_metai(metai, men, diena);
        K[i].skirtumas = d2-d1;
    }
}