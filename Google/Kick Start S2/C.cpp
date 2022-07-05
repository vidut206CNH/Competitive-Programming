/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
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

int t;
int n,q;
int f[MAXN1][30];

int solve() {
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		char x;
		cin >> x;
		
		for(int c = 0; c < 26; ++c) f[i][c] = f[i - 1][c] + (x - 'A' == c);
		
	}
	int res = 0;
	while(q--) {
		int L,R;
		cin >> L >> R;
		int cnt = 0;
		for(int c = 0; c < 26; ++c) cnt += (f[R][c] - f[L - 1][c])%2;
		res += (cnt <= 1);
	}
	
	return res;
}

int main() {
	fast_cin();
	
	cin >> t;
	for(int tt = 1; tt  <= t; ++tt) {
		cout << "Case #" << tt << ": " << solve() << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}