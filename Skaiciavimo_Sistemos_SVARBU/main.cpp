#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void Skaitymas(int &n, string SK[], int P[], int G[]);
int iDesimtaine(string skc, int ps);
string isDesimtaines(string skc, int ps);
void Rasymas(int n, string SK[], int P[], int G[]);

int main()
{
    int n,  P[21], G[21];
    string SK[21];
    Skaitymas(n,SK,P,G);
    Rasymas(n,SK,P,G);
    return 0;
}
void Skaitymas(int &n, string SK[], int P[], int G[])
{
    ifstream in("duom.txt");
    in>>n;
    for(int i=0; i<n; i++)
    {
        in>>SK[i]>>P[i]>>G[i];
    }
    in.close();
}

int iDesimtaine(string skc, int ps)
{
    int sum=0, sim, k=1; //sum-desimtainis skaicius;  sim- raide ar simbolis paverstas int;   k-laipsnio rodiklis, kuris vis dides
    int d=skc.size()-1; //nes pvz "123" tai antras elementas yra 3 o turiu imti nuo galo
    while(d>0)
    {
        if(skc[d]>='A')
            sim=skc[d]-'A'+10; // pvz: C=67, tai 67-64+10=13 o 13=c
        else
            sim=skc[d]-'0'; //0-9 = [48-57]

        sum+=sim*k; // pradedu kaupt suma t.y dauginu savo gauta int'a is sistemos pagrindo(pakeltu laipsniu - jis vis dideja)
        k*=ps; // k yra tas lapsnis jis vis dideja pvz(astuntaineje): is pradziu k=1, po to k=1*8, veliau k=8*8
        d--; // ispradziu imu paskutini simboli, daba sumazinu ir imsiu antra nuo galo
    }
    return sum;
}

string isDesimtaines(string skc, int ps)
{
    string ats = "";
    string S = "0123456789ABCDEF";
    stringstream x(skc);
    int skc1=0;
    x>>skc1;
    while(skc1>0)
    {
        int liek = skc1%ps;
        ats = S[liek] + ats;
        skc1/=ps;
    }
    return ats;
}

void Rasymas(int n, string SK[], int P[], int G[])
{
    ofstream out("rez.txt");
    for(int i=0; i<n; i++)
    {
        out<<SK[i]<<" "<<P[i];
        if(P[i]==10)
            out<<" "<<isDesimtaines(SK[i], G[i]);
        else
            out<<" "<<iDesimtaine(SK[i], P[i]);
        out<<" "<<G[i]<<endl;
    }

    out.close();
}
