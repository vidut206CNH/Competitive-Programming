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
const int MAXN2 = 1e7+5;

int n,m,k,x,q;

int a[MAXN2];
int pref[MAXN2], suf[MAXN2];
int res[MAXN1];

bool comp(const pair<pii, pii>& A, const pair<pii, pii>& B) {
	return (A.fi.se < B.fi.se);
}


signed main() {
	fast_cin();
	cin >> n >> m >> k >> x >> q;
	a[1] = x;
	
	for(int i=2;i<=n;++i) {
		a[i] = a[i-1]*k%m;
	}
	
	pref[0] = -INF;
	for(int i=1;i<=n;++i) {
		a[i] -= q;
		pref[i] = max(pref[i-1], a[i]);
	}
	suf[n+1] = -INF;
	for(int i=n;i >= 1; --i) {
		suf[i] = max(suf[i+1], a[i]);
	}
	
	
	int t;
	cin >> t;	
	vector<pair<pii, pii > > p(t + 1);
	for(int i=1;i<=t;++i) {
		cin >> p[i].fi.fi >> p[i].fi.se >> p[i].se.fi;
		p[i].se.se = i;
	}
	
	sort(p.begin(), p.end(), comp);
	
	int pos = 0;
	
	deque<int> d;
	
	for(int i=1;i<sz(p);++i) {
		while(pos < p[i].fi.se) {
			pos++;
			while(!d.empty() && a[d.back()] <= a[pos]) d.pop_back();
			d.push_back(pos);
		}
		
		res[p[i].se.se] = max(pref[p[i].fi.fi - 1], suf[p[i].fi.se + 1]);
		
		if(d.front() >= p[i].fi.fi) {
			res[p[i].se.se] = max(a[d.front()] - p[i].se.fi, res[p[i].se.se]);
		}
		//db(a[d.front()]);
		
	}
	
	for(int i=1;i<=t;++i) cout << res[i] << "\n";
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}