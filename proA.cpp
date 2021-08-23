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
typedef long long ll;
typedef long double ld;
int SpT[20][maxn];//SpT[j][i]: to tien thu 2^j cua i
int T[maxn];//F[i]: khoang cach tu diem i den dinh
int n, root, m;
int h[maxn];
vi ke[maxn];
void dfs(int u){
    for(int v : ke[u]){
        if(v != SpT[0][u]){
            h[v] = h[u] + 1;
            SpT[0][v] = u;
            for(int i = 1; i < 20; i++)
            SpT[i][v] = SpT[i-1][SpT[i-1][v]];
            dfs(v);
        }
    }
}
int lca (int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    int lg = log2(h[u]);
    for (int i = lg; i >= 0; i --)
        if (h[u] - (1 << i) >= h[v])
            u = SpT[i][u];
    if (u == v) return u;
    for (int i = lg; i >= 0; i --)
        if (SpT[i][u] != -1 && SpT[i][u] != SpT[i][v]) {
            u = SpT[i][u];
            v = SpT[i][v];
        }
    return SpT[0][u];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n >> root >> m;
    for (int i = 1; i < n; i ++)
    {
        int x, y;
        cin >> x >> y;
        ke[x].PB(y);
        ke[y].PB(x);
    }
    dfs(root);
    while (m --)
    {
        int x, y;
        cin >> x >> y;
        cout << lca(x, y) << "\n";
    }
}
