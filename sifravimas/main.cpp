#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

void skaitymas(int &k, int &ilgis,char T[]);

void sifravimas(char T[], int k, int ilgis, char T_naujas[]);

int main()
{
    ofstream out("Rezultatai1.txt");
    int k,ilgis;
    char T[1000], T_naujas[1000];
    skaitymas(k,ilgis,T);
    sifravimas(T,k,ilgis,T_naujas);
    out<<"Iššifruota žinutė:"<<endl;
    for(int i=0;i<ilgis;i++)
        out<<T_naujas[i];

    out.close();
    return 0;
}
void skaitymas(int &k, int &ilgis,char T[])
{
    ifstream in("Duomenys1.txt");
    string x;
    in>>k;
    in>>x;
    ilgis=x.size();
    for(int i=0;i<ilgis;i++)
        T[i]=x[i];
    in.close();
}

void sifravimas(char T[], int k, int ilgis, char T_naujas[])
{
    int kiek_raidziu=0; //kiek zodis turi raidziu
    char baze = 'a'; 
    for(int i=0;i<ilgis;i++)
    {
        int raide =  T[i]- baze;
        raide = (raide - k + 26) %26;
        T_naujas[i]= raide + baze;

        if(T_naujas[i]=='x') 
        {
            k+=kiek_raidziu; //prie sifrorakto pridedu raidziu skaiciu
            T_naujas[i]=' ';// pakeiciu 'x' i tarpa
            kiek_raidziu=0; //naujas zodis bus sifruojamas tai is naujo skaiciuoju raides
        }
        else
            kiek_raidziu++; //skaiciuoja raides
    }
}