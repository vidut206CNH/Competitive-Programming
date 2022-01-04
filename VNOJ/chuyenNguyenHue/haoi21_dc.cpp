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
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e5+5;

int n,k;
unordered_map<int,int> m,t;
int d[MAXN1];
pii a[MAXN2];

signed main() {
	fast_cin();
	
	cin >> n >> k;
	
	vector<int> p;
	for(int i=1;i<=n;++i) {
		cin >> 	a[i].fi >> a[i].se;
		++a[i].se;
		p.push_back(a[i].fi);
		p.push_back(a[i].se);
	}
	
	sort(p.begin(), p.end());
	int pos = 1;
	int last = p[0];
	
	m[pos-1] = p[0] - 1;
	m[pos] = p[0];
	t[p[0]] = pos;
	
	for(int i=1;i<sz(p);++i) {
		if(p[i] == last) {
			continue;
		} else {
			m[++pos] = p[i];
			t[p[i]] = pos;
			last = p[i];
		}
	}
	
	m[++pos] = p.back() +1;
	
	for(int i=1;i<=n;++i) {
		int l = a[i].fi;
		int r = a[i].se;
		d[t[l]]++;
		d[t[r]]--;
	}
	
	
	int ans = 0;
	for(int i=1;i<=pos;++i) {
		d[i] += d[i-1];
		/*
		db(m[i]);
		db(d[i]);
		cerr << "\n";
		*/
		if(d[i-1] == k) {
			ans += (m[i] - m[i-1]);
		}
	}
	
	cout << ans;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}