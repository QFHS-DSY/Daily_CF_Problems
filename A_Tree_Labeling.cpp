//https://codeforces.com/gym/106020/problem/A
//260629
//2100
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

inline void solve()
{
    int n;
    cin>>n;

    vector<vector<int>> g(n+1);
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> color(n+1,-1), mask(n+1,7);
    auto assign_color=[&](int st,int c)
    {
        vector<int> stk;
        mask[st]=1<<c;
        stk.push_back(st);
        while(!stk.empty())
        {
            int u=stk.back();
            stk.pop_back();

            if(color[u]!=-1)
                continue;

            int cu=__builtin_ctz(mask[u]);
            color[u]=cu;
            for(int v:g[u])
            {
                if(color[v]!=-1)
                    continue;

                if(mask[v]&(1<<cu))
                {
                    mask[v]^=(1<<cu);
                    if(__builtin_popcount(mask[v])==1)
                        stk.push_back(v);
                }
            }
        }
    };

    for(int i=1;i<=n;i++)
    {
        if(color[i]==-1)
        {
            int c=__builtin_ctz(mask[i]);
            assign_color(i,c);
        }
    }

    string ans(n,'a');
    for(int i=1;i<=n;i++)
        ans[i-1]=char('a'+color[i]);
    cout<<ans<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    //cout<<fixed<<setprecision(15);

    solve();

    return 0;
}
