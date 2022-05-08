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

const int MOD = 998244353;
const int MAXN1 = 1e7;
const int MAXN2 = 1e5+5;
const int inf = 1e18;


int t;
int f[MAXN1 + 5];
int lp[MAXN1 + 5];
vector<int> pr;
pii q[MAXN2];
int p[MAXN2];

void sieve() {
	for(int i = 2; i < MAXN1; ++i) {
		if(lp[i] == 0) {
			lp[i] = i;
			pr.push_back(i);
		}
		
		for(auto x : pr) {
			if(x > lp[i]) break;
			if(i*x > MAXN1) break;
			lp[i*x] = x;
		}
	}
}

signed main() {
	fast_cin();
	
/*	freopen("primelcm.inp", "r", stdin);
	freopen("primelcm.out", "w", stdout);*/
	
	sieve();
	
	cin >> t;
	
	for(int i = 1; i <= t; ++i) {
		cin >> q[i].fi;
		q[i].se = i;
	}
	
	sort(q + 1, q + t + 1);
	
	vector<pii> g;
	
	for(auto x : pr) {
		
		int mul = x;
		
		while(mul <= MAXN1*MAXN1/x) {
			mul *= x;
			g.push_back({mul, x});
		}
		
	}
	
	sort(g.begin(), g.end());
	
	
	int id1 = 0;
	int res = 1;
	
	for(int i = 1; i <= t; ++i) {
		
		while(id1 < sz(g) && g[id1].fi <= q[i].fi)	 {
			res = res*g[id1].se%MOD;
			++id1;
		}
		
		p[q[i].se] = res;
	}
	
	
	for(int i = 1; i <= t; ++i) cout << p[i] << " ";
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}