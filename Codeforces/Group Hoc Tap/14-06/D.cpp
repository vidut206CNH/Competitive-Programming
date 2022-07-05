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
const int MAXN1 = 5005;
const int MAXN2 = 1e6+5;

int n;
vector<int> cur, nex;

int main() {
	fast_cin();
	
	cin >> n;
	bool sign = true;
	for(int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		cur.push_back(x);
	}
	for(int i = 1; i < n; ++i) {
		nex.clear();
		
		for(int j = 1; j < sz(cur); ++j) {
			sign ^= 1;
			
			if(sign) nex.push_back((cur[j - 1] - cur[j] + MOD)%MOD);
			else nex.push_back((cur[j - 1] + cur[j])%MOD);
		}
		
		cur = nex;
	}
	
	cout << cur.back();
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}