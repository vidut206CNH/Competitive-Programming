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

struct points{
	int x,y,z;
};

int n;
points a[20];
long long dp[18][(1 << 18) + 5];

long long calc(const points &A, const points &B) {
	return abs(A.x - B.x) + abs(A.y - B.y) + max(0LL, 0LL + B.z - A.z);
}

int main() {
	fast_cin();
	
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i].x >> a[i].y >> a[i].z;
	}
	
	
	
	
	// DP
	memset(dp, 0x3f, sizeof dp);
	
	for(int i = 1; i < n; ++i) {
		
		dp[i][1 << i] = calc(a[0], a[i]);
		
	}
	
	
	for(int mask = 0; mask < (1 << n); ++mask) {
		for(int cur = 0; cur < n; ++cur) {
			if(!(mask >> cur & 1)) continue;
			long long val = dp[cur][mask];
			
			for(int next = 0; next < n; ++next) {
				if(mask >> next & 1) continue;
				
				int mask1 = mask | (1 << next);
				
				dp[next][mask1] = min(dp[next][mask1], val + calc(a[cur], a[next]));
			}
		}
	}
	
	cout << dp[0][(1 << n) - 1];
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}