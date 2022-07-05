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

int n,q;
int h[MAXN2];
int p[MAXN2];
int subsz[MAXN2];
vector<int> adj[MAXN2];

void dfs(int u) {
	subsz[u] = 1;	
	for(int v : adj[u]) {
		if(v == p[u]) continue;
		p[v] = u;
		h[v] = h[u] + 1;
		dfs(v);
		subsz[u] += subsz[v];
	}
	
}



void solve(int u, int v) {
	if(h[u] < h[v]) swap(u, v);
	

	
	vector<long long> L, R;
	int su = -1, sv = -1;
	while(h[u] > h[v]) {
		L.emplace_back(subsz[u] - (su == -1 ? 0 : subsz[su]));
		su = u;
		u = p[u];
	}
	
	while(u != v) {
		L.emplace_back(subsz[u] - (su == -1 ? 0 : subsz[su]));
		R.emplace_back(subsz[v] - (sv == -1 ? 0 : subsz[sv]));
		su = u;
		sv = v;
		u = p[u];
		v = p[v];
	}
	L.emplace_back(n - subsz[u] + subsz[u] - (su == -1 ? 0 : subsz[su]) - (sv == -1 ? 0 : subsz[sv]));
	
	
	reverse(R.begin(), R.end());
	L.insert(L.end(), R.begin(), R.end());
/*	for(auto x : L) db(x);
	cerr << "\n";*/
	vector<long long> sufix(sz(L) + 5);
	
	for(int i = sz(L) - 1; i >= 0; --i) {
		sufix[i] = sufix[i + 1] + L[i];
	}
	
	int j = (sz(L) + 1)/2 + (sz(L)%2 == 0);
	long long sum = 0;
	for(int i = 0; i < sz(L); ++i) {
		if(j >= sz(L)) break;
		sum += 1LL*L[i]*sufix[j];
		++j;
	}
	
	cout << sum << "\n";

}

int main() {
	fast_cin();
	
	cin >> n >> q;
	for(int i = 2; i <= n; ++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(1);	
	
	for(int i = 1; i <= q; ++i) {
		int x,y;
		cin >> x >> y;
		solve(x,y);
	}
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}