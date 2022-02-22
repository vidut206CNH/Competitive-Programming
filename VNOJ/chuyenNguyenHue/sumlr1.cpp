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

int n,l,r;
int a[MAXN1];
int f[MAXN1];
int minn[MAXN1];

signed main() {
	fast_cin();
	
	
	cin >> n >> l >> r;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		f[i] = f[i - 1] + a[i];
	}
	
	deque<int> d;
	int len = r - l + 1;
	for(int i = 0; i <= n; ++i) {
		while(!d.empty() && f[d.back()] >= f[i]) d.pop_back();
		d.push_back(i);
		while(!d.empty() && d.front() < i - len + 1) d.pop_front();
		minn[i] = f[d.front()];
	}
	
	int res = -inf;
	for(int i = l; i <= n; ++i) {
		res = max(res, f[i] - minn[i - l]);
	}
	
	cout << res;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}