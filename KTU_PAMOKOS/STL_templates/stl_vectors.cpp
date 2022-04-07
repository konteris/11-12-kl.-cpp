#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    int n;
    fstream in("U2.txt");
    vector<int> Skaiciai;

    in>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        in>>x;
        Skaiciai.push_back(x); // visada reikia naudoti push_back
        cout<<Skaiciai[i];
    }

    for(int d : Skaiciai)
        cout<<d<<endl; //galima ir sitaip iteruoti
    in.close();
    return 0;
}
