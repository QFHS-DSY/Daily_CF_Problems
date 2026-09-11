//https://codeforces.com/gym/105492/problem/I
//260911
//1600
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

vector<int> dp;
vector<PII> a;
vector<array<int,3>> b;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    //cout<<fixed<<setprecision(15);

    int n,k;cin>>n>>k;
    a.resize(n+1),b.resize(k),dp.assign(n+1,INT_MAX);
    for (int i=1;i<=n;++i) cin>>a[i].fi>>a[i].se;
    for (auto &[p,d,c] : b) cin>>p>>d>>c;

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    dp[0]=0;
    for (int i=1;i<=n;++i) {
        dp[i]=min(dp[i],dp[i-1]+a[i].se);

        for (int j=0;j<k;++j) {
            int l=i,r=min(n,i+b[j][1]-1);
            while (l<r) {
                int mid=l+r+1>>1;
                if (a[mid].fi-a[i].fi+1>b[j][0]) r=mid-1;
                else l=mid;
            }

            dp[l]=min(dp[l],dp[i-1]+b[j][2]);
            //cout<<l<<' '<<dp[l]<<endl;
        }
    }

    cout<<dp[n]<<endl;
    return 0;
}
