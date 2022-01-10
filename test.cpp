/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
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
const int MAXN1 = (1LL << 32) - 1;
const int MAXN2 = 1e6+5;

bitset<MAXN1> p;

signed main() {
	fast_cin();
	
	int q,s,a,b;
	cin >> q >> s >> a >> b;
	int res = 0;
	for(int i=1;i <= q;++i) {
		int g = (s >> 1);
		if(s&1) {
			if(!(p >> g & 1)) res += g;
			p[g] = 1;
		}
		s = ((a*s + b) & ((1LL << 32) - 1));
		//db(res);
	}
	//db((1LL << 32) - 1);
	cout << res;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}