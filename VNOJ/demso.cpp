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

int L,R,D,K;
vector<int> digits;
int a[20];
int dp[20][20][12][2][2];

int solve(int val) {
	digits.clear();
	while(val) {
		digits.push_back(val%10);
		val /= 10;
	}
	reverse(digits.begin(), digits.end());
	for(int i = 0; i < sz(digits); ++i) {
		a[i + 1] = digits[i];
	}
	
	
	// DP
	memset(dp, 0, sizeof dp);
	int k = min(K, sz(digits) - 1);
	dp[0][0][0][0][0] = 1;
	for(int id = 0; id < sz(digits); ++id) {
		for(int bad = 0; bad <= k; ++bad) {
			for(int last = 0; last  <= 9; ++last) {
				for(int lower = 0; lower < 2; ++lower) {
					for(int posi = 0; posi < 2; ++posi) {
						int cur = dp[id][bad][last][lower][posi];
						if(cur == 0) continue;
						for(int next = 0; next <= 9; ++next) {
							
							if(!lower && next > a[id + 1]) continue;
							int low2 = (lower || next < a[id + 1]);
							int bad2 = bad;
							if((last != 0 || posi) && abs(next - last) <= D) bad2++;
							int posi2 = (posi || next > 0);
							
							dp[id + 1][bad2][next][low2][posi2] += cur;
/*							db(id + 1);
							db(bad2);
							db(last);
							db(next);
							db(low2);
							db(posi2);
							cerr << "\n";*/
						}
					}
				}
			}
		}
	}
	
	int res = 0;
	for(int bad = 0; bad <= k; ++bad) {
		for(int last = 0; last <= 9; ++last) {
			for(int lower = 0; lower < 2; ++lower) {
				res += dp[sz(digits)][bad][last][lower][true];
			}
		}
	}
	
	return res;
	
}


signed main() {
	fast_cin();
	
	cin >> L >> R >> D >> K;
	
	
	cout << solve(R) - solve(L - 1);
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}