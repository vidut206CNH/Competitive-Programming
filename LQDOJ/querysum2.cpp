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

int b[MAXN1];
int d[MAXN1];
int n,q;

void add(int bit[], int pos, int val) {
	for(;pos <= n;pos += pos&-pos) {
		bit[pos] += val;
	}
}

void update(int l, int r, int val) {
	add(b, l, val);
	add(b, r+1, -val);
	add(d, l, val*(l-1));
	add(d, r+1, -val*r);
}

int get(int bit[], int pos) {
	int res = 0;
	for(;pos > 0; pos -= pos&-pos) {
		res += bit[pos];
	}
	
	return res;
}

int range_sum(int l, int r) {
	int fr = get(b, r)*r - get(d, r);
	int fl = get(b, l-1)*(l-1) - get(d, l-1);
	return fr - fl;
}

signed main() {
	fast_cin();
	
	cin >> n >> q;
	for(int i=1;i<=n;++i) {
		int x;
		cin >> x;
		update(i,i,x);
	}
	
	for(int i=1;i<=q;++i) {
		int t;
		cin >> t;
		if(t==1) {
			int l,r,val;
			cin >> l >> r >> val;
			update(l,r,val);
		} else {
			int l,r;
			cin >> l >> r;
			cout << range_sum(l,r) << "\n";
		}
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}