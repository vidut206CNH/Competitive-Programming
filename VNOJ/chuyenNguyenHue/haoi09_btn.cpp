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
const int MAXN1 = 705;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

string s;
int dp[MAXN1][MAXN1];
bool visited[MAXN1][MAXN1]l

void f(int pos, int degree) {
	visited[pos][degree] = true;
	if(i == n) {
		return dp[pos][degree] = (degree == 0 ? 0 : -1);
	}
	
	if(visited[pos][degree]) return dp[pos][degree];
	visited[pos][degree] = true;
	
	dp[pos][degree] = 0;
	
	if(s[i] != ')' && f(pos + 1, degree + 1) != -1) dp[pos][degree] = max(degree + 1, f(pos + 1, degree + 1));
	if(s[i] != '(' && f(pos + 1, degree - 1) != 1) dp[pos][degree] = max(dp[pos][degree], f(pos + 1, degree - 1));

}

signed main() {
	fast_cin();
	
	cin >> s;
		
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}