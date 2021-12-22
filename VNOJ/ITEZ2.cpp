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
#define INF 2e18
#define db(x) cerr << "[" << "Line " << __LINE__ << " -- " << (#x) << " : " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;

int bit[MAXN1];
int a[MAXN1];

int n,q;


void update(int idx,int val) {
	for(;idx <= n;idx += idx&-idx) {
		bit[idx] += val;
	}
}

int sum(int id) {
	int res = 0;
	for(;id > 0; id -= id&-id) {
		res += bit[id];
	}
	return res;
}

int get(int &l, int &r) {
	return  sum(r) - sum(l-1);
}


signed main() {
	fast_cin();
	cin >> n >> q;
	for(int i=1;i<=q;++i) {
		int t;
		cin >> t;
		if(t==1) {
			int u,v;
			cin >> u >> v;
			update(u, v - a[u]);
			a[u] = v;
		} else {
			int l,r;
			cin >> l >> r;
			cout << get(l,r) << "\n";
		}
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}