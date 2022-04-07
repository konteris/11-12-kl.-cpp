#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    int N,L,C,T;
    int papildomas[100000];
    vector<int> x; // atstumai tarp bitu
    vector<int> z; //R reiksmes

    ifstream in("makleris-vyr.txt");
    in>>N>>L>>C>>T; // N=kiek bitu yra ;  L=atstumas;  C=1m antenos;  T=kiek praranda kai nesiekia
    for (int i = 1; i <= N; i++)
        in>>papildomas[i];
    for (int i = 1; i < N; i++)
    {
        int y = papildomas[i+1]-papildomas[i];
        x.push_back(y);

        z.push_back(y/2); // tai jam reiktu antenos kuri yra puse atsumo tarp bitu
    }
    sort(x.begin(), x.end()); //susirikiuoju atstumus tarp bitu 
    sort(z.begin(), z.end()); //surikiuoju galimas R reiksmes
   

    long int nesieks_bito = (L+1)-N; //kiek metru nesiekia
    long int kaina = nesieks_bito *T; // tai sita kaina kolkas maziausia
    long int sutaupo; //cia kaupsiu kiek kainuos kelione su antena
    int j=0;
    for(int i=0; i<z.size();i++)
    {
        int R = z[i]; //kokios yra galimos antenos R;
        //jeigu nesiektu antenos:
        while(R*2 > x[j])
            j++; //tiek metru nesieks antenos
        /*
         sutaupo = R*C + ??? 
        //bet kaip prideti tu metru kaina, kai nesiekia su antena, t.y j(metru)?
        */
    } //maziauia atstuma
    //cout<<min(sutaupo,kaina);// galiausiai tureciau spausdinti mazesni
    in.close();
    
    return 0;
}