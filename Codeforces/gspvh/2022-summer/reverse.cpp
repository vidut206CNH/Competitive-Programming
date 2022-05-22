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

int n;
int val[MAXN1];
string a[2][MAXN1];
int dp[2][MAXN1];


bool le(const string &A, const string& B) {
	for(int i = 0; i < min(sz(A), sz(B)); ++i) {
		if(A[i] != B[i]) return A[i] < B[i];
	}
	
	if(sz(A) != sz(B)) return sz(A) < sz(B);
	
	return true;
	
}

int calc(int pos, int state) {
	if(pos == n) return 0;
	
	if(dp[state][pos] != -1) return dp[state][pos];
	
	int res = inf;
	if(le(a[state][pos], a[0][pos + 1])) {
		res = min(res, calc(pos + 1, 0));
	}
	
	if(le(a[state][pos], a[1][pos + 1])) {
		res = min(res, calc(pos + 1, 1) + val[pos + 1]);
	}
	
	return dp[state][pos] = res;
}


signed main() {
	fast_cin();
	
	
	cin >> n;
	
	for(int i = 1; i <= n; ++i) cin >> val[i];
	for(int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		a[0][i] = s;
		reverse(s.begin(), s.end());
		a[1][i] = s;
	}
	
	
	memset(dp, -1, sizeof dp);
	
	
	int res = calc(0, 0);
	
	cout << (res == inf ? -1 : res);
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}