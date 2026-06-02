//https://codeforces.com/gym/106094/problem/B
//260522
//1600
#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define PII pair<ll, ll>
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3fLL
// #define int long long
using namespace std;
typedef long long ll;

inline void solve()
{
    ll n,t;cin>>n>>t;
    vector<PII> a(2*n+1);
    for (ll i=1,x;i<=2*n;i+=2) {
        cin>>x;
        a[i].fi=x/3,a[i+1].fi=x/6;
        a[i].se=(i+1)/2,a[i+1].se=(i+1)/2;
        t-=x/2;
    }

    sort(a.begin()+1,a.end(),[](PII x,PII y){return x.fi<y.fi;});
    ll sum=50*n;
    vector<double> ans(n+1,2);
    for (int i=1;i<=2*n;++i) {
        if (t>=a[i].fi) ans[a[i].se]-=0.5,sum+=25,t-=a[i].fi;
        else break;
    }

    cout<<sum<<endl;
    for (int i=1;i<=n;++i) cout<<ans[i]<<" ";
    cout<<endl;
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
