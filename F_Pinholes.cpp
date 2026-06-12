//https://codeforces.com/gym/104755/problem/F
//260610
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
using ll=long long;
using ld=long double;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    //cout<<fixed<<setprecision(15);

    // int n,m;cin>>n>>m;
    // vector<int> a(n),b(m);
    // set<int> ans;
    // for (auto &x : a) cin>>x;
    // for (auto &x : b) cin>>x;

    // sort(a.begin(),a.end());
    // sort(b.begin(),b.end());

    // for (int x : a) 
    //     for (int y: b) 
    //         ans.insert(2*x-y);

    // map<int,int> mp;
    // int cn=ans.size();
    // for (int x : ans) {
    //     mp[x]=1;
    //     for (int y : a) {
    //         if (find(b.begin(),b.end(),2*y-x)==b.end()) {
    //             mp[x]=0;
    //             cn--;
    //             break;
    //         }
    //     }
    // }

    // if (cn==0) cout<<"No"<<endl;
    // else {
    //     cout<<"Yes"<<endl;
    //     cout<<cn<<endl;
    //     for (int x : ans) if (mp[x]) cout<<x<<" ";
    //     cout<<endl;
    // }


	int n, m;
	cin >> n >> m;

	vector<int> holes(n), targets(m);

	for (auto &x: holes) cin >> x;
	for (auto &x: targets) cin >> x;

	sort(holes.begin(), holes.end());
	sort(targets.begin(), targets.end());

	vector<int> ans, vis(m, 0);

	for (auto &v: targets) {
		int pt = 0;
		bool flg = true;

		for (auto &x: holes) {
			while (pt < m && targets[pt] < v + 2 * (x - holes[0])) pt ++;
			if (pt == m || targets[pt] != v + 2 * (x - holes[0])) flg = false;
		}

		if (flg) {
			ans.emplace_back(2 * holes[0] - v);
			pt = 0;

			for (auto &x: holes) {
				while (pt < m && targets[pt] < v + 2 * (x - holes[0])) pt ++;
				vis[pt] = 1;
			}
		}
	}

	if (*min_element(vis.begin(), vis.end())) {
		cout << "Yes\n";
		cout << ans.size() << '\n';
		for (int i = 0; i < ans.size(); i ++)
			cout << ans[i] << " \n"[i + 1 == ans.size()];
	}
	else cout << "No\n";


    return 0;
}
