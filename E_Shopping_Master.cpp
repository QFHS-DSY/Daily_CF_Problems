//https://codeforces.com/gym/106677/problem/E
//260901
//1500
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

int n;
vector<PII> a;

inline void solve()
{
    int ans=0,mx=n,c=0;
    a.assign(n,{0,0});
    for (int i=0;i<n;++i) {
        cin>>a[i].fi>>a[i].se;
        mx=max(mx-a[i].se,1ll);
    }
    sort(a.begin(),a.end());

    int id=-1;
    for (int i=0;i<n;++i) if (a[i].se){ans+=a[i].fi,id=i,mx--; break;}
    for (int i=0;i<n;++i) if (mx && i!=id) mx--,ans+=a[i].fi;
    cout<<ans<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    //cout<<fixed<<setprecision(15);

    while(cin>>n) {
        if (!n) break;
        solve();
    }

    return 0;
}