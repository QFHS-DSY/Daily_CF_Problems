//https://codeforces.com/gym/105315/problem/H
//260527
//1400
#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define PII pair<int, int>
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3fLL
#define int long long
using namespace std;
typedef long long ll;

inline void solve()
{
    int n,k;cin>>n>>k;
    vector<pair<int,ll>> a(n+1);
    for (int i=1;i<=n;++i) cin>>a[i].fi>>a[i].se;

    sort(a.begin()+1,a.end(),
        [&](pair<int,ll> x,pair<int,ll> y){return x.se<y.se;});

    priority_queue<int,vector<int>,greater<int>> pq;
    ll ans=LLONG_MIN,cur=0;
    for (int i=1;i<k;++i) {
        cur+=a[i].fi;
        pq.push(a[i].fi);
    }

    for (int i=k;i<=n;++i) {
        ans=max(ans,cur+a[i].fi-a[i].se);
        cur+=a[i].fi;
        pq.push(a[i].fi);
        cur-=pq.top();
        pq.pop();
    }

    cout<<ans<<endl;
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
