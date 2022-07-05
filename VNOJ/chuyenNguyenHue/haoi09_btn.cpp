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
const int MAXN2 = 700;
const int inf = 1e18;

string s;
int dp[MAXN1][MAXN1];
int lim;
bool visited[2*MAXN2][2*MAXN2];
char res[MAXN1];

int f(int pos, int degree) {
	if(pos == sz(s) - 1) {
		return dp[pos][degree + MAXN2] = (degree == 0 ? 0 : -1);
	}
	
	if(visited[pos][degree + MAXN2]) return dp[pos][degree + MAXN2];
	visited[pos][degree + MAXN2] = true;
	
	dp[pos][degree + MAXN2] = -1;
	
	if(s[pos + 1] != ')' && f(pos + 1, degree + 1) != -1) dp[pos][degree + MAXN2] = max(degree + 1, f(pos + 1, degree + 1));
	if(degree && s[pos + 1] != '(' && f(pos + 1, degree - 1) != -1) dp[pos][degree + MAXN2] = max(max(dp[pos][degree + MAXN2], degree), f(pos + 1, degree - 1));
	
	return dp[pos][degree + MAXN2];
}




signed main() {
	fast_cin();
	
	cin >> s;
	s = '0' + s;
	lim = f(0, 0);
	int cur = 0, best = 0;	
	for(int pos = 1; pos <= sz(s) - 1; ++pos) {
		if(s[pos] != '?') {
			res[pos] = s[pos];
			cur += (s[pos] == '(' ? +1 : -1);
			best = max(best, cur);
			continue;
		}
		
		if(cur) {
			if(f(pos, cur - 1) != -1 && max(best, f(pos, cur - 1)) == lim) {
				res[pos] = ')';
				best = max(best, cur - 1);
				--cur;
			}
			else {
				res[pos] = '(';
				best = max(best, cur + 1);
				++cur;
			}
		}
		
		else {
			res[pos] = '(';
			best = max(best, cur + 1);
			++cur;
		}
	}
	
	for(int i = 1; i <= sz(s) - 1; ++i) cout << res[i];	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}