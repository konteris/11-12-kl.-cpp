/*ble nenoriu visko isspoilinti tai skaityma ikeliu :DD p
pabandziau cia siek tiek paaiskint kas vyksta

aisku gal tu kazkaip kitaip sumastei ir kazkur kitur nezinai kaip daryt
bet still gal kazka pades
*/
void Skaitymas(int Numeriai[])
{
    ifstream in("U2.txt");
    in>>n;
    for(int j=1;j<=50;j++)
        Numeriai[j]=0; // sitas Numeriai masyvą ir naudoju sumuoti indekse. Dabar kiekvienas jo elementas =0
    
    char X[21];
    for(int i=0;i<n;i++)
    {
        in>>ws;
        in.get(X,21);
        S[i].pavadinimas = X;
        in>>S[i].k;
        for(int j=0;j<S[i].k ; j++)
            {
                int nr; // papildomas kintamasis kuri nusiskaitysiu
                in>>nr;
                S[i].stoteliu_numeriai[j]=nr; // cia isirasau visus tuos marsrutu numerius. Veliau panaudoju rasyme, kai jau susirandu ilgiausia marsruta(tam turiu Numeriai masyva)
                Numeriai[nr]++; //sicia ir sumuoju, tarkim nr=4(marsruto numeris cia) tai Numeriai[4] atsiranda +1 marsrutas
            }
    }
    in.close();
}