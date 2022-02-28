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

int n;
pii a[MAXN1];

void sub1() {
	int minn = inf;
	pii res;
	for(int i = 2; i <= n; ++i) {
		for(int j = 1; j < i; ++j) {
			if(a[i].fi >= a[j].fi && a[i].se >= a[j].se) {
				int diff = abs(a[i].fi - a[j].fi) + abs(a[i].se - a[j].se);
				if(diff == minn) {
					if(res.fi > j) {
						res.fi = j;
						res.se = i;
					}
					if(res.fi == j) {
						res.se = min(res.se, i);
					}
				}	
				
				if(diff < minn) {
					minn = diff;
					res.fi = j;
					res.se = i;
				}			
			}
			
			else if (a[i].fi <= a[j].fi && a[i].se <= a[j].se) {
				int diff = abs(a[i].fi - a[j].fi) + abs(a[i].se - a[j].se);
				if(diff == minn) {
					if(res.fi > i) {
						res.fi = i;
						res.se = j;
					}
					if(res.fi == i) {
						res.se = min(res.se, j);
					}
				}
				if(diff < minn) {
					minn = diff;
					res.fi = i;
					res.se = j;
				}
			}
		}
	}
	if(minn == inf) {
		cout << -1;
	}
	else cout << minn << "\n" << res.fi << " " << res.se;
}

signed main() {
	fast_cin();
	
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i].fi >> a[i].se; 
	}
	
	sub1();
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}