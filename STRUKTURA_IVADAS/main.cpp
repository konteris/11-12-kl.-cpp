#include <iostream>
#include <fstream>

using namespace std;

struct mokiniai
{
    string vardas, pavarde;
    int k, K[20];

};

mokiniai M[30]; //strukturos masyvas,o 30 nes gali but 30 mokiniu
int n;

void Skaityti();
void Rasymas();

int main()
{
    Skaityti();
    Rasymas();

    return 0;
}

void Skaityti()
{
    ifstream in ("duomenys1.txt");
    in>>n;

    char r[16]; //visada vienu daugiau

    for(int i = 0; i < n; i++)
    {
        in>>ws;//praleidzia visus tarpus ir enterius

        in.get(r, 16);//nuskaityti string'a
        M[i].vardas = r;  //priskiriu

        in>>ws;
        in.get(r, 16);
        M[i].pavarde = r;

        in>>M[i].k; //kiek dienu

        for(int j = 0; j < M[i].k; j++) //vidinis ciklas nes skirtingas praleistu dienu skaicius
        {
            in>>M[i].K[j]; //nuskaitau dienas praleistas
        }
    }
    in.close();
}

void Rasymas()
{
    ofstream out("rezultatai1.txt");
    out<<n<<endl;

    for(int i=0; i<n; i++)
    {
        out<<M[i].vardas<<" "<<M[i].pavarde<<M[i].k;
        for(int j=0; j < M[i].k; j++)
            out<<" "<<M[i].K[j];
        out<<endl;

    }
    out.close();
}
