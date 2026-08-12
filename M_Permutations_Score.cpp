//https://codeforces.com/gym/103821/problem/M
//260707
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
using ll=long long;
using ld=long double;

constexpr int MOD=1e9+7;
constexpr int inv2=500000004;
constexpr int MAXN=1e5+5;
ll cnt[MAXN],pre[MAXN],a[MAXN],ans[MAXN];

// ll ksm(ll b,ll e) {
//     ll ans=1;
//     b%=MOD;
//     while (e) {
//         if (e&1) (ans*=b)%=MOD;
//         e>>=1;
//         b=b*b%MOD;
//     }
//     return ans;
// }

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    //cout<<fixed<<setprecision(15);

    a[0]=1;
    for (ll i=1;i<=100000;++i) {
        a[i]=a[i-1]*i%MOD;
        for (int j=1;j*j<=i;++j) {
            if (i%j==0) cnt[i]++;
        }
        if (int(sqrt(i))*int(sqrt(i))==i) cnt[i]=2*cnt[i]-2;
        else cnt[i]*=2-1;
        pre[i]=pre[i-1]+cnt[i];
        ans[i]=pre[i]*a[i]%MOD*inv2%MOD;
    }

    int T,n;
    cin>>T;
    while(T--) {
        cin>>n;
        cout<<ans[n]<<endl;
    }
    //cout<<ksm(2ll,(ll)MOD-2)<<endl;

    return 0;
}
