//https://codeforces.com/gym/106531/problem/H
//260519
//1700
#include <bits/stdc++.h>
#define endl "\n"
#define fi first
#define se second
#define PII pair<int, int>
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3fLL
// #define int long long
using namespace std;
typedef long long ll;

constexpr int MAXN=200005;
int n,m,k,deg[MAXN],cnt=0,ans;
vector<int> g[MAXN];
set<int> f[MAXN];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin>>n>>m;
    for (int j=1,x,y;j<=m;++j) {
        cin>>x>>y;
        deg[y]++;
        g[x].push_back(y);
    }
    cin>>k;
    for (int i=1,x,j;i<=k;++i) {
        cin>>j>>x;
        f[x].insert(j);
    }

    queue<int> q,cq;
    for (int i=1;i<=n;++i) 
        if (!deg[i]) q.push(i);
    
    ans=1;
    while (!q.empty() || !cq.empty()) {
        if (q.empty()) {q=cq;while(!cq.empty()) cq.pop(); ans++;}
        int x=q.front();q.pop();
        if (f[x].find(ans)!=f[x].end()) cq.push(x);
        else {
            //cout<<x<<" "<<ans<<endl;
            cnt++;
            for (int y : g[x]) {
                deg[y]--;
                if (!deg[y]) cq.push(y);
            }
        }
    }
    if (cnt!=n) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}