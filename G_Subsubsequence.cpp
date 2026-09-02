//https://codeforces.com/gym/105223/problem/G
//260902
//1800
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

constexpr ll MOD=1e9+7;
constexpr ll inv2=(MOD+1)/2;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    //cout<<fixed<<setprecision(15);

    int n,q,pos,x;cin>>n;
    vector<int> a(n),cnt(30,0),pw3(n+1,1);
    for (int i=0;i<n;++i) {
        cin>>a[i];
        for (int j=0;j<30;++j) cnt[j]+=a[i]>>j&1;
    }

    for (int i=0;i<n;++i) pw3[i+1]=3*pw3[i]%MOD;
    cin>>q;
    while (q--) {
        cin>>pos>>x;
        pos--;
        for (int i=0;i<30;++i) cnt[i]-=a[pos]>>i&1;
		a[pos]=x;
		for (int i=0;i<30;++i) cnt[i]+=a[pos]>>i&1;

		int ans=0;
		for (int i=29;i>=0;--i) {
			ans=2*ans%MOD;
			ans=(ans+pw3[n]) %MOD;
			ans=(ans+MOD-pw3[n-cnt[i]])%MOD;
		}

		cout<<ans*inv2%MOD<<endl;
    }

    return 0;
}
