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


struct Edge{
	int u, v, c;
};

struct DSU{
	vector<int> e;
	
	DSU(int n) {e = vector<int> (n, -1); }
	
	int get(int x) {
		return (e[x] < 0 ? x : e[x] = get(e[x]));
	}
	
	
	bool same_set(int a, int b) {
		return get(a) == get(b);
	}
	
	int size_set(int x) {
		return -e[get(x)];
	}
	
	bool unite(int a, int b) {
		a = get(a);
		b = get(b);
		if(a == b) return false;
		if(e[a] > e[b]) swap(a, b);
		e[a] += e[b];
		e[b] = a;
		return true;
	}
	
};

int n,m;
vector<Edge> E;

signed main() {
	fast_cin();
	
	cin >> n >> m;
	for(int i = 1; i <= m; ++i) {
		int u,v,c;
		cin >> u >> v >> c;
		E.push_back({u, v, c});
	}
	
	sort(E.begin(), E.end(), [] (Edge& X, Edge& Y) {
		return X.c < Y.c;
	});
	
	int res = 0;
	
	
	// MST
	
	DSU dsu(n + 1);
	for(auto e : E) {
		int u = e.u;
		int v = e.v;
		int c = e.c;
		
		if(!dsu.unite(u, v)) continue;
		res = max(res, c);
	}
	
	cout << res;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}