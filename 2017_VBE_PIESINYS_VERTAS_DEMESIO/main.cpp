#include <iostream>
#include <fstream>

using namespace std;

struct staciakampis
{
    int x, y;
    int x1, y1;
    int R,G,B;
};

void skaitymas(int &n, staciakampis S[], int &gx, int &gy);
void spalvos_nustatymas(staciakampis S[], int n, int xi, int yj, int &r, int &g, int &b);

int main()
{
    int n,r,g,b, gx,gy;
    staciakampis S[100];
    skaitymas(n,S,gx,gy);
    ofstream out("U2rez.txt");

    out<<gy<<" "<<gx<<endl;
    for(int i=0; i<gy; i++)
    {
        for(int j=0; j<gx; j++)
        {
            r = 255; //is pradziu balta
            g = 255;
            b = 255;
            spalvos_nustatymas(S,n,j,i,r,g,b);
            out<<r<<" "<<g<<" "<<b<<" "<<endl;
        }
    }
    out.close();
    return 0;
}

void skaitymas(int &n, staciakampis S[], int &gx, int &gy)
{
    ifstream in("U2.txt");
    in>>n;
    int dx,dy;
    gx=0;
    gy=0;
    for(int i=0; i<n; i++)
    {
        in>>S[i].x>>S[i].y>>dx>>dy>>S[i].R>>S[i].G>>S[i].B;
        S[i].x1 = S[i].x + dx; // galutine x koordinate, visas piesinio ilgis
        if(S[i].x1 > gx)
            gx = S[i].x1;
        S[i].y1 = S[i].y +dy; // galutine y koordinate
        if(S[i].y1 > gy)
            gy = S[i].y1; //papildomas
    }
    in.close();
}

void spalvos_nustatymas(staciakampis S[], int n, int xi, int yj, int &r, int &g, int &b)
{
    for(int i=0; i<n; i++)
    {
        if(xi>=S[i].x && xi<=S[i].x1-1   &&  yj>=S[i].y && yj<=S[i].y1-1) //jeigu langelis yra staciakampio dalis, tai
        {
            r = S[i].R; // to langelio spalva yra jau paskutinio nuskaityto stac. spalva
            g = S[i].G;
            b = S[i].B;
        }
    }
}
