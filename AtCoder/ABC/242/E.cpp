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
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int t;
int n;
int a[MAXN2];
int b[MAXN2];
int dp[2][MAXN2];
bool ok = true;

int calc(int pos, int lower) {
/*	db(pos);
	db(lower);
	cerr << "\n";*/
	if(pos > (n + 1)/2) return 1;
	if(dp[lower][pos] != -1) return dp[lower][pos]%MOD;
	
	int sum = 0;
	
	for(int next = 1;next <= 26; ++next) {
		if(lower && next > a[pos]) break;
		
		sum = (sum + calc(pos + 1, lower&(next == a[pos])))%MOD;
	}
	
	return dp[lower][pos] = sum;
}


signed main() {
	fast_cin();
	
	cin >> t;
	
	while(t--) {
		
		cin >> n;
		ok = false;
		
		for(int i = 1; i <= n; ++i) {
			char c;
			cin >> c;
			a[i] = c - 'A' + 1;
		}
		
		// init
		
		for(int i = 1; i <= n; ++i) {
			for(int lower = 0; lower < 2; ++lower) {
				dp[lower][i] = -1;
			}
		}
		
		// DP
		for(int i = 1; i <= (n + 1)/2; ++i) b[i] = a[i];
		for(int i = (n + 1)/2 + 1; i <= n; ++i) b[i] = b[n - i + 1];
		for(int i = (n + 1)/2 + 1; i <= n; ++i) {
			if(a[i] != b[i]) {
				ok = (a[i] < b[i]);
				break;
			}
		}
		
		int res = (calc(1, 1) - ok + MOD)%MOD;
		
		cout << res << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}