//https://codeforces.com/gym/103150/problem/D
//260603
//1700
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
    int n,d;cin>>n>>d;
    if (d>(n/2)*(n/2)*2) {cout<<"NO"<<endl; return;}

    cout<<"YES"<<endl;
    int c=n/2;
    for (int i=1;i<=c;++i) {
        for (int j=1;j<=c*2;++j) {
            if (j>c) {
                cout<<i<<' '<<j<<' '<<i+c<<' '<<j-c<<endl;
                cout<<i+c<<' '<<j-c<<' '<<i<<' '<<j<<endl;
            } else {
                cout<<i<<' '<<j<<' '<<i+c<<' '<<j+c<<endl;
                cout<<i+c<<' '<<j+c<<' '<<i<<' '<<j<<endl;
            }
        }
    }

    if (n&1) {
        for (int i=1;i<=n;++i)
		    cout<<i<<' '<<n<<' '<<n<<' '<<n+1-i<<endl;
        for (int i=1;i<n;++i)
		    cout<<n<<' '<<i<<' '<<n-i<<' '<<n<<endl;
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
