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

vector<string> p(2);
int bit[2][25][MAXN1];
int cnt[2][25][25];


void update(int d, int c, int pos) {
	for(;pos < sz(p[d]); pos += (pos & -pos))
}

signed main() {
	fast_cin();
	for(int i = 0; i < 2; ++i) {
		cin >> p[i];
		p[i] = '0' + p[i];
		
		for(int pos = 1; pos <= sz(p[i]) - 1; ++pos) {
			
		}
	}
	
	int q;
	cin >> q;
	while(q--) {
		string d;
		cin >> d;
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}