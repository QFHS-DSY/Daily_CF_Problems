//https://codeforces.com/gym/106020/problem/H
//260625
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
using ll=long long;
using ld=long double;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    //cout<<fixed<<setprecision(15);

    int n;cin>>n;
    vector<int> a(n);
    for (int i=0;i<n;++i) cin>>a[i];

	vector<int> idxs;
	for (int i = 0; i < n; i ++) if (a[i]) idxs.emplace_back(i);

	long long ans = 0;
	for (int i = 1; i < idxs.size(); i ++) {
		int x = idxs[i - 1], y = idxs[i];
		if (min(a[x], a[y]) == 1 && max(a[x], a[y]) <= 2) {
			int lx = (i >= 2 ? idxs[i - 2] : -1);
			int ry = (i + 1 < idxs.size() ? idxs[i + 1] : n);

			ans += 1ll * (x - lx) * (ry - y);
			if (y - x == 1) ans --;
		}
	}

	cout << ans;
    return 0;
}
