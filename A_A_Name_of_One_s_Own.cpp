//https://codeforces.com/gym/106607/problem/A
//260701
//1800
#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define PII pair<int, int>
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3fLL
#define int long long
using namespace std;
using ll=long long;
using ld=long double;

constexpr ll MOD=998244353;
constexpr ll MAXN=3e5+5;
vector<ll> invs(MAXN);

struct DSU {
    vector<int> fa, p, e, f;

    DSU(int n) {
        fa.resize(n + 1);
        iota(fa.begin(), fa.end(), 0);
        p.resize(n + 1, 1);
        e.resize(n + 1);
        f.resize(n + 1);
    }
    int get(int x) {
        while (x != fa[x]) {
            x = fa[x] = fa[fa[x]];
        }
        return x;
    }
    bool merge(int x, int y) { // 设x是y的祖先
        if (x == y) f[get(x)] = 1;
        x = get(x), y = get(y);
        e[x]++;
        if (x == y) return false;
        if (x < y) swap(x, y); // 将编号小的合并到大的上
        fa[y] = x;
        f[x] |= f[y], p[x] += p[y], e[x] += e[y];
        return true;
    }
    void reset(int x) {
        fa[x]=x,p[x]=1,e[x]=0,f[x]=0;
    }
    bool same(int x, int y) {
        return get(x) == get(y);
    }
    bool F(int x) { // 判断连通块内是否存在自环
        return f[get(x)];
    }
    int size(int x) { // 输出连通块中点的数量
        return p[get(x)];
    }
    int E(int x) { // 输出连通块中边的数量
        return e[get(x)];
    }
};

inline void solve()
{
    int n;cin>>n;
    DSU dsu(2*n+1);

    vector<PII> e(n);
    vector<int> a;

    for (auto &[u,v] : e) {
        cin>>u>>v;
        a.emplace_back(u);
        a.emplace_back(v);
    }
    sort(a.begin(),a.end());
    vector<int> tag(2*n,0);
    ll ans=1;

    for (int i=0;i<n;++i) {
        int u=lower_bound(a.begin(),a.end(),e[i].fi)-a.begin();
        int v=lower_bound(a.begin(),a.end(),e[i].se)-a.begin();

        u=dsu.get(u),v=dsu.get(v);
        int szu=dsu.size(u),szv=dsu.size(v);

        dsu.merge(u,v);
        int p=dsu.get(u);

        if (u!=v) {
            if (tag[u] && tag[v]) ans=0;
            else if (tag[u]) {
                (ans*=invs[szv])%=MOD;
                tag[p]=1;
            } else if (tag[v]) {
                (ans*=invs[szu])%=MOD;
                tag[p]=1;
            } else ans=ans*invs[szu]%MOD*invs[szv]%MOD*(szu+szv)%MOD;
        } else {
            if (tag[u]) ans = 0;
            else {
                (ans*=2*invs[szu])%=MOD;
                tag[u]=1;
            }
        }

        cout<<ans<<(i==n-1 ? "\n" : " ");
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    //cout<<fixed<<setprecision(15);
	
	invs[1]=1;
	for (int i=2;i<MAXN;++i)
		invs[i]=(MOD - MOD/i)*invs[MOD%i]%MOD;

    int T;
    cin>>T;
    while(T--)
        solve();

    return 0;
}
