#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{

    int a, b, c, n, m; // a,b statiniai;  c-izambine;   n,m intervalas
    int p, s; //perimetras ir plotas

    ifstream in("skaiciai.txt"); ofstream out("pitagorai.txt");
    in>>n>>m; //nusiskaitau intervala
    for (int a=n; a< m; a++) //tai statinis a bus lygus intervalo pradziai. Tada vyksta ciklas kol a mazesnis m(didziausias intervalo skaicius.
    {
        for (int b =a+1; b < m; b++) //statinis b jau turi buti didesnis uz a todel +1. tada vyksta ciklas kol b mazesnis m
        {
            for (int c =b+1; c < m; c++) //tas pats .
            {
                if (((a*a)+(b*b) == c*c)) // tikrini ar atitinka pitagoro teorema
                {
                    p=a+b+c; //nu cia tai easy xdd
                    s=(a*b)/2;
                    out << a << " "<<b <<" " <<c <<" "<<p<< " "<<s<<endl;// isspausdini

                }
            }
        }
    }

    return 0;
}



