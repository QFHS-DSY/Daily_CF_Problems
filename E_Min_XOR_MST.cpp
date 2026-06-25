//https://codeforces.com/gym/106592/problem/E
//260622
//2000
#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define PII pair<int, int>
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3fLL
// #define int long long
using namespace std;
using ll=long long;
using ld=long double;

struct DSU
{
    vector<int> fa, sz;

    DSU(int n = 0)
    {
        init(n);
    }

    void init(int n)
    {
        fa.resize(n + 1);
        sz.assign(n + 1, 1);
        iota(fa.begin(), fa.end(), 0);
    }

    int find(int x)
    {
        while(x != fa[x])
        {
            fa[x] = fa[fa[x]];
            x = fa[x];
        }
        return x;
    }

    bool unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if(x == y)
            return false;
        if(sz[x] < sz[y])
            swap(x, y);
        fa[y] = x;
        sz[x] += sz[y];
        return true;
    }
};

struct Edge
{
    int u, v, id;
    ll w;
    bool in_mst = false;
};

struct Adj
{
    int to, id;
    ll w;
};

struct SegTree
{
    int n;
    vector<ll> tag;

    SegTree(int n = 0)
    {
        init(n);
    }

    void init(int n_)
    {
        n = n_;
        tag.assign(4 * n + 4, LLINF);
    }

    void update(int p, int l, int r, int ql, int qr, ll val)
    {
        if(ql <= l && r <= qr)
        {
            tag[p] = min(tag[p], val);
            return;
        }
        int mid = (l + r) >> 1;
        if(ql <= mid)
            update(p << 1, l, mid, ql, qr, val);
        if(mid < qr)
            update(p << 1 | 1, mid + 1, r, ql, qr, val);
    }

    void update(int l, int r, ll val)
    {
        if(l <= r)
            update(1, 1, n, l, r, val);
    }

    ll query(int p, int l, int r, int idx)
    {
        ll res = tag[p];
        if(l == r)
            return res;
        int mid = (l + r) >> 1;
        if(idx <= mid)
            res = min(res, query(p << 1, l, mid, idx));
        else
            res = min(res, query(p << 1 | 1, mid + 1, r, idx));
        return res;
    }

    ll query(int idx)
    {
        return query(1, 1, n, idx);
    }
};

inline void solve()
{
    int n, m;
    ll x;
    cin>>n>>m>>x;

    vector<Edge> edges(m);
    vector<int> ord(m);
    for(int i=0;i<m;i++)
    {
        cin>>edges[i].u>>edges[i].v>>edges[i].w;
        edges[i].id = i;
        ord[i] = i;
    }

    sort(ord.begin(), ord.end(), [&](int a, int b)
    {
        return edges[a].w < edges[b].w;
    });

    DSU dsu(n);
    ll mst = 0;
    vector<vector<Adj>> g(n + 1);
    for(int id: ord)
    {
        auto &e = edges[id];
        if(dsu.unite(e.u, e.v))
        {
            e.in_mst = true;
            mst += e.w;
            g[e.u].push_back({e.v, id, e.w});
            g[e.v].push_back({e.u, id, e.w});
        }
    }

    int LOG = 1;
    while((1<<LOG) <= n)
        LOG++;
    vector<vector<int>> up(LOG, vector<int>(n + 1, 1));
    vector<vector<ll>> mx(LOG, vector<ll>(n + 1, 0));
    vector<int> dep(n + 1, 0), parent(n + 1, 0), parent_edge(n + 1, -1);

    vector<int> st;
    st.push_back(1);
    up[0][1] = 1;
    for(int i=0;i<(int)st.size();i++)
    {
        int u = st[i];
        for(auto [v, id, w]: g[u])
        {
            if(v == parent[u])
                continue;
            parent[v] = u;
            parent_edge[v] = id;
            up[0][v] = u;
            mx[0][v] = w;
            dep[v] = dep[u] + 1;
            st.push_back(v);
        }
    }

    for(int k=1;k<LOG;k++)
    {
        for(int v=1;v<=n;v++)
        {
            up[k][v] = up[k - 1][up[k - 1][v]];
            mx[k][v] = max(mx[k - 1][v], mx[k - 1][up[k - 1][v]]);
        }
    }

    auto query_max = [&](int u, int v)
    {
        ll res = 0;
        if(dep[u] < dep[v])
            swap(u, v);
        int diff = dep[u] - dep[v];
        for(int k=LOG-1;k>=0;k--)
        {
            if(diff >> k & 1)
            {
                res = max(res, mx[k][u]);
                u = up[k][u];
            }
        }
        if(u == v)
            return res;
        for(int k=LOG-1;k>=0;k--)
        {
            if(up[k][u] != up[k][v])
            {
                res = max(res, mx[k][u]);
                res = max(res, mx[k][v]);
                u = up[k][u];
                v = up[k][v];
            }
        }
        res = max(res, mx[0][u]);
        res = max(res, mx[0][v]);
        return res;
    };

    vector<int> sz(n + 1, 1), heavy(n + 1, 0);
    for(int i=n-1;i>0;i--)
    {
        int u = st[i];
        int p = parent[u];
        sz[p] += sz[u];
        if(!heavy[p] || sz[u] > sz[heavy[p]])
            heavy[p] = u;
    }

    vector<int> top(n + 1, 0), pos(n + 1, 0), edge_child(m, 0);
    int timer = 0;
    vector<pair<int, int>> chains;
    chains.push_back({1, 1});
    while(!chains.empty())
    {
        auto [u, h] = chains.back();
        chains.pop_back();
        for(int cur=u;cur;cur=heavy[cur])
        {
            top[cur] = h;
            pos[cur] = ++timer;
            if(parent_edge[cur] != -1)
                edge_child[parent_edge[cur]] = cur;

            for(auto e: g[cur])
            {
                int v = e.to;
                if(v != parent[cur] && v != heavy[cur])
                    chains.push_back({v, v});
            }
        }
    }

    SegTree seg(n);
    auto update_path = [&](int u, int v, ll w)
    {
        while(top[u] != top[v])
        {
            if(dep[top[u]] < dep[top[v]])
                swap(u, v);
            seg.update(pos[top[u]], pos[u], w);
            u = parent[top[u]];
        }
        if(dep[u] > dep[v])
            swap(u, v);
        seg.update(pos[u] + 1, pos[v], w);
    };

    for(auto &e: edges)
    {
        if(!e.in_mst)
            update_path(e.u, e.v, e.w);
    }

    vector<ll> replacement(m, LLINF);
    for(auto &e: edges)
    {
        if(e.in_mst)
            replacement[e.id] = seg.query(pos[edge_child[e.id]]);
    }

    ll ans = LLINF;
    if(m > n - 1)
        ans = mst;

    for(auto &e: edges)
    {
        ll nw = (e.w ^ x);
        ll cand;
        if(e.in_mst)
            cand = mst - e.w + min(nw, replacement[e.id]);
        else
            cand = mst + min(0LL, nw - query_max(e.u, e.v));
        ans = min(ans, cand);
    }

    cout<<ans<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    //cout<<fixed<<setprecision(15);

    int T;
    cin>>T;
    while(T--)
        solve();

    return 0;
}
