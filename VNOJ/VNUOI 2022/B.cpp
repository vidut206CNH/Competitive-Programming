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
const int MAXN1 = 3e6+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;


int n,q;
int q_type;
int l_start, l_mul, l_add;
int r_start, r_mul, r_add;
int delta_start, delta_mul, delta_add, delta_max;

int segsum[4*MAXN1];
int segsquare[4*MAXN1];
int lazy[3*MAXN1];


void pushdown(int node, int l, int r) {
	segsquare[node] = (segsquare[node] + 2*segsum[node]%MOD*lazy[node]%MOD + (r - l + 1)*lazy[node]%MOD*lazy[node]%MOD)%MOD;
	segsum[node] = (segsum[node] + (r - l + 1)*lazy[node])%MOD;
	
	if(l != r) {
		lazy[node << 1] = (lazy[node << 1] + lazy[node])%MOD;
		lazy[node << 1|1] = (lazy[node << 1|1] + lazy[node])%MOD;
	}
	
	lazy[node] = 0;
}


void update(int node, int l, int r, int u, int v,const int& val) {
	pushdown(node, l, r);
	if(r < u || v < l) return;
	if(u <= l && r <= v) {
		lazy[node] = (lazy[node] + val)%MOD;
		pushdown(node, l, r);
		return;
	}
	
	int mid = (l+r) >> 1;
	update(node << 1, l, mid, u, v, val);
	update(node << 1|1, mid + 1, r, u, v, val);
	segsum[node] = segsum[node << 1] + segsum[node << 1|1];
	segsquare[node] = segsquare[node << 1] + segsquare[node << 1|1];
}


int get(bool type, int node, int l, int r, int u, int v) {
	pushdown(node, l, r);
	if(u <= l && r <= v) {
		if(!type) return segsum[node];
		else return segsquare[node]; 
	}
	int mid = (l+r) >> 1;
	int ans = 0;
	if(u <= mid) ans = (ans + get(type, node << 1, l, mid, u, v))%MOD;
	if(mid + 1 <= v) ans = (ans + get(type, node << 1|1, mid + 1, r, u, v))%MOD;
	return ans%MOD;
}


signed main() {
	fast_cin();
	
	cin >> n >> q;
	cin >> q_type;
	cin >> l_start >> l_mul >> l_add;
	cin >> r_start >> r_mul >> r_add;
	cin >> delta_start >> delta_mul >> delta_add >> delta_max;	
	
	int ans = 0;

	for(int i=0;i<q;++i) {
		int t = i%q_type;
		l_start = (l_start*l_mul%n + l_add)%n;
		r_start = (r_start*r_mul%n + r_add)%n;
		if(t == 0) {
			delta_start = (delta_start*delta_mul%delta_max + delta_add)%delta_max;
			update(1,0, n-1, min(l_start, r_start), max(l_start, r_start), delta_start);
		} else {
			bool d = (t == 1 ? false : true);
			ans = (ans +  get(d, 1, 0, n-1, min(l_start, r_start), max(l_start, r_start)))%MOD;
			//db(ans);
		}
		
				
	}
	
	cout << ans%MOD;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}