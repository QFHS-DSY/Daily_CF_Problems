//https://codeforces.com/gym/106677/problem/F
//260901
//2200
#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3fLL
#define ctz __builtin_ctz //unsigned int 最低位1的下标
#define ctzll __builtin_ctzll // unsigned ll 最低位1的下标
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define int long long
using namespace std;
using PII=pair<int,int>;
using ll=long long;
using ld=long double;
using ull=unsigned long long;
using i128=__int128_t;
using u128=__uint128_t;

int n,u,v,m,q,t1,t2,t3,t4,x,y;
vector<vector<int>> g;
vector<array<int,4>> gg;

inline void solve()
{
    vector<int> gx={1,u,n},gy={1,v,n};
    gg.clear();
    cin>>m;
    while (m--) {
        cin>>t1>>t2>>t3>>t4;
        gg.push_back({t1,t2,t3,t4});
        if (t1-1>=1) gx.emplace_back(t1-1);
        gx.emplace_back(t1);
        gx.emplace_back(t2);
        if (t2+1<=n) gx.emplace_back(t2+1);

        if (t3-1>=1) gy.emplace_back(t3-1);
        gy.emplace_back(t3);
        gy.emplace_back(t4);
        if (t4+1<=n) gy.emplace_back(t4+1);
    }

    sort(gx.begin(),gx.end());
    gx.erase(unique(gx.begin(),gx.end()),gx.end());
    sort(gy.begin(),gy.end());
    gy.erase(unique(gy.begin(),gy.end()),gy.end());

    int N=gx.size(),M=gy.size();
    g.assign(N,vector<int>(M,0));
    for (auto &[t1,t2,t3,t4] : gg) {
        int xl=lower_bound(gx.begin(),gx.end(),t1)-gx.begin();
        int xr=lower_bound(gx.begin(),gx.end(),t2+1)-gx.begin();
        int yl=lower_bound(gy.begin(),gy.end(),t3)-gy.begin();
        int yr=lower_bound(gy.begin(),gy.end(),t4+1)-gy.begin();

        g[xl][yl]++;
        if (xr<N) g[xr][yl]--;
        if (yr<M) g[xl][yr]--;
        if (xr<N && yr<M) g[xr][yr]++;
    }

    for (int i=0;i<N;++i) for (int j=1;j<M;++j) g[i][j]+=g[i][j-1];
    for (int i=1;i<N;++i) for (int j=0;j<M;++j) g[i][j]+=g[i-1][j];

    vector<vector<ll>> dis(N,vector<ll>(M,INF));
    int sx=lower_bound(gx.begin(),gx.end(),u)-gx.begin();
	int sy=lower_bound(gy.begin(),gy.end(),v)-gy.begin();
	dis[sx][sy]=0;

	priority_queue<array<ll,3>,vector<array<ll,3>>,greater<>> pq;
    pq.push({0,sx,sy});

    while (!pq.empty()) {
        auto [d,x,y]=pq.top();pq.pop();

        if (dis[x][y]==d) {
            if (x && g[x-1][y]==0) {
                ll nd=d+gx[x]-gx[x-1];
                if (dis[x-1][y]>nd) {
                    dis[x-1][y]=nd;
                    pq.push({dis[x-1][y],x-1,y});
                }
            }

            if (x+1<N && g[x+1][y]==0) {
                ll nd=d+gx[x+1]-gx[x];
                if (dis[x+1][y]>nd) {
                    dis[x+1][y]=nd;
                    pq.push({dis[x+1][y],x+1,y});
                }
            }

            if (y && g[x][y-1]==0) {
                ll nd=d+gy[y]-gy[y-1];
                if (dis[x][y-1]>nd) {
                    dis[x][y-1]=nd;
                    pq.push({dis[x][y-1],x,y-1});
                }
            }

            if (y+1<M && g[x][y+1]==0) {
                ll nd=d+gy[y+1]-gy[y];
                if (dis[x][y+1]>nd) {
                    dis[x][y+1]=nd;
                    pq.push({dis[x][y+1],x,y+1});
                }
            }
        }
    }

    cin>>q;
    while (q--) {
        cin>>x>>y;

        int pxl=upper_bound(gx.begin(),gx.end(),x)-gx.begin()-1;
        int pyl=upper_bound(gy.begin(),gy.end(),y)-gy.begin()-1;

        int pxr=(pxl+1<N && g[pxl+1][pyl]==0) ? pxl+1 : pxl;
        int pyr=(pyl+1<M && g[pxl][pyl+1]==0) ? pyl+1 : pyl;

        ll ans=INF;
        for (int i=pxl;i<=pxr;i++) {
            for (int j=pyl;j<=pyr;j++) {
                if (g[i][j]==0) 
                    ans=min(ans,dis[i][j]+abs(gx[i]-x)+abs(gy[j]-y));
            }
        }

        if (ans<INF) cout<<ans<<endl;
        else cout<<"no"<<endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    //cout<<fixed<<setprecision(15);

    while (cin>>n>>u>>v) {
        if (!n && !u && !v) break;
        solve();
    }

    return 0;
}
