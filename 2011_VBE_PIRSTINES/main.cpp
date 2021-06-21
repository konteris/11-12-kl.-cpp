#include <iostream>
#include <fstream>
using namespace std;

void Skaitymas(int MK[], int MD[], int VK[], int VD[]);

int Poros(int K[], int D[]);

int Atliekamos(int K[], int D[]);

void Isvedimas(int MK[], int MD[], int VK[], int VD[]);

int main()
{
    int MK[51], MD[51], VK[51], VD[51];
    Skaitymas(MK,MD,VK,VD);
    Isvedimas(MK,MD,VK,VD);

    return 0;
}

void Skaitymas(int MK[], int MD[], int VK[], int VD[])
{
    int a,b,c,n;
    for(int i=1; i<=50; i++)
    {
        MK[i]=0;
        MD[i]=0;
        VK[i]=0;
        VD[i]=0;
    }
    ifstream in("U1.txt");
    in>>n;

    for(int i=0; i<n; i++)
    {
        in>>a>>b>>c;

        if(a==3 && b==1)
            VK[c]++;

        else if(a==3 && b==2)
            VD[c]++;

        else if(a==4 && b==1)
            MK[c]++;

        else if(a==4 && b==2)
            MD[c]++;
    }

    in.close();
}

int Poros(int K[], int D[])
{
    int p=0;

    for(int i=1; i<=50; i++)
    {
        if(K[i]<D[i])//jeigu pirstiniu yra, ir jeigu kairiu daugiau negu desiniu tai imam mazesni skaiciu ir pridedam prie poros
            p+=K[i];
        else
            p+=D[i];
    }
    return p;
}

int Atliekamos(int K[], int D[])
{
    int liko=0;

    for(int i=1; i<=50; i++)
    {
        if(K[i] > D[i])
            liko+=(K[i]-D[i]);
        else
            liko+=(D[i]-K[i]);
    }
    return liko;
}

void Isvedimas(int MK[], int MD[], int VK[], int VD[])
{
    ofstream out("U1rez.txt");

    int mp = Poros(MK, MD);
    int VP = Poros(VK,VD);
    int ml = Atliekamos(MK,MD);
    int VL = Atliekamos(VK,VD);


    out<<mp<<endl;


    out<<VP<<endl;

    //-----------------------

    out<<ml<<endl;

    out<<VL<<endl;

    out.close();
}
