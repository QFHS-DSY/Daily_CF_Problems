//https://codeforces.com/gym/106682/problem/L
//260905
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
// #define int long long
using namespace std;
using PII=pair<int,int>;
using ll=long long;
using ld=long double;
using ull=unsigned long long;
using i128=__int128_t;
using u128=__uint128_t;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    //cout<<fixed<<setprecision(15);

    int n,m;cin>>n>>m;
    vector<int> a(n),b;
    for (auto &x : a) cin>>x;

    b=a;
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    map<int,int> mp;
    for (int i=0;i<b.size();++i) mp[b[i]]=i,b[i]=i;
    for (int i=0;i<n;++i) a[i]=mp[a[i]];
    map<int,int> mpl,mpr,f;
    for (int i=0;i<n;++i) {
        if (f[a[i]]) mpl[a[i]]=max(mpl[a[i]],mpl[a[i]+1]+1);
        else mpl[a[i]]=1;
        f[a[i]-1]=1;
    }

    f.clear();
    for (int i=n-1;i>=0;--i) {
        if (f[a[i]]) mpr[a[i]]=max(mpr[a[i]],mpr[a[i]+1]+1);
        else mpr[a[i]]=1;
        f[a[i]-1]=1;
    }   

    // for (int i=0;i<b.size();++i) 
    //     cout<<b[i]<<' '<<mpl[b[i]]<<' '<<mpr[b[i]]<<endl;
    
    int i=0,ans=0;
    while (i<b.size()) {
        int mx=max(mpl[b[i]],mpr[b[i]]);
        i+=mx,ans++;
    }

    cout<<b.size()<<' '<<ans<<endl;
    return 0;
}
