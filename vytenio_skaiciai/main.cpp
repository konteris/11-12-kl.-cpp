#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

void Skaitymas(int &N, string &vyteniskas_skc);
long long int Simbolio_verte(char vyt_simbolis, long long int Kodai[]);
int main()
{
    int N,X[10];
    long long int Kodai[26], Vertes[26];
    string vyteniskas_skc;
    string alfabetas = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
    Skaitymas(N, vyteniskas_skc);
    for(int i=0;i<26;i++)
    {
        Kodai[i]=pow(5,i);
        if(Kodai[i]%5 !=0 and i>0) //nesuprantu kodel duoda 24 124 ir t.t
            Kodai[i]+=1;
    }
    for(int i=0;i<N;i++)
    {
        Vertes[i] = Simbolio_verte(vyteniskas_skc[i], Kodai);
        if(Vertes[i]>Vertes[i-1] and i>0)
            Vertes[i-1] *= (-1); 
        //IR dar jeigu tai pasikartoja: pvz ACAD:

    }
    for(int i=0;i<N;i++)
        cout<<Vertes[i]<<endl;
    return 0;
}

void Skaitymas(int &N, string &vyteniskas_skc)
{
    ifstream in("vyteniski.txt");

    in>>N;
    in>>vyteniskas_skc;
    in.close();
}

long  long int Simbolio_verte(char vyt_simbolis, long  long int Kodai[])
{
    int index;
    if(vyt_simbolis < 97) //jeigu didzioji raide:
        index= int(vyt_simbolis)-65; //is ascii vertes atimu 65
    else
        index=int(vyt_simbolis)-97;//jei mazoji -65 - 32
    return Kodai[index];
}