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
const int MAXN2 = 2e6+5;

int n;
int a[MAXN2];
int cnt[MAXN2];
long long dp[MAXN2][22];
long long F[MAXN2];

long long power(long long A, long long B) {
	long long res = 1;
	while(B) {
		if(B&1) res = res*A%MOD;
		A = A*A%MOD;
		B /= 2;
	}
	
	return res;
}

long long get(int mask, int id) {
	if(id < 0) return (power(2, cnt[mask]) - 1 + MOD)%MOD;
	return dp[mask][id];
}

int main() {
	fast_cin();
	
	cin >> n;
	
	for(int i = 1; i <= n; ++i) {
		
		cin >> a[i];
		a[i] = ((1 << 20) - 1)^a[i];
		db(a[i]);
		cnt[a[i]]++;
		
	}
	
	for(int mask = 0;mask < (1 << 20); ++mask) {
		for(int i = 0; i < 20; ++i) {
			
			if(mask >> i & 1) {
				dp[mask][i] = 1LL*get(mask, i - 1)*get(mask^(1 << i), i - 1)%MOD;
			}
			
			else dp[mask][i] = get(mask, i - 1)%MOD;
			
			if(dp[mask][i] != 0) {
				db(mask);
				db(i);
				db(dp[mask][i]);
				cerr << "\n";
			}
		}
		
	}
	
	cout << dp[(1 << 20) - 1][19];	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}