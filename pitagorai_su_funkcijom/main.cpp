#include <iostream>

#include <fstream>

using namespace std;

double trikampioplotas (int a, int b);

int trikampioperimetras (int a, int b, int c);

int main() {

    ifstream in ("skaiciai.txt");
    ofstream out ("pitagorai.txt");
    int x1, x2,k=0;
    in>>x1>>x2;
    for(int a=x1; a<=x2-2; a++)
        for (int b=a+1; b<=x2-1; b++)
          for (int c=b+1; c<=x2; c++)
            if (c*c==a*a+b*b)
            {
                k++;
                cout<<a<<" "<<b<<" "<<c<<" "<<trikampioperimetras(a,b,c)<<" "<<trikampioplotas(a, b)<<endl;
            }
    if(k==0)
        cout<<"Pitagoro trikampiu nera."<<endl;

    in.close();
    out.close();
    return 0;
}

double trikampioplotas (int a, int b)

{

    return (a*b)/2;
}

int trikampioperimetras (int a, int b, int c)

{

return a+b+c;
}

