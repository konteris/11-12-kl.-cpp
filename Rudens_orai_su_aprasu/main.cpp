#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//funkcijų prototipai

void Skaitymas(int &n, string D[], double L[], double S[], double A[], int &la, int &sa, int &aa, double Y[]);
double Vidurkis(int x, double X[]);
int Kiek(int x, double X[], double vid);
void Rasymas(string D, int x, double xvid, int xK);
int main()
{
    int n, la, sa, aa, LK, SK, AK;
    double L[91], S[91], A[91], Lvid, Svid,Avid, Y[91], sum=0;
    string D[91];
    Skaitymas(n, D, L, S, A, la, sa, aa, Y);
    Lvid = Vidurkis(la, L), Svid = Vidurkis(sa, S), Avid = Vidurkis(aa, A);
    LK = Kiek(la, L, Lvid), SK = Kiek(sa, S, Svid), AK = Kiek(aa, A, Avid);
    Rasymas("LIETINGOS", la, Lvid, LK);
    Rasymas("SAULĖTOS", sa, Svid, SK);
    Rasymas("APSINIAUKUSIOS", aa, Avid, AK);

    //ofstream out1("orai_res.txt", ios::app);
    for(int i = 0; i < n; i++)
        sum += Y[i];
    double Mvid = sum / double(n);
    cout<<"Mėnesio vidutinė temperatūra: "<<fixed<<setprecision(2)<<Mvid<<endl;
    //cout.close();
    return 0;
}

//pradinių duomenų skaitymo funkcija

void Skaitymas(int &n, string D[], double L[], double S[], double A[], int &la, int &sa, int &aa, double Y[])
{
    ifstream in("orai_data.txt");
    in>>n;
    double x;
    la = 0,sa = 0,aa = 0;

    for(int i = 0; i < n; i++)
    {
        in>>D[i]>>x;
        if(D[i] == "L")
        {
            L[la] = x;
            la++;
        }
        else if(D[i] == "S")
        {
            S[sa] = x;
            sa++;
        }
        else
        {
            A[aa] = x;
            aa++;
        }
        Y[i] = x;
    }
    in.close();
}

//aritmetinio vidurkio skaičiavimo funkcija

double Vidurkis(int x, double X[])
{
    double s = 0;
    for(int i = 0; i < x; i++)
    {
        s += X[i];
    }
    return s / double(x);
}

//kiekio skaičiavimo funkcija

int Kiek(int x, double X[], double vid)
{
    int k = 0;
    for(int i = 0; i < x; i++)
    {
        if(X[i] > vid)
            k++;
    }
    return k;
}
void Rasymas(string D, int x, double xvid, int xK)
{
    //ofstream out("orai_res.txt", ios::app);
    cout<<D<<":";
    if(x > 0)
    {
        cout<<endl;
        cout<<x<<" dienos"<<endl;
        cout<<"Vidutinė dienos temperatūra: "<<fixed<<setprecision(2)<<xvid<<endl;
        cout<<"Dienų, kai temperatūra buvo didesnė už vidutinę, skaičius: "<<xK<<endl;
    }
    else
        cout<<" nėra"<<endl;
    //out.close();
}

/*
void Rasymas(int la, int sa, int aa, double Lvid, double Svid, double Avid, int LK, int SK, int AK)
{
    ofstream out("orai_res.txt");
    out<<"LIETINGOS:";
    if(la > 0)
    {
        out<<endl;
        out<<la<<" dienos"<<endl;
        out<<"Vidutinė dienos temperatūra: "<<fixed<<setprecision(2)<<Lvid<<endl;
        out<<"Dienų, kai temperatūra buvo didesnė už vidutinę, skaičius: "<<LK<<endl;
    }
    else
        out<<" nėra"<<endl
    out<<"SAULĖTOS:";
    if(sa>0)
    {
        out<<endl;
        out<<sa<<" dienos"<<endl;
        out<<"Vidutinė dienos temperatūra: "<<fixed<<setprecision(2)<<Svid<<endl;
        out<<"Dienų, kai temperatūra buvo didesnė už vidutinę, skaičius: "<<SK<<endl;
    }
    else
        out<<" nėra"<<endl;
    out<<"APSINIAUKUSIOS:";
    if(aa>0)
    {
        out<<endl;
        out<<aa<<" dienos"<<endl;
        out<<"Vidutinė dienos temperatūra: "<<fixed<<setprecision(2)<<Avid<<endl;
        out<<"Dienų, kai temperatūra buvo didesnė už vidutinę, skaičius: "<<AK<<endl;
    }
    else
        out<<" nėra"<<endl;
    out.close();
}
*/
