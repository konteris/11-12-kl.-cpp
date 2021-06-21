#include <iostream>
#include <fstream>

using namespace std;

string pakeisti(int sk);

int main()
{
    ifstream in("U1.txt");
    ofstream out("U1rez.txt");
    int a,b,sk1,sk2,sk3;
    cin>>a>>b;
    for(int i=0; i<a*b; i++)
    {
        cin>>sk1>>sk2>>sk3;
        cout<<pakeisti(sk1)<<pakeisti(sk2)<<pakeisti(sk3);
        if((i+1)%b == 0)
            cout<<endl;
        else
            cout<<";";
    }

    in.close();
    out.close();
    return 0;
}

string pakeisti(int sk)
{
    int x,y;
    //string ses_sk="";
    string ses[] = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};

//    while(sk>0)
//    {
//        x=sk%16;
//        ses_sk += ses[x];
//        sk/=16;
//    }
    x = sk / 16;
    y = sk % 16;
    return ses[x] + ses[y];
}
