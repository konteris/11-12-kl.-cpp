#include <iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream in("duom.txt");
    ofstream out("rez.txt");

    int n, k, c, pinigai, euras, eurocent;
    int kupiura=0, centai=0;
    in>>n;
    for(int x=1; x<=n; x++)
    {
        in>>k>>c;
        kupiura+=k;
        centai+=c;
        pinigai=kupiura*100+centai;
        euras= pinigai/100;
        eurocent=pinigai%100;

    }

    out<<"Iğ viso uş pirkinius mokësite "<<euras<<" Eur "<<eurocent<<" euro ct"<<endl;
    return 0;
}
