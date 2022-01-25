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

int t,alp;
string n;
int k;

bool div(string &s, int d) {
	string tmp = s;
	int rem = 0;
	for(int i=0;i<sz(tmp);++i) {
		int g = tmp[i] - '0' + rem*10;
		tmp[i] = char(g/d + '0');
		rem = g%d;
	}
	if(rem) return false;
	while(tmp[0] == '0') tmp.erase(tmp.begin());
	s = tmp;
	return true;
}

void solve() {
	cin >> n >> k;
	string res = "";
	
	for(int i=1;i<=k;++i) {
		if(n == "1") {
			res = '1' + res;
			continue;
		}
		for(int d = 9; d>= 1;--d) {
			if(div(n,d)) {
				res = char(d + '0') + res;
				break;
			}		
		}
	}
	cout << res << "\n";
}

signed main() {
	fast_cin();
	
	cin  >> t >> alp;
	while(t--) {
		solve();
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}