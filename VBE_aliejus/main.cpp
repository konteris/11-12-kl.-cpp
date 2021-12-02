#include <iostream>
#include <fstream>

using namespace std;

void Skaitymas(int &n1,int &n3,int &n5,int &k,int &gamybos_kaina,int &n1_kaina,int &n3_kaina,int &n5_kaina);

void Pila(int n1,int n3,int n5,int &k, int &penki, int &trys, int &vienas);

void Rasymas(int penki, int trys, int vienas, int k,int n1,int n3,int n5,int gamybos_kaina,int n1_kaina,int n3_kaina,int n5_kaina);

int main()
{
    int n1,n3,n5,k,gamybos_kaina, n1_kaina, n3_kaina, n5_kaina,penki,trys,vienas;
    Skaitymas(n1,n3,n5,k,gamybos_kaina,n1_kaina,n3_kaina,n5_kaina);
    Pila(n1,n3,n5,k,penki,trys,vienas);
    Rasymas(penki,trys,vienas,k,n1,n3,n5, gamybos_kaina,n1_kaina,n3_kaina,n5_kaina);
    return 0;
}

void Skaitymas(int &n1,int &n3,int &n5,int &k,int &gamybos_kaina,int &n1_kaina,int &n3_kaina,int &n5_kaina)
{
    ifstream in("U1.txt");
    in>>n1>>n3>>n5>>k; // skirtingu talpu kiekis ir kiek litru isspausta
    in>>gamybos_kaina>>n1_kaina>>n3_kaina>>n5_kaina;
    in.close();
}

void Pila(int n1,int n3,int n5,int &k, int &penki, int &trys, int &vienas)
{
    penki = min(k/5,n5);
    k-=penki*5;
    trys = min(k/3,n3);
    k-=trys*3;
    vienas = min(k/1,n1);
    k-=vienas;
}

void Rasymas(int penki, int trys, int vienas, int k,int n1,int n3,int n5,int gamybos_kaina,int n1_kaina,int n3_kaina,int n5_kaina)
{
    ofstream out("U1rez.txt");

    out<<vienas<<" "<<trys<<" "<<penki<<" "<<k<<endl;
    out<<n1-vienas<<" "<<n3-trys<<" "<<n5-penki<<endl;

    int papildomai_penki = k/5;
    k-= papildomai_penki *5;
    int papildomai_trys = k/3;
    k-= papildomai_trys *3;
    int papildomai_vienas = k;
    out<<papildomai_vienas<<" "<<papildomai_trys<<" "<<papildomai_penki<<endl;

    int pardavimo_kaina = ((vienas+papildomai_vienas)*n1_kaina + (trys+papildomai_trys)*n3_kaina + (penki+papildomai_penki)*n5_kaina );
    int pelnas = pardavimo_kaina - gamybos_kaina;
    out<<pelnas<<endl;

    out.close();
}
