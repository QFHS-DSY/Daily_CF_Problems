//https://codeforces.com/gym/101962/problem/C
//260617
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

constexpr ll MOD=(ll)1e9+7;

ll ksm(ll b,ll e) {
    b%=MOD;
    ll res=1;
    while (e) {
        if (e&1) (res*=b)%=MOD;
        b=b*b%MOD;
        e>>=1;
    }
    return res;
}

inline void solve()
{
    ll n;cin>>n;
    if (n==1) cout<<0<<endl;
    else if (n==2) cout<<1<<endl;
    else {
        ll ans=ksm(2ll,n-1);
        ans=ans*((2*n-6)%MOD)%MOD;
        (ans+=n+3)%=MOD;
        cout<<ans<<endl;
    }
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
