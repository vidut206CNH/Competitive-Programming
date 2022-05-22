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


struct DSU{
	
	vector<int> e;
	
	DSU(int n) { e = vector<int>(n, -1); }
	
	
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
	
	
	int same_set(int x, int  y) {
		return get(x) == get(y);
	}
	
	int size_set(int x) {return -e[get(x)]; }
	
	
	bool unite(int x, int y) {
		x = get(x);
		y = get(y);
		
		if(x == y) return false;
		
		if(e[x] > e[y]) swap(x, y);
		
		e[x] += e[y];
		e[y] = x;
		
		return true;
	}
	
};

vector<int> E[1005];
int n,m;

signed main() {
	fast_cin();
	
	
	cin >> n >> m;
	int res = n;
	
	DSU dsu(n + 1);
	for(int i = 1; i <= m; ++i) {
		char c;
		int x,y;
		cin >> c >> x >> y;
		if(c == 'F') {
			res -= dsu.unite(x, y);
		}
		
		else {
			E[x].push_back(y);
			E[y].push_back(x);
		}
	}
	
	for(int u = 1; u <= n; ++u) {
		for(auto v : E[u]) {
			for(auto k : E[v]) {
				res -= dsu.unite(u, k);
			}
		}
	}
	
	cout << res;

	
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}