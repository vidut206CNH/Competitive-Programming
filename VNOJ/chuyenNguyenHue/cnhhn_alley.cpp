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

const int MOD = 20152015;
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;

int n;
long long dp[505][(1 << 5) + 5];
char a[MAXN1][5];

int main() {
	fast_cin();
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j < 5; ++j) {
			cin >> a[i][j];
		}
	}
	
	dp[0][0] = 1;
	
	for(int r = 0; r < n; ++r) {
		for(int cur = 0; cur < (1 << 5); ++cur) {
			bool ok = true;
			if(r != 0) {
				for(int j = 0; j < 5; ++j) {
					if(a[r][j] == 'x') ok &= (cur >> j & 1);
				}
			}
			
			if(!ok) continue;
			
			int val = dp[r][cur];
			for(int next = 0; next < (1 << 5); ++next) {
				bool ok1 = true;
				
				for(int j = 0; j < 5; ++j) {
					if(a[r + 1][j] == 'x') ok1 &= (next >> j & 1);
				}
				
				if(!ok1) continue;
				
				for(int bit = 0; bit < 4; ++bit) {
					if(r != 0 && (cur >> bit & 1) && (cur >> (bit + 1) & 1)
					    && (next >> bit & 1) && (next >> (bit + 1) & 1)
						&& (a[r][bit] != 'x') && (a[r][bit + 1] != 'x')
						&& (a[r + 1][bit] != 'x') && (a[r + 1][bit + 1] != 'x')) {
							ok1 = false;
						}
					if(r != 0 && !(cur >> bit & 1) && !(cur >> (bit + 1) & 1)
					    && !(next >> bit & 1) && !(next >> (bit + 1) & 1)
						&& (a[r][bit] != 'x') && (a[r][bit + 1] != 'x')
						&& (a[r + 1][bit] != 'x') && (a[r + 1][bit + 1] != 'x')) {
							ok1 = false;
						}
				}
				
				if(!ok1) continue;
				
				dp[r + 1][next] = (dp[r + 1][next] + val)%MOD;
			}
			
		}
	}
	
	int res = 0;
	
	for(int state = 0; state < (1 << 5); ++state) {
		bool ok = true;
		
		for(int j = 0; j < 5; ++j) {
			if(a[n][j] == 'x') ok &= (state >> j & 1);
		}
		
		if(!ok) continue;
		res = (res + dp[n][state])%MOD;
	}
	
	
	cout << res;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}