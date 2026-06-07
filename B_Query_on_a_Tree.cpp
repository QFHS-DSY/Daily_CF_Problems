//https://codeforces.com/gym/104345/problem/B
//260606
//1700
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

constexpr int MAXN=250005;
vector<int> g[MAXN];
int fa[MAXN],vis[MAXN];

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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    //cout<<fixed<<setprecision(15);

    int n;cin>>n;
    DSU dsu(n);
    for (int i=1,u,v;i<n;++i) {
        cin>>u>>v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    auto dfs=[&](auto &self,int x,int y) -> void {
        fa[x]=y;
        for (auto z : g[x]) {
            if (z!=y) self(self,z,x);
        }
    };

    dfs(dfs,1,0);

    int q;cin>>q;
    while (q--) {
        int k;cin>>k;
        vector<int> a(k);
        for (auto &x : a) {
            cin>>x;
            vis[x]=1;
        }

        for (auto x : a) {
            if (vis[fa[x]]) {
                dsu.merge(x,fa[x]);
                dsu.get(x);
            }
        }

        ll ans=0;
        for (auto x : a) {
            if (x==dsu.get(x)) {
                int c=dsu.size(x);
                ans+=(c-1)*c/2;
            }
        }

        cout<<ans<<endl;

        for (auto x : a) {
            dsu.reset(x);
            vis[x]=0;
        }
    }
    return 0;
}
