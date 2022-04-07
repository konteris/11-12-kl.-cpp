#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream in("U1.txt");
    ofstream out("U1rez.txt");
    int N, paw=0, rook=0, kn=0, bi=0, k=0, q=0, komplektas=0;
    int p,r,kn1,b,k1,q1; 
    in>>N;
    for(int i=0;i<N;i++)
    {
        in>>p>>r>>kn1>>b>>k1>>q1;
        paw+=p; rook+=r; kn+=kn1; bi+=b; k+=k1; q+=q1;
    }
    while(paw>7 and rook>1 and kn>1 and bi>1 and k>0 and q>0)
    {
        paw-=8;rook-=2; kn-=2;bi-=2;k-=1;q-=1;
        komplektas++; 
    }
    out<<komplektas<<endl;

    in.close();
    out.close();
    return 0;
}
