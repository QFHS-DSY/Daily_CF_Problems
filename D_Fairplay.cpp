//https://codeforces.com/gym/103821/problem/D
//260706
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
using ll=long long;
using ld=long double;

inline void solve()
{
    int n;cin>>n;
    int x=int(sqrt(n+1));
    if (x*x!=n+1) cout<<-1<<endl;
    else {
        int cnt=1+(2*x-4);
        cout<<cnt<<endl;
        cout<<1<<" ";
        for (int i=4;i<2*x;++i) cout<<i<<" ";
        cout<<endl;
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
