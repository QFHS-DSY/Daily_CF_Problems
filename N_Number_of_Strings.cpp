//https://codeforces.com/gym/106682/problem/N
//260904
//1300
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

constexpr int MOD=998244353;

ll qpow(ll b,ll e) {
    ll res=1;
    b%=MOD;
    while (e) {
        if (e&1) res=res*b%MOD;
        e>>=1;
        b=b*b%MOD;
    }
    return res;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    //cout<<fixed<<setprecision(15);

    int n,k,a;cin>>n>>k>>a;
    if (n==1) {cout<<(k ? 0 : a)<<endl; return 0;}
	else if (n==2) {cout<<(k ? 0 : a*a)<<endl; return 0;}
    else if (k>n-2) {cout<<0<<endl; return 0;}

    vector<int> f(n+1,0),invf(n+1);
    f[0]=1;
    for (int i=1;i<=n;++i) f[i]=f[i-1]*i%MOD;
    invf[n]=qpow(f[n],MOD-2);
    for (int i=n;i>=1;--i) invf[i-1]=invf[i]*i%MOD;

    auto C=[&](ll x,ll y) -> ll {
        if (y<0 || y>x) return 0;
        return f[x]*invf[y]%MOD*invf[x-y]%MOD;
    };

    //ll ans=a*a*f[n-2]%MOD*invf[k]%MOD*invf[n-k-2]%MOD*qpow(a-1,n-k-2)%MOD;

    int l=n/2,r=n-l,j,cl,cr;
    ll ans=0;
    for (int i=max(0ll,k-l+1);i<=min(k,r-1);++i) {
        j=k-i,cl=l-j,cr=r-i;
        int tmp=a*a*qpow(a-1,cl-1)%MOD*qpow(a-1,cr-1)%MOD;
        tmp=tmp*C(l-1,j)%MOD*C(r-1,i)%MOD;
        ans=(ans+tmp)%MOD;
    }

    cout<<ans<<endl;
    return 0;
}
