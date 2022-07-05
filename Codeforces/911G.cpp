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
const int BLOCK_SIZE = 805;

int n,q;
int lazy[MAXN1/BLOCK_SIZE + 10][105];
int a[MAXN1];

void pushdown(int id) {
	for(int i = id*BLOCK_SIZE; i <= min(n - 1,(id + 1)*BLOCK_SIZE - 1); ++i) a[i] = lazy[id][a[i]];
	
	for(int val = 1; val <= 100; ++val) lazy[id][val] = val;
}

void upd(int id, int L, int R, int oval, int nval) {
	pushdown(id);
	
	for(int i = L; i <= R; ++i) {
		if(a[i] == oval) a[i] = nval;
	}
}

void update(int L, int R, int oval, int nval) {
	
	int l = L/BLOCK_SIZE;
	int r = R/BLOCK_SIZE;
	if(l == r) {
		upd(l, L, R, oval, nval);
		return;
	}
	
	for(int i = l + 1; i <= r - 1; ++i) {
		for(int val = 1; val <= 100; ++val) {
			if(lazy[i][val] == oval) lazy[i][val] = nval;
		}
	}
	
	upd(l, L, (l + 1)*BLOCK_SIZE - 1, oval, nval);
	upd(r, r*BLOCK_SIZE, R, oval, nval);
	
}

int main() {
	fast_cin();
	
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int lim = (n + BLOCK_SIZE - 1)/BLOCK_SIZE;
	
	for(int i = 0; i <= lim; ++i) {
		for(int val = 1; val <= 100; ++val) lazy[i][val] = val;
	}
	
	cin >> q;
	
	while(q--) {
		int l, r, x, y;
		cin >> l >> r >> x >> y;
		--l;
		--r;
		update(l, r, x, y);
	}
	
	
	
	for(int i = 0; i < n; ++i) cout << lazy[i / BLOCK_SIZE][a[i]] << " ";
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}