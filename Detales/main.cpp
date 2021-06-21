
#include <iostream>
#include <fstream>

using namespace std;

void Skaitymas(int &k,int &j,int &s,int &v, int n,int K1[], int J1[], int S1[], int V1[]);
int Suma(int x, int X[]);
void Rinkinys(int x, int X[], int &p, int &n, int &sum);
int Kiek(int x, int y, int z, int c);
void Rasymas(int suma, int kompl, int nep, char x);
int main()
{
    ofstream out("detales_res.txt");
    out.close();
    int k,j,s,v,n, K1[100], J1[100], S1[100], V1[100];
    int kp,kn, ksum,jp,jn,jsum,sp,sn,ssum,vp,vn,vsum;
    Skaitymas(k,j,s,v,n,K1,J1,S1,V1);
    Rinkinys(k,K1,kp,kn,ksum);
    Rinkinys(j,J1,jp,jn,jsum);
    Rinkinys(s,S1,sp,sn,ssum);
    Rinkinys(v,V1,vp,vn,vsum);

    Rasymas(ksum,kp,kn,'K');
    Rasymas(jsum,jp,jn,'J');
    Rasymas(ssum,sp,sn,'S');
    Rasymas(vsum,vp,vn,'V');


    ofstream out1("detales_res.txt", ios::app);
    int pilni_rinkiniai = Kiek(kp,jp,sp,vp);
    out1<<"Iš viso galima sudaryti pilnų komplektų: "<<pilni_rinkiniai<<endl;
    out1.close();
    return 0;
}

void Skaitymas(int &k,int &j,int &s,int &v, int n,int K1[], int J1[], int S1[], int V1[])
{
    ifstream in("detales_data.txt");
    char k2='K';
    char j2='J';
    char s2='S';
    char v2='V';
    char x;
    int y;
    in>>k>>j>>s>>v;
    in>>n;
    for(int i=0; i<100; i++)
    {
        K1[i]=0;
        J1[i]=0;
        S1[i]=0;
        V1[i]=0;
    }
    for(int i=0; i<n; i++)
    {
        in>>x>>y;
        if(x==k2)
            K1[i]=y;
        else if(x==j2)
            J1[i]=y;
        else if(x==s2)
            S1[i]=y;
        else
            V1[i]=y;
    }
    in.close();
}

int Suma(int x, int X[])
{
    int s=0;
    for(int i=0; i<x; i++)
    {
        s+=X[i];
    }
    return s;
}

void Rinkinys(int x, int X[], int &p, int &n, int &sum)
{
    sum = Suma(100,X);
    p = sum/x;
    n = sum%x;
}

int Kiek(int x, int y, int z, int c)
{
    int rinkiniai = min(min(x,y), min(z,c));
    return rinkiniai;
}

void Rasymas(int suma, int kompl, int nep, char x)
{
    ofstream out("detales_res.txt", ios::app);

    out<<"Yra "<<x<<" detalių: ";
    if(suma==0)
        out<<"nėra"<<endl;
    else{
        out<<suma<<endl;
        out<<"Iš "<<x<<" detalių galima sudaryti: "<<kompl<<" komplekt."<<endl;
        out<<"Lieka nepanaudotų: "<<nep<<endl;
    }
    out.close();
}
