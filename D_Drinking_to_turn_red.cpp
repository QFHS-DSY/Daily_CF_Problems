//https://codeforces.com/gym/102448/problem/D
//260608
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
    cout<<fixed<<setprecision(10);

    int n,x,y;cin>>n>>x>>y;
    vector<pair<ld,int>> g(n);
    ll a,b,r;
    for (int i=0;i<n;++i) {
        cin>>a>>b>>r;
        a-=x,b-=y;
        g[i]={sqrt(a*a+b*b)-r,r};
    }

    sort(g.begin(),g.end(),[](pair<ld,int> x,pair<ld,int> y)
        {return x.fi<y.fi;});
    
    ld ans=0;
    ll pre=0;
    for (auto &[a,b] : g) {
        if ((ans+pre)<a) ans=a-pre;
        pre+=b;
    }

    cout<<ans<<endl;
    return 0;
}