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
const int MAXN1 = 5e2+5;
const int MAXN2 = 1e6+5;

int n;
char a[MAXN1];
int dp[MAXN1][MAXN1][MAXN1];

int calc(int l = 1, int r = n, int sum = 0) {
	if(l >= r) {
		return 0;
	}
	
	int res = dp[l][r][sum];
	if(res != -1) return res;
	res = 0;
	if(a[l] != a[r]) {
		if((sum && a[l] == ')') || (a[l] == '(')) {
			res = (res + 1 + calc(l + 1, r - 1, sum + (a[l] == '(' ? +1 : -1)))%MOD;
		}  
	}
	res = (res + calc(l + 1, r, sum))%MOD;
	res = (res + calc(l, r - 1, sum))%MOD;
	res = (res - calc(l + 1, r - 1, sum) + MOD)%MOD;
	return dp[l][r][sum] = res;
}

int main() {
	fast_cin();
	
	memset(dp, -1, sizeof dp);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	cout << calc() << "\n";
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}