//https://codeforces.com/gym/106677/problem/D
//260831
//1600
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
#define int long long
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

    int s,k;
    while (cin>>s>>k) {
        if (s==0 && k==0) break;
        k --;

		if (s * s <= k) {
			k -= s * s;

			int x = k / (2 * s), y = k % (2 * s);

			if (y % 2 == 0) {
				y /= 2;
				cout << (y ? y : s) << '\n';
			}
			else cout << s + 1 + x << '\n';
		}
		else {
			long long l = 0, r = s;

			while (l <= r) {
				long long mid = (l + r) / 2;

				long long x = 2 * s - 1, y = x - 2 * (mid - 1);

				if ((x + y) * mid / 2 > k) r = mid - 1;
				else l = mid + 1;
			}

            long long x = 2 * s - 1, y = x - 2 * (r - 1);
            k -= (x + y) * r / 2;

            if (!k) cout << s << '\n';
            else {
                int x = (k - 1) / 2, y = (k - 1) % 2;

                if (!y) cout << r + 1 + x << '\n';
                else cout << r + 1 << '\n';
            }
		}
    }

    return 0;
}

/*
6

2
2
3
2
4
2
5
2
6
3
3
4
3
5
3
6
4
4
5
4
6
5
5
6

5 4 3 

2 2 2
2 2 2
3 3 3
2 2
4 4
2 3
5 3
3 4
3
4
3
5
4
4
5
*/
