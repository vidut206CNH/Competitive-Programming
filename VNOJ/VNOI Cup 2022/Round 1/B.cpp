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

int n;
long long cnt[MAXN2];
long long sum[MAXN2];
long long dp[2*MAXN2];
long long f[2*MAXN2];
int c[MAXN2];

int main() {
	fast_cin();
	
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> c[i];
		cnt[c[i]]++;
	}
	
	for(int i = (int)1e6; i >= 1; --i) {
		sum[i] = cnt[i];
		for(int j = i*2; j < MAXN2; j += i) sum[i] += cnt[j];
	}
	
	for(int i = (int)1e6; i >= 1; --i) {
		dp[i] = 1LL*(sum[i])*(sum[i] - 1)/2;
		
/*		for(int j = i*2; j < MAXN2; j += i) dp[i] -= dp[j];
		
		
		f[i] = dp[i];
		for(int j = i*2; j < MAXN2; j += i) f[i] += f[j];*/
	}
	
	for(int i = 1; i <= n; ++i) {
		cout << dp[c[i]*2] << " ";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}