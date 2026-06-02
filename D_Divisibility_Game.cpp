//https://codeforces.com/gym/105010/problem/D
//260530
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
typedef long long ll;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    //cout<<fixed<<setprecision(15);
    
    int n,k,c=0;cin>>n>>k;
    for (int i=1,x;i<=n;++i) {
        cin>>x;
        if (x%k!=0) c++;
    }

	if (c==0) cout<<"Rami"<<endl;
	else if (c==2) cout<<"Oussama"<<endl;
	else cout<<((n&1) ? "Rami" : "Oussama")<<endl;
    
    return 0;
}
