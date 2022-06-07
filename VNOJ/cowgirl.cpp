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
int m,n;
long long dp[35][(1 << 6) + 5];


long long f(int pos, int state) {
	if(pos == n) return 1;
	if(dp[pos][state] != -1) return dp[pos][state];
	
	long long res = 0;
	
	for(int next = 0; next < (1 << m); ++next) {
		bool good = true;
		for(int i = 0; i < m - 1; ++i) {
			if((state >> i & 1) && (state >> (i + 1) & 1)
				&& (next >> i & 1) && (next >> (i + 1) & 1)) {
					good =false;
			}
			if(!(state >> i & 1) && !(state >> (i + 1) & 1)
				&& !(next >> i & 1) && !(next >> (i + 1) & 1)) {
					good = false;
			}
		}
		
		if(good) {
			res += f(pos + 1, next);
		}
	}
	
	return dp[pos][state] = res;
}



int main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		cin >> m >> n;
		if(m > n) swap(m,n);
		memset(dp, -1, sizeof dp);
		
		long long res = 0;
		for(int state = 0; state < (1 << m); ++state) {
			res = res + f(1, state);
		}
		
		cout << res << "\n";
	}	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}