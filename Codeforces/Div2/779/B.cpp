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

const int MOD = 998244353;
const int MAXN1 = 1e3+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int t;
int n;
int p[MAXN1];

signed main() {
	fast_cin();
	
	
	cin >> t;
	p[0] = 1;
	for(int i = 1; i < MAXN1; ++i) p[i] = p[i - 1]*i%MOD; 
	
	while(t--) {
		cin >> n;
		if(n&1) cout << 0 << "\n";
		else {
			cout << p[n/2]*p[n/2]%MOD << "\n";
		}
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}