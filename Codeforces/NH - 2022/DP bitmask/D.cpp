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
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int t;
int dp[MAXN1][64];
int f[3][MAXN1];
/*
state:
00: right
01: up
10: down
11: left
*/
vector<int> possible = {44, 50, 28, 49, 21, 42};

/*
44: 10 11 00
50: 11 00 10
28: 01 11 00
49: 11 00 01
21: 01 01 01
42: 10 10 10
*/


bool checkdown(const int& state) {
	bool found = 0;
	for(int i=0;i<5;i += 2) {
		found |= (!(state >> i & 1) && (state >> (i+1) & 1));
	}
	return found;
}


bool checkup(const int& state) {
	bool found = 0;
	for(int i=0;i<5;i += 2) {
		found |= ((state >> i & 1) && !(state >> (i+1) & 1));
	}
	return found;
}

bool check(const int& pre, const int& cur) {
	if((cur ^ pre) == 3 && (cur >> 1 & 1)) return true;
	if((cur ^ pre) == 48 && (cur >> 5 & 1)) return true;
	if((cur ^ pre) == 63 && (cur >> 1 & 1)) return true;
	
	
	return (!checkup(pre) && !checkdown(cur));
}


bool checkf(const int& state, int pos) {
	pos = (pos-1)*2;
	return ((state >> pos & 1) && !(state >> (pos + 1) & 1));
}



signed main() {
	fast_cin();
	
	cin >> t;
	
	for(auto state : possible) {
		if(checkup(state)) continue;
		dp[0][state] = 1;
	}
	
	for(int i=1;i<=100000;++i) {
		for(auto state : possible) {
			for(auto pre : possible) {
				if(!check(pre, state)) continue;
				dp[i][state] = (dp[i][state] + dp[i-1][pre])%MOD;
				if(i > 5) continue;
				db(pre);
				db(state);
				db(i);
				db(dp[i][state]);
				cerr << "\n";				
			}
		}
	}
	
	for(int i=1;i<=t;++i) {
		int n,x,y;
		int res = 0;
		cin >> n >> x >> y;
		for(auto left : possible) {
			if(!checkf(left, y)) continue;
			for(auto right : possible) {
				if(!checkf(right, y)) continue;
				db(dp[x][left]);
				db(left);
				db(right);
				cerr << "\n";				
/*				if(!check(left, right)) continue;
				db(left);
				db(right);
				cerr << "\n";*/
				res = (res + dp[x][left]*dp[n - x][right])%MOD;
			}
		}
		cerr << "\n";
		
		cout << res << "\n";
	}
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}