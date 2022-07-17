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
const int MAXN1 = 3e3+5;
const int MAXN2 = 1e6+5;

int n,k,q;
int a[MAXN1];
vector<pii> adj[MAXN1];
bool bad = false;
int best[MAXN1];
int color[MAXN1];
int last, L;

void dfs(int u) {
	if(bad) return;
	color[u] = 1;
	
	for(auto x : adj[u]) {
		int id = x.se;
		if((id <= L) || id > last) continue;
		int v = x.fi;
		
		if(color[v] == 1) {
			bad = true;
			return;
		}
		
		else if(color[v] == 0) {
			dfs(v);
		}
		
	}
	
	color[u] = 2;
}



bool check() {
	
	
	bad = false;
	memset(color, 0, sizeof color);
	
	for(int i = 1; i <= n; ++i) {
		if(color[i] == 0) dfs(i);
		if(bad) break;
	}
	
	return (!bad);
}


int main() {
	fast_cin();
	
	cin >> n >> k >> q;
	for(int i = 1; i <= n; ++i) cin >> a[i];	
	for(int i = 1; i < n; ++i) {
		if(i&1) adj[a[i]].push_back({a[i + 1], i + 1});
		else adj[a[i + 1]].push_back({a[i], i + 1});
	}
	last = L = n;
	for(; L >= 1; --L) {
		while(!check()) {
			--last;
		}
		best[L] = last;
	}
	
	for(int i = 1; i <= q; ++i) {
		int l,r;
		cin >> l >> r;
		cout << (best[l] >= r ? "YES\n" : "NO\n");
	}
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}