//https://codeforces.com/gym/106682/problem/C
//260903
//1500
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

    int n,s=0;cin>>n;
    vector<int> a(n+1,0),b(n+1,0);
    for (int i=1;i<=n;++i) cin>>a[i];
    for (int i=1;i<=n;++i) cin>>b[i];

    int w1=a[n],w2=b[n];
    for (int i = n - 1; i >= 0; i --) {
		int nw1 = max(w1, min(a[i], w2)), nw2 = min(w2, max(b[i], w1));
		w1 = nw1, w2 = nw2;
	}

	cout << w1;
    return 0;
}
