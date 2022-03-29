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
const int MAXN1 = 1e7+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,q;
int res[MAXN1];
int f[MAXN1], s[MAXN1];
int pref[MAXN1], suf[MAXN1];

signed main() {
	fast_cin();
	
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		int p, t, d;
		cin >> p >> t >> d;
		++d;
		if(p >= d) {
			s[p - d] = t;
		}
		
		if(p + d < MAXN1) {
			f[p + d] += t;
		}
	}
	
	for(int i = 0; i < MAXN1; ++i) {
		if(i != 0) f[i] += f[i - 1];
		//db(f[i]);
		pref[i] = f[i];
		if(i != 0) pref[i] += pref[i - 1];
	}
	
	for(int i = (int)1e7; i >= 0; --i) {
		s[i] += s[i + 1];
		suf[i] = s[i];
		suf[i] += suf[i + 1];
	}
	
	while(q--) {
		int v;
		cin >> v;
		//db(pref[v]);
		cout << pref[v] + suf[v] << "\n";
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}