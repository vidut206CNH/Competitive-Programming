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

int n,v;
pii lef[MAXN1];
pii righ[MAXN1];
int p[MAXN1];

signed main() {
	fast_cin();
	
	cin >> n;
	
	for(int i = 1; i <= n; ++i) {
		cin >> lef[i].fi >> lef[i].se >> righ[i].fi >> righ[i].se;
		int lc = lef[i].fi;
		int rc = righ[i].fi;
		if(lc != 0) p[lc] = i;
		//db(p[lc]);
		//db(lc);
		//cerr << "\n";
		if(rc != 0) p[rc] = i; 
	}
	
	
	cin >> v;
	int res = 1;
	bool bad = false;
	while(v != 1) {
		db(v);
		db(res);
		int par = p[v];
		pii le = lef[par];
		pii ri = righ[par];
		
		if(le.fi == v) {
			if(le.se < res) {
				bad = true;
				break;
			}
		}
		else {
			if(ri.se < res) {
				bad = false;
				break;
			}
		}
		
		if(le.fi == 0 && le.se == 0) {
			v = p[v];
			continue;
		}
		if(ri.fi == 0 && ri.se == 0) {
			v = p[v];
			continue;
		}
		
		
		int diff = abs(le.se - ri.se);
		diff = res - diff;
		if(le.fi == v) {
			if(le.se > ri.se && diff < res) {
				res = diff + (res - diff)* 2 - 1;
			}
			if(le.se < ri.se) {
				 res += (diff);
			}
		}
		else {
			if(ri.se > le.se && diff < res) {
				res = diff + (res - diff)*2;
			}
			
			if(ri.se < le.se) {
				res += (diff + 1);
			}
			if(ri.se == le.se) {
				res++;
			}
		}
		
		v = p[v];
	}
	
	cout << (bad ? -1 : res);
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}