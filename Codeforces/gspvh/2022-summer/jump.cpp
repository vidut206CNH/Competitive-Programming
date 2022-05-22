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
const int MAXN1 = 3e3 + 5;
const int MAXN2 = 1e6+5;
const long long inf = 1e18;


vector<int> all_state = {0, 1, 2, 4, 5, 8, 9, 10};
vector<int>	adj_state[(1 << 4) + 5];

int m,n, k;
long long dp[2][MAXN1][(1 << 4)  + 5];
int a[MAXN1][10];


bool check(int A, int B) {
	for(int i = 0; i < n; ++i) {
		if((A >> i & 1) & (B >> i & 1)) return false;
	}
	
	return true;
}




int get_sum(int i, int state) {
	
	int res = 0;
	
	for(int j = 0; j < n; ++j) {
		if(state >> j & 1) res += a[i][j];
	}
	
	return res;
}



signed main() {
	fast_cin();

/*	freopen("jump.inp", "r", stdin);
	freopen("jump.out", "w", stdout);*/	

	cin >> m >> n >> k;
	
	for(int i = 0; i < 2; ++i) {
		for(int num = 0; num <= k; ++num) {
			for(int state = 0; state < (1 << n); ++state) {
				dp[i][num][state] = -inf;
			}
		}
	}
	
	
	
	for(int i = 1; i <= m; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}


	for(auto x : all_state) {
		
		for(auto v : all_state) {
			
			if(!check(x, v)) continue;
			
			adj_state[x].push_back(v);	
		}
	}
	
	// DP

	long long res = -inf;
	dp[0][0][0] = 0;
	
	
	for(int i = 0; i < m; ++i) {
		for(int num = 0; num <= k; ++num) {
			for(auto x : all_state) {
				if(x >= (1 << n)) break;
				
				
				long long cur = dp[i%2][num][x];
				
				if(cur == -inf) continue;
				
				for(auto v : adj_state[x]) {
					
					if(v >= (1 << n)) break;
					
					int num1 = num + __builtin_popcount(v);
					
					if(num1 > k) continue;
					
					dp[(i + 1)%2][num1][v] = max(dp[(i + 1)%2][num1][v], 0LL + cur + get_sum(i + 1, v));
					
				}
				
				dp[i%2][num][x] = -inf;
			}
		}
	}
	
	
	
	// result
	
	for(int state = 0; state < (1 << n); ++state) {
		res = max(res, dp[m%2][k][state]);
	}
	
	cout << res;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}