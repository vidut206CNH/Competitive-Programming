/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
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

struct ss{
	int id, u,v;
};

vector<int> adj[MAXN1];
vector<ss> Q[4];

int main() {
	fast_cin();
	
	int n,q;
	cin >> n >> q;
	DSU dsu(n + 5);
	
	
	while(q--) {
		int t;
		cin >> t;
		if(t == 1) {
			int u,v;
			cin >> u >> v;
			Q[t].push_back({i, u, v});
		}
		
		if(t == 2) {
			int u,v;
			cin >> u >> v;
			Q[t].push_back({i, u, v});
		}
		
		if(t == 3) {
			int u;
			cin >> u;
			Q[t].push_back({i, u, u});
		}
	}
	int i1 = 0, i2 = 0;
	for(auto X : Q[3]) {
		int id = X.id;
		
		while(i1 < sz(Q[1]) && Q[1][i1].id <= id) {
			int u = Q[1][i1].fi;
			int v = Q[1][i1].se;
			dsu.unite(u,v);
			++i1;
		}
		
		while(i2 < sz(Q[2]) && Q[2][i2].id <= id) {
			int u = Q[2][i2].fi;
			int v = Q[2][i2].se;
		}
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}