//https://codeforces.com/gym/102396/problem/E
//260609
//1200
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

    int n;cin>>n;
    ll ans=0,r=n-1,l=0;
    vector<int> a(n);
    for (int i=0,x;i<n;++i) {
        cin>>x;
        if (x==0) a[i]=(1ll<<l),l++;
        else {
            ans+=(1ll<<r);
            if (x==1) a[i]=(1ll<<r);
            else if (x==-1) a[i]=(-1)*(1ll<<r);
            r--;
        }
    }
    cout<<ans<<endl;
    for (int i=0;i<n;++i) cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
