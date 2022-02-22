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
const int MAXN1 = 2e3 + 5;
const int MAXN2 = 205;
const int inf = 1e18;

int L,R;
int dp[20][MAXN2][MAXN1][2][2];
int a[20];
vector<int> digits;





int solve(int val) {
	
	if(val == 0) return 0;
	
	digits.clear();
	
	while(val) {
		digits.push_back(val%10);
		val /= 10;
	}
	reverse(digits.begin(), digits.end());
	for(int i = 0; i < sz(digits); ++i) {
		a[i + 1] = digits[i];
		//cout << a[i + 1] << " ";
	}
	//cout << "\n";
	
	// DP
	memset(dp, 0, sizeof dp);
	
	dp[0][0][0][0][0] = 1;
	for(int id = 0; id < sz(digits); ++id) {
		for(int sum = 0; sum < MAXN2; ++sum) {
			for(int square_sum = 0; square_sum < MAXN1; ++square_sum) {
				for(int lower = 0; lower < 2; ++lower) {
					for(int positive = 0; positive < 2; ++positive) {
						int cur = dp[id][sum][square_sum][lower][positive];
						if(cur == 0) continue;
						
						for(int next = 0; next <= 9; ++next) {
							
							if(!lower && next > a[id + 1]) continue;
							int lower2 = (lower || next < a[id + 1]);
							int sum2 = sum + next;
							int square_sum2 = square_sum + next*next;
							int positive2 = (positive || next > 0);
							
							dp[id + 1][sum2][square_sum2][lower2][positive2] += cur;
						}
					}
				}
			}
		}
	}
	
	int res = 0;
	for(int sum = 0; sum < MAXN2; ++sum) {
		for(int square_sum = 0; square_sum < MAXN1; ++square_sum) {
			if(gcd(sum ,square_sum) == 1) {
				for(int lower = 0; lower < 2; ++lower) {
					res += dp[sz(digits)][sum][square_sum][lower][true];
				}
			}
		}
	}
	return res;
}

signed main() {
	fast_cin();
	
	cin >> L >> R;
	cout << solve(R) - solve(L - 1);
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}