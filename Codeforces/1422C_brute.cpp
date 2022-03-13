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

signed main() {
	fast_cin();
	
	cin >> s;
	int res = 0;
	for(int i = 0; i < sz(s); ++i) {
		int sum = 0;
		for(int j = i; j < sz(s); ++j) {
			string tmp = s;
			tmp.erase(i, j - i + 1);
			cout << tmp << "\n";
			reverse(tmp.begin(), tmp.end());
			int mul = 1;
			for(auto x : tmp) {
				sum = (sum + mul*(x - '0'))%MOD;
				mul = (mul*10)%MOD;
			}
		}
		db(sum);
		cerr << "\n";
		res = (res + sum)%MOD;
	}
	
	
	cout << res;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}