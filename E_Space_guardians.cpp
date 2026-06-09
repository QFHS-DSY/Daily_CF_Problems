//https://codeforces.com/gym/102416/problem/E
//260609
//1600
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

struct e {
    int x,y,z,r,id;
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    //cout<<fixed<<setprecision(15);

    int n;cin>>n;
    vector<e> g(n);
    for (int i=0;i<n;++i) {
        cin>>g[i].x>>g[i].y>>g[i].z>>g[i].r;
        g[i].id=i+1;
    }

    return 0;
}
