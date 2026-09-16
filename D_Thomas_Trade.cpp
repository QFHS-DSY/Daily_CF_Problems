//https://codeforces.com/gym/106197/problem/D
//260914
//1100
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
#define int long long
using namespace std;
using ll=long long;
using ull=unsigned long long;
using ld=long double;
using i128=__int128_t;
using PII=pair<int,int>;

string calc(int x) {
    string s;
    while (x) s+=(x&1 ? '1' : '0'),x>>=1;
    return s;
}

inline void solve()
{
    int n,k,sum=0;cin>>n>>k;
    string s,ans;cin>>s;
    
    for (int i=0;i<n;++i) {
        if (s[i]=='+') sum+=(1ll<<i),ans+='#';
        else ans+='.';
    }
    //cout<<ans<<endl;

    if (k>sum) {cout<<-1<<endl; return;}
    int diff=sum-k,i=0;
    string ss=calc(diff);
    for (int i=0;i<ss.size();++i) {
        if (ss[i]=='0') continue;
        if (ans[i]=='#') ans[i]='.';
        else ans[i]='#';
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
