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
const int MAXN1 = 2e3+5;
const int MAXN2 = 1e6+5;

int n,k;
string s;
char c[] = {'{', '[', '('};
char o[] = {'}', ']', ')'};
int f[MAXN1][305][6][6];

int dp(int pos, int state, int degree, int sz) {
	
/*	db(pos);
	db(state);
	db(degree);
	db(sz);
	cerr << '\n';*/
	if(pos == n) return (!state && degree == k && !sz);
	
	auto &res = f[pos][state][degree][sz];
	
	if(res != -1) return res;
	res = 0;
	
	if(sz < k) {
		
		for(int i = 0; i < 3; ++i) {
			if(s[pos] != '?' && s[pos] != c[i]) continue;
			
			int new_state = state*3 + i;
			int new_degree = max(degree, sz + 1);
			
			res = (res + dp(pos + 1, new_state, new_degree, sz + 1))%MOD;
		}
		
	}
	if(sz) {
		
		for(int i = 0; i < 3; ++i) {
			if((s[pos] == '?' || s[pos] == o[i]) && state%3 == i) {		
			
				int new_state = state/3;
				int new_degree = degree;
				res = (res + dp(pos + 1, new_state, new_degree, sz - 1))%MOD;
				
			}
		}
		 
	}
	
	return res;
	
	
}

int main() {
	fast_cin();
	
	memset(f, -1, sizeof f);
	cin >> n >> k >> s;	
	
	cout << dp(0, 0, 0, 0);
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}