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
const int base = 3;

int n,q;
string s;
int p[MAXN1];
int bit[MAXN1];

int power(int x, int y) {
	int res = 1;
	while(y) {
		if(y&1) res = res*x%MOD;
		x = x*x%MOD;
		y /= 2;
	}
	return res;
}

void update(int pos, int val) {
	for(;pos <= n; pos += (pos & -pos)) {
		bit[pos] = (bit[pos] + val)%MOD;
	}
}

int get(int pos) {
	int res = 0;
	for(; pos > 0; pos -= (pos & -pos)) {
		res = (res + bit[pos])%MOD;
	}
	return res;
}

void sub1() {
	for(int j = 1; j <= q; ++j) {
		int t,u,v,x;
		cin >> t >> u >> v >> x;
		if(t == 1) {
			for(;u <= v; ++u) {
				s[u] = x + '0';
			}
		}
		else {
			bool bad = false;
			for(int i = 0; i < x; ++i) {
				bad |= (s[u + i] != s[v + i]);
			}
			
			cout << !bad;
		}
	}
}

int get_hash(int l, int r) {
	return (get(r) - get(l - 1) + MOD%MOD)*power(p[l - 1], MOD - 2)%MOD;
}

bool solve(int u, int v, int x) {
	int low = 0, high = x - 1;
	while(low <= high) {
		int mid = (low + high) >> 1;
		int sum1 = get_hash(u, u + mid);
		int sum2 = get_hash(v, v + mid);
		if(sum1 == sum2) {
			low = mid + 1;
		}
		else return false;
	}
	
	return true;
}

signed main() {
	fast_cin();
	
	cin >> s;
	n = sz(s);
	s = ' ' + s;
	
	cin >> q;
	if(n <= 3000 && q <= 3000) {
		sub1();
	}
	else {
		p[0] = 1;
		for(int i = 1; i <= n; ++i) {
			p[i] = (base*p[i - 1])%MOD;
		}
		
		for(int i = 1; i <= n; ++i) {
			int x = s[i] - '0' + 1;
			int val = x*p[i]%MOD;
			update(i, val);
		}
		while(q--) {
			int t,u,v,x;
			cin >> t >> u >> v >> x;
			if(t == 1) {
				if(s[u] - '0' == x) continue;
				
				if(s[u] - '0' == 0) {
					update(u, p[u]);
				}
				else {
					update(u, MOD*MOD - p[u]);
				}
				s[u] = (x + '0');
			}
			
			
			else {
				cout << solve(u, v, x);
			}
		}
		
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}