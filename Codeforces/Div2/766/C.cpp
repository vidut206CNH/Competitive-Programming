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
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int t;


signed main() {
	fast_cin();
	
	
	cin >> t;
	
	
	while(t--) {
		int n;
		cin >> n;
		vector<pii > p(n + 1);
		vector<int> f(n + 5);
		vector<int> res(n + 1);
		
		for(int i=1;i<n;++i) {
			int u,v;
			cin >> u >> v;
			f[u]++;
			f[v]++;
			p[i] = {u,v};
		}
		
		if(n > 4) {
			cout << "-1\n";
			continue;
		}
		
		if(n==2) {
			cout << "2\n";
			continue;
		}
		if(n==3) {
			cout << "2 3\n";
			continue;
		}
		
		bool bad = 0;
		pii node;
		
		for(int i=1;i<=n;++i) {
			bad |= (f[i] > 2);
			if(f[i] == 2) {
				if(node.fi == 0) node.fi = i;
				else node.se = i;
			}
		}
		if(bad) {
			cout << "-1\n";
			continue;
		}
		vector<int> prime = {3,5};
		int id = -1;
		for(int i=1;i<n;++i) {
			if(p[i].fi == node.fi && p[i].se == node.se) {
				res[i] = 2;
			}
			else if(p[i].fi == node.se && p[i].se == node.fi) {
				res[i] = 2;
			}
			else res[i] = prime[++id];
		}
		for(int i=1;i<n;++i) cout << res[i] << " ";
		cout << "\n";
		
		
	}	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}