//https://codeforces.com/gym/105325/problem/D
//1500
#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define PII pair<int, int>
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3fLL
#define int long long
using namespace std;
typedef long long ll;

inline void solve()
{
    int n,mx;cin>>n;
    vector<int> a(n+1),b(1000005,0);
    ll ans=0;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        if (i==1) mx=a[i];
        else {
            if (a[i]>=a[i-1]) ans+=a[i]-a[i-1],a[i]=a[i-1];
            else {
                for (int j=mx;j>a[i];--j) b[j]=i-1;
                mx=a[i];
            }
        }
    }
    for (int j=mx;j>0;--j) b[j]=n;

    int r=n;
    for (int i=1;i<=n&&i<=b[r];++i) {
        if (a[i]>=b[i]) ans+=a[i]-b[i],a[i]=b[i];
        else {
            for (int j=r;j>a[i];--j) ans+=a[j],a[j]=0;
            r=a[i];
        }
    }

    cout<<ans<<endl;
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


// void solve() {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for (int &x : a) cin >> x;

//     ll ans = 0;
//     int end = n;
//     int r = n - 1;

//     for (int i = 1; i <= n; ++i) {
//         while (end > 0 && a[end - 1] < i) --end;
//         int need = end;

//         if (a[i - 1] > need) {
//             int v = need;
//             ans += a[i - 1] - v;
//             a[i - 1] = v;
//             for (int j = i; j < n; ++j) {
//                 if (a[j] <= v) break;
//                 ans += a[j] - v;
//                 a[j] = v;
//             }
//         } else if (a[i - 1] < need) {
//             int deficit = need - a[i - 1];
//             while (deficit > 0 && r >= i) {
//                 while (r >= i && a[r] < i) --r;
//                 if (r < i) break;
//                 int nh = i - 1;
//                 if (r > 0) nh = min(nh, a[r - 1]);
//                 if (a[r] > nh) {
//                     ans += a[r] - nh;
//                     a[r] = nh;
//                     if (nh < i) --deficit;
//                 } else if (a[r] > 0) {
//                     ans += a[r];
//                     a[r] = 0;
//                     --deficit;
//                 }
//                 --r;
//             }
//         }
//     }
//     cout << ans << '\n';
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int T;
//     cin >> T;
//     while (T--) solve();
//     return 0;
// }