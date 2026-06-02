//https://codeforces.com/gym/106539/problem/D
//260602
//1400
#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define PII pair<int, int>
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3fLL
// #define int long long
using namespace std;
typedef long long ll;

inline void solve()
{
    int n,m;cin>>n>>m;
    int ans=(m+1)/2+1;
    cout<<min(ans,n)<<endl;
    //vector<int> cnt(n+1,0);

    // for (int i=0;i<(1<<m);++i) {
    //     auto dfs=[&](auto self,int now,int c,int ch) {
    //         if (c>n) return;
    //         if (now==m) {cnt[c]++; return;}
    //         if ((ch && i&(1<<now)) || (!ch && !(i&(1<<now)))) 
    //             self(self,now+1,c,0),self(self,now+1,c,1);
    //         else self(self,now+1,c+1,0),self(self,now+1,c+1,1);
    //     };

    //     dfs(dfs,0,1,0);
    //     dfs(dfs,0,1,1);
    // }

    // int id=1,mx=0;
    // for (int i=1;i<=n;++i) cout<<cnt[i]<<" ";
    // cout<<endl;
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
