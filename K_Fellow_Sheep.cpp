//https://codeforces.com/gym/105442/problem/K
//260616
//1300
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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    //cout<<fixed<<setprecision(15);

    // a   b
    //   c  
    // d   e

    int n;cin>>n;
    ll t=LLONG_MAX;
    for (int i=1,a,b,c,d,e;i<=n;++i) {
        cin>>a>>b>>c>>d>>e;
        ll ans=0;
        if (b>=a) {
            ans+=a;
            if (e>=d) ans+=d;
            else {
                ans+=e;
                int tmp=min(c,b-a);
                ans+=min(tmp,d-e);
            }
        } else {
            ans+=b;
            if (e>=d) {
                ans+=d;
                int tmp=min(c,e-d);
                ans+=min(tmp,a-b);
            } else ans+=e;
        }
        t=min(t,ans);
    }

    cout<<t<<endl;
    return 0;
}
