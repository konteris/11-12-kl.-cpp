/*

Bandþiau kaþkà daryti, bet net neþinojau nuo ko pradëti
tai pamaniau, jog geriau iðsianalizuosiu sprendimà

*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1000000;

bool turi_virsininka[MAX_N]; //turi ar neturi virsininko i darbuotojas
vector<pair<int,int> > panaikinti; //vektoriaus elementas yra pair tipo(pair mano supratimu tiesiog masyvas is dvieju elemtu)

int main()
{
    freopen("virsininkai.in", "r", stdin);
    freopen("virsininkai.out", "w", stdout);

    int N, M;
    scanf("%d%d", &N, &M);

    for (int i = 0; i < N; ++i)
        turi_virsininka[i] = false; // visi darbuotojai neturi virsininko

    for (int j = 0; j < M; ++j) {
        int a, b;
        scanf("%d%d", &a, &b);
        int pavaldinys = max(a, b) - 1; // susiranda kuris yra didesni t.y pavaldinys, BET kodel -1?

        if (!turi_virsininka[pavaldinys]) //if'a vykdo jeigu turi_virsininka[pavaldinys] yra false; tai jei neturi virsininko
            turi_virsininka[pavaldinys] = true; //tai tas programuotojas tures virsininka ir daugiau tureti nebegales
        else
            panaikinti.push_back(make_pair(a, b)); //prideda projekta kuris bus nutrauktas, nes programuotojas jau turi virsininka
    }

    printf("%d %d %d\n", N - 1, panaikinti.size(), N - 1 - (M - panaikinti.size())); //panaikinti.size() - P
    for (int j = 0; j < panaikinti.size(); ++j)
        printf("%d %d\n", panaikinti[j].first, panaikinti[j].second);
    for (int i = 1; i < N; ++i)
        if (!turi_virsininka[i])
            printf("1 %d\n", i+1);

    return 0;
}
