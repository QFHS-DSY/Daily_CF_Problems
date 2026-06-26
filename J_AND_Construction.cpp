//https://codeforces.com/gym/106020/problem/J
//260626
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
using ll=long long;
using ld=long double;

inline void solve()
{
    int n,k,w=0;cin>>n>>k;

    if (n==2) {
		if ((k&-k)==k) cout<<1<<endl;
		else cout<<0<<endl;
    } else if (3*n-2*k-1>0) cout<<(3*n-2*k-1)<<endl;
    else if (n&1) cout<<0<<endl;
    else if ((k-3*n/2)==1) cout<<1<<endl;
    else cout<<0<<endl;
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
