//https://codeforces.com/gym/102254/problem/H
//260907
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
#define int long long
using namespace std;
using PII=pair<int,int>;
using ll=long long;
using ld=long double;
using ull=unsigned long long;
using i128=__int128_t;
using u128=__uint128_t;

constexpr int MAXN=1e6+10;
int is[MAXN],phi[MAXN],c,pr[MAXN];

inline void solve()
{
    int n,m;cin>>n>>m;
    if (gcd(n,m)==1 && phi[m]<=1e6) cout<<phi[m]<<endl;
    else cout<<-1<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    //cout<<fixed<<setprecision(15);

    is[1]=1,phi[1]=1;
    for (int i=2;i<=1e6;++i) {
        if (!is[i]) pr[++c]=i,phi[i]=i-1;
        for (int j=1;pr[j]*i<=MAXN;++j) {
            int m=pr[j]*i;
            is[m]=1;
            if (i%pr[j]==0) {phi[m]=phi[i]*pr[j]; break;}
            else phi[m]=phi[i]*(pr[j]-1);
        }
    }

    //for (int i=1;i<=10;++i) cout<<is[i]<<' '<<phi[i]<<endl;

    int T;
    cin>>T;
    while(T--)
        solve();

    return 0;
}
