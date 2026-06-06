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
// #define int long long
using namespace std;
using ll=long long;
using ld=long double;

constexpr int MAXN=250005;
vector<int> g[MAXN];
int fa[MAXN], dsu[MAXN], sz[MAXN], vis[MAXN];

int find(int x)
{
    while (dsu[x]!=x) {
        dsu[x]=dsu[dsu[x]];
        x=dsu[x];
    }
    return x;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    //cout<<fixed<<setprecision(15);

    int n;cin>>n;
    for (int i=1,u,v;i<n;++i) {
        cin>>u>>v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    vector<int> st{1};
    fa[1]=0;
    for (int i=0;i<(int)st.size();++i) {
        int u=st[i];
        for (auto v:g[u]) {
            if (v==fa[u]) continue;
            fa[v]=u;
            st.emplace_back(v);
        }
    }

    int q;cin>>q;
    vector<int> a;
    for (int id=1;id<=q;++id) {
        int k;cin>>k;
        a.resize(k);
        for (auto &x:a) {
            cin>>x;
            vis[x]=id;
            dsu[x]=x;
            sz[x]=1;
        }

        ll ans=0;
        for (auto x:a) {
            if (fa[x]&&vis[fa[x]]==id) {
                int rx=find(x), ry=find(fa[x]);
                if (rx!=ry) {
                    ans+=1LL*sz[rx]*sz[ry];
                    dsu[rx]=ry;
                    sz[ry]+=sz[rx];
                }
            }
        }
        cout<<ans<<endl;
    }


    return 0;
}
