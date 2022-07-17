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
const int MAXN1 = 1005;
const int MAXN2 = 1e6+5;

int m,n,q;
long long sum[MAXN1][4*MAXN1];
long long lazy[MAXN1][4*MAXN1];


void pushdown(int row, int id, int l, int r) {
	
	sum[row][id] += lazy[row][id]*(r - l + 1);
	
	if(l != r) {
		lazy[row][id << 1] += lazy[row][id];
		lazy[row][id << 1|1] += lazy[row][id];	
	}
	
	lazy[row][id] = 0;
	
}

void update(int row, int id, int l, int r, int u, int v, int val) {
	
	if(u <= l && r <= v) {
		lazy[row][id] += val;
		pushdown(row, id, l, r);
		return;
	}
	
	int mid = (l + r) >> 1;
	
	if(u <= mid) update(row, id << 1, l, mid, u, v, val);
	if(mid + 1 <= v) update(row, id << 1|1, mid + 1, r, u, v, val);
	
	pushdown(row, id << 1, l, mid);
	pushdown(row, id << 1|1, mid + 1, r);
	
	sum[row][id] = sum[row][id << 1] + sum[row][id << 1|1];
	
}


long long get(int row, int id, int l, int r, int u, int v) {
	
	pushdown(row, id, l, r);
	
	if(u <= l && r <= v) {
		return sum[row][id];
	}
	
	int mid = (l + r) >> 1;
	
	long long res = 0;
	if(u <= mid) res += get(row, id << 1, l, mid, u, v);
	if(mid + 1 <= v) res += get(row, id << 1|1, mid + 1, r, u, v);
	
	return res;
}


int main() {
	fast_cin();
	
	cin >> m >> n >> q;
	
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			update(i, 1, 1, n, j, j, 1);
		}
	}
	
	while(q--) {
		int type;
		cin >> type;
		if(type == 1) {
			int x,y,u,v,c;
			cin >> x >> y >> u >> v >> c;
			
			for(int r = x; r <= u; ++r) {
				update(r, 1, 1, n, y, v, c);
			}
			
		}
		
		else{
			int x,y,u,v;
			cin >> x >> y >> u >> v;
			long long res = 0;
			for(int r = x; r <= u; ++r) {
				res += get(r, 1, 1, n, y, v);
			}
			
			cout << res << "\n";
		}
	}
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}