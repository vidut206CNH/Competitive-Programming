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

string s;
int q;

void calc(char& res, int x) {
	if(res == 'A') {
		if(x == 0) res = 'C';
		else res = 'B';
	}
	else if(res == 'B') {
		if(x == 0) res = 'A';
		else res = 'C';
	}
	else if(res == 'C') {
		if(x == 0) res = 'B';
		else res = 'A';
	}
}


char solve(char d, int m) {
	if(d == 'A') {
		if(m%3 == 0) return 'A';
		if(m%3 == 1) return 'B';
		return 'C';
	}
	if(d == 'B') {
		if(m%3 == 0) return 'B';
		if(m%3 == 1) return 'C';
		return 'A';
	}
	
	if(d == 'C') {
		if(m%3 == 0) return 'C';
		if(m%3 == 1) return 'A';
		if(m%3 == 2) return 'B';
	}
	return 'V';
}

signed main() {
	fast_cin();
	
	cin >> s >> q;
	while(q--) {
		int t,k;
		cin >> t >> k;
		vector<int> d;
		while(k != 1 && t) {
			d.push_back(k&1);
			if(k&1) k = (k + 1) >> 1;
			else k >>= 1;
			--t;
		}
		if(t == 0) {
			reverse(d.begin(),d.end());
			char res = s[k - 1];
			for(auto x : d) {
				calc(res, x);
			}
			
			cout << res << "\n";
			continue;
		} else {
			reverse(d.begin(), d.end());
			char res = solve(s[k - 1], t);
			for(auto x : d) {
				calc(res, x);
			}
			
			cout << res << "\n";
		}
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}