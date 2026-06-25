//https://codeforces.com/gym/105757/problem/B
//260611
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

vector<int> nxt_prime;

void build_primes(int n)
{
    int lim=max(3,2*n+5);
    vector<bool> is_prime(lim+1,true);
    is_prime[0]=is_prime[1]=false;
    for (ll i=2;i*i<=lim;i++)
        if (is_prime[i])
            for (ll j=i*i;j<=lim;j+=i)
                is_prime[j]=false;

    nxt_prime.assign(lim+2,0);
    int last=0;
    for (int i=lim;i>=0;i--) {
        if (is_prime[i]) last=i;
        nxt_prime[i]=last;
    }
}

inline void solve(int n)
{
    vector<pair<int,int>> pairs;
    pairs.reserve(n/2);

    int m=n;
    while (m>1) {
        int p=nxt_prime[m+1];
        int l=p-m;
        for (int x=l;x<=p/2;x++)
            pairs.push_back({x,p-x});
        m=l-1;
    }

    vector<int> ans(n);
    for (int i=0;i<(int)pairs.size();i++) {
        ans[i]=pairs[i].first;
        ans[n-i-1]=pairs[i].second;
    }
    if (n&1) ans[n/2]=1;

    for (int i=0;i<n;i++)
        cout<<ans[i]<<" \n"[i==n-1];
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    //cout<<fixed<<setprecision(15);

    int T;
    cin>>T;
    vector<int> ns(T);
    int mx=1;
    for (int &n:ns) {
        cin>>n;
        mx=max(mx,n);
    }

    build_primes(mx);
    for (int n:ns)
        solve(n);

    return 0;
}
