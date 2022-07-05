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
vector<int> b(5);
map<vector<int>, int> dp;

int calc(vector<int> x) {
	if(dp.count(x)) return dp[x];
	
	int res = 0;
	
	for(int i = 0; i < n; ++i) {
		if(x[i]  && x[i]%2 == 0) {
			vector<int> tmp = x;
			tmp[i] /= 2;
			res = (res + calc(tmp))%MOD;
		}
		
		if(x[i] && (x[i]%2 == 1)) {
			int j = (i + 1)%n;
			if(x[j] == 0 || x[j]%2 == 0) continue;
			vector<int> tmp = x;
			tmp[i] = (tmp[i] - 1)/2;
			tmp[j] = (tmp[j] - 1)/2;
			
			res = (res + calc(tmp))%MOD;
		}
	}
	
	return dp[x] = res;
}

int main() {
	fast_cin();
	
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> b[i];
	dp[vector<int>(5, 0)] = 1;
	cout << calc(b);	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}