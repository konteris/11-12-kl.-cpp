#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int N, L, C, T, X[3], k=0, a;

    cin>>N>>L>>C>>T;

    for(int i=0; i<N; i++)
    {
        cin>>X[i];
    }

    for(int i=0; i<N-1; i++)
    {
        a = (X[((i+1)-i)])/2;
    }
    k = a*C;
    cout<<k;
    return 0;
}
