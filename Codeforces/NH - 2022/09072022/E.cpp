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
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;

int n,q;
pii a[MAXN1];
pair<pii, int> p[MAXN1];
int st_val[4*MAXN1];
int st_id[4*MAXN1];

pii pre[MAXN1][25];
vector<int> values;


int ff(int X) {
	return lower_bound(values.begin(), values.end(), X) - values.begin() + 1;
}


void minimize(int &res, int X) {res = min(res, X); }


void comb(int id) {
	
	int val, idx = 0;
	val = 2e9;
	if(val > st_val[id << 1]) {
		val = st_val[id << 1];
		idx = st_id[id << 1];
	}
	
	if(val > st_val[id << 1|1]) {
		val = st_val[id << 1|1];
		idx = st_id[id << 1|1];
	}
	
	st_val[id] = val;
	st_id[id] = idx;
	
}

void update(int id, int l, int r, int pos, int val, int idx) {
	if(l == r) {
		
		if(st_val[id] > val) {
			st_val[id] = val;
			st_id[id] = idx;
		}
		
		return;
	}
	
	int mid = (l + r) >> 1;
	if(pos <= mid) update(id << 1, l, mid, pos, val, idx);
	if(mid + 1 <= pos) update(id << 1|1, mid + 1, r, pos, val, idx);
	
	comb(id);
	
}

void get(int id, int l, int r, int u, int v, pii &X) {
	if(u <= l && r <= v) {
		
		if(X.fi > st_val[id]) {
			X.fi = st_val[id];
			X.se = st_id[id];
		}
		
		return;
	}
	
	int mid = (l + r) >> 1;
	if(u <= mid) get(id << 1, l, mid, u, v, X);
	if(mid + 1 <= v) get(id << 1|1, mid + 1, r, u, v, X);
}

int main() {
	fast_cin();
	
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i].fi >> a[i].se;
		values.push_back(a[i].fi);
		values.push_back(a[i].se);
	}	
	
	sort(values.begin(), values.end());
	values.resize(unique(values.begin(), values.end()) - values.begin());
	
	memset(st_val, 0x3f, sizeof st_val);
	
	for(int i = 1; i <= n; ++i) {
		a[i].fi = ff(a[i].fi);
		a[i].se = ff(a[i].se);
		
		update(1, 1, sz(values), a[i].se, a[i].fi, i);
		p[i] = {a[i], i};
	}
	
	sort(p + 1, p + n + 1, [&] (const pair<pii, int> &A, const pair<pii, int> &B) {
		if(A.fi.se != B.fi.se) return A.fi.se < B.fi.se;
		return A.fi.fi < B.fi.fi;
	});
	
	for(int i = 1; i <= n; ++i) {
		for(int k = 0; k <= 20; ++k) {
			pre[i][k] = {-1, -1};
		}
	}
	
	for(int i = 1; i <= n; ++i) {
		int L = p[i].fi.fi;
		int R = p[i].fi.se;
		int id = p[i].se;
		
		pii val = {2e9, -1};
		get(1, 1, sz(values), L, R, val);
		
		if(val.se != -1 && val.se != id) pre[id][0] = val;
		for(int k = 1; k <= 20; ++k) {
			
			int v = pre[id][k - 1].se;
			
			if(v != -1) pre[id][k] = pre[v][k - 1];
		}
	}
	
	
	while(q--) {
		int u,v;
		cin >> u >> v;
		
		if(a[u].se > a[v].se) {
			cout << "impossible\n";
			continue;
		}
		
		if(u == v) {
			cout << 0 << "\n";
			continue;
		}
		
		if(a[u].se >= a[v].fi && a[u].se <= a[v].se) {
			cout << 1 << '\n';
			continue;
		}
		
		else {
			
			int node = v;
			int res = 0;
			for(int i = 20; i >= 0; --i) {
				int c = pre[node][i].fi;
				int idx = pre[node][i].se;
				if(idx != -1 && idx != node && c > a[u].se) {
					node = idx;
					res += (1 << i);
				}
				
			}
			
			node = pre[node][0].se;
			
			
			if(node != -1 && a[u].se >= a[node].fi && a[u].se <= a[node].se) cout << res + 2 << "\n";
			else cout << "impossible\n";
		}
	}

	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}