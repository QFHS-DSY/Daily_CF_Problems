//https://codeforces.com/gym/106607/problem/B
//260701
//1000
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
    int n,t,f=1;cin>>n;
    vector<int> a(n+1);
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        if (i==1) t=a[i];
        else if (t!=a[i]) f=0;
    }

    if (f) cout<<(a[1]==1 ? 0 : 1)<<endl;
    else {
        int l=1,r=n;
        while (l<=n) {
            if (a[l]==1) l++;
            else break;
        }
        while (r>=1) {
            if (a[r]==1) r--;
            else break;
        }

        int flag=1;
        for (int i=l;i<=r;++i) {
            if (i==l) t=a[i];
            else if (t!=a[i]) flag=0;
        }

        if (flag) cout<<1<<endl;
        else cout<<2<<endl;
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
