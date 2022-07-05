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

const long long MOD = 1e12 + 7;
const int MAXN1 = 1e3+5;
const int MAXN2 = 1e6+5;

int n,m;
long long C[1005][1005];
long long dp[MAXN1][MAXN1];
int cnt[MAXN1];
int a[MAXN1];
vector<int> values;

void calc_C() {
	
	C[0][0] = 1;
	
	for(int i = 1; i < MAXN1; ++i) {
		C[i][0] = 1;
		
		for(int j = 1; j <= i; ++j) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j])%MOD;
		}
	}
}


long long mul(long long A, long long B) {
	long long res = 0;
	while(B) {
		if(B&1) res = (res + A)%MOD;
		A = (A*2)%MOD;
		B /= 2;
	}
	
	return res;
}

int main() {
	fast_cin();
	calc_C();
	
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		values.push_back(a[i]);
	}	
	
	values.push_back((int)(-(1e9 + 7)));
	
	sort(values.begin(), values.end());
	values.resize(unique(values.begin(), values.end()) - values.begin());
	for(int i = 1; i <= n; ++i) {
		int id = lower_bound(values.begin(), values.end(), a[i]) - values.begin();
		cnt[id]++;
	}
	
	dp[0][0] = 1;
	
	for(int i = 0; i < sz(values) - 1; ++i) {
		for(int num = 0; num <= m; ++num) {
			long long val = dp[i][num];
			if(val == 0) continue;
			
			for(int next = 0; next + num <= m && next <= cnt[i + 1]; ++next) {
				dp[i + 1][num + next] = (dp[i + 1][num + next] + mul(val, C[next + num][next]))%MOD;
			}
			
		}
	}
	
	
	cout << dp[sz(values) - 1][m];
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}