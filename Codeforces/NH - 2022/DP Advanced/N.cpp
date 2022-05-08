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
const int MAXN1 = 5e3;
const int MAXN2 = 1e6+5;
const long long inf = 1e18;


int n;
char s[MAXN1 + 15];
int f[MAXN1 + 15];
int p[MAXN1 + 15];
// 0 ~ -1
// 1 ~ 0
// 2 ~ +1

int prefix_pos[3][MAXN1 + 15];
int sufix_pos[3][MAXN1 + 15];

int dp[2][2*MAXN1 + 35];
int zeros[MAXN1 + 15];
int d[3];


signed main() {
	fast_cin();
	
	memset(prefix_pos, -1, sizeof prefix_pos);
	memset(sufix_pos, -1, sizeof sufix_pos);
	
	
	cin >> n;
	int cnt_zero = 0;
	zeros[0] = 0;
	int lim = 0;
	
	for(int i = 1; i <= n; ++i) {
		cin >> s[i];
		f[i] = f[i - 1];
		if(s[i] == '1') f[i]++;
		else if(s[i] == '2') f[i]--;
		
		cnt_zero += (s[i] == '0');
		if(s[i] == '0') {
			zeros[++lim] = i;
		}
		p[i] = i - cnt_zero;
	}
	
	
	prefix_pos[1][0] = 0;
	
	for(int i = 1; i <= n; ++i) {
		prefix_pos[0][i] = ((f[i] < 0 && s[i] != '0') ? i : prefix_pos[0][i - 1]);
		prefix_pos[1][i] = ((f[i] == 0 && s[i] != '0') ? i : prefix_pos[1][i - 1]);
		prefix_pos[2][i] = ((f[i] > 0 && s[i] != '0') ? i : prefix_pos[2][i - 1]);
	}
	
	for(int i = n; i >= 1; --i) {
		sufix_pos[0][i] = ((f[i] < 0 && s[i] != '0') ? i : sufix_pos[0][i + 1]);
		sufix_pos[1][i] = ((f[i] == 0 && s[i] != '0') ? i : sufix_pos[1][i + 1]);
		sufix_pos[2][i] = ((f[i] > 0 && s[i] != '0') ? i : sufix_pos[2][i + 1]);
	}
	
	
	
	// DP
	memset(dp, -1, sizeof dp);
	
	dp[0][0 + MAXN1] = 0;
	
	for(int i = 0; i <  lim; ++i) {
		int next = i + 1;
		int pos = zeros[next];
		
		
		for(int w = -i + MAXN1; w <= i + MAXN1; ++w) {
			if(dp[i%2][w] == -1) continue;
			int val = dp[i%2][w];
			
			dp[i%2][w] = -1;
/*			db(i);
			db(w);
			db(val);
			db(pos);*/
			
			
			for(int id = 0; id < 3; ++id) {
				d[id] = MOD;
				if(prefix_pos[id][pos] != -1) d[id] = min(d[id], abs(p[pos] - p[prefix_pos[id][pos]]));
				if(sufix_pos[id][pos] != -1) d[id] = min(d[id], abs(p[sufix_pos[id][pos]] - p[pos]));
			}
			if(d[0] != MOD) dp[next%2][w - 1] = (dp[next%2][w - 1] == -1 ? val + d[0] : min(dp[next%2][w - 1], val + d[0]));
			if(d[1] != MOD) dp[next%2][w] = (dp[next%2][w] == -1 ? val + d[1] : min(dp[next%2][w], val + d[1]));
			if(d[2] != MOD) dp[next%2][w + 1] = (dp[next%2][w + 1] == -1 ? val + d[2] : min(dp[next%2][w + 1], val + d[2]));
		}
		
		
		
	}
	int res = MOD;
	
	for(int w = MAXN1 + 1; w <= cnt_zero + MAXN1; ++w) {
		if(dp[lim%2][w] == -1) continue;
		res = min(res, dp[lim%2][w]);
	}
	
	if(res == MOD) cout << "impossible";
	else cout << res;
	
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}