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

int a,b;
int f[MAXN1];


signed main() {
	fast_cin();
	
	cin >> a >> b;
	int res = 0;
	
	for(int i=1;i*i<=b;++i) {
		int low = (a + i - 1)/i;
		int high = b/i;
		low = max({low, 2LL, i});
		
		for(;low <= high; low++) {
			f[i*low] += i;
			if(i != 1) f[i*low] += low;
/*			db(i*low);
			db(i);
			cerr << '\n';*/
			if(low == i) f[i*low] -= i;
		}
		
	}
	
	for(int i = a; i <= b; ++i) {
/*		db(f[i]);
		cerr << "\n";*/
		res += abs(i - f[i]);
	}
	
	cout << res;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}