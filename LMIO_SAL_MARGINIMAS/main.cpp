#include <iostream>
#include <fstream>

using namespace std;

struct kartotiniai{
    int a;
};
kartotiniai K[10000];
int main()
{
    long int N;
    int R ;
    cin>>N>>R;
    int ats=0;
    int valandos[N];
    for(int i=1; i<=N; i++)
    {
        valandos[i]=0;
    }
    for(int i=1; i<=R; i++)
    {
        cin>>K[i].a;
        for(int j=K[i].a; j<=N; j+=K[i].a)
            valandos[j]++;
    }
    for(int i=1;i<=N;i++)
        if(valandos[i]==R)
            ats++;
    cout<<ats;
    return 0;
}

//    int ats=0;
//    int valandos[N];
//    for(int i=1;i<=N;i++)
//    {
//        valandos[i]=0;
//    }
//    for(int i=a1; i<=N; i+=a1)
//        valandos[i]++;
//    for(int i=a2; i<=N;i+=a2)
//        valandos[i]++;
//    for(int i=a3; i<=N;i+=a3)
//        valandos[i]++;
//    for(int i=1;i<=N;i++)
//        if(valandos[i]>2)
//            ats++;
