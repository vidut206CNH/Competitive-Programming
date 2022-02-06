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
const int MAXN1 = 3e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18 + 7;

int n;
int a[MAXN1];
int f[MAXN1];

signed main() {
	fast_cin();
	
	
	cin >> n;
	for(int i=1;i<=n;++i) cin >> a[i];
	deque<int> d;
	int res = (n - 1)*2;
	for(int i=1;i <= n; ++i) {
		while(!d.empty() && a[d.back()] <= a[i]) {
			d.pop_back();
		}
		if(!d.empty()) {
			if(d.back() == i-1) res -= 2;
			res += (i - d.back() + 1);
/*			db(i);
			db(d.back());
			cerr << '\n';*/
		}
		d.push_back(i);
	}
	d.clear();
	
	for(int i=n;i>=1;--i) {
		while(!d.empty() && a[d.back()] <= a[i]) d.pop_back();
		if(!d.empty()) {
			if(d.back() == i + 1) res -= 2;
			res += (d.back() - i + 1);
/*			db(i);
			db(d.back());
			cerr << "\n";*/
		}
		d.push_back(i);
	}
	
	d.clear();
	
	for(int i=1;i<=n;++i) {
		while(!d.empty() && a[d.back()] < a[i]) d.pop_back();
		while(!d.empty() && a[d.back()] > a[i]) d.pop_back();
		f[i] = 1;
		if(!d.empty() && a[d.back()] == a[i]) {
			if(d.back() == i-1) res -= 2;
			f[i] = d.size()*(i - d.back()) + f[d.back()] + 1;
			res += (f[i] - 1);
/*			db(res);
			db(i);
			db(d.size());
			cerr << '\n';*/
		}
		d.push_back(i);
	}
	
	cout << res;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}