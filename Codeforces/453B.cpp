/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
//#define int long long
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
const int MAXN1 = 105;
const int MAXN2 = 1 << 17;
const int inf = 1e9;

int n;
int a[MAXN1];

int dp[MAXN1][MAXN2];
int f[MAXN1][MAXN2];
int pre[MAXN1][MAXN2];

vector<int> prime;
bool isp[65];

signed main() {
	fast_cin();
	
	memset(isp, true, sizeof isp);
	for(int i=2;i<=60;++i) {
		if(isp[i]) prime.push_back(i);
		if(isp[i]) for(int j=i*i;j <= 60; j += i) isp[j] = false;
	}
	
	cin >> n;
	for(int i=1;i<=n;++i) cin >> a[i];
	
	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;
	f[0][0] = -1;
	
	int best = inf,g = 0;

	for(int i=1;i<=n;++i) {
		for(int val = 1; val < 2*a[i]; ++val) {
			int mask = 0;
			
			for(int p=0; p < sz(prime); ++p) {
				if(prime[p] > val) break;
				if(val % prime[p] == 0) {
					mask |= (1 << p);
				}
			}
			int p_mask = ((MAXN2 - 1)^(mask));
			
			
			for(int s = p_mask;;s = (s - 1)&p_mask) {
				
				if(dp[i-1][s] + abs(val - a[i]) < dp[i][s | mask]) {
					f[i][s | mask] = val;
					pre[i][s | mask] = s;
					dp[i][s | mask] = dp[i-1][s] + abs(val - a[i]);
					if(i == n) {
						if(dp[i][s | mask] < best) {
							best = dp[i][s | mask];
							g = (s | mask);
						}
					}
				}
				
				if(s == 0) break;
			}
		}
	}
	
	vector<int> res(n+1);
	for(int i=n;i>=1;--i) {
		res[i] = f[i][g];
		g = pre[i][g];
	}
	for(int i=1;i<=n;++i) cout << res[i] << " ";
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}