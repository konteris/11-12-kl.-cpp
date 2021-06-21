#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void Skaitymas(int &k, int Sk1[], int Sk2[], int Sk3[], int &d1, int &d2, int &d3);

int Balsu_Suma(int k, int S[]);

int Didziausias(int a, int b, int c);

void Taskai(int a, int b, int c, int &t1, int &t2, int &t3);

void Taskai_atskiri(int Sk1[], int Sk2[], int Sk3[], int &t1,int &t2,int &t3,int k);

void Direktorius(int d1, int d2, int d3, int &tv1, int &tv2, int &tv3);

int main()
{
    int k, Sk1[100],Sk2[100],Sk3[100], d1, d2, d3;
    int t1, t2, t3, tv1,tv2,tv3;
    int nugaletojas;

    ofstream out("U1rez.txt");

    Skaitymas(k,  Sk1,  Sk2,  Sk3,  d1,  d2, d3);

    Taskai_atskiri(Sk1,  Sk2,  Sk3,tv1,tv2,tv3, k);
    Direktorius(d1,d2,d3,tv1,tv2,tv3);

    int d = Didziausias(tv1, tv2, tv3);
    if(tv1==d)
        nugaletojas = 1;
    else if(tv2==d)
        nugaletojas = 2;
    else if(tv3==d)
        nugaletojas = 3;

    out<<Balsu_Suma(k, Sk1)<<" "<<Balsu_Suma(k, Sk2)<<" "<<Balsu_Suma(k, Sk3)<<endl;
    out<< tv1<<" "<<tv2<<" "<<tv3<<endl;
    out<<nugaletojas<<endl;

    out.close();
    return 0;
}

void Skaitymas(int &k, int Sk1[], int Sk2[], int Sk3[], int &d1, int &d2, int &d3)
{
    ifstream in("U1.txt");
    in>>k;
    for(int x=0; x<k; x++)
    {
        in>>Sk1[x]>>Sk2[x]>>Sk3[x];
    }
    in>>d1>>d2>>d3;
    in.close();
}

int Balsu_Suma(int k, int S[])
{
    int balsai = 0;
    for(int x=0; x<k; x++)
    {
        balsai+=S[x];
    }
    return balsai;
}

int Didziausias(int a, int b, int c)
{
    int didz;
//funkcija bûtø efektyvesnë, jei sudëtum else, tai atradus teisingà variantà ji netikrintø kitø
    if(a>=b &&a >=c)
        didz=a;

    else if(b>=a && b>=c)
        didz=b;

    else if (c>=a && c>=b)
        didz=c;

    return didz;
}

void Taskai(int a, int b, int c, int &t1, int &t2, int &t3)

{
    int d = Didziausias(a,b,c);

    if((a==d) && (b!=d) && (c!=d)) //jei pirmas daugiaugiai balsu
    {
        t1 = 4;
        t2=0;
        t3=0;
    }

    if((a!=d) && (b==d) && (c!=d)) //jei antras daugiaugiai balsu
    {
        t1 = 0;
        t2=4;
        t3=0;
    }

    if((a!=d) && (b!=d) && (c==d)) //jei trecias daugiaugiai balsu
    {
        t1 = 0;
        t2=0;
        t3=4;
    }

    if((a==d) && (b==d) && (c!=d)) //jei 1 ir 2 vienodai balsu
    {
        t1 = 2;
        t2=2;
        t3=0;
    }

    if((a==d) && (b!=d) && (c==d)) //jei 1 ir 3 vienodai balsu
    {
        t1 = 2;
        t2=0;
        t3=2;
    }

    if((a!=d) && (b==d) && (c==d)) //jei 2 ir 3 vienodai balsu
    {
        t1 = 0;
        t2=2;
        t3=2;
    }

    if((a==d) && (b==d) && (c==d)) //jei visi vienodai
    {
        t1 = 0;
        t2=0;
        t3=0;
    }
}

void Taskai_atskiri(int Sk1[], int Sk2[], int Sk3[], int &tv1,int &tv2,int &tv3,int k)
{
    tv1=0,tv2=0,tv3=0;
    int t1,t2,t3;


    for(int x=0; x<k; x++)
    {
        Taskai(Sk1[x],Sk2[x],Sk3[x],t1,t2,t3);
        tv1+=t1;
        tv2+=t2;
        tv3+=t3;
    }
}

void Direktorius(int d1, int d2, int d3, int &tv1, int &tv2, int &tv3)
{
    int d = Didziausias(tv1,tv2,tv3);

    if(tv1==d && tv2 ==d && tv3 == d)
    {
        tv1+= d1;
        tv2+= d2;
        tv3+= d3;
    }
    if(tv1==d && tv2 ==d && tv3 != d)
    {

        tv1+= d1;
        tv2+= d2;
        tv3+= d3;
    }

    if(tv1==d && tv2 !=d && tv3 == d)
    {
        tv1+= d1;
        tv2+= d2;
        tv3+= d3;
    }
    if(tv1!=d && tv2 ==d && tv3 == d)
    {
        tv1+= d1;
        tv2+= d2;
        tv3+= d3;
    }
}
