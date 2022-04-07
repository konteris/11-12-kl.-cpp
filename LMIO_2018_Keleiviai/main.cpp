#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
    int N;
    ifstream in("U1.txt");
    in>>N;
    vector<int> a,b,sum;
    for(int i=1;i<=N;i++)
    {
        int x,y;
        in>>x>>y;
        a.push_back(x);
        b.push_back(y);
        sum[i]=x+y;
    }
    long long T=0;
    //sort(a.begin(), a.end()); 
    sort(b.begin(), b.end());
    int i=1; //kur yra palydove
    int j=0;
    while(N>0)
    {
        while(i<a[j]) // kol nepasiekiama pirmo keleivio
        {
            i++;
            T++;
        }
           
        N=0;
    }
    cout<<i;
    in.close();
    return 0;
}
