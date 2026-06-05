//https://codeforces.com/gym/102860/problem/B
//260605
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
using ll=long long;
using ld=long double;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    //cout<<fixed<<setprecision(15);

    int n,l;cin>>n>>l;
    vector<int> a(2*n+1);
    for (int i=1;i<=n;++i) cin>>a[i];
    sort(a.begin()+1,a.begin()+n+1);
    for (int i=1;i<=n;++i) a[i+n]=a[i]+l;

    ll ans=n*(n-1)/2ll*(n-2)/3ll,r=1;
    for (int i=1;i<=n;++i) {
        while ((a[r]-a[i])*2<l) r++;
        ans-=1ll*(r-i-1)*(r-i-2)/2;
        //cout<<i<<" "<<r<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
