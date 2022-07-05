/*
	Author : vidut_206_CNH
	Link problem: 
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
const int MAXN2 = 1e6;
const int Test = 100;


mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l,int r) {
	return l + rng() * 1LL * rng()%(r - l + 1);
	
}


signed main() {
	fast_cin();
	
	srand(time_t(0));
	
	cout << (int)6e4 << "\n";
	for(int i = 1; i <= 60000; ++i) {
		cout << getRand(1, 60000) << " ";
	}
  
	#ifndef LOCAL_DEFINE
	cerr << "\nTime elapsed: " << 1.0 * clock_t() / CLOCKS_PER_SEC << " s.\n ";
	#endif
	
	return 0;
}
