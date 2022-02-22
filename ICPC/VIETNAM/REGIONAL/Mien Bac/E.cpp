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


int n;
int dp[20][10][155][155];
bool p[150];

signed main() {
	fast_cin();
	p[0] = true;
	p[1] = true;
	for(int i = 2; i*i < 150; ++i) {
		if(p[i]) continue;
		for(int j = i *i ; j < 150; j += i) p[j] = true;
	}
	
	cin >> n;
	vector<int> digits;
	while(n) {
		digits.push_back(n%10);
		n /= 10;
	}	
	
	reverse(digits.begin(), digits.end());
	int lim = sz(digits);
	
	// DP: build from i -> n
	// Complexity: log10(n)*1000*(150^2)
	dp[lim][0][0][0] = 1;
	
	for(int i = lim; i > 0; --i) {
		for(int rem = 0; rem < 10; ++rem) {
			for(int sx = 0; sx < 150; ++sx) {
				for(int sy = 0; sy < 150; ++sy) {
					int cur = dp[i][rem][sx][sy];
					if(cur == 0) continue;
					
					for(int x = 0;x < 10; ++x) {
						for(int y = 0; y < 10; ++y) {
							
							int rem2 = x + 2*y + rem;
							int sx2 = sx + x;
							int sy2 = sy + y;
							
							if(rem2%10 == digits[i - 1]) {
								dp[i - 1][rem2/10][sx2][sy2] += cur;
							}
							
						}
					}
				}
			}
		}
	}
	
	int res = 0;
	for(int sx = 0;sx < 150; ++sx) {
		for(int sy = 0; sy < 150; ++sy) {
			if(!p[sx] && !p[sy]) {
				res += dp[0][0][sx][sy];
			}
		}
	}
	
	cout << res;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}