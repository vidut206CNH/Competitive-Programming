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
const int MAXN1 = 3005;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n;
int dp[MAXN1];
int trace[MAXN1];
string s;

bool check(const char & c) {
	for(auto x : {'a', 'e', 'u', 'o', 'i'}) {
		if(c == x) return false; 
	}
	return true;
}

signed main() {
	fast_cin();
	
	cin >> s;
	n = sz(s);
	s = '0' + s;	
	
	for(int i=1;i<=n;++i) {
		
		int cnt = 1, lastc = ' ';
		dp[i] = inf;
		vector<int> d;
		for(int j=i;j>=1;--j) {
			if(check(s[j])) {
				bool bad = false;
				if(j <= i-2) { 
					for(int k = j+1; k <= j+2;++k) {
						if(!check(s[k])) {
							bad = false;
							break;
						}
						bad |= (s[k] != s[j]);
					}
					if(bad) break;
				}
			}
			
			if(dp[i] > dp[j-1] + 1) {
				dp[i] = dp[j-1] + 1;
				trace[i] = j; 
			}
			
			
		}	
	}
	
	vector<string> res;
	int pos = n;
	while(pos) {
		string tmp = "";
		for(int i = trace[pos]; i <= pos;++i) tmp += s[i];
		res.push_back(tmp);
		pos = trace[pos] - 1;
	}
	
	reverse(res.begin(), res.end());
	
	for(auto x : res) cout << x << " ";
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}