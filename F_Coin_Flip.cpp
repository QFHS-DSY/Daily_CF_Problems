//https://codeforces.com/gym/106020/problem/F
//260630
//1600
#include <bits/stdc++.h>
#define fi first
#define se second
#define PII pair<int, int>
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3fLL
//#define int long long
using namespace std;
using ll=long long;
using ld=long double;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    //cout<<fixed<<setprecision(15);

    int n,k,x;cin>>n>>k;
    vector<PII> even,odd;
    for (int i=1;i<=n;++i) {
        cin>>x;
        if (i&1) odd.push_back({x,i});
        else even.push_back({x,i});
    }
    sort(odd.begin(),odd.end(),[](PII a,PII b){return a.fi>b.fi;});
    sort(even.begin(),even.end(),[](PII a,PII b){return a.fi>b.fi;});
    
    int a=0,b=0;
    while (k--) {
        cin>>x;
        if (x==1) {
            //cerr<<odd[a].fi<<" "<<even[b+k].fi<<endl;
            if (odd[a].fi>=even[b+k].fi) {
                cout<<odd[a].se<<endl;
                a++;
            } else {
                cout<<even[b].se<<endl;
                b++;
            }
        } else {
            cout<<even[b].se<<endl;
            b++;
        }

        cin>>x;
        if (x==0) return 0;
    }

    return 0;
}
