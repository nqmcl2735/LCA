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
#define MOD1
#define Task ""
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
int n, m, s, t;
int dd[maxn];
int SpT[20][maxn];
int minP[20][maxn];
int trc[maxn];
int d[maxn];
int que[maxn];
vi ke[maxn];
void bfs()
{
    reset(d, -1);
    d[s] = 0;
    dd[s] = 1;
    int l = 1, r = 1;
    que[1] = s;
    while (l <= r)
    {
        int u = que[l ++];
        for (int v : ke[u])
        {
            if (dd[v]) continue;
            que[++ r] = v;
            d[v] = d[u] + 1;
            dd[v] = 1;
            if (v == t) return;
        }
    }
}
bool Better(int u, int v){
    int minu = oo, minv = oo;
    for (int i = 19; i >= 0; i--)
        if (SpT[i][u] != SpT[i][v])
        {
            minu = min(minu, minP[i][u]);
            minv = min(minv, minP[i][v]);
            u = SpT[i][u]; v = SpT[i][v];
        }
    minu = min(minu, u);
    minv = min(minv, v);
    return (minu < minv);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n >> m >> s >> t;
    swap(s, t);
    for (int i = 1; i <= m; i ++)
    {
        int u, v;
        cin >> u >> v;
        ke[u].PB(v);
        ke[v].PB(u);
    }
    bfs();
    if (!dd[t])
    {
        cout << - 1;
        return 0;
    }
    for (int i = 1; que[i]; i ++)
    {
        int u = que[i];
        for (int v : ke[u])
            if (d[v] == d[u] - 1){
                if (trc[u] == 0 || Better(v, trc[u])) trc[u] = v;
        }
        minP[0][u] = u;
        SpT[0][u] = trc[u];
        for (int j = 1; j < 20; j ++) {
            SpT[j][u] = SpT[j - 1][SpT[j - 1][u]];
            minP[j][u] = min(minP[j - 1][u], minP[j - 1][SpT[j - 1][u]]);
        }
    }
    for (; s != t; t = trc[t]) {
        cout << t << " ";
    }
    cout << t;
}
