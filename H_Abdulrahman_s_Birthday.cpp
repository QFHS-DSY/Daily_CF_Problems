//https://codeforces.com/gym/105315/problem/H
//1400
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

inline void solve()
{
    int n,k;cin>>n>>k;
    vector<ll> a(n),b(n);
    for (int i=0;i<n;++i) cin>>a[i]>>b[i];

    ll ans=0;
    vector<vector<PII>> dp(n,vector<PII> (n+1));
    priority_queue<ll> pq1;
    priority_queue<ll,vector<ll>,greater<ll>> pq2;
    map<ll,int> mp1,mp2;
    for (int i=0;i<k;++i) {
        ans+=a[i];
        pq2.push(a[i]);
        pq1.push(b[i]);
    }

    ans-=pq1.top();
    for (int i=k;i<n;++i) {
    }
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
