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
const int MAXN1 = 1e3;
const int MAXN2 = 1e6+5;

int t;
string s;
int dp[MAXN1 + 1][MAXN1 + 5][2];

int calc(int pos, int sum, int state) {
	
	if(pos == MAXN1) return (sum == 0);
	
	auto &res = dp[pos][sum][state];
	if(res != -1) return res;
	res = 0;
	if(sum) {
		res = (res + calc(pos + 1, sum - 1, 1))%MOD;
	}
	
	res = (res + calc(pos + 1, sum + 1, 0))%MOD;
	
	return res;
	
}


void pre_calc() {
	memset(dp, -1, sizeof dp);
}

void solve() {
	int d = MAXN1 - sz(s);
	s = '0' + s;
	
	int sum = 0;
	int res = 0;
	for(int i = 1; i < sz(s); ++i) {
		
		if(s[i] == ')') {
			res = (res + calc(d + i, sum + 1, 0))%MOD;
			sum--;
		}
		
		else {
			sum++;
		}
		
	}
	
	cout << res + 1 << "\n";
}

int main() {
	fast_cin();
	
	pre_calc();
	
	cin >> t;
	while(t--) {
		cin >> s;
		solve();
	}	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}