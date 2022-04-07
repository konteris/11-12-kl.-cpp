// Sudėtingumas - O(N log N)
// Autorius - Kęstutis Vilčinskas

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

#define MaxN 100010
#define INF 2100000000


int N, L, C, T;
int x[MaxN];

vector<int> A, // Atstumai tarp BIT'ų
            B; // Galimos R reikšmės
int S[MaxN];

int main() {
    freopen("makleris-vyr.in", "r", stdin);
    freopen("makleris-vyr.out", "w", stdout);
    scanf("%d%d%d%d\n", &N, &L, &C, &T);
    for (int i = 1; i <= N; i++)
        scanf("%d\n", &x[i]);
    
    for (int i = 1; i < N; i++) {
        int t = x[i+1] - x[i];
        A.push_back(t);
   
        // Tikrinsim tik šias R reikšmes:
        B.push_back(t/2);
        B.push_back(t/2 + t%2);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Paskaičiuojame sumų masyvą:
    S[N-1] = 0;
    A.push_back(INF);
    for (int i = N-2; i >= 0; i--)
        S[i] = S[i+1] + A[i];
        
    ll gera_kaina = (ll)L*(ll)T; // antena = 0;
    int j = 0;
    
    for (int i = 0; i < B.size(); i++) {
        
        // Bandome visus galimus antenos ilgius
        int R = B[i];
        
        // Gali būti, kad 
        while (2*R >= A[j])
           j++;
        
        // Kaina, naudojant anteną B[i]
        ll cost = R*C + (S[j] - (N - j - 1)*(2*R)) * T;
        
        if (gera_kaina > cost) 
            gera_kaina = min(gera_kaina, cost);
        
    }
    printf("%lld\n", gera_kaina);    
    return 0;
}
