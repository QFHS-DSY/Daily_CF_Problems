//https://codeforces.com/gym/105873/problem/G
//1900
#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second 
#define PII pair<int,int> 
#define INF 0x3f3f3f3f
#define LNF 0x3f3f3f3f3f3f3f3f
//#define int long long
using ll=long long;
using namespace std;

inline void solve()
{
    int n,cn,a;cin>>n>>a;cn=n;
    vector<PII> ans;
    if (n%2==0) {
        n-=2;n/=2;
        if (a<n) {cout<<"No"<<endl; return;}
        else {
            cout<<"Yes"<<endl;
            ans.emplace_back(0,0);
            ans.emplace_back(1,0);
            int f=1,h=1;
            while (n>1) {
                if (f) {
                    ans.emplace_back(1,h);
                    ans.emplace_back(2,h);
                } else {
                    ans.emplace_back(0,h);
                    ans.emplace_back(1,h);
                }
                h++,n--,a--,f=1-f;
            }
            if (f) {
                ans.emplace_back(1,h+a-1);
                ans.emplace_back(2,h+a-1);
            } else {
                ans.emplace_back(0,h+a-1);
                ans.emplace_back(1,h+a-1);
            }
        }
    } else {
        n-=1;n/=2;
        if (a<n) {cout<<"No"<<endl; return;}
        else {
            cout<<"Yes"<<endl;
            ans.emplace_back(0,0);
            ans.emplace_back(1,0);
            int f=1,h=1;
            while (n>1) {
                if (f) {
                    ans.emplace_back(1,h);
                    ans.emplace_back(2,h);
                } else {
                    ans.emplace_back(0,h);
                    ans.emplace_back(1,h);
                }
                    h++,n--,a--,f=1-f;
            }
            if (f) ans.emplace_back(1,h-1+2*a);
            else ans.emplace_back(0,h-1+2*a);
        }
    }

    for (int i=0;i<cn;++i) 
        if (i%2==0) cout<<ans[i].fi<<" "<<ans[i].se<<endl;
    for (int i=cn-1;i;--i) 
        if (i&1) cout<<ans[i].fi<<" "<<ans[i].se<<endl;
    
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin>>T;
    while (T--) solve();

    return 0;
}