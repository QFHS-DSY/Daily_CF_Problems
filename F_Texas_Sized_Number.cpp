//https://codeforces.com/gym/106712/problem/F
//260918
//1400
#include <bits/stdc++.h>
#define endl '\n'
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

    string s;cin>>s;
    ll sum=0,pre=0;
    vector<ll> cnt(10,0);
    for (int i=s.size()-1;i>=0;--i) {
        sum+=s[i]-'0';
        cnt[(pre+sum)%10]++;
        pre=(pre+sum)/10%10;
    }

    sum=sum%10;
    //cout<<sum<<' '<<pre<<endl;
    for (int i=1;i<=100000;++i) {
        cnt[(sum+pre)%10]++;
        pre=(sum+pre)/10%10;
    }

    int id=-1,mx=0;
    for (int i=0;i<=9;++i) {
        //cout<<cnt[i]<<endl;
        if (cnt[i]>mx) mx=i,id=i;
    }
    cout<<id<<endl;
    return 0;
}
