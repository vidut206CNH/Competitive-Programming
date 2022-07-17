/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define lcm(a,b) (a/gcd(a,b)*b)
#define sz(x) (int)(x.size())
#define fast_cin() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define db(x) cerr << "[" << "Line " << __LINE__ << " : " << (#x) << " = " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;

int t;
pii res;

int gcd(int a, int b) {
	int m = a;
	pii pm = {1, 0};
	int n = b;
	pii pn = {0, 1};
	pii pr;
	
	while(n) {
		int q = m/n;
		int r = m - q*n;
		pr.fi = pm.fi - q*pn.fi;
		pr.se = pm.se - q*pn.se;
		
		m = n; pm = pn;
		n = r; pn = pr;
	}
	
	res = pm;	
	return m;
}

signed main() {
	fast_cin();
	
/*	freopen("DIOPHANTINE.INP", "r", stdin);
	freopen("DIOPHANTINE.OUT", "w", stdout);*/
	
	cin >> t;
	while(t--) {
		int a,b,c;
		cin >> a >> b >> c;
		int d = gcd(a,b);
		if(c%d != 0) {
			cout << 0 << "\n";
		}
		
		else {
			res.fi *= c/d;
			res.fi += abs(res.fi)*b;
			int p = b / d;
			res.fi %= p;
			db(res.fi);
			cout << max(0LL, ((c - b)/a - res.fi)/p + (res.fi != 0 && res.fi <= (c - b)/a)) << "\n";
		}
	}	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}