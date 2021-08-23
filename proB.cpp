//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define pii pair <ll, ll>
#define vi vector <int>
#define vii vector <pii>
#define mpa make_pair
#define oo INT_MAX
#define F first
#define S second
#define reset(x, i) memset(x,i,sizeof(x))
#define sz(x) int(x.size())
#define mp make_pair
#define maxn 100011
#define MOD
#define Task ""
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
ll n, q;
vii ke[maxn];
ll h[maxn];
ll d[maxn];
const ll lg = 20;
ll SpT[lg][maxn];

void Reset(){
    reset(ke, 0);
    reset(h, 0);
    reset(d, 0);
    reset(SpT, 0);
}
void Init(){
    for(ll u = 1; u < n; u++){
        ll v, w;
        cin >> v >> w;
        ke[u].PB({v, w});
        ke[v].PB({u, w});
    }
}

void DFS(ll u){
    for(pii x : ke[u]){
        ll v = x.F;
        ll w = x.S;
        if(v == SpT[0][u]) continue;
        d[v] = d[u] + w;
        h[v] = h[u] + 1;
        SpT[0][v] = u;
        for(ll i = 1; i < lg; i++){
            SpT[i][v] = SpT[i-1][SpT[i-1][v]];
        }
        DFS(v);
    }
}

ll lca(ll u, ll v){
    if(h[u] < h[v]) swap(u, v);
    ll k = h[u] - h[v];
    for(ll i = lg - 1; i >= 0; i--){
        if(k & (1 << i)) u = SpT[i][u];
    }
    if(u == v) return u;
    for(ll i = lg - 1; i >= 0; i--){
        if(SpT[i][u] != SpT[i][v]){
            u = SpT[i][u];
            v = SpT[i][v];
        }
    }
    return SpT[0][u];
}

void Sol(){
    DFS(0);
    cin >> q;

    while(q --){
        ll u, v;
        cin >> u >> v;
        cout << d[u] + d[v] - 2* d[lca(u, v)] << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(cin >> n){
        if(!n) return 0;
        Reset();
        Init();
        Sol();
    }
    return 0;
}
