//https://codeforces.com/gym/101059/problem/B
//260923
//1200
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
// #define int long long
using namespace std;
using PII=pair<int,int>;
using ll=long long;
using ld=long double;
using ull=unsigned long long;
using i128=__int128_t;
using u128=__uint128_t;

inline void solve()
{
    int n,mx=0;cin>>n;
    vector<int> a(2*n+1);
    for (int i=1;i<=n;++i) cin>>a[i],a[i+n]=a[i],mx=max(mx,a[i]);

    vector<int> mp1(mx+1,0),mp2(mx+1,0);
    set<int> s(a.begin()+1,a.end());
    for (int i=1;i<=2*n;++i) {
        mp2[a[i]]=max(mp2[a[i]],i-mp1[a[i]]-1);
        mp1[a[i]]=i;
    }

    int mi=INT_MAX;
    for (auto p : s) {
        mi=min(mi,mp2[p]);
        //cout<<p<<' '<<mp2[p]<<endl;
    }
    cout<<n+mi<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    //cout<<fixed<<setprecision(15);

    int T=1;
    //cin>>T;
    while(T--)
        solve();

    return 0;
}
