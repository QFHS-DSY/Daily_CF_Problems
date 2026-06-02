//https://codeforces.com/gym/106531/problem/E
//260519
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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    //cout<<fixed<<setprecision(15);

    ll ax,ay,bx,by,m,kk,l=INT_MIN,r=INT_MAX,ans,f;
    cin>>ax>>ay>>bx>>by>>m;
    if ((ax>=bx && ay>=by) || (ax<=bx && ay<=by)) kk=ay-ax,f=1;
    else kk=ay+ax,f=2;
    for (ll i=1,k,d;i<=m;++i) {
        cin>>k>>d;
        if (d==f) {
            if (k==kk) r=k,l=k;
            if (k>kk) r=min(r,k);
            else l=max(l,k);
        }
    }

    ans=abs(ax-bx)+abs(ay-by);
    if (l!=INT_MIN) {
        ll tmp=kk-l,t;
        if (f==1) {
            if (ax<=bx) {

            } else tmp+=ax-bx;
        } else {
            if (ax<=bx) tmp+=bx-ax;
            else tmp+=by-ay;
        }
        ans=min(ans,tmp);
    }
    if (r!=INT_MAX) {
        ll tmp=r-kk;
        if (f==1) {
            if (ax<=bx) tmp+=bx-ax;
            else tmp+=ay-by;
        } else {
            if (ax<=bx) tmp+=ay-by;
            else tmp+=ax-bx;
        }
        ans=min(ans,tmp);
    }

    cout<<ans<<endl;

    return 0;
}
