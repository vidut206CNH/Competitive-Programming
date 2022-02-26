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

int n,k;
int h[MAXN1];
int maxx[4*MAXN1];

int  L_max[MAXN1];
int  R_max[MAXN1];


void build(int id, int l, int r) {
	if(l == r) {
		maxx[id] = h[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(id << 1, l, mid );
	build(id << 1|1, mid + 1, r);
	maxx[id] = max(maxx[id << 1], maxx[id << 1|1]);
}


int get(int id, int l, int r, int u, int v) {
	if(u > r || v < l) {
		return -inf;
	}
	
	if(u <= l && r <= v) {
		return maxx[id];
	}
	
	int mid = (l + r) >> 1;
	return max(get(id << 1, l, mid, u, v), get(id << 1|1, mid + 1, r, u, v));
}


int findleft(int l, int r, int pos) {
	int res = 1;
	
	while(l <= r) {
		int mid = (l + r) >> 1;
		int val = get(1, 1, n, mid, r);
		if(h[pos] + k >= val) {
			res = mid;
			r = mid - 1;
		} else l = mid + 1;
	}
	
	return res;
}


int findright(int l, int r, int pos) {
	int res = n;
	
	while(l <= r) {
		int mid = (l + r) >> 1;
		int val = get(1, 1, n, l, mid);
		if(h[pos] + k >= val) {
			res = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	
	return res;
}


signed main() {
	fast_cin();
	
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) cin >> h[i];
	
	build(1, 1, n);
	
	
	for(int i = 1; i <= n; ++i) {
		L_max[i] = findleft(1, i, i);
		
		R_max[i] = findright(i, n, i);
		int L = i - L_max[i];
		int R = R_max[i] - i;
/*		db(L);
		db(R);
		cerr << '\n';*/
		cout << R + L + 1 << " ";
	}
	
		
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}