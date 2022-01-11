/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define gcd(a,b) (__gcd(a,b))
#define lcm(a,b) (a/gcd(a,b)*b)
#define sz(x) (int)(x.size())
#define fast_cin() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define db(x) cerr << "[" << "Line " << __LINE__ << " : " << (#x) << " = " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;


int t,n,k;
vector<int> dist(2*MAXN1);
int g[2*MAXN1];


signed main() {
	fast_cin();
	
	cin >> t;
	
	while(t--) {
		cin >> n >> k;
		dist.assign(n+1, inf);
		vector<int> p[n+1];
		for(int i=1;i<n;++i) {
			int u,v;
			cin >> u >> v;
			p[u].push_back(v);
			p[v].push_back(u);
		}
		
		queue<int> q;
		
		for(int i=1;i<=n;++i) {
			g[i] = sz(p[i]);
			if(g[i] == 1) {
				dist[i] = 1;
				q.push(i);
			}
		}
		int ans = 0;
		while(!q.empty()) {
			int cur = q.front();
			q.pop();
			for(auto x : p[cur]) {
				if(g[x] <= 1) continue;
				--g[x];
				if(g[x] == 1) {
					dist[x] = dist[cur] + 1;
					q.push(x);
				}
			}
		}
		if(n==1) {
			cout << "0\n";
			continue;
		}
		for(int i=1;i<=n;++i) ans += (dist[i] > k);
		cout << ans << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}