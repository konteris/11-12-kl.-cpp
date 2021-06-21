#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void Skaitymas(double V[], double M[], int &vi, int &mi);
void Skaiciuoti(int x, double X[], double &sum, double &vid);
void Rasyti(double vsum, double vvid, double msum, double mvid);
int main()
{
    int vi,mi;
    double V[100],M[100], vsum,vvid,msum,mvid;
    Skaitymas(V,M,vi,mi);
    Skaiciuoti(vi, V, vsum,vvid);
    Skaiciuoti(mi, M, msum,mvid);
    Rasyti(vsum,vvid,msum,mvid);
    return 0;
}

void Skaitymas(double V[], double M[], int &vi, int &mi)
{
    ifstream in("drabuziai_data.txt");
    int n;
    in>>n;
    char x;
    double y, xV[100], xM[100];
    vi=0, mi=0;
    for(int i=0; i<100; i++)
    {
        xM[i]=0;
        xV[i]=0;
    }
    for(int i=0; i<n; i++)
    {
        in>>x>>y;
        if(x=='m')
            xM[i]=y;
        else
            xV[i]=y;
    }
    for(int i=0; i<100; i++)
    {
        if(xM[i]>0)
        {
            M[mi]=xM[i];
            mi++;
        }
        if(xV[i]>0)
        {
            V[vi]=xV[i];
            vi++;
        }
    }
    in.close();
}

void Skaiciuoti(int x, double X[], double &sum, double &vid)
{
    sum=0;
    for(int i=0;i<x;i++)
    {
        sum+=X[i];
    }
    vid = sum/double(x);
}

void Rasyti(double vsum, double vvid, double msum, double mvid)
{
    ofstream out("drabuziai_res.txt");
    out<<"MOTERIÐKI"<<endl;
    if(msum==0)
        out<<"NE"<<endl;
    else
        out<<fixed<<setprecision(2)<<msum<<" "<<mvid<<endl;
    out<<"VYRIÐKI"<<endl;
    if(vsum==0)
        out<<"NE"<<endl;
    else
         out<<fixed<<setprecision(2)<<vsum<<" "<<setw(2)<<vvid<<endl;

    out<<fixed<<setprecision(2)<<msum+vsum<<endl;
    out.close();
}
