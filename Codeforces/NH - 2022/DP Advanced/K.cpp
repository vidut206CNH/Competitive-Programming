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
const int MAXN1 = 46656;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,m;

int dp[MAXN1 + 5][1005];


void calc(int pos, int state) {
	if(pos == n + 1) {
		bool ok = true;
		int tmp = state;
		while(tmp) {
			ok &= ((tmp%m) == 0);
			tmp /= m;
		}
		
		return ok;
	}
	
	if(dp[state][pos] != -1) return dp[state][pos];
	
	vector<int> d(m, 0);
	int tmp = state;
	int id = 0;
	while(tmp) {
		d[id] = (tmp%m);
		tmp /= m;
		++id;
	}
	
	vector<int> next;
	
	for(int i = 0; i < m; ++i) {
		next
		if(d[i] != 0)
	}
}

signed main() {
	fast_cin();
	
	memset(dp, -1, sizeof dp);
	cin >> n >> m;
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}