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
#define db(x) cerr << "[" << "Line " << __LINE__ << " -- " << (#x) << " : " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;


int get(int val) {
	int res = 0;
	for(int i=0;(1LL << i) < val;++i) {
		int tmp = (val >> i);
		res += (tmp >> 1)*(1LL << i);
		//db(res);
		if((val & ((1LL << i) - 1)) && (tmp & 1)) {
			res += (val - (1LL << i)*(tmp));
		}
		//db(res);
		//cerr << "\n";
	}
	return res;
}

signed main() {
	fast_cin();
	
	int q;
	cin >> q;
	//cout << get(q + 1);
	
	for(int i=1;i<=q;++i) {
		int l, r;
		cin >> l >> r;
		
		cout << get(r + 1) - get(l) << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}