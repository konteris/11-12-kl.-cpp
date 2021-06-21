#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int N, K, D[100001], d;
    int sum=0;

    ifstream in("sampunas-vyr.in");
    ofstream out ("sampunas-vyr.out");
    in>>N>>K;

    for(int i=1; i<=N; i++)
        D[i]=0;

    for(int i=1; i<2; i++)
        D[i]=1; // pirma diena plaunasi galva ir cia todel nepraeina tu testu

    for(int i=1; i<=K; i++)
    {
        in>>d;
        D[d]+=1;
    }

    for(int i=1; i<=N; i++)
    {
        if((D[i]+D[i+1])==0) //jeigu dvi dienas sudejus gaunu 0 tai ta antraja diena plaus
            D[i+1]=1;
    }
    for(int i=1; i<=N; i++)
    {
        sum+=D[i];
        //cout<<D[i];
    }
    cout<<sum;

    in.close();
    out.close();
    return 0;
}
