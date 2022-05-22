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
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n;
int a[MAXN1];
int p[65][MAXN1];
int bit[MAXN1];
int dp[MAXN1];

void update(int pos, int val) {
	for(;pos <= n; pos += (pos & -pos)) bit[pos] += val;
}

int get(int pos) {
	int res = 0;
	for(;pos > 0; pos -= (pos & -pos)) res += bit[pos];
	return res;
}

signed main() {
	fast_cin();
	
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	
	for(int i = 1; i <= n; ++i) {
		int maxx = 0;
		for(int d = 0; (1LL << d) <= a[i]; ++d) {
			if(a[i] >> d & 1) {
				p[d][i] = (p[d][i - 1] + 1);
				maxx = max(maxx, p[d][i]);
			}
			
			else p[d][i] = 0;
		}
		dp[i] = get(i - 1) - get(i - maxx) + 1;
		db(dp[i]);
		db(maxx);
		cerr << "\n";
		update(i, dp[i]);
	}
	
	cout << dp[n];
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}