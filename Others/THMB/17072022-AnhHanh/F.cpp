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

const int MOD = 1e4 + 7;
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;

int n,k;
int cnt[3*MAXN1][22];
int prod[3*MAXN1];
int g[MAXN1];
int c[MAXN1];


void pushup(int id) {
	
	prod[id] = prod[id << 1]*prod[id << 1|1]%MOD;
	
	memset(cnt[id], 0, sizeof cnt[id]);
	
	for(int i = 0; i < k; ++i) {
		for(int j = 0; j < k; ++j) {
			
			if(i + j >= k) break;
			
			cnt[id][i + j] += cnt[id << 1][i]*cnt[id << 1|1][j];
			
		}
	}
	
	for(int i = 0; i < k; ++i) cnt[id][i] %= MOD;
	
} 

void update(int id, int l, int r,const int& pos,const int& G,const int &C) {
	if(l == r) {
		prod[id] = (G + C)%MOD;
		cnt[id][0] = C%MOD;
		cnt[id][1] = G%MOD;
		return;
	}
	
	int mid = (l + r) >> 1;
	if(pos <= mid) update(id << 1, l, mid, pos, G, C);
	else update(id << 1|1, mid + 1, r, pos, G, C);
	
	pushup(id);
}


void build(int id, int l, int r) {
	if(l == r) {
		prod[id] = (g[l] + c[l])%MOD;
		cnt[id][0] = c[l];
		cnt[id][1] = g[l];
		return;
	}
	
	int mid = (l + r) >> 1;
	build(id << 1, l, mid);
	build(id << 1|1, mid + 1, r);
	pushup(id);
}

int main() {
	fast_cin();
	
/*	freopen("relativnost.inp", "r", stdin);
	freopen("relativnost.out", "w", stdout);*/
	
	cin >> n >> k;
	
	
	for(int i = 1; i <= n; ++i) cin >> g[i], g[i] %= MOD;
	for(int i = 1; i <= n; ++i) cin >> c[i], c[i] %= MOD; 
	
	build(1, 1, n);
	
	int q;
	cin >> q;
	
	while(q--) {
		int pos, G, C;
		cin >> pos >> G >> C;
		update(1, 1, n, pos, G, C);
		int sum = prod[1];
		
		for(int i = 0; i < k; ++i) {
			sum -= cnt[1][i];
		}
		
		sum = (sum + MOD*MOD)%MOD;
		cout << sum << " "; 
	}
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}