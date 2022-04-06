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

int l, r, n;
int dp[20][2][2][3][3][3][3][3][3][3][3][3][3];
vector<int> digits;


int calc(int pos, bool equal, bool positive, vector<int> &c) {
	if(pos == sz(digits)) {
		if(positive) return 1;
		return 0;
	}
	int& res = dp[pos][equal][positive][c[0]][c[1]][c[2]][c[3]][c[4]][c[5]][c[6]][c[7]][c[8]][c[9]];
	if(res != -1) return res;
	
	res = 0;
	
	for(int i = 0; i <= 9; ++i) {
		bool positive2 = (positive || i > 0);
		
		if(equal && i > digits[pos]) break;
		
		
		bool equal2 = (equal && i == digits[pos]);
		
		vector<int> next = c;
		
		if(i == 0) {
			if(positive2 && next[0] < 2) {
				next[0]++;
				res = res + calc(pos + 1, equal2, positive2, next);
			}
			else if(!positive2) {
				res = res + calc(pos + 1, equal2, positive2, next);
			}
		}
		
		else {
			if(next[i] < 2) {
				next[i]++;
				res = res + calc(pos + 1, equal2, positive2, next);
			}
		}
	}
	return res;
}


int solve(int val) {
	digits.clear();
	digits.push_back(0);
	
	while(val) {
		digits.push_back(val%10);
		val /= 10;
	}
	if(sz(digits) == 1) digits.push_back(0);
	
	reverse(digits.begin() + 1, digits.end());
	
	vector<int> c(10,0);
	
	memset(dp, -1, sizeof dp);
	
	return calc(1, 1, 0, c);
}

signed main() {
	fast_cin();
	
	
	cin >> l >> r;
	cout << solve(r) - solve(l - 1);
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}