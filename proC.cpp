//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define pii pair <ll ,ll>
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
#define Task "proC"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
struct canh{
    ll u, v, w;
};
canh edge[maxn];
ll n, m;
bool cmp(canh a, canh b)
{
    return a.w > b.w;
}
ll par[maxn];
ll root(ll v) {
    return par[v] == 0
            ? v
            : (par[v] = root(par[v]));
}
vii ke[maxn];
ll h[maxn];
const ll lg = 20;
ll SpT[lg][maxn];
ll minP[lg][maxn];
void dfs(ll u)
{
    for(pii x : ke[u]){
        ll v = x.F;
        ll w = x.S;
        if(v == SpT[0][u]) continue;
//        d[v] = d[u] + w;
        h[v] = h[u] + 1;
        SpT[0][v] = u;
        minP[0][v] = w;
        for(ll i = 1; i < lg; i++){
            SpT[i][v] = SpT[i-1][SpT[i-1][v]];
            minP[i][v] = min(minP[i - 1][v], minP[i-1][SpT[i-1][v]]);
        }
        dfs(v);
    }
}
ll lca(ll u, ll v)
{
    ll minr = oo;
    if(h[u] < h[v]) swap(u, v);
    ll k = h[u] - h[v];
    for(ll i = lg - 1; i >= 0; i--){
        if(k & (1 << i)) {
            minr = min(minr, minP[i][u]);
            u = SpT[i][u];
        }
    }
    if(u == v) return minr;
    for(ll i = lg - 1; i >= 0; i--){
        if(SpT[i][u] != SpT[i][v]){
            minr = min (min(minr, minP[i][u]), minP[i][v]);
            u = SpT[i][u];
            v = SpT[i][v];
        }
    }
    return min(min(minr, minP[0][u]), minP[0][v]);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n >> m;
    for (ll i = 1; i <= m; i ++)
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    sort(edge + 1, edge + m + 1, cmp);
    for (ll i = 1; i <= m; i ++) {
        ll x = edge[i].u;
        ll y = edge[i].v;
        x = root(x);
        y = root(y);
        if(x == y) continue ;
        par[x] = y;
        ll a = edge[i].u;
        ll b = edge[i].v;
        ll c = edge[i].w;
        ke[a].PB({b, c});
        ke[b].PB({a, c});
    }
    dfs(1);
    ll res = 0;
    for (ll i = 1; i <= m; i ++)
    {
        ll x = edge[i].u;
        ll y = edge[i].v;
        ll z = edge[i].w;
        res += lca(x, y) - z;
    }
    cout << res;
}
