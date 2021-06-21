#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int dal_kiek(int d);

int main()
{
    ifstream in ("intervalas.txt");
    ofstream out("rezultatai.txt");
    int  n, m,d,a=1,b,s;// d- daugiausiai dalikliu turintis sk.
    // y - kiek yra dalikliu;
    in>>n>>m;
    d=m;
    for(int i=n; i<=m; i++)
    {
        b=1;
        for(int x=2; x<=i; x++)
        {
            if(i % x == 0)
                b= b+1;

            if(b>a)
            {
                d=i;
                a=b;
            }

        }

    }
    out<<d<<" "<<dal_kiek(d)<<endl;
    for(int g = 1; g <= d; ++g)
            {
                if(d % g == 0)
                    out<<g<<" ";
            }
    in.close();
    out.close();
    return 0;

}
int dal_kiek(int d)
{
    int y = 0;
    for (int k = 1; k <= sqrt(d); k++)
    {
        if (d % k == 0)
        {
            //jeigu dalikliai lygus tai skaiciuoja tik viena
            if (d / k == k)
                y++;

            else // kitu atveju skaiciuoja abu
                y = y + 2;
        }
    }
    return y;
}


