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
const int MAXN1 = 1e4+5;
const int MAXN2 = 1e6+5;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r) {
	return l + rng() * 1LL * rng()%(r - l + 1);
}

int t;
int f[MAXN1][20][8];

bool check(int state, int c) {
	return (state >> ((30 - c)%3))&1;
}

int dp(int pos, int rem, int state) {
	
	if(pos == -1) return (rem == 0);
	
	auto &res = f[pos][rem][state];
	if(res != -1) return res;
	
	res = 0;
	
	for(int num = 0; num < 10; ++num) {
		
		if(check(state, num)) continue;
		
		int rem1 = (rem*10 + num)%19;
		int state1 = (num == 0 && state == 0) ? 0 : (state | (1 << (num%3)));
		
		res = (res + dp(pos - 1, rem1, state1))%MOD;
	}
	
	return res;
}

int cnt(string X) {
	reverse(X.begin(), X.end());
	
	int rem = 0, state = 0;
	int res = 0;
	
	for(int pos = sz(X) - 1; pos >= 0; --pos) {
/*		db(rem);
		db(state);
		db(pos);
		cerr << "\n";*/
		int val = X[pos] - '0';
		
		for(int num = 0; num < val; ++num) {
			if(check(state, num)) continue;
			
			int rem1 = (rem*10 + num)%19;
			int state1 = (num == 0 && state == 0) ? 0 : (state | (1 << (num%3)));
			
			res = (res + dp(pos - 1, rem1, state1))%MOD;
		}
		
		if(check(state, val)) break;
		
		rem = (rem*10 + val)%19;
		state = (state == 0 && val == 0) ? 0 : (state | (1 << (val%3)));
	}

	return res;
}


int main() {
	fast_cin();
	
	memset(f, -1, sizeof f);
	cin >> t;
	
	while(t--) {
		string L,R;
		cin >> L >> R;
		
		if(*min_element(R.begin(), R.end()) == '9') {
			R = "1" + string(sz(R), '0');
		}
		
		else {
			for(int i = sz(R) - 1; i >= 0; --i) {
				if(R[i] != '9') {
					++R[i];
					for(int j = i + 1; j < sz(R); ++j) R[j] = '0';
					break;
				}
			}
		}
		
		cout << (cnt(R) + MOD - cnt(L))%MOD << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}