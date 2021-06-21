#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int k,s,N[1000], x=0, y=0;
    ifstream in("ateiviu-kojines-vyr.in");
    ofstream out("ateiviu-kojines-vyr.out");

    in>>k>>s;
    for(int i=0; i<s; i++)
    {
        in>>N[i];
    }

    for(int i=0; i<s; i++)
    {
        if(N[i]>=k)
            x+=k-1;
        else
            x+=N[i];
    }

    for(int i=0; i<s; i++)
    {
        if(N[i]>=k)
            y++;
    }

    if(y>0)
        out<<x+1;
    else
        out<<-1;

    in.close();
    out.close();
    return 0;
}
