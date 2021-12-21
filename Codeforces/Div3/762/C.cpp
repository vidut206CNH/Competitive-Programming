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
#define INF 2e18
#define db(x) cerr << "[" << "Line " << __LINE__ << " -- " << (#x) << " : " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;


string a,s;


void solve() {
	cin >> a >> s;
	if((a.size() == s.size() && a > s) || a.size() > s.size()) {
		cout << "-1\n";
	}
	reverse(a.begin(),a.end());
	reverse(s.begin(),s.end());
	
	int i=0,j=0;
	bool bad = 0;
	string b = "";
	while(i < a.size() && j < s.size()) {
		if(a[i] > s[j]) {
			if(j < s.size() && s[j + 1] == '1') {
				b =char(10 + s[j] - a[i] + '0') + b;
				j++;
			}
			else {
				bad = 1;
			}
		} else {
			b = char(s[j] - a[i] + '0') + b;
		}
		i++;
		j++;
	}
	while(j < s.size()) {
		b = s[j] + b;
		j++;
	}
	bad |= (i != a.size());
	if(bad) {
		cout << "-1\n";
	} else {
		while(b.size() != 1 && b[0] == '0') b.erase(b.begin());
		cout << b << "\n";
	}
}

signed main() {
	fast_cin();
	
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}