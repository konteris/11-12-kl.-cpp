#include <iostream>
#include <fstream>

using namespace std;

void Skaitymas(int ATS[]);

int main()
{
    int ATS[20], X[20];
    Skaitymas(ATS);
    for(int i=0;i<20;i++)
    {
        X[i]=ATS[i];
    }
    for(int i=0;i<10;i++)
    {
        for(int j=1;j<=10-X[i];j++)
            ATS[i+j]++;
    }

    for(int i=0;i<20;i++)
        cout<<ATS[i]<<endl;    
    return 0;
}
void Skaitymas(int ATS[])
{
    ifstream in("U1.txt");
    for(int i=0;i<20;i++)
        ATS[i]=0;

    for(int i=0;i<10;i++)
    {
        //int x;
        //in>>x;
        in>>ATS[i];
    }

    in.close();
}