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
#define maxn 100011
#define MOD
#define Task ""
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
map <pii, int> mp;
struct dinh
{
    int low = 0, num = 0, pre;
};
vector <int> ke[maxn];
int n, m, time_DFS;
dinh a[maxn];
int cnt = 0;
pii res[maxn];
void dfs (int u)
{
    a[u].num = a[u].low = ++time_DFS;
    for (int i = 0; i < sz(ke[u]); i ++)
    {
        int v = ke[u][i];
        if (v == a[u].pre) continue;
        if (!a[v].num)
        {
            a[v].pre = u;
            dfs(v);
            a[u].low = min(a[u].low, a[v].low);
            if (a[v].low == a[v].num) res[++cnt] ={min(u, v), max(v, u)};
        }
        else a[u].low = min(a[u].low, a[v].num);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n;
    for (int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        ke[u].PB(v);
        ke[v].PB(u);
    }
    cin >> m;
    for (int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        ke[u].PB(v);
        ke[v].PB(u);
        mp[{min(u, v), max(v, u)}] = 1;
    }
    dfs(1);
    int ans = cnt;
    for (int i = 1; i <= cnt; i ++)
        if (mp[res[i]]) ans --;
    cout << ans;
}
