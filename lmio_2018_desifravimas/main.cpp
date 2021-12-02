#include <iostream>
#include <fstream>

using namespace std;

void Skaitymas(int &M, string &blogas_sif, string &pilnas_sif);
int main()
{
    int M, index, sifro_kodas;
    string blogas_sif, pilnas_sif;

    Skaitymas(M,blogas_sif, pilnas_sif);
    string ats;
    //char ats[M];
    for(int i=0; i<M; i++)
    {
        if(blogas_sif[i] != pilnas_sif[i])
        {
            index = i;
            break;
        }
    }
    sifro_kodas = (pilnas_sif[index] ) - (blogas_sif[index]);

    for(int i=0; i<M; i++)
    {
        if((pilnas_sif[i] - 0) < 65 or (pilnas_sif[i] - 0) >122)
            ats[i] = pilnas_sif[i];

        else if((pilnas_sif[i] - 0) > 90 and (pilnas_sif[i] - 0) <97)
            ats[i] = pilnas_sif[i];

        else if((pilnas_sif[i] - 0) - sifro_kodas < 65)
        {
            int x = sifro_kodas - ((pilnas_sif[i] - 0) - 65);
            ats[i] = 91-x;
        }
        else if((pilnas_sif[i] - 0) - sifro_kodas < 97 and (pilnas_sif[i] - 0) - sifro_kodas > 90)
        {
            int x = sifro_kodas - ((pilnas_sif[i] - 0) - 97);
            ats[i] = 123-x;
        }
        else
            ats[i] = (pilnas_sif[i] - 0) - sifro_kodas;

    }

    ofstream out("rez.txt");

    for(int i=0; i<M; i++)
        out<<ats[i];

    out.close();
    return 0;
}

void Skaitymas(int &M, string &blogas_sif, string &pilnas_sif)
{
    ifstream in("duom.txt");
    in>>M>>blogas_sif>>pilnas_sif;
    in.close();
}


//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main() {
//  int N;
//  string A, B;
//  ifstream in("duom.txt");
//  ofstream out("rez.txt");
//  in >> N >> A >> B;
//
//  int K;
//  for (int i = 0; i < N; i++) {
//    if (A[i] != B[i]) {
//      K = (A[i] - B[i] + 26) % 26;
//      break;
//    }
//  }
//
//  for (int i = 0; i < N; i++) {
//    char baze = ' ';
//    if ('A' <= B[i] && B[i] <= 'Z') {
//      baze = 'A';
//    } else if ('a' <= B[i] && B[i] <= 'z') {
//      baze = 'a';
//    } else {
//      continue;
//    }
//
//    int raide = B[i] - baze;
//    raide = (raide + K + 26) % 26;
//    B[i] = raide + baze;
//  }
//
//  out << B << endl;
//  in.close();
//  out.close();
//  return 0;
//}
