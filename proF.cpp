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
#define maxn 200005
#define MOD
#define Task "proF"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
struct cpn
{
    int In, Ou, pos;
};
cpn a[maxn];
int n;
bool cmp (cpn a, cpn b)
{
    return (a.Ou < b.Ou);
}
int dp[maxn];
int trc[maxn];
int SpT[20][maxn];
int minP[20][maxn];
bool Better(int u, int v){
    int minu = oo, minv = oo;
    for (int i = 19; i >= 0; i--)
        if (SpT[i][u] != SpT[i][v])
        {
            minu = min(minu, minP[i][u]);
            minv = min(minv, minP[i][v]);
            u = SpT[i][u]; v = SpT[i][v];
        }
    minu = min(minu, a[u].pos);
    minv = min(minv, a[v].pos);
    return (minu < minv);
}
int bnSearch(int l, int r, int k){
    int res = 0;
    while(l <= r){
        int mid = (l + r)/2;
        if(a[mid].Ou < k) res = mid, l = mid + 1;
        else r = mid - 1;
    }
    return res;
}
int p[maxn];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i].In;
        cin >> a[i].Ou;
        a[i].pos = i;
    }
    vi v;
    for (int i = 1; i <= n; i ++) {
        v.PB(a[i].In);
        v.PB(a[i].Ou);
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (int i = 1 ; i <= n; i ++) {
        a[i].In = lower_bound(v.begin(), v.end(), a[i].In) - v.begin() + 1;
        a[i].Ou = lower_bound(v.begin(), v.end(), a[i].Ou) - v.begin() + 1;
    }
    sort(a + 1, a + n + 1, cmp);
//    for (int i = 1; i <= n; i ++)
//        fo << a[i].In << " " << a[i].Ou << endl;
    a[0].Ou = 0;
    for (int i = 1; i <= n; i ++)
    {
        int x = bnSearch(0, i - 1, a[i].In);
        dp[i] = dp[x] + 1;
        trc[i] = p[x];
        SpT[0][i] = p[x];
        p[i] = i;
        minP[0][i] = min(a[i].pos, a[p[x]].pos);
        for (int j = 1; j < 20; j ++)
        {
            SpT[j][i] = SpT[j - 1][SpT[j - 1][i]];
            minP[j][i] = min(minP[j - 1][i], minP[j - 1][SpT[j - 1][i]]);
        }
        if (dp[i - 1] > dp[i])
        {
            dp[i] = dp[i - 1];
            p[i] = p[i - 1];
            continue;
        }
        if (dp[i - 1] == dp[i])
            if (Better(p[i - 1], i))
            {
                dp[i] = dp[i - 1];
                p[i] = p[i - 1];
            }
    }
    cout << dp[n] << "\n";
    vi res;
    int x = p[n];
    while (sz(res) < dp[n])
    {
        res.PB(a[x].pos);
        x = trc[x];
    }
    sort(res.begin(), res.end());
    for (int i : res) cout << i << " ";
}
