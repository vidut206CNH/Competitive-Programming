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

int t;
int f[MAXN1][10];
int s[MAXN1][10];
int Pow[MAXN1];

int dp(int pos, int last) {
	if(pos == -1) return 1;
	
	auto &res = f[pos][last];
	
	if(res != -1) return res;
	
	res = 0;
	
	for(int num = 0; num < 10; ++num) {
		
		if(num == last) res = (res + dp(pos - 1, num))%MOD;
		
		else {
			res = (res + 1LL*num*Pow[pos]%MOD*dp(pos - 1, num)%MOD)%MOD;
		}
		
	}
	
	return res;
}

int cnt(string X) {
	reverse(X.begin(), X.end());
	
	int last = 0;
	int res = 0;
	
	for(int i = sz(X) - 1; i >= 0; --i) {
		int val = X[i] - '0';
		
		for(int num = 0; num < val; ++num) {
			if(num == last) res = (res + 1LL*10*dp(i - 1, num))%MOD;
			else res = (res + 1LL*10*dp(i - 1, num)%MOD)%MOD;
		} 
		db(res);
		cerr << "\n";
		last = val;
	}
	
	return res;
}

int main() {
	fast_cin();
	
	
	memset(f, -1, sizeof f);
	
	Pow[0] = 1;
	
	for(int i = 1; i < MAXN1; ++i) Pow[i] = 1LL*Pow[i - 1]*10%MOD;
	cin >> t;
	
	while(t--) {
		string L, R;
		cin >> L >> R;
		if(*min_element(R.begin(), R.end()) == '9') {
			R = "1" + string(sz(R), '0');
		}	
		
		else {
			for(int i = sz(R) - 1; i >= 0; --i) {
				if(R[i] != '9') {
					
					++R[i];
					for(int j = i + 1; j < sz(R); ++j) R[j] = 0;
					break;
					
				}
			}
		}
		db(cnt(L));
		cout << (cnt(R) - MOD + cnt(L))%MOD << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}