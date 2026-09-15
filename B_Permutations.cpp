//https://codeforces.com/gym/103426/problem/B
//260912
//1000
//#pragma GCC optimize("O3","unroll-loops")
#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3fLL
#define  ctz __builtin_ctz //unsigned int 最低位1的下标
#define  ctzll __builtin_ctzll // unsigned ll 最低位1的下标
#define  pcnt __builtin_popcount
#define  pcntll __builtin_popcountll
#define int long long
using namespace std;
using ll=long long;
using ull=unsigned long long;
using ld=long double;
using i128=__int128_t;
using PII=pair<int,int>;

const ll MOD=1e9+7;
int a[1010][1010],vis[1010];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    //cout<<fixed<<setprecision(15);

    int n;cin>>n;
    int s=n*(n+1)/2,c=0;
    map<int,int> mp;
    for (int i=1;i<n;++i) for (int j=1;j<=n;++j) cin>>a[i][j];
    for (int i=1;i<=n;++i) {
        memset(vis,0,sizeof vis);
        int t=0,f=0;
        for (int j=1;j<n;++j) if (!vis[a[j][i]]) vis[a[j][i]]=1,t+=a[j][i]; else {f=1; break;}
        if (f) c++;
        else {
            if (mp[s-t]) c++;
            mp[s-t]++;
        }
        //cout<<t<<' '<<c<<endl;
    }

    int ans=1;
    for (int i=1;i<=c;++i) ans=ans*i%MOD;
    for (int i=1;i<=n;++i) if (mp[i]) ans=ans*mp[i]%MOD;
    cout<<n-c<<' '<<ans<<endl;
    return 0;
}
