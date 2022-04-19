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
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n;
int a[MAXN1];
vector<int> st[4*MAXN1];

void build(int id, int l, int r) {
	if(l == r) {
		st[id] = {a[l]};
		return;
	}
	
	int mid = (l + r) >> 1;
	build(id << 1, l, mid);
	build(id << 1|1, mid + 1, r);
	
	merge(st[id << 1].begin(), st[id << 1].end(), st[id << 1|1].begin(), st[id << 1|1].end(), back_inserter(st[id]));
	 
}


int get(int id, int l, int r, int u, int v, int x) {
	
	if(r < u || v < l) return 0;
	
	if(u <= l && r <= v) {
		return upper_bound(st[id].begin(), st[id].end(), x) - lower_bound(st[id].begin(), st[id].end(), x);
	}
	
	int mid = (l + r) >> 1;
	int sum = 0;
	sum += get(id << 1, l, mid, u, v, x);
	sum += get(id << 1|1, mid + 1, r, u, v, x);
	
	return sum;
	
}

signed main() {
	fast_cin();
	
	cin >> n;
	for(int i = 1; i<= n; ++i) cin >> a[i];
	build(1, 1, n);
	
	int q;
	cin >> q;
	while(q--) {
		int l, r, x;
		cin >> l >> r >> x;
		
		cout << get(1, 1, n, l, r, x) << "\n";
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}