//https://codeforces.com/gym/106706/problem/M
//260917
//1400
#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3fLL
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

inline void solve()
{
    ll n;cin>>n;
    vector<int> a(n+1,0),pre(n+1,0),ls(n+1,-1);
    for (int i=1;i<=n;++i) cin>>a[i],ls[a[i]]=i,pre[i]=pre[i-1]+a[i];

    int l=ls[1],r=ls[1];
    ll ans=n*(n-1)/2-1;
    for (int i=1;i<=n;++i) {
        int x=ls[i];
        if (i==1) {
            ans=max(ans,(ll)pre[n]-pre[x]-i);
            ans=max(ans,(ll)pre[x-1]-pre[0]-i);
            l=r=x;
        } else if (x<l) {
            ans=max(ans,(ll)pre[n]-pre[x]-i);
            l=x;
        } else if (x>r) {
            ans=max(ans,(ll)pre[x-1]-pre[0]-i);
            r=x;
        }
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
