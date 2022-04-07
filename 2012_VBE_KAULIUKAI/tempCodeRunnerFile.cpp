#include <iostream>
#include <fstream>

using namespace std;

struct Dievas{
    string vardas;
    int taskai=0;
    int lyginis=0;
};
Dievas D[50];
Dievas D1[50]; //kopija
void Skaitymas(int &n);
void Rikiavimas(int n);
void Rasymas(int n, int indeksas);

int main()
{
    int n, indeksas;
    Skaitymas(n);
    for(int i=0;i<n;i++)
        D1[i]=D[i];
    Rikiavimas(n);
    Rasymas(n, indeksas);
    return 0;
}
void Skaitymas(int &n)
{
    ifstream in("U2.txt");
    int k;
    in>>n>>k;
    char X[11];
    for(int i=0;i<n;i++)
    {
        in>>ws;
        in.get(X,11);
        D[i].vardas = X;
        for(int j=0;j<k;j++)
        {
            int x;
            in>>x;
            if(x%2==0)
            {
                D[i].taskai+=x;
                D[i].lyginis++;
            }
                
            else
                D[i].taskai-=x;
        }
    }
    in.close();
}
void Rikiavimas(int n)
{
    for(int i=0; i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(D[i].taskai<D[j].taskai || D[i].taskai==D[j].taskai && D[i].lyginis<D[j].lyginis)
                swap(D[i],D[j]);
}
void Rasymas(int n, int indeksas)
{
    ofstream out("U2Rez.txt");

    for(int i=0;i<n;i++)
    {
        if(D[i].taskai == D[i+1].taskai and D[i].lyginis == D[i+1].lyginis and D1[i].vardas == D[i].vardas)
        {
            indeksas = i;
            break;
        }
        else{
            indeksas=0;
        }
    }
    out<<D[indeksas].vardas<<" "<<D[indeksas].taskai<<endl;
    out.close();
}