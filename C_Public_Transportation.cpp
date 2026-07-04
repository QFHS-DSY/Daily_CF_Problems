//https://codeforces.com/gym/104879/problem/C
//260704
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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    //cout<<fixed<<setprecision(15);

    int n,m;
	cin>>n>>m;

	vector<vector<int>> g(n, vector<int>(m));
	for (auto &x: g) for (auto &y: x) cin >> y;

	vector<vector<int>> cnt(n, vector<int>(m, 0));

	for (int i=0;i<n;++i) {
		map<int,int> mp;
		for (int j=m-1;j>=0;--j) {
			cnt[i][j]=mp[g[i][j]+j];
			mp[g[i][j]+j]++;
		}
	}

	ll ans=0;

	for (int j=0;j<m;++j) {
		map<int,int> mp;
		for (int i=n-1;i>=0;--i) {
			ans+=cnt[i][j]*mp[g[i][j]+i];
			mp[g[i][j]+i]++;
		}
	}

	cout<<ans;

    return 0;
}
