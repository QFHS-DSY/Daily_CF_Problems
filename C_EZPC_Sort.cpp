//https://codeforces.com/gym/103150/problem/C
//260603
//1300
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
    string s;cin>>s;
    int p=0,c=0;
    for (char x : s) {
        if (x=='p') p=1;
        else if (x=='c') c=1;
        if ((c && x=='e') || (c && x=='z') || (c && x=='p')) {cout<<"NO"<<endl; return;}
        else if (p && x=='z') {cout<<"NO"<<endl; return;}
    }
    cout<<"YES"<<endl;
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
