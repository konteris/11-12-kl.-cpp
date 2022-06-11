#include <iostream>
#include<fstream>
using namespace std;

struct Preke{
    string pavadinimas;
    int metai, men,diena;
};
Preke P[500];
int n,y,m,d;

void Skaitymas();

int main()
{
  
    return 0;
}
void Skaitymas()
{
    ifstream in("prekes_data.txt");

    in>>n>>y>>m>>d;
    
    for(int i=0;i<n;i++)
    {
        in>>P[i].pavadinimas>>P[i].metai>>P[i].men>>P[i].diena;
    }
    in.close();
}