//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define mpa make_pair
#define oo INT_MAX
#define F first
#define S second
#define reset(x, i) memset(x,i,sizeof(x))
#define sz(x) int(x.size())
#define mp make_pair
#define maxn 100005
#define MOD
#define Task ""
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
//typedef long long ll;
//typedef long double ld;
int n, Root, m, l[maxn], P[20][maxn];

int level(int u) {
    if (u == Root)
        return l[u] = 1;
    if (l[u] == 0)
        l[u] = level(P[0][u]) + 1;
    return l[u];
}

int lca(int x, int y) {
    for (int k = 19; k >= 0; k--)
        if (l[P[k][x]] >= l[y])
            x = P[k][x];
    for (int k = 19; k >= 0; k--)
        if (l[P[k][y]] >= l[x])
            y = P[k][y];
    for (int k = 19; k >= 0; k--)
        if (P[k][x] != P[k][y]) {
            x = P[k][x];
            y = P[k][y];
        }
    while (x != y) {
        x = P[0][x];
        y = P[0][y];
    }
    return x;
}
void solve() {
    cin >> n >> Root >> m;
    for (int i = 1; i < n; i ++)
    {
        int x, y;
        cin >> x >> y;
        P[0][y] = x;
    }
    for (int i = 1; i <= n; i++)
        level(i);
    for (int k = 1; k <= 19; k++)
        for (int i = 1; i <= n; i++)
            P[k][i] = P[k - 1][P[k - 1][i]];
    while (m --)
    {
        int x , y;
        cin >> x >> y;
        cout << lca(x, y) << "\n";
    }
}
