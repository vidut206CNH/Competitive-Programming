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

const int MOD = 1e9 + 19972207;
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;
//const int inf = 1e18;

int n;
int dp[MAXN2][2][2];
string a,b;

int calc(int pos, bool equalA, bool equalB) {
	
	if(pos == n) {
		return (((sz(a) - 1 < n) || !equalA) && ((sz(b) - 1 > n) || !equalB));
	}
	
	if(dp[pos][equalA][equalB] != -1) return  dp[pos][equalA][equalB];
	
	int res = 0;
	
	for(char c = 'a'; c <= 'z'; ++c) {
		if(equalA && c < a[pos + 1]) continue;
		if(equalB && c > b[pos + 1]) continue;
		
		bool equalA1 = (equalA && c == a[pos + 1]);
		bool equalB1 = (equalB && c == b[pos + 1]);
		res = (res + calc(pos + 1, equalA1, equalB1))%MOD;
	}
	
	
	return dp[pos][equalA][equalB] = res;
	

}

signed main() {
	fast_cin();
	
	freopen("strings.inp", "r", stdin);
	freopen("strings.out", "w", stdout);
	
	cin >> n;
	
	cin >> a >> b;
	a = '0' + a;
	b = '0' + b;
	//a.resize(sz(b));

	
	memset(dp, -1, sizeof dp);
	
	cout << calc(0, 1, 1);
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}