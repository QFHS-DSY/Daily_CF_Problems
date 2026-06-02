//https://codeforces.com/gym/105532/problem/D
//260523
//1200
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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    //cout<<fixed<<setprecision(15);

    int n,mx=0;cin>>n;
    vector<PII> a(n+1);
    for (int i=1,x,y;i<=n;++i) {
        cin>>x>>y;
        a[i].fi=max(x,y),a[i].se=min(x,y);
        mx=max(mx,a[i].fi);
    }

    int l=1,r=mx;
    while (l<r) {
        int mid=l+r+1>>1;

        auto chk=[&](int x) -> bool {
            int c=0;
            for (int i=1;i<=n;++i) {
                if (a[i].se>=x) c+=a[i].fi;
                else if (a[i].fi>=x) c+=a[i].se;

                if (c>=x) return true;
            }
            return false;
        };

        if (chk(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l<<endl;
    return 0;
}
