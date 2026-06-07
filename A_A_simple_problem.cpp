//https://codeforces.com/gym/106540/problem/A
//260522
//1700
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

const int MOD=998244353;

vector<int> prep(const string &s) {
	int n=s.size();
	vector<int> pi(n);
	for (int i=1;i<n;++i) {
		int j=pi[i-1];
		while (j>0 && s[i]!=s[j])
			j=pi[j-1];
		if (s[i]==s[j]) j++;
		pi[i]=j;
	}
	return pi;
}

inline void solve()
{
	int n, k;
	string s;
	cin>>n>>k>>s;

	auto kmp=prep(s);

	vector<int> dp(k+1,0);
	dp[0]=1;

	for (int i=0;i<k;i++) {
		for (int j=0;j<n;++j) {
			if (!kmp[j] && i+j+1<=k) {
				dp[i+j+1]=(dp[i+j+1]+dp[i])%MOD;
			}
		}
	}

	cout<<dp[k]<<endl;
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
