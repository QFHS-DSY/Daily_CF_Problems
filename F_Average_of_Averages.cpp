//https://codeforces.com/gym/105059/problem/F
//260529
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
    int n;cin>>n;
    vector<ld> a(n+1),pre(n+1,0),p(n+1,0);
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
        p[i]=p[i-1]+pre[i];
    }

    ld ans=0;
    for (int i=1;i<=n;++i) {
        ld tmp=p[n]-p[i-1];
        tmp-=p[n-i];
        ans+=tmp/(ld)i;
    }
    
    ans*=2;
    ans/=(ld)n*(ld)(n+1);
    cout<<ans<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout<<fixed<<setprecision(15);

    int T;
    cin>>T;
    while(T--)
        solve();

    return 0;
}
