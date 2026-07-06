//https://codeforces.com/gym/105164/problem/D
//260704
//1800
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

	int n,mod=1e9+7;
	cin >> n;

	ll ans = 1ll * n * (n - 1) * (n - 2) / 6;

	for (int z = 1; z < n - 1; z ++) {
		int x = min(z, n - z);
		ans -= 3ll * (x - 1) * x / 2;
	}

	ll c1 = n / 3, c2 = 0;
	
	for (int z = 1; z <= n; z ++) {
		int l = z / 2 + 1, r = (n - z) / 2;
		c2 += max(r - l + 1, 0);
	}

	c2 -= c1;
	ans -= c1 + 3 * c2;

	cout << (ans / 6 + c1 + c2) % mod;

    return 0;
}
