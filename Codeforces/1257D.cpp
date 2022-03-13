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

int t;
int n,m;

int fin(int val,const vector<pii> & p) {
	int low = 1, high = m, res = 0;
	while(low <= high) {
		int mid = (low + high) >> 1;
		if(p[mid].fi >= val) {
			res = mid;
			high = mid - 1;
		}
		else low = mid + 1;
	} 
	
	return res;
}

void solve() {
	cin >> n;
	vector<int> a(n + 5);
	for(int i = 1; i <= n; ++i) cin >> a[i];
	cin >> m;
	vector<pii > p(m + 5);
	for(int i = 1; i <= m; ++i) {
		cin >> p[i].fi >> p[i].se;
	}
	
	sort(p.begin() + 1, p.begin() + m + 1);
	for(int i = m - 1; i >= 1; --i) {
		p[i].se = max(p[i].se, p[i + 1].se);
	}
	
	if(*max_element(a.begin() + 1, a.begin() + n + 1) > p[m].fi) {
		cout << "-1\n";
		return;
	}
	int res = 0;
	int maxx = -1,l = 1;
	for(int r = 1; r <= n; ++r) {
		maxx = max(a[r], maxx);
		int id = fin(maxx, p);
		if(p[id].se < r - l + 1) {
			cerr << "\n";
			res++;
			l = r;
			maxx = a[r];
		}
		
		if(r == n) res++;
	}
	
	cout << res << "\n";
	
}

signed main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		solve();
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}