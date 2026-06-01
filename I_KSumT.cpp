//https://codeforces.com/gym/104782/problem/I
//260601
//1500
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

constexpr ll MOD=(ll)1e9+7,M=(ll)5e6+5;

inline ll ksm(ll b,ll e) {
    b%=MOD;
    ll ans=1;
    while (e) {
        if (e&1) (ans*=b)%=MOD;
        e>>=1;
        b=b*b%MOD;
    }

    return ans;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    //cout<<fixed<<setprecision(15);

	vector<int> f(M), g(M);

	f[0]=1;
	for (int i=1;i<M;i++) f[i]=1ll*i*f[i-1]%MOD;
	g[M-1]=ksm(f[M-1],MOD-2);
	for (int i=M-1;i>0;i--) g[i-1]=1ll*i*g[i]%MOD;

	auto C=[&] (int x,int y) -> int {
		if (x==y) return 1;
		if (y<0 || x<0 || y>x) return 0;
		return 1ll*f[x]*g[y]%MOD*g[x-y]%MOD;
	};

    int k,s,t;cin>>k>>s>>t;
    int m=k/t,n=k%t;
    
    ll ans=0;
    for (int i=1;i<=s;++i) {
        if (i*m>s) break;
        if ((s-i*m)%(m+1)==0) {
            int c1=i,c2=(s-i*m)/(m+1);
            (ans+=1ll*C(c1-1,t-n-1)*C(c2-1,n-1)%MOD)%=MOD;
        }
    }

    cout<<ans<<endl;
    return 0;
}