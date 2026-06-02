//https://codeforces.com/gym/105437/problem/H
//260525
//1400
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

    int n;string s;cin>>n>>s;
    vector<int> a(n);
    ll ans=0;
    int l=0,r=0,cnt=1;
    for (int i=1;i<n;++i) {
        if (s[i]!=s[i-1]) {
            for (int j=l;j<=r;++j) a[j]=cnt;
            l=i,r=i;
            ans+=cnt*cnt;
            cnt=1;
        } else cnt++,r++;
    }
    for (int j=l;j<=r;++j) a[j]=cnt;
    ans+=cnt*cnt;

    ll x=0;
    for (int i=1;i<n;++i) {
        if (s[i]!=s[i-1]) {
            ll c=a[i-1]*a[i-1]+a[i]*a[i],d=0;
            if (i>1 && s[i]==s[i-2]) {
                d+=2*a[i-2]+1;
            }  else d+=1+(a[i-1]-1)*(a[i-1]-1);
            if (i<n-1 && s[i-1]==s[i+1]) {
                d+=2*a[i+1]+1;
            } else d+=1+(a[i]-1)*(a[i]-1);

            x=max(x,ans-c+d);
        }
    }
    cout<<x<<endl;
    return 0;
}
