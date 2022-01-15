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
const int MAXN1 = 105;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int alpha;
int n,q,t;
vector<int> E[MAXN1];
bool d[MAXN1];
pii p[MAXN2];
bool f[MAXN2][MAXN1];


void dfs(int cur, int par, const int& des) {
	if(cur == des) {
		d[cur] = 1;
		return;
	}
	for(auto x : E[cur]) {
		if(x == par) continue;
		dfs(x, cur ,des);
		d[cur] |= d[x]; 
	}
}


void sub1() {
	cin >> t;
	
	while(t--) {
		cin >> q;
		for(int i=1;i<=q;++i) {
			cin >> p[i].fi >> p[i].se;
		}
		
		for(int i=1;i<=q;++i) {			
			memset(d, 0, sizeof d);
			
			dfs(p[i].fi, 0, p[i].se);
			
			for(int k=1;k<=n;++k) {
				f[i][k] = d[k];
				if(!d[k]) continue;
/*				db(i);
				db(k);
				cerr << "\n";*/
			}
			//cerr << "\n\n";
			
		}
		bool found = 0;
		for(int i=1;i<=q;++i) {
			for(int j=i+1;j<=q;++j) {
				int ci=0,cj=0,g=0;
				
				for(int k=1;k<=n;++k) {
					ci += (f[i][k]);
					cj += (f[j][k]);
					g += (f[i][k] && f[j][k]);
				}
				
/*				db(g);
				db(ci);
				db(cj);
				cerr << "\n";*/
				if(g != 0 && g != ci && g != cj) {
					found = true;
					break;
				}
			}
			if(found) break;
		}
		
		cout <<  (found ? "MAP MO\n" : "RO RANG\n");
	}
}




/*void dfs(int cur, int par) {
	d[cur] = d[par] + 1;
	for(auto x : E[v]) {
		if(x == par) continue;
		dfs(x, cur);
	}
}

void sub4() {
	dfs(1,1);
	cin >> t;
	while(cin >> q) {
		for(int i=1;i<=q;++i) {
			int u,v;
			cin >> u >> v;
			u = d[u];
			v = d[v];
			if(u > v) swap(u,v);
		}
	}
}*/


signed main() {
	fast_cin();
	cin >> alpha;
	cin >> n;
	for(int i=1;i<n;++i) {
		int u,v;
		cin >> u >> v;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	sub1();
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}