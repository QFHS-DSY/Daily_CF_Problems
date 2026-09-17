//https://codeforces.com/gym/106706/problem/D
//260916
//1600
#include <bits/stdc++.h>
// #define endl '\n'
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3fLL
#define ctz __builtin_ctz //unsigned int 最低位1的下标
#define ctzll __builtin_ctzll // unsigned ll 最低位1的下标
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
// #define int long long
using namespace std;
using PII=pair<int,int>;
using ll=long long;
using ld=long double;
using ull=unsigned long long;
using i128=__int128_t;
using u128=__uint128_t;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    //cout<<fixed<<setprecision(15);

    int n,t,id,c;cin>>n;
    vector<int> a(n+1,0); //1T,2F,3M
    map<int,int> mp;

    cout<<"? "<<n;
    for (int i=1;i<=n;++i) cout<<' '<<i;
    cout<<endl;
    cin>>c;

    for (int i=1;i<=n;++i) {
        cout<<"? "<<n-1;
        for (int j=1;j<=n;++j) if (j!=i) cout<<' '<<j;
        cout<<endl;
        cin>>t;
        if (t==c) a[i]=2,id=i,mp[i]=2;
        else a[i]=1;
    }

    for (int i=1;i<=n;++i) {
        if (i==id) continue;
        cout<<"? "<<2<<' '<<i<<' '<<id<<endl;
        cin>>t;
        if (t==0 && !mp[i]) a[i]=3;
    }

    cout<<"! ";
    for (int i=1;i<=n;++i) {
        if (a[i]==1) cout<<'T';
        else if (a[i]==2) cout<<'F';
        else cout<<'M';
    }
    cout<<endl;
    return 0;
}
