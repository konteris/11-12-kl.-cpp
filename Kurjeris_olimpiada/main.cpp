#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int N,K,a,t, M[100],st, d=0, x=0;
    cin>>N;
    for(int i=1; i<=N; i++)
        cin>>M[i];
    cin>>K;
    for(int i=1; i<=K; i++)
    {
        cin>>a>>t;
        st=0;
        for(int j=1; j<=a; j++)
            st += M[j];
        if(st>t)
        {
            x=-1;
            break;
        }
        else if(st>d)
            d=st;
    }
    if(x==-1)
        cout<<x;
    else
        cout<<d*2<<endl;
    return 0;
}
