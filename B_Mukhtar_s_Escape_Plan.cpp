//https://codeforces.com/gym/106575/problem/B
//260623
//1700
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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    //cout<<fixed<<setprecision(15);

    int n,m,k;
    ll c;
    cin>>n>>m>>k>>c;
    vector<bool> is(n+1,0);
    vector<ll> f(n+1);
    vector<vector<int>> g(n+1);
    for (int i=1,x;i<=k;++i) cin>>x,is[x]=1;
    for (int i=1;i<=n;++i) cin>>f[i];
    for (int i=0,u,v;i<m;++i) {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<ll> dis(n+1,LLINF);
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
    dis[1]=0;
    q.push({0,1});

    while (!q.empty()) {
        auto [d,u]=q.top();
        q.pop();
        if (d!=dis[u]) continue;
        if (u==n) break;

        if (is[u]) {
            for (auto v:g[u]) {
                if (is[v]) continue;
                if (d<dis[v]) {
                    dis[v]=d;
                    q.push({dis[v],v});
                }
            }
        } else {
            for (auto v:g[u]) {
                ll w=is[v]?f[v]:0;
                if (d+w<dis[v]) {
                    dis[v]=d+w;
                    q.push({dis[v],v});
                }
            }
        }
    }

    cout<<(dis[n]<=c?dis[n]:-1)<<endl;

    return 0;
}
