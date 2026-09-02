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
// #define int long long
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

    // int s,k;
    // while (cin>>s>>k) {
    //     if (s==0 && k==0) break;
    //     if (s==1) {
    //         if (k==1) cout<<1<<endl;
    //         else cout<<(k&1 ? k/2+1 : 1)<<endl;
    //     } else if (k<=2*s) {
    //         if (k==1) cout<<s<<endl;
    //         else if (k==2) cout<<1<<endl;
    //         else cout<<(k&1 ? 1 : k/2)<<endl;
    //     } else if (k==2*s+1) cout<<2<<endl;
    //     else if (k-2*s-1<=2*(s-2)) {
    //         int x=k-2*s-1;
    //         cout<<(x&1 ? 2 : x/2+2)<<endl;
    //     }
    // }

    int a[105];
    a[1]=2;
    cout<<a[1]<<endl;
    for (int i=2;i<=100;++i) {
        int x=a[i-1],c=0;
        for (int j=1;j<i;++j) {
            if (x==a[j]) c++;
        }
        a[i]=c;
        cout<<a[i]<<endl;
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
