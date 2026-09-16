//https://codeforces.com/gym/106197/problem/I
//260915
//1000
//#pragma GCC optimize("O3","unroll-loops")
#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3fLL
#define  ctz __builtin_ctz //unsigned int 最低位1的下标
#define  ctzll __builtin_ctzll // unsigned ll 最低位1的下标
#define  pcnt __builtin_popcount
#define  pcntll __builtin_popcountll
// #define int long long
using namespace std;
using ll=long long;
using ull=unsigned long long;
using ld=long double;
using i128=__int128_t;
using PII=pair<int,int>;

vector<string> s;
vector<PII> ans;

inline void solve()
{
    int n;cin>>n;
    s.resize(n),ans.resize(n);
    for (int i=0;i<n;++i) cin>>s[i];
    for (int i=0;i<n;++i) {
        int c=0,x=-1,y=-1;
        for (int j=0;j<n;++j) {
            if (s[i][j]=='V') c++;
            else x=i+1,y=j+1;
        }
        if (c==n) {
            cout<<n<<endl;
            for (int j=1;j<=n;++j) cout<<i+1<<' '<<j<<endl;
            return;
        } else ans[i]={x,y};
    }

    cout<<n<<endl;
    for (auto &[x,y] : ans) cout<<x<<' '<<y<<endl;
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
