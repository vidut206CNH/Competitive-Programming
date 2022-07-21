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
vector<int> digits;
int ans[25][2];
vector<int> num;
int f[12][12][2][2];

int dp(int pos, int d, int ok, int equal) {
	if(pos == -1) return (d == sz(num) && ok);
	
	auto &res = f[pos][d][ok][equal];
	if(res != -1) return res;
	
	res = 0;
	
	
	for(int i = 0; i < 10; ++i) {
		
		if(equal && i > digits[pos]) continue;
		bool equal1 = (equal && i == digits[pos]);
		
		if(d < sz(num) && i == num[d]) {
			if(num[d] == 0 && !ok);
			else res = res + dp(pos - 1, d + 1, ok | (i), equal1);
		}
		
		res = res + dp(pos - 1, d, ok | i, equal1);
		
	}
	
	return res;
}

void cnt(int X, int ok) {
	digits.clear();
	
	if(X == 0) {
		return;
	}
	
	while(X) {
		digits.push_back(X%10);
		X /= 10;
	}
	
	for(int mask = 0; mask < (1 << 10); ++mask) {
		
		num.clear();
		memset(f, -1, sizeof f);
		
		for(int i = 0; i < 10; ++i) {
			if(mask >> i & 1) {
				num.push_back(i);
			}
		}
		
		int s = __builtin_popcount(mask);
		ans[s][ok] += dp(sz(digits) - 1, 0, 0, 1);
	}
	
}

void solve(int L, int R) {
	memset(ans, 0, sizeof ans);
	
	cnt(L - 1, 0);
	cnt(R, 1);
	
	for(int i = 20; i >= 0; --i) {
		if(ans[i][1] - ans[i][0]) {
			cout << i << " " << ans[i][1] - ans[i][0] << "\n";
			return;
		}
	}	
}

int main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		int L, R;
		cin >> L >> R;
		
		solve(L, R);
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}