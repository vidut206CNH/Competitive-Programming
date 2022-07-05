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
const int MAXN1 = 3e5+5;
const int MAXN2 = 1e6+5;

vector<int> adj[MAXN1];
long long k;
int n;
int down[MAXN1], up[MAXN1];
int ndown[MAXN1], nup[MAXN1];
int h[MAXN1];
int val[MAXN1];
int d[MAXN1];
int res[MAXN1];


void dfs1(int u, int par) {
	
	for(int v : adj[u]) {
		if(v == par) continue;
		h[v] = h[u] + 1;
		dfs1(v, u);
		
		int sum = (down[v] < val[v] - h[v] ? val[v] - h[v] : down[v]);
		int node;
		if(down[v] > val[v] - h[v]) node = ndown[v];
		else if(down[v] < val[v] - h[v]) node = v;
		else if(down[v] == val[v] - h[v] && v < ndown[v]) node = v;
		else node = ndown[v];
		
		if(sum > down[u]) {
			
			down[u] = sum;
			ndown[u] = node; 
		}
		
		else if(sum == down[u] && node < ndown[u]) {
			ndown[u] = node;
		}
	}
	
/*	db(u);
	db(down[u]);
	db(ndown[u]);
	cerr << "\n";*/
}

void dfs2(int u, int par) {
/*	db(u);
	db(up[u]);
	db(nup[u]);
	cerr << "\n";*/
	vector< pair<int,pii> > p;
	p.push_back({val[u] - h[u], {u, u}});
	
	for(int v : adj[u]) {
		if(v == par) continue;
		p.push_back({down[v], {v, ndown[v]}});
		p.push_back({val[v] - h[v], {v, v}});
	}
	
	sort(p.begin(), p.end(), [&](const pair<int,pii> &A, const pair<int,pii> &B) {
		if(A.fi != B.fi) return A.fi > B.fi;
		return A.se.se < B.se.se;
	});
	
	for(int v : adj[u]) {
		if(v == par) continue;
		up[v] = up[u];
		nup[v] = nup[u];
		
		if(v == p[0].se.fi) {
			
			int node = p[1].se.se;
			int sum = p[1].fi + 2*h[u];
			
			
			if(up[v] < sum) {
				if(v == 2) db(node);
				up[v] = sum;
				nup[v] = node;
			}	
			
			else if(up[v] == sum && nup[v] > node) {
				nup[v] = node;
			}
		}
		
		else {
			int node = p[0].se.se;
			int sum = p[0].fi + 2*h[u];
			
			if(up[v] < sum) {
				up[v] = sum;
				nup[v] = node;
			}
			
			else if(up[v] == sum && nup[v] > node) nup[v] = node;
		}
		
		dfs2(v, u);
	}
}

int main() {
	fast_cin();
	
	cin >> n >> k;
	++k;
	for(int i = 1; i <= n; ++i) cin >> val[i];
	
	for(int i = 2; i <= n; ++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	
	memset(down, - 60, sizeof down);
	memset(up, - 60, sizeof up);
	
	dfs1(1, -1);
	dfs2(1, -1);
	
	long long cur = 1, id = 0;
	
	memset(d, -1, sizeof d);
	
	while(id < k && d[cur] == -1) {
		++id;
		d[cur] = id;
		res[id] = cur;
		
		int val1 = up[cur];
		int val2 = down[cur] + 2*h[cur];
		int n1 = nup[cur];
		int n2 = ndown[cur];
/*		db(cur);
		db(n1);
		db(n2);
		db(val1);
		db(val2);
		cerr << "\n";*/
		
		if(n1 == cur) {
			cur = n2;
			continue;
		}
		
		if(n2 == cur) {
			cur = n1;
			continue;
		}
		
		if(val1 < val2) {
			cur = n2;	
		}
		else if(val1 > val2) {
			cur = n1;
		}
		else {
			cur = min(n1, n2);
		}
		
	}
	
	if(id < k) {
		int pos = d[cur];
		long long num = k - id - 1;
		cout << res[pos + (num%(id + 1 - pos))];
	}
	
	else cout << res[k];
	
	
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}